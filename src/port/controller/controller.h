#pragma once
#include "ultra64/types.h"



class N64Controller
{
public:
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

	N64Controller(bool isLocal = true);
	virtual void update() {}
	virtual void resolveInputs();
	virtual bool isLocal() const {
		return m_isLocal;
	}
	State& state() {
		return m_state;
	}

	virtual void merge(const N64Controller& controller);
	virtual bool hasMouse() const { return m_state.has_mouse; }

	virtual void SendMotorEvent(short time, short level) {}
	virtual void SendMotorDecay(short level) {}
	virtual void ResetMotorPack() {}
	virtual void SendMotorVib(int level) {}

	//virtual bool updateRebind(int input);

protected:
	State m_state;
	bool m_isLocal;
	bool m_motorEnabled;
};