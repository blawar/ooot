#if !defined(DISABLE_SDL_CONTROLLER)
#include <algorithm>
#include "ultra64/types.h"
#include "padmgr.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#include <SDL2/SDL.h>
#include "sdl.h"
#include <unordered_map>
#ifdef ENABLE_JSON
#include"keyboard.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"
#include <rapidjson/istreamwrapper.h>
#endif
#include <fstream>
#include "../options.h"
#include "../player/players.h"
#include "tas.h"
#include "SDL_gamecontrollerdb.h"

#ifndef __SWITCH__
#define DEADZONE 20
#define RDEADZONE 20
#else
#define DEADZONE 0
#define RDEADZONE 0
#endif

#define INITIAL_PEAK 0x8000

extern RumbleStruct g_Rumble;

OSTime osGetTime(void);

static int g_lstickX_peak = INITIAL_PEAK;
static int g_lstickY_peak = INITIAL_PEAK;
static int g_rstickX_peak = INITIAL_PEAK;
static int g_rstickY_peak = INITIAL_PEAK;

namespace oot::hid
{
#ifdef ENABLE_JSON
	bool saveJson(rapidjson::Document& doc, const std::string& jsonFilePath);
#endif

	static bool g_haptics = false;

	// const char* getInputName(int input);
	// int getInputValue(const std::string& input);

	Joypad::~Joypad()
	{
		closeHaptics();
		SDL_QuitSubSystem(SDL_INIT_HAPTIC);
	}

	Joypad::Joypad() : N64Controller()
	{
		if(SDL_Init(SDL_INIT_GAMECONTROLLER) != 0)
			fprintf(stderr, "SDL init error: %s\n", SDL_GetError());

		g_haptics = SDL_InitSubSystem(SDL_INIT_HAPTIC) == 0;

#ifdef __SWITCH__
		// swap A, B and X, Y to correct positions
		SDL_GameControllerAddMapping("53776974636820436F6E74726F6C6C65,Switch Controller,"
					     "a:b0,b:b1,back:b11,"
					     "dpdown:b15,dpleft:b12,dpright:b14,dpup:b13,"
					     "leftshoulder:b6,leftstick:b4,lefttrigger:b8,leftx:a0,lefty:a1,"
					     "rightshoulder:b7,rightstick:b5,righttrigger:b9,rightx:a2,righty:a3,"
					     "start:b10,x:b2,y:b3");
#endif

		for(int i = 0; i < SDL_NumJoysticks(); i++)
		{
			if(SDL_IsGameController(i))
			{
				m_context = SDL_GameControllerOpen(i);

				if(m_context)
					break;
			}
		}

#ifdef ENABLE_MOUSE
		// temporarily change mouse mode to not take over the cursor
		// SDL_SetRelativeMouseMode(m_controllers.size() ? SDL_FALSE : SDL_TRUE);
#endif

		m_motorEnabled = initHaptics();

		m_keyBindings[SDL_CONTROLLER_BUTTON_START]	   = Button::START_BUTTON;
		m_keyBindings[SDL_CONTROLLER_BUTTON_LEFTSHOULDER]  = Button::Z_TRIG;
		m_keyBindings[SDL_CONTROLLER_BUTTON_RIGHTSHOULDER] = Button::R_TRIG;
		m_keyBindings[SDL_CONTROLLER_BUTTON_A]		   = Button::A_BUTTON;
		m_keyBindings[SDL_CONTROLLER_BUTTON_X]		   = Button::B_BUTTON;
		m_keyBindings[SDL_CONTROLLER_BUTTON_B]		   = Button::A_BUTTON;
		m_keyBindings[SDL_CONTROLLER_BUTTON_Y]		   = Button::B_BUTTON;
		m_keyBindings[SDL_CONTROLLER_BUTTON_DPAD_LEFT]	   = Button::L_CBUTTONS;
		m_keyBindings[SDL_CONTROLLER_BUTTON_DPAD_RIGHT]	   = Button::R_CBUTTONS;
		m_keyBindings[SDL_CONTROLLER_BUTTON_DPAD_UP]	   = Button::U_CBUTTONS;
		m_keyBindings[SDL_CONTROLLER_BUTTON_DPAD_DOWN]	   = Button::D_CBUTTONS;

	//Connect rumble pack callback
	g_Rumble.onVibrate = [=](auto strength, auto time, auto decay) { onVibrate(strength, time, decay); };

#ifndef __SWITCH__
		loadKeyBindings();
#endif
	}

	void Joypad::scan()
	{
		auto controller = std::make_shared<Joypad>();
		m_controllers.push_back(controller);
		Players::get().attach(controller, 0);
	}

	void Joypad::loadKeyBindings()
	{
#ifdef ENABLE_JSON
		try
		{
			std::ifstream ifs("gamepad1.bindings.json", std::ifstream::in);

			if(ifs.is_open())
			{
				rapidjson::IStreamWrapper isw(ifs);
				rapidjson::Document d;
				d.ParseStream(isw);

				if(d.IsObject())
				{
					for(auto itr = d.MemberBegin(); itr != d.MemberEnd(); ++itr)
					{
						if(itr->name.IsString() && itr->value.IsString())
						{
							auto key   = SDL_GameControllerGetButtonFromString(itr->name.GetString());
							auto value = getInputValue(itr->value.GetString());

							if(key != SDL_CONTROLLER_BUTTON_INVALID && value != Button::NONE)
								m_keyBindings[key] = value;
							else
							{
								// sm64::log("could not bind key: \"%s\" -> \"%s\"\n", itr->value.GetString(), itr->name.GetString());
							}
						}
					}
				}
			}
			else
			{
#ifndef __SWITCH__
				saveKeyBindings(); // create default bindings file
#endif
			}
		}
		catch(...)
		{
		}
#endif
	}

	void Joypad::saveKeyBindings()
	{
#ifdef ENABLE_JSON
		try
		{
			rapidjson::Document d;
			d.SetObject();

			rapidjson::Document::AllocatorType& allocator = d.GetAllocator();

			for(const auto i : m_keyBindings)
			{
				rapidjson::Value value(getInputName(i.second), allocator);
				rapidjson::Value key(SDL_GameControllerGetStringForButton(i.first), allocator);
				d.AddMember(key, value, allocator);
			}

			saveJson(d, "gamepad1.bindings.json");
		}
		catch(...)
		{
		}
#endif
	}

	bool Joypad::initHaptics()
	{
		if(!g_haptics)
			return false;

		m_haptic = SDL_HapticOpenFromJoystick(SDL_GameControllerGetJoystick(m_context));

		if(!m_haptic)
			return false;

		if(SDL_HapticRumbleSupported(m_haptic) != 1)
		{
			closeHaptics();
			return false;
		}

		if(SDL_HapticRumbleInit(m_haptic) != 0)
		{
			closeHaptics();
			return NULL;
		}

		return true;
	}

	void Joypad::closeHaptics()
	{
		if(m_haptic)
		{
			SDL_HapticClose(m_haptic);
			m_haptic = nullptr;
		}
	}

	void Joypad::SendMotorEvent(short time, short level)
	{
		if(m_motorEnabled)
			SDL_HapticRumblePlay(m_haptic, level / 100.0f, time * 10);
	}

	void Joypad::ResetMotorPack()
	{
		if(m_motorEnabled)
			SDL_HapticRumbleStop(m_haptic);
	}

	void Joypad::SendMotorVib(int level)
	{
		SendMotorEvent(30, level);
	}

	int8_t Joypad::convertToByte(int value, int max)
	{
		int8_t result = value * 0x7F / max;
		return result;
	}

	int8_t Joypad::invert(const int8_t value)
	{
		if(value <= -128)
			return 127;
		return -value;
	}

	int8_t Joypad::stickLeftX()
	{
		auto value = SDL_GameControllerGetAxis(m_context, SDL_CONTROLLER_AXIS_LEFTX);

		if(abs(value) > g_lstickX_peak)
			g_lstickX_peak = abs(value);

		return convertToByte(value, g_lstickX_peak);
	}

	inline int8_t Joypad::stickLeftY()
	{
		auto value = SDL_GameControllerGetAxis(m_context, SDL_CONTROLLER_AXIS_LEFTY);

		if(abs(value) > g_lstickY_peak)
			g_lstickY_peak = abs(value);

		return convertToByte(value, g_lstickY_peak);
	}

	inline int8_t Joypad::stickRightX()
	{
		auto value = SDL_GameControllerGetAxis(m_context, SDL_CONTROLLER_AXIS_RIGHTX);

		if(abs(value) > g_rstickX_peak)
			g_rstickX_peak = abs(value);

		return convertToByte(value, g_rstickX_peak);
	}

	inline int8_t Joypad::stickRightY()
	{
		auto value = SDL_GameControllerGetAxis(m_context, SDL_CONTROLLER_AXIS_RIGHTY);

		if(abs(value) > g_rstickY_peak)
			g_rstickY_peak = abs(value);

		return convertToByte(value, g_rstickY_peak);
	}

	bool Joypad::canRebind(SDL_GameControllerButton button, Button input)
	{
		if(m_keyBindings.count(button) == 0)
			return true;

		auto replacingInput = m_keyBindings[button];
		u64 count	    = 0;

		if(replacingInput != Button::START_BUTTON && replacingInput != Button::A_BUTTON && replacingInput != Button::B_BUTTON)
			return true;

		if(replacingInput == input)
			return true;

		for(auto& [input, button] : m_keyBindings)
		{
			if(button == replacingInput)
				count++;
		}

		if(count == 1)
			return false;
		return count != 1;
	}

	bool Joypad::updateRebind(Button input)
	{
		u8 state[SDL_CONTROLLER_BUTTON_MAX];

		for(int i = 0; i < SDL_CONTROLLER_BUTTON_MAX; i++)
		{
			bool newState	 = SDL_GameControllerGetButton(m_context, (SDL_GameControllerButton)i);
			state[i]	 = (m_buttonState[i] ^ newState) & newState;
			m_buttonState[i] = newState;
		}

		for(int i = 0; i < SDL_CONTROLLER_BUTTON_MAX; i++)
		{
			if(state[i] && canRebind((SDL_GameControllerButton)i, input))
			{
				m_keyBindings[(SDL_GameControllerButton)i] = input;
				saveKeyBindings();
				return true;
			}
		}

		return false;
	}

	void Joypad::update()
	{
		if(!m_context || tas::isTasPlaying())
			return;

		bool walk = false;
		SDL_GameControllerUpdate();

	updateVibration();

	if (m_context != NULL && !SDL_GameControllerGetAttached(m_context))
	{
		SDL_GameControllerClose(m_context);
		m_context = NULL;
	}

		for(int i = 0; i < SDL_CONTROLLER_BUTTON_MAX; i++)
			m_buttonState[i] = SDL_GameControllerGetButton(m_context, (SDL_GameControllerButton)i);

		m_state.stick_x	  = stickLeftX();
		m_state.stick_y	  = invert(stickLeftY());
		m_state.r_stick_x = stickRightX();
		m_state.r_stick_y = stickRightY();

		for(const auto& [scancode, input] : m_keyBindings)
		{
			if(m_buttonState[scancode])
			{
				if((uint32_t)input <= 0xFFFF)
					m_state.button |= (uint16_t)input;
				else
				{
					switch(input)
					{
						case Button::STICK_X_DOWN:
							m_state.stick_y = -128;
							break;
						case Button::STICK_X_UP:
							m_state.stick_y = 127;
							break;
						case Button::STICK_X_LEFT:
							m_state.stick_x = -128;
							break;
						case Button::STICK_X_RIGHT:
							m_state.stick_x = 127;
							break;
						case Button::WALK_BUTTON:
							walk = true;
							break;
					}
				}
			}
		}

		if(oot::config().camera().useClassicCamera())
		{
			int16_t leftx  = SDL_GameControllerGetAxis(m_context, SDL_CONTROLLER_AXIS_LEFTX);
			int16_t lefty  = SDL_GameControllerGetAxis(m_context, SDL_CONTROLLER_AXIS_LEFTY);
			int16_t rightx = SDL_GameControllerGetAxis(m_context, SDL_CONTROLLER_AXIS_RIGHTX);
			int16_t righty = SDL_GameControllerGetAxis(m_context, SDL_CONTROLLER_AXIS_RIGHTY);

			if(abs(righty) > 0x7000)
			{
				if(righty > 0)
					m_state.button |= (uint16_t)Button::D_CBUTTONS;
				else
					m_state.button |= (uint16_t)Button::U_CBUTTONS;
			}

			if(abs(rightx) > 0x7000)
			{
				if(rightx > 1)
					m_state.button |= (uint16_t)Button::R_CBUTTONS;
				else
					m_state.button |= (uint16_t)Button::L_CBUTTONS;
			}
		}

		int16_t ltrig = SDL_GameControllerGetAxis(m_context, SDL_CONTROLLER_AXIS_TRIGGERLEFT);
		int16_t rtrig = SDL_GameControllerGetAxis(m_context, SDL_CONTROLLER_AXIS_TRIGGERRIGHT);

		if(ltrig > 30 * 256)
			m_state.button |= (uint16_t)Button::Z_TRIG;
		// if(rtrig > 30 * 256)
		// m_state.button |= (uint16_t)Button::R_TRIG;

		if(walk)
		{
			m_state.stick_x *= 0.25f;
			m_state.stick_y *= 0.25f;
		}

		uint32_t magnitude_sq = (uint32_t)(m_state.stick_x * m_state.stick_x) + (uint32_t)(m_state.stick_y * m_state.stick_y);

		if(magnitude_sq < (uint32_t)(DEADZONE * DEADZONE))
		{
			m_state.stick_x = 0;
			m_state.stick_y = 0;
		}

		magnitude_sq = (uint32_t)(m_state.r_stick_x * m_state.r_stick_x) + (uint32_t)(m_state.r_stick_y * m_state.r_stick_y);

		if(magnitude_sq < (uint32_t)(RDEADZONE * RDEADZONE))
		{
			m_state.r_stick_x = 0;
			m_state.r_stick_y = 0;
		}

		// When the right trigger is pressed, interpret the c buttons as the dpad
		if(rtrig > 30 * 256)
		{
			if(m_state.button & (uint16_t)Button::U_CBUTTONS)
				m_state.button |= (uint16_t)Button::U_JPAD;
			if(m_state.button & (uint16_t)Button::D_CBUTTONS)
				m_state.button |= (uint16_t)Button::D_JPAD;
			if(m_state.button & (uint16_t)Button::L_CBUTTONS)
				m_state.button |= (uint16_t)Button::L_JPAD;
			if(m_state.button & (uint16_t)Button::R_CBUTTONS)
				m_state.button |= (uint16_t)Button::R_JPAD;

			m_state.button &= ~((uint16_t)Button::U_CBUTTONS | (uint16_t)Button::D_CBUTTONS | (uint16_t)Button::L_CBUTTONS | (uint16_t)Button::R_CBUTTONS); // Unpress the c buttons
		}

	//When the back button is pressed. Mark all dpad button as pressed. Used to open map select
	if (m_buttonState[SDL_CONTROLLER_BUTTON_BACK])
		m_state.button |= (uint16_t)Button::U_JPAD | (uint16_t)Button::D_JPAD | (uint16_t)Button::L_JPAD | (uint16_t)Button::R_JPAD;
}

void Joypad::onVibrate(uint8_t strength, uint8_t vibtime, uint8_t decay)//Called from the game
{
	if (tas::isTasPlaying())
		return;
	if (strength <= 20)
		return;
	if (decay < 8)
		decay = 8;

	uint32_t strengthScaled = strength * strength;
	//uint32_t strengthScaled = strength * 257;
	//uint32_t strengthScaled = strength * 150 + 27135;

	if (strengthScaled < m_VibrationStrength)//The new one is weak
		return;//Let's not play the new one

	auto current_time = osGetTime();

	m_VibrationEnds = current_time + (int)(vibtime * 0.04f);
	m_VibrationStrength = strengthScaled;
	m_VibrationDecay = decay * 15;

	xinput.Vibrate(m_VibrationStrength, m_VibrationStrength);
}

//Called once per frame
//BUG: this should not depend on the framerate!
void Joypad::updateVibration()
{
	if (m_VibrationStrength <= 0)
		return;

	auto current_time = osGetTime();

	if (current_time >= m_VibrationEnds)//Ease off
	{
		//m_VibrationStrength -= 250;
		m_VibrationStrength -= m_VibrationDecay;
		m_VibrationStrength = std::max(m_VibrationStrength, 0);
	}

	xinput.Vibrate(m_VibrationStrength, m_VibrationStrength);
}
} // namespace oot::hid
#endif
