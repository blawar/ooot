#pragma once
#include "ultra64/types.h"

namespace sm64::hid
{
	enum Button
	{
		CONT_A	   = 0x8000,
		CONT_B	   = 0x4000,
		CONT_G	   = 0x2000,
		CONT_START = 0x1000,
		CONT_UP	   = 0x0800,
		CONT_DOWN  = 0x0400,
		CONT_LEFT  = 0x0200,
		CONT_RIGHT = 0x0100,
		CONT_L	   = 0x0020,
		CONT_R	   = 0x0010,
		CONT_E	   = 0x0008,
		CONT_D	   = 0x0004,
		CONT_C	   = 0x0002,
		CONT_F	   = 0x0001,

		A_BUTTON     = CONT_A,
		B_BUTTON     = CONT_B,
		L_TRIG	     = CONT_L,
		R_TRIG	     = CONT_R,
		Z_TRIG	     = CONT_G,
		START_BUTTON = CONT_START,
		U_JPAD	     = CONT_UP,
		L_JPAD	     = CONT_LEFT,
		R_JPAD	     = CONT_RIGHT,
		D_JPAD	     = CONT_DOWN,
		U_CBUTTONS   = CONT_E,
		L_CBUTTONS   = CONT_C,
		R_CBUTTONS   = CONT_F,
		D_CBUTTONS   = CONT_D,
		STICK_X_LEFT = 0x10000,
		STICK_X_RIGHT = 0x20000,
		STICK_X_DOWN = 0x80000,
		STICK_X_UP = 0x40000,
		WALK_BUTTON	 = 0x100000
	};

	class State
	{
		public:
		State();
		void reset();

		u16 button;
		s8 stick_x; /* -80 <= stick_x <= 80 */
		s8 stick_y; /* -80 <= stick_y <= 80 */
		u8 errnum;
		s8 r_stick_x; /* -80 <= stick_x <= 80 */
		s8 r_stick_y; /* -80 <= stick_y <= 80 */

		s64 mouse_x;
		s64 mouse_y;
		bool has_mouse;
	};

	class Controller
	{
		public:
		s16 rawStickX;
		s16 rawStickY;
		float stickX;	// [-64, 64] positive is right
		float stickY;	// [-64, 64] positive is up
		float stickMag; // distance from center [0, 64]
		u16 buttonDown;
		u16 buttonPressed;
		s16 r_rawStickX;  //
		s16 r_rawStickY;  //
		float r_stickX;	  // [-64, 64] positive is right
		float r_stickY;	  // [-64, 64] positive is up
		float r_stickMag; // distance from center [0, 64]


		s64 mouse_x() const;
		s64 mouse_y() const;

		Controller(bool isLocal = true);
		virtual void update();
		virtual void resolveInputs();
		virtual bool isLocal() const
		{
			return m_isLocal;
		}
		State& state()
		{
			return m_state;
		}

		virtual void merge(const Controller& controller);
		virtual bool hasMouse() const;

		virtual void SendMotorEvent(short time, short level);
		virtual void SendMotorDecay(short level);
		virtual void ResetMotorPack();
		virtual void SendMotorVib(int level);

		virtual bool updateRebind(int input);

		protected:
		State m_state;
		bool m_isLocal;
		bool m_motorEnabled;
	};

	bool isTasPlaying();
} // namespace sm64::hid
