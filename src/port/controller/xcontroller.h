#pragma once
//XInput controller class written by DaMarkov
#include <stdint.h>



class XController
{
	class State
	{
	friend class XController;

	public:
		bool DPad_Up()    const { return wButtons & 0x0001; }
		bool DPad_Down()  const { return wButtons & 0x0002; }
		bool DPad_Left()  const { return wButtons & 0x0004; }
		bool DPad_Right() const { return wButtons & 0x0008; }

		bool Start() const { return wButtons & 0x0010; }
		bool Back()  const { return wButtons & 0x0020; }

		bool Thumb_Left()  const { return wButtons & 0x0040; }
		bool Thumb_Right() const { return wButtons & 0x0080; }

		bool Shoulder_Left()  const { return wButtons & 0x0100; }
		bool Shoulder_Right() const { return wButtons & 0x0200; }

		bool Button_A() const { return wButtons & 0x1000; }
		bool Button_B() const { return wButtons & 0x2000; }
		bool Button_X() const { return wButtons & 0x4000; }
		bool Button_Y() const { return wButtons & 0x8000; }

		bool Button_A_Up() const { return wButtons_Previous & ~wButtons & 0x1000; }
		bool Button_B_Up() const { return wButtons_Previous & ~wButtons & 0x2000; }
		bool Button_X_Up() const { return wButtons_Previous & ~wButtons & 0x4000; }
		bool Button_Y_Up() const { return wButtons_Previous & ~wButtons & 0x8000; }

		bool Button_A_Down() const { return ~wButtons_Previous & wButtons & 0x1000; }
		bool Button_B_Down() const { return ~wButtons_Previous & wButtons & 0x2000; }
		bool Button_X_Down() const { return ~wButtons_Previous & wButtons & 0x4000; }
		bool Button_Y_Down() const { return ~wButtons_Previous & wButtons & 0x8000; }

		uint8_t Trigger_Left()  const { return bLeftTrigger; }
		uint8_t Trigger_Right() const { return bRightTrigger; }

		int16_t Joystick_LeftX() const { return sThumbLX; }
		int16_t Joystick_LeftY() const { return sThumbLY; }

		int16_t Joystick_RightX() const { return sThumbRX; }
		int16_t Joystick_RightY() const { return sThumbRY; }

	private:
		uint16_t wButtons_Previous;
		uint16_t wButtons;
		uint8_t  bLeftTrigger;
		uint8_t  bRightTrigger;
		int16_t  sThumbLX;
		int16_t  sThumbLY;
		int16_t  sThumbRX;
		int16_t  sThumbRY;
	};

public:
	XController(uint32_t ControllerID = 0) : m_ID(ControllerID) { Update(); }
	~XController() { Vibrate(0, 0); }

	bool IsConnected() const;

	bool Update();//Updates the Controller, returns true if a change has occured

	const State& GetState() const { return m_State; }

	bool Vibrate(uint16_t LowFreq, uint16_t HighFreq);

private:
	State m_State;

	uint32_t m_ID;
	uint32_t m_LastPacketNum = 0;
};