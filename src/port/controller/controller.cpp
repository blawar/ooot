#include "global.h"
#include <ctime>
#include <filesystem>
#include <fstream>
#include <math.h>
#include "../options.h"
#include "controller.h"
#include "state.h"
#include "ultra64/types.h"
#include "def/z_player_lib.h"

#define ENABLE_30FPS

#ifdef __SWITCH__
#define TAS_DIR "sdmc:/switch/oot/tas"
#else
#define TAS_DIR "tas"
#endif

#ifndef _MSC_VER
#define fopen_s(pFile, filename, mode) ((*(pFile)) = fopen((filename), (mode))) == NULL
#endif

extern "C"
{
	u64 get_display_refresh_rate();
}

namespace oot::hid
{
	static bool g_firstPersonEnabled = false;
#ifdef ENABLE_30FPS
	static float f_framerates[] = {20, 30, 60, 120, 240};
#else
	static float f_framerates[] = {20, 60, 120, 240};
#endif

	static float getPrevFramerate(float framerate)
	{
		float maxFramerate = get_display_refresh_rate();

		for(int i = ARRAY_COUNT(f_framerates); i > 0; i--)
		{
			if(f_framerates[i - 1] < framerate && f_framerates[i - 1] <= maxFramerate)
			{
				return f_framerates[i - 1];
			}
		}

		return f_framerates[0];
	}

	static float getNextFramerate(float framerate)
	{
		float maxFramerate = get_display_refresh_rate();

		for(int i = 0; i < ARRAY_COUNT(f_framerates); i++)
		{
			if(f_framerates[i] > framerate && f_framerates[i] <= maxFramerate)
			{
				return f_framerates[i];
			}
		}

		for(int i = ARRAY_COUNT(f_framerates); i > 0; i--)
		{
			if(f_framerates[i - 1] <= maxFramerate)
			{
				return f_framerates[i - 1];
			}
		}

		return f_framerates[0];
	}

	void firstPersonEnable()
	{
		g_firstPersonEnabled = true;
	}

	void firstPersonDisable()
	{
		g_firstPersonEnabled = false;
	}

	bool isFirstPerson()
	{
		return g_firstPersonEnabled;
	}

	static Button gActionOverrideButton = Button::EMPTY_BUTTON;

	void setActionOverride(Button btn)
	{
		gActionOverrideButton = btn;
	}

	static u16 gClearButtonPressFrames = 0;

	void clearPressedButtons(u16 frames)
	{
		gClearButtonPressFrames = frames;
	}

	State::State()
	{
		mouse_x = 0;
		mouse_y = 0;
		has_mouse = false;

		memset(&gyro, 0, sizeof(gyro));
		memset(&accel, 0, sizeof(accel));

		reset();
	}

	void State::reset()
	{
		button = 0;
		stick_x = 0;
		stick_y = 0;
		errnum = 0;
		r_stick_x = 0;
		r_stick_y = 0;
		has_mouse = false;
	}

	Controller::Controller(bool isLocal) :
	    rawStickX(0), rawStickY(0), stickX(0), stickY(0), stickMag(0), buttonDown(0), buttonPressed(0), r_rawStickX(0), r_rawStickY(0), r_stickX(0), r_stickY(0), r_stickMag(0), m_isLocal(isLocal), m_state(), m_motorEnabled(false), m_rumbleTimer(0),
	    m_rumbleStrengh(0), m_rumbleDecay(0), m_rumbleActive(0)
	{
	}

	void Controller::ResetMotorPack()
	{
	}

	void Controller::SendMotorVib(int level)
	{
	}

	void Controller::update()
	{
	}

	void Controller::merge(const Controller& controller)
	{
		m_state.button |= controller.m_state.button;

		if(abs(m_state.stick_x) < abs(controller.m_state.stick_x))
		{
			m_state.stick_x = controller.m_state.stick_x;
		}

		if(abs(m_state.stick_y) < abs(controller.m_state.stick_y))
		{
			m_state.stick_y = controller.m_state.stick_y;
		}

		if(abs(m_state.r_stick_x) < abs(controller.m_state.r_stick_x))
		{
			m_state.r_stick_x = controller.m_state.r_stick_x;
		}

		if(abs(m_state.r_stick_y) < abs(controller.m_state.r_stick_y))
		{
			m_state.r_stick_y = controller.m_state.r_stick_y;
		}

		if(controller.hasMouse())
		{
			m_state.mouse_x = controller.m_state.mouse_x;
			m_state.mouse_y = controller.m_state.mouse_y;
		}

		m_state.has_mouse |= controller.m_state.has_mouse;
	}

	bool Controller::hasMouse() const
	{
		return m_state.has_mouse;
	}

	static std::string getTasFileName()
	{
		std::error_code error;
		std::filesystem::create_directory(TAS_DIR, error);

		time_t now = time(0);
		tm* ltm = localtime(&now);

		if(!ltm)
		{
			return TAS_DIR "/record.tas";
		}

		char buf[64] = {0};
		sprintf(buf, TAS_DIR "/%04d.%02d.%02d-%04d.tas", ltm->tm_year, ltm->tm_mon + 1, ltm->tm_mday, ltm->tm_hour * 60 + ltm->tm_min);
		return buf;
	}

#ifdef ENABLE_TAS
	static std::ofstream* g_tas = nullptr;

	static std::ofstream& stream()
	{
		if(!g_tas)
		{
			auto name = getTasFileName();
			g_tas = new std::ofstream(name, std::ifstream::binary);
			g_tas->write((const char*)&config(), sizeof(config()));
		}

		return *g_tas;
	}
#endif

	void Controller::resolveInputs()
	{
#ifdef ENABLE_TAS
		if(!hid::isTasPlaying() && config().game().recordTas())
		{
			stream().write((const char*)&m_state, sizeof(m_state));

			if(m_state.button)
			{
				int y = 0;
			}
		}
#endif
		bool invertLeftY = false;
		bool invertRightY = false;

		if(config().controls().invertLeftStickY())
		{
			invertLeftY = !invertLeftY;
		}

		if(isFirstPerson() && config().controls().invertLeftStickFirstPersonY())
		{
			invertLeftY = !invertLeftY;
		}

		if(!config().controls().cButtonsOnRightStick())
		{
			if(config().controls().invertRightStickY())
			{
				invertRightY = !invertRightY;
			}

			if(isFirstPerson() && config().controls().invertRightStickFirstPersonY())
			{
				invertRightY = !invertRightY;
			}
		}


		if(invertLeftY)
		{
			m_state.stick_y = invertAnalog(m_state.stick_y);
		}

		if(invertRightY)
		{
			m_state.r_stick_y = invertAnalog(m_state.r_stick_y);
		}

		if(isFirstPerson())
		{
			if(gActionOverrideButton != Button::EMPTY_BUTTON)
			{
				auto btn = config().controls().actionOverrideButton();
				if(m_state.button & btn)
				{
					m_state.button &= ~btn;
					m_state.button |= gActionOverrideButton;
				}
			}
		}

		rawStickX = m_state.stick_x;
		rawStickY = m_state.stick_y;
		r_rawStickX = m_state.r_stick_x;
		r_rawStickY = m_state.r_stick_y;

		if(gClearButtonPressFrames)
		{
			gClearButtonPressFrames--;
			buttonPressed = 0;
			m_state.button &= ((u16)Button::Z_TRIG | (u16)Button::R_TRIG);
		}
		else
		{
			buttonPressed = m_state.button & (m_state.button ^ buttonDown);
		}

		buttonDown = m_state.button;

		if(oot::config().game().mirror())
		{
			rawStickX = -rawStickX;
			r_rawStickX = -r_rawStickX;
		}

		// reset the controller's x and y floats.
		this->stickX = 0;
		this->stickY = 0;

		// modulate the rawStickX and rawStickY to be the new f32 values by adding/subtracting 6.
		if(this->rawStickX <= -8)
		{
			this->stickX = this->rawStickX + 6;
		}

		if(this->rawStickX >= 8)
		{
			this->stickX = this->rawStickX - 6;
		}

		if(this->rawStickY <= -8)
		{
			this->stickY = this->rawStickY + 6;
		}

		if(this->rawStickY >= 8)
		{
			this->stickY = this->rawStickY - 6;
		}

		// calculate f32 magnitude from the center by vector length.
		this->stickMag = sqrtf(this->stickX * this->stickX + this->stickY * this->stickY);

		// magnitude cannot exceed 64.0f: if it does, modify the values appropriately to
		// flatten the values down to the allowed maximum value.
		if(this->stickMag > 64)
		{
			this->stickX *= 64 / this->stickMag;
			this->stickY *= 64 / this->stickMag;
			this->stickMag = 64;
		}

		this->r_stickX = 0;
		this->r_stickY = 0;

		if(this->r_rawStickX <= -8)
		{
			this->r_stickX = this->r_rawStickX + 6;
		}

		if(this->r_rawStickX >= 8)
		{
			this->r_stickX = this->r_rawStickX - 6;
		}

		if(this->r_rawStickY <= -8)
		{
			this->r_stickY = this->r_rawStickY + 6;
		}

		if(this->r_rawStickY >= 8)
		{
			this->r_stickY = this->r_rawStickY - 6;
		}

		// calculate f32 magnitude from the center by vector length.
		this->r_stickMag = sqrtf(this->r_stickX * this->r_stickX + this->r_stickY * this->r_stickY);

		// magnitude cannot exceed 64.0f: if it does, modify the values appropriately to
		// flatten the values down to the allowed maximum value.
		if(this->r_stickMag > 64)
		{
			this->r_stickX *= 64 / this->r_stickMag;
			this->r_stickY *= 64 / this->r_stickMag;
			this->r_stickMag = 64;
		}

		if(isFirstPerson() && !config().camera().useClassicCamera())
		{
			if(this->r_stickMag > 0)
			{
				this->stickMag = this->r_stickMag;
				this->stickX = this->r_stickX;
				this->stickY = this->r_stickY;

				this->m_state.stick_x = this->m_state.r_stick_x;
				this->m_state.stick_y = this->m_state.r_stick_y;

				this->m_state.r_stick_y = this->m_state.r_stick_x = 0;
				this->r_stickY = this->r_stickX = this->r_stickMag = 0;
			}
		}
		else if(oot::state.center_camera)
		{
			const float scaler = 0.1f;
			this->stickX *= scaler;
			this->m_state.stick_x *= scaler;
			this->stickMag *= scaler;

			if(this->stickY < 0)
			{
				this->stickY = 0;
				this->m_state.stick_y = 0;
				this->stickMag = sqrtf(this->stickX * this->stickX + this->stickY * this->stickY);
			}

			this->r_stickX *= scaler;
			this->m_state.r_stick_x *= scaler;
			this->r_stickMag *= scaler;
		}

		if(config().controls().cButtonsOnRightStick() && config().camera().useClassicCamera())
		{
			if(m_state.r_stick_y > 0x20)
				m_state.button |= U_CBUTTONS;
			if(m_state.r_stick_y < -0x20)
				m_state.button |= D_CBUTTONS;
			if(m_state.r_stick_x < -0x20)
				m_state.button |= L_CBUTTONS;
			if(m_state.r_stick_x > 0x20)
				m_state.button |= R_CBUTTONS;
		}
	}

	s64 Controller::mouseScaleX(s64 value)
	{
		return value * (oot::config().controls().mousexInvert() ? -1 : 1) * oot::config().controls().mousexScaler();
	}

	s64 Controller::mouseScaleY(s64 value)
	{
		return value * (oot::config().controls().mouseyInvert() ? -1 : 1) * oot::config().controls().mouseyScaler();
	}

	bool Controller::updateRebind(hid::Button input)
	{
		return false;
	}

	void Controller::processKey(hid::Button input)
	{
		if(input > 0xFFFF)
		{
			switch(input)
			{
				case STICK_X_DOWN:
					m_state.stick_y = -128;
					break;
				case STICK_X_UP:
					m_state.stick_y = 127;
					break;
				case STICK_X_LEFT:
					m_state.stick_x = -128;
					break;
				case STICK_X_RIGHT:
					m_state.stick_x = 127;
					break;
				case WALK_BUTTON:
					m_state.m_walk = true;
					break;
				case DEBUG_MENU:
					m_state.button |= (uint16_t)Button::U_JPAD | (uint16_t)Button::D_JPAD | (uint16_t)Button::L_JPAD | (uint16_t)Button::R_JPAD;
					break;
				case FAST_FORWARD:
					break;
			}
		}
		else
		{
			m_state.button |= input;
		}
	}

	void Controller::processKeyDown(hid::Button input)
	{
		switch(input)
		{
			case Button::OCARINA:
				Player_EquipOcarina();
				break;
			case Button::BOW_ARROW:
				Player_EquipBow();
				break;
			case Button::LENS_OF_TRUTH:
				Player_EquipLensOfTruth();
				break;
			case Button::BOOTS_TOGGLE:
				Player_ToggleBoots();
				break;
			case Button::SWORD_TOGGLE:
				Player_ToggleSword();
				break;
			case Button::SHIELD_TOGGLE:
				Player_ToggleShield();
				break;
			case Button::TUNIC_TOGGLE:
				Player_ToggleTunic();
				break;
			case Button::FAST_FORWARD:
				oot::state.fastForward = config().game().fastForwardSpeed();
				break;
			case Button::CENTER_CAMERA:
				oot::state.center_camera = true;
				break;
			case LANGUAGE_TOGGLE:
				config().game().setNextLanguage();
				break;
			case FRAMERATE_DECREASE:
				setMaxFramerate(getPrevFramerate(getMaxFramerate()));
				break;
			case FRAMERATE_INCREASE:
				setMaxFramerate(getNextFramerate(getMaxFramerate()));
				break;
		}
	}

	void Controller::processKeyUp(hid::Button input)
	{
		switch(input)
		{
			case Button::FAST_FORWARD:
				oot::state.fastForward = 1;
				break;
			case Button::CENTER_CAMERA:
				oot::state.center_camera = false;
				break;
		}
	}

	void Controller::resetBindings()
	{
	}

	void Controller::rumble()
	{
		if(m_rumbleTimer)
		{
			m_rumbleActive = true;
			vibrate();
			m_rumbleTimer--;
		}
		else if(m_rumbleStrengh)
		{
			vibrate();

			if(m_rumbleStrengh < m_rumbleDecay)
			{
				m_rumbleStrengh = 0;
			}
			else
			{
				m_rumbleStrengh -= m_rumbleDecay;
			}
		}
		else if(m_rumbleActive) // send an empty rumble to turn it off
		{
			vibrate();
			m_rumbleActive = false;
		}
	}

	void Controller::SendMotorEvent(short time, short level, u8 decay)
	{
		m_rumbleTimer = time * 0.75;
		m_rumbleStrengh = level;
		m_rumbleDecay = decay;
		rumble();
	}

	void Controller::vibrate()
	{
	}

	namespace controller
	{
		const char* getInputName(hid::Button input)
		{
			switch(input)
			{
				case Button::STICK_X_UP:
					return "STICK_X_UP";
				case Button::STICK_X_LEFT:
					return "STICK_X_LEFT";
				case Button::STICK_X_DOWN:
					return "STICK_X_DOWN";
				case Button::STICK_X_RIGHT:
					return "STICK_X_RIGHT";
				case Button::A_BUTTON:
					return "A_BUTTON";
				case Button::B_BUTTON:
					return "B_BUTTON";
				case Button::Z_TRIG:
					return "Z_TRIG";
				case Button::U_CBUTTONS:
					return "U_CBUTTONS";
				case Button::L_CBUTTONS:
					return "L_CBUTTONS";
				case Button::D_CBUTTONS:
					return "D_CBUTTONS";
				case Button::R_CBUTTONS:
					return "R_CBUTTONS";
				case Button::R_TRIG:
					return "R_TRIG";
				case Button::L_TRIG:
					return "L_TRIG";
				case Button::START_BUTTON:
					return "START_BUTTON";
				case Button::WALK_BUTTON:
					return "WALK_BUTTON";
				case Button::DEBUG_MENU:
					return "DEBUG_MENU";
				case Button::FAST_FORWARD:
					return "FAST_FORWARD";
				case Button::LANGUAGE_TOGGLE:
					return "LANGUAGE_TOGGLE";
				case Button::FRAMERATE_DECREASE:
					return "FRAMERATE_DECREASE";
				case Button::FRAMERATE_INCREASE:
					return "FRAMERATE_INCREASE";
				case Button::CENTER_CAMERA:
					return "CENTER_CAMERA";
				case Button::CURRENT_ACTION:
					return "CURRENT_ACTION";

				case Button::OCARINA:
					return "OCARINA";
				case Button::HOOKSHOT:
					return "HOOKSHOT";
				case Button::BOW_ARROW:
					return "BOW_ARROW";
				case Button::LENS_OF_TRUTH:
					return "LENS_OF_TRUTH";
				case Button::BOOTS_TOGGLE:
					return "BOOTS_TOGGLE";
				case Button::SWORD_TOGGLE:
					return "SWORD_TOGGLE";
				case Button::SHIELD_TOGGLE:
					return "SHIELD_TOGGLE";
				case Button::TUNIC_TOGGLE:
					return "TUNIC_TOGGLE";
			}
			return "";
		}

		Button getInputValue(const std::string& input)
		{
			if(input == "STICK_X_UP")
				return Button::STICK_X_UP;
			if(input == "STICK_X_LEFT")
				return Button::STICK_X_LEFT;
			if(input == "STICK_X_DOWN")
				return Button::STICK_X_DOWN;
			if(input == "STICK_X_RIGHT")
				return Button::STICK_X_RIGHT;
			if(input == "A_BUTTON")
				return Button::A_BUTTON;
			if(input == "B_BUTTON")
				return Button::B_BUTTON;
			if(input == "Z_TRIG")
				return Button::Z_TRIG;
			if(input == "U_CBUTTONS")
				return Button::U_CBUTTONS;
			if(input == "L_CBUTTONS")
				return Button::L_CBUTTONS;
			if(input == "D_CBUTTONS")
				return Button::D_CBUTTONS;
			if(input == "R_CBUTTONS")
				return Button::R_CBUTTONS;
			if(input == "R_TRIG")
				return Button::R_TRIG;
			if(input == "L_TRIG")
				return Button::L_TRIG;
			if(input == "START_BUTTON")
				return Button::START_BUTTON;
			if(input == "WALK_BUTTON")
				return Button::WALK_BUTTON;
			if(input == "CENTER_CAMERA")
				return Button::CENTER_CAMERA;
			if(input == "CURRENT_ACTION")
				return Button::CURRENT_ACTION;

			if(input == "DEBUG_MENU")
				return Button::DEBUG_MENU;
			if(input == "FAST_FORWARD")
				return Button::FAST_FORWARD;
			if(input == "LANGUAGE_TOGGLE")
				return Button::LANGUAGE_TOGGLE;
			if(input == "FRAMERATE_DECREASE")
				return Button::FRAMERATE_DECREASE;
			if(input == "FRAMERATE_INCREASE")
				return Button::FRAMERATE_INCREASE;
			if(input == "OCARINA")
				return Button::OCARINA;
			if(input == "HOOKSHOT")
				return Button::HOOKSHOT;
			if(input == "BOW_ARROW")
				return Button::BOW_ARROW;
			if(input == "LENS_OF_TRUTH")
				return Button::LENS_OF_TRUTH;
			if(input == "BOOTS_TOGGLE")
				return Button::BOOTS_TOGGLE;
			if(input == "SWORD_TOGGLE")
				return Button::SWORD_TOGGLE;
			if(input == "SHIELD_TOGGLE")
				return Button::SHIELD_TOGGLE;
			if(input == "TUNIC_TOGGLE")
				return Button::TUNIC_TOGGLE;

			return (Button)0;
		}
	} // namespace controller
} // namespace oot::hid
