#include "ultra64/types.h"
#include "controller.h"
#include <ctime>
#include <fstream>
#include <filesystem>
#include "../options.h"

#ifdef __SWITCH__
#define TAS_DIR "sdmc:/switch/sm64/tas"
#else
#define TAS_DIR "tas"
#endif

namespace sm64::hid
{
	State::State()
	{
		mouse_x	      = 0;
		mouse_y	      = 0;
		has_mouse     = false;

		reset();
	}

	void State::reset()
	{
		button	  = 0;
		stick_x	  = 0;
		stick_y	  = 0;
		errnum	  = 0;
		r_stick_x = 0;
		r_stick_y = 0;
		has_mouse = false;
	}

	Controller::Controller(bool isLocal) :
	    rawStickX(0), rawStickY(0), stickX(0), stickY(0), stickMag(0), buttonDown(0), buttonPressed(0), r_rawStickX(0), r_rawStickY(0), r_stickX(0), r_stickY(0), r_stickMag(0), m_isLocal(isLocal), m_state(), m_motorEnabled(false)
	{
	}

	void Controller::SendMotorEvent(short time, short level)
	{
	}

	void Controller::SendMotorDecay(short level)
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

		if (!ltm)
		{
			return TAS_DIR"/record.tas";
		}

		char buf[64] = { 0 };
		sprintf(buf, TAS_DIR"/%04d.%02d.%02d-%04d.tas", ltm->tm_year, ltm->tm_mon + 1, ltm->tm_mday, ltm->tm_hour * 60 + ltm->tm_min);
		return buf;
	}

#ifdef ENABLE_TAS
	static std::ofstream* g_tas = nullptr;

	static std::ofstream& stream()
	{
		if (!g_tas)
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
		if (!hid::isTasPlaying() && config().game().recordTas())
		{
			stream().write((const char*)&m_state, sizeof(m_state));

			if (m_state.button)
			{
				int y = 0;
			}
		}
#endif

		rawStickX     = m_state.stick_x;
		rawStickY     = m_state.stick_y;
		r_rawStickX   = m_state.r_stick_x;
		r_rawStickY   = m_state.r_stick_y;
		buttonPressed = m_state.button & (m_state.button ^ buttonDown);
		// 0.5x A presses are a good meme
		buttonDown = m_state.button;

		if(oot::config().game().mirror())
		{
			rawStickX   = -rawStickX;
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

} // namespace sm64::hid
