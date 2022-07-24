#pragma once
#include <string>
#include "ultra64/types.h"

namespace oot::hid
{
	enum Button : s64
	{
		EMPTY_BUTTON = 0,
		CONT_A = 0x8000,
		CONT_B = 0x4000,
		CONT_G = 0x2000,
		CONT_START = 0x1000,
		CONT_UP = 0x0800,
		CONT_DOWN = 0x0400,
		CONT_LEFT = 0x0200,
		CONT_RIGHT = 0x0100,
		CONT_L = 0x0020,
		CONT_R = 0x0010,
		CONT_E = 0x0008,
		CONT_D = 0x0004,
		CONT_C = 0x0002,
		CONT_F = 0x0001,

		A_BUTTON = CONT_A,
		B_BUTTON = CONT_B,
		L_TRIG = CONT_L,
		R_TRIG = CONT_R,
		Z_TRIG = CONT_G,
		START_BUTTON = CONT_START,
		U_JPAD = CONT_UP,
		L_JPAD = CONT_LEFT,
		R_JPAD = CONT_RIGHT,
		D_JPAD = CONT_DOWN,
		U_CBUTTONS = CONT_E,
		L_CBUTTONS = CONT_C,
		R_CBUTTONS = CONT_F,
		D_CBUTTONS = CONT_D,
		STICK_X_LEFT = 1ULL << 16,
		STICK_X_RIGHT = 1ULL << 17,
		STICK_X_DOWN = 1ULL << 19,
		STICK_X_UP = 1ULL << 18,
		WALK_BUTTON = 1ULL << 20,
		DEBUG_MENU = 1ULL << 21,
		OCARINA = 1ULL << 22,
		HOOKSHOT = 1ULL << 23,
		BOW_ARROW = 1ULL << 24,
		LENS_OF_TRUTH = 1ULL << 25,
		BOOTS_TOGGLE = 1ULL << 26,
		SWORD_TOGGLE = 1ULL << 27,
		SHIELD_TOGGLE = 1ULL << 28,
		TUNIC_TOGGLE = 1ULL << 29,
		FAST_FORWARD = 1ULL << 30,
		CENTER_CAMERA = 1ULL << 31,
		CURRENT_ACTION = 1ULL << 32,
		LANGUAGE_TOGGLE = 1ULL << 33,
		FRAMERATE_INCREASE = 1ULL << 34,
		FRAMERATE_DECREASE = 1ULL << 35
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

		float gyro[3];
		float accel[3];

		s64 mouse_x;
		s64 mouse_y;
		bool has_mouse;
		bool m_walk;
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

		bool m_hasGyro = false;
		bool m_hasAccel = false;

		static s64 mouseScaleX(s64 value);
		static s64 mouseScaleY(s64 value);

		Controller(bool isLocal = true);
		virtual void update();
		virtual void resolveInputs();
		virtual void rumble();
		virtual void SendMotorEvent(short time, short level, u8 decay = 0);
		virtual bool isLocal() const
		{
			return m_isLocal;
		}

		const State& state() const
		{
			return m_state;
		}

		State& state()
		{
			return m_state;
		}

		virtual void resetBindings();

		virtual void merge(const Controller& controller);
		virtual bool hasMouse() const;

		virtual void ResetMotorPack();
		virtual void SendMotorVib(int level);

		virtual bool updateRebind(hid::Button input);
		virtual void processKey(hid::Button input);
		virtual void processKeyUp(hid::Button input);
		virtual void processKeyDown(hid::Button input);

		protected:
		virtual void vibrate();
		State m_state;
		bool m_isLocal;
		bool m_motorEnabled;
		u16 m_rumbleTimer;
		u16 m_rumbleStrengh;
		u8 m_rumbleDecay;
		bool m_rumbleActive;
	};

	bool isTasPlaying();
	void firstPersonEnable();
	void firstPersonDisable();
	bool isFirstPerson();
	void clearPressedButtons(u16 frames = 1);
	void setActionOverride(Button btn);

	namespace controller
	{
		const char* getInputName(hid::Button input);
		Button getInputValue(const std::string& input);
	} // namespace controller

	static constexpr inline int8_t convertToByte(int value, int max)
	{
		if(value > 0)
		{
			//printf("value: %d, byte: %d\n", value, value * 0x7F / (max * 1.5));
			return value * 0x7F / (max * 1.5);
		}
		else
		{
			//printf("value: %d, byte: %d\n", value, value * 0x80 / (max + 1));
			return value * 0x80 / (1.5 * (max+1));
		}
	}

	static inline int8_t invertAnalog(const int8_t value)
	{
		if(value == -128)
		{
			return 0x7F;
		}
		if(value == 127)
		{
			return -0x80;
		}

		return -value;
	}
} // namespace oot::hid
