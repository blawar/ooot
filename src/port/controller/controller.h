#pragma once
#include "ultra64/types.h"
#include <stdio.h>



namespace oot
{
	namespace hid
	{
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

			class StateCompressed
			{
			public:
				StateCompressed() = default;
				StateCompressed(State state)
				{
					m_data.button  = state.button;
					m_data.stick_x = state.stick_x;
					m_data.stick_y = state.stick_y;

					//Is there any real data?
					m_isUsed = m_data.button || m_data.stick_x || m_data.stick_y;
				}

				operator State ()
				{
					State ret;
					ret.button  = m_data.button;
					ret.stick_x = m_data.stick_x;
					ret.stick_y = m_data.stick_y;
					return ret;
				}

				bool read(FILE* in) {
					if (fread(&m_isUsed, sizeof(u8), 1, in) != 1)//Read the flag
						return true;//End of file reached

					if (m_isUsed)//Is there even any input?
						fread(&m_data, sizeof(InputFrame), 1, in);//Write the full state
					return false;
				}

				void write(FILE* out) {
					fwrite(&m_isUsed, sizeof(u8), 1, out);//Write if there is data

					if (m_isUsed)//Is there even any input?
						fwrite(&m_data, sizeof(InputFrame), 1, out);//Write the full state
				}

			private:
				u8 m_isUsed = 0;//0 when all input is zero
				struct InputFrame {
					u16 button = 0x0000;
					s8 stick_x = 0; /* -80 <= stick_x <= 80 */
					s8 stick_y = 0; /* -80 <= stick_y <= 80 */
				} m_data;
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
			~N64Controller();

			virtual void update() {}
			virtual void resolveInputs();
			virtual bool isLocal() const {
				return m_isLocal;
			}
			State& state() {
				return m_state;
			}
			const State state() const {
				return m_state;
			}

			virtual void merge(const N64Controller& controller);
			virtual bool hasMouse() const { return m_state.has_mouse; }

			virtual void SendMotorEvent(short time, short level) {}
			virtual void SendMotorDecay(short level) {}
			virtual void ResetMotorPack() {}
			virtual void SendMotorVib(int level) {}

			//virtual bool updateRebind(Button input);

		protected:
			State m_state;
			bool m_isLocal;
			bool m_motorEnabled;

		private:
			FILE* m_tasFile = nullptr;
		};
	}
}