#include "ultra64/types.h"
#include "controller.h"
#include <ctime>
#include <fstream>
#include <filesystem>
#include "../options.h"
#include "def/z_player_lib.h"
#include "state.h"

#ifdef __SWITCH__
#define TAS_DIR "sdmc:/switch/oot/tas"
#else
#define TAS_DIR "tas"
#endif

static inline int8_t invert(const int8_t value)
{
	if(value <= -128)
	{
		return 127;
	}

	return -value;
}

namespace oot::hid
{
	static bool g_firstPersonEnabled = false;

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

		if(isFirstPerson())
		{
			m_state.stick_y = invert(m_state.stick_y);
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

		if(isFirstPerson())
		{
			if(this->r_stickMag > RDEADZONE)
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

	}

	s64 Controller::mouse_x() const
	{
		return m_state.mouse_x * (oot::config().camera().mousexInvert() ? -1 : 1) * oot::config().camera().mousexScaler();
	}

	s64 Controller::mouse_y() const
	{
		return m_state.mouse_y * (oot::config().camera().mouseyInvert() ? -1 : 1) * oot::config().camera().mouseyScaler();
	}

	bool Controller::updateRebind(int input)
	{
		return false;
	}

	void Controller::processKey(int input)
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

	void Controller::processKeyDown(int input)
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
				oot::state.fastForward = 5;
				break;
			case Button::CENTER_CAMERA:
				oot::state.center_camera = true;
				break;
		}
	}

	void Controller::processKeyUp(int input)
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

} // namespace oot::hid
