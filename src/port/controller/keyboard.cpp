#include "ultra64/types.h"
#include "keyboard.h"
#ifdef ENABLE_JSON
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"
#include <rapidjson/istreamwrapper.h>
#endif
#include <fstream>
#include <unordered_map>
#include <algorithm>

#if !defined(DISABLE_SDL_CONTROLLER)
#include <SDL2/SDL.h>
#endif
#include "../player/players.h"
#include "../options.h"
#include "tas.h"

extern "C"
{
	void set_fullscreen(bool value);
}


using namespace oot::hid;

u8 Get_Language();
void Set_Language(u8 language_id);

#ifdef ENABLE_JSON
bool saveJson(rapidjson::Document& doc, const std::string& jsonFilePath)
{
	rapidjson::StringBuffer buffer;
	rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);

	if (!doc.Accept(writer))
	{
		return false;
	}

	std::ofstream out(jsonFilePath.c_str(), std::ofstream::trunc);
	out << buffer.GetString();

	return true;
}
#endif


const char* Keyboard::getInputName(Button input)
{
	switch (input)
	{
	case Button::STICK_X_UP: return "STICK_X_UP";
	case Button::STICK_X_LEFT: return "STICK_X_LEFT";
	case Button::STICK_X_DOWN: return "STICK_X_DOWN";
	case Button::STICK_X_RIGHT: return "STICK_X_RIGHT";
	case Button::A_BUTTON: return "A_BUTTON";
	case Button::B_BUTTON: return "B_BUTTON";
	case Button::Z_TRIG: return "Z_TRIG";
	case Button::U_CBUTTONS: return "U_CBUTTONS";
	case Button::L_CBUTTONS: return "L_CBUTTONS";
	case Button::D_CBUTTONS: return "D_CBUTTONS";
	case Button::R_CBUTTONS: return "R_CBUTTONS";
	case Button::R_TRIG: return "R_TRIG";
	case Button::START_BUTTON: return "START_BUTTON";
	case Button::WALK_BUTTON: return "WALK_BUTTON";
	}
return "";
}



Button Keyboard::getInputValue(const std::string& input)
{
	if (input == "STICK_X_UP") return Button::STICK_X_UP;
	if (input == "STICK_X_LEFT") return Button::STICK_X_LEFT;
	if (input == "STICK_X_DOWN") return Button::STICK_X_DOWN;
	if (input == "STICK_X_RIGHT") return Button::STICK_X_RIGHT;
	if (input == "A_BUTTON") return Button::A_BUTTON;
	if (input == "B_BUTTON") return Button::B_BUTTON;
	if (input == "Z_TRIG") return Button::Z_TRIG;
	if (input == "U_CBUTTONS") return Button::U_CBUTTONS;
	if (input == "L_CBUTTONS") return Button::L_CBUTTONS;
	if (input == "D_CBUTTONS") return Button::D_CBUTTONS;
	if (input == "R_CBUTTONS") return Button::R_CBUTTONS;
	if (input == "R_TRIG") return Button::R_TRIG;
	if (input == "START_BUTTON") return Button::START_BUTTON;
	if (input == "WALK_BUTTON") return Button::WALK_BUTTON;

	return (Button)0;
}



Keyboard::Keyboard() : N64Controller()
{
	memset(m_lastKeyState, 0, sizeof(m_lastKeyState));
	m_keyBindings[SDL_SCANCODE_W] = Button::STICK_X_UP;
	m_keyBindings[SDL_SCANCODE_A] = Button::STICK_X_LEFT;
	m_keyBindings[SDL_SCANCODE_S] = Button::STICK_X_DOWN;
	m_keyBindings[SDL_SCANCODE_D] = Button::STICK_X_RIGHT;
	m_keyBindings[SDL_SCANCODE_SPACE] = Button::A_BUTTON;
	m_keyBindings[SDL_SCANCODE_F] = Button::B_BUTTON;
    m_keyBindings[SDL_SCANCODE_O] = Button::A_BUTTON;
    m_keyBindings[SDL_SCANCODE_P] = Button::B_BUTTON;
	m_keyBindings[SDL_SCANCODE_LSHIFT] = Button::Z_TRIG;
	m_keyBindings[SDL_SCANCODE_C] = Button::Z_TRIG;
    m_keyBindings[SDL_SCANCODE_I] = Button::U_JPAD;
    m_keyBindings[SDL_SCANCODE_J] = Button::L_JPAD;
    m_keyBindings[SDL_SCANCODE_K] = Button::D_JPAD;
    m_keyBindings[SDL_SCANCODE_L] = Button::R_JPAD;
	m_keyBindings[SDL_SCANCODE_UP] = Button::U_CBUTTONS;
	m_keyBindings[SDL_SCANCODE_LEFT] = Button::L_CBUTTONS;
	m_keyBindings[SDL_SCANCODE_DOWN] = Button::D_CBUTTONS;
	m_keyBindings[SDL_SCANCODE_RIGHT] = Button::R_CBUTTONS;
	m_keyBindings[SDL_SCANCODE_X] = Button::L_TRIG;
	m_keyBindings[SDL_SCANCODE_V] = Button::R_TRIG;
	m_keyBindings[SDL_SCANCODE_RSHIFT] = Button::R_TRIG;
	m_keyBindings[SDL_SCANCODE_RETURN] = Button::START_BUTTON;

#ifndef __SWITCH__
	loadKeyBindings();
#endif
}



void Keyboard::loadKeyBindings()
{
#ifdef ENABLE_JSON
	try
	{
		std::ifstream ifs("keyboard1.bindings.json", std::ifstream::in);


		if (ifs.is_open())
		{
			rapidjson::IStreamWrapper isw(ifs);
			rapidjson::Document d;
			d.ParseStream(isw);

			if (d.IsObject())
			{
				for (auto itr = d.MemberBegin(); itr != d.MemberEnd(); ++itr)
				{
					if (itr->name.IsString() && itr->value.IsString())
					{
						auto key = SDL_GetScancodeFromName(itr->name.GetString());
						auto value = getInputValue(itr->value.GetString());								

						if (key != SDL_SCANCODE_UNKNOWN && value)						{
							m_keyBindings[key] = value;
						else
						{
							// TODO FIX sm64::log("could not bind key: \"%s\" -> \"%s\"\n", itr->value.GetString(), itr->name.GetString());
						}
					}
				}
			}
		}
	}
	catch (...)
	{
	}
#endif
}



void Keyboard::saveKeyBindings()
{
#ifdef ENABLE_JSON
	try
	{
		rapidjson::Document d;
		d.SetObject();

		rapidjson::Document::AllocatorType& allocator = d.GetAllocator();

		for (const auto i : m_keyBindings)
		{
			rapidjson::Value value(getInputName(i.second), allocator);
			rapidjson::Value key(SDL_GetScancodeName(i.first), allocator);
			d.AddMember(key, value, allocator);
		}

		saveJson(d, "keyboard1.bindings.json");
	}
	catch (...)
	{
	}
#endif
}



bool Keyboard::hasMouse() const
{
	return true;
	return m_state.has_mouse;
}



Button Keyboard::keyboard_map_scancode(SDL_Scancode scancode)
{
	if (m_keyBindings.count(scancode))
		return m_keyBindings[scancode];
	return Button::NONE;
}



bool Keyboard::on_key_down(SDL_Scancode scancode)
{
	Button mapped = keyboard_map_scancode(scancode);
	keyboard_buttons_down |= (int)mapped;
	return (int)mapped != 0;
}



bool Keyboard::on_key_up(SDL_Scancode scancode)
{
	Button mapped = keyboard_map_scancode(scancode);
	keyboard_buttons_down &= ~(int)mapped;
	return (int)mapped != 0;
}



bool Keyboard::canRebind(SDL_Scancode scancode, Button input)
{
	if (m_keyBindings.count(scancode) == 0)
		return true;

	auto replacingInput = m_keyBindings[scancode];
	u64 count = 0;

	for (auto i : m_keyBindings)
	{
		if (i.second == replacingInput)
			count++;
	}

	return count != 1;
}



bool Keyboard::updateRebind(Button input)
{
	int count = 0;
	auto state = SDL_GetKeyboardState(&count);
	u64 changed = 0;

	for (int i = 0; i < std::min(MAX_KEY_STATE, count); i++)
		m_lastKeyState[i] = (state[i] ^ m_lastKeyState[i]) & state[i];

	for (int i = 0; i < std::min(MAX_KEY_STATE, count); i++)
	{
		if (m_lastKeyState[i] && canRebind((SDL_Scancode)i, input))
		{
  			m_keyBindings[(SDL_Scancode)i] = input;
			changed++;
			saveKeyBindings();
		}
	}

	memcpy(m_lastKeyState, state, std::min(MAX_KEY_STATE, count));
	return changed != 0;
}



void Keyboard::update()
{
	bool walk = false;
	int count = 0;
	auto state = SDL_GetKeyboardState(&count);

	if (state[SDL_SCANCODE_F10] && (m_lastKeyState[SDL_SCANCODE_F10] ^ state[SDL_SCANCODE_F10]))
	{
		oot::config().game().fullscreen() = !oot::config().game().fullscreen();
		set_fullscreen(oot::config().game().fullscreen());
	}

	if (state[SDL_SCANCODE_F9] && (m_lastKeyState[SDL_SCANCODE_F9] ^ state[SDL_SCANCODE_F9]))
		Set_Language(Get_Language()+1);

	if (state[SDL_SCANCODE_ESCAPE] && (m_lastKeyState[SDL_SCANCODE_ESCAPE] ^ state[SDL_SCANCODE_ESCAPE]))
	{
		if (oot::config().game().fullscreen())
		{
			oot::config().game().fullscreen() = false;
			set_fullscreen(oot::config().game().fullscreen());
		}
	}

	//When F5 is pressed. Mark all dpad button as pressed. Used to open map select
	if (state[SDL_SCANCODE_F5] && (m_lastKeyState[SDL_SCANCODE_F5] ^ state[SDL_SCANCODE_F5]))
		m_state.button |= (uint16_t)Button::U_JPAD | (uint16_t)Button::D_JPAD | (uint16_t)Button::L_JPAD | (uint16_t)Button::R_JPAD;

	if (tas::isTasPlaying())
		return;

	for (const auto& [scancode, input] : m_keyBindings)
	{
		if (scancode < count && state[scancode])
		{
			if ((uint32_t)input <= 0xFFFF)
				m_state.button |= (uint32_t)input;
			else
			{
				switch (input)
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

#ifdef ENABLE_MOUSE
	int mouse_delta_x = 0;
	int mouse_delta_y = 0;

	auto buttons = SDL_GetRelativeMouseState(&mouse_delta_x, &mouse_delta_y);
	enableMouse();

	if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
		m_state.button |= (uint16_t)Button::B_BUTTON;

	if (buttons & SDL_BUTTON(SDL_BUTTON_RIGHT))
		m_state.button |= (uint16_t)Button::A_BUTTON;

	if (buttons & SDL_BUTTON(SDL_BUTTON_MIDDLE))
		walk = true;

	m_state.mouse_x += mouse_delta_x * 4;
	m_state.mouse_y += mouse_delta_y * 4;
#endif

	if (walk)
	{
		m_state.stick_x *= 0.25f;
		m_state.stick_y *= 0.25f;
	}

	memcpy(m_lastKeyState, state, std::min(MAX_KEY_STATE, count));
}



void Keyboard::scan()
{
	if (!size())
	{
#ifdef ENABLE_MOUSE
		//SDL_SetRelativeMouseMode(SDL_TRUE);
#endif
		auto controller = std::make_shared<Keyboard>();
#ifdef ENABLE_MOUSE

		controller->enableMouse();
#endif
		m_controllers.push_back(controller);
		Players::get().attach(controller, 0);
	}
}



/*void Keyboard::update()
{
	for (auto& keyboard : m_controllers)
		((Keyboard*)keyboard.get())->update();
}*/