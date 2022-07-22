#if !defined(DISABLE_SDL_CONTROLLER)

#include <SDL2/SDL.h>
#include <fstream>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <unordered_map>
#include "../options.h"
#include "../player/players.h"
#include "json.h"
#include "macros.h"
#include "sdl.h"
#include "state.h"
#include "ultra64/types.h"

static bool init_ok;

#define INITIAL_PEAK 0x8000

static int g_lstickX_peak = INITIAL_PEAK;
static int g_lstickY_peak = INITIAL_PEAK;
static int g_rstickX_peak = INITIAL_PEAK;
static int g_rstickY_peak = INITIAL_PEAK;

#ifdef DEBUG
#include <time.h>
extern struct Object* gMarioObject;
#endif

namespace oot::hid
{
	static bool g_haptics = false;

	namespace controller
	{
		class SDL : public Controller
		{
			public:
			SDL(SDL_GameController* controller, int index) : Controller(), m_context(controller), m_index(index), m_haptic(nullptr)
			{
				m_motorEnabled = initHaptics();

				resetBindingsImpl();

#if SDL_VERSION_ATLEAST(2, 0, 14) != 0
				if(SDL_GameControllerHasSensor(m_context, SDL_SENSOR_GYRO) == SDL_TRUE)
				{
					if(!SDL_GameControllerSetSensorEnabled(m_context, SDL_SENSOR_GYRO, SDL_TRUE))
					{
						m_hasGyro = true;
					}
				}

				if(SDL_GameControllerHasSensor(m_context, SDL_SENSOR_ACCEL) == SDL_TRUE)
				{
					if(!SDL_GameControllerSetSensorEnabled(m_context, SDL_SENSOR_ACCEL, SDL_TRUE))
					{
						m_hasAccel = true;
					}
				}
#endif

#ifndef __SWITCH__
				loadKeyBindings();
#endif
			}

			virtual ~SDL()
			{
				closeHaptics();
			}

			void resetBindingsImpl() // dont want to call virtual functions from constructor
			{
				m_keyBindings.clear();
				m_keyBindings[SDL_CONTROLLER_BUTTON_START] = START_BUTTON;
				m_keyBindings[SDL_CONTROLLER_BUTTON_LEFTSHOULDER] = Z_TRIG;
				m_keyBindings[SDL_CONTROLLER_BUTTON_RIGHTSHOULDER] = R_TRIG;
				m_keyBindings[SDL_CONTROLLER_BUTTON_A] = A_BUTTON;
				m_keyBindings[SDL_CONTROLLER_BUTTON_X] = B_BUTTON;
				m_keyBindings[SDL_CONTROLLER_BUTTON_B] = A_BUTTON;
				m_keyBindings[SDL_CONTROLLER_BUTTON_Y] = B_BUTTON;
				if(config().controls().cButtonsOnRightStick())
				{
					m_keyBindings[SDL_CONTROLLER_BUTTON_DPAD_LEFT] = L_JPAD;
					m_keyBindings[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] = R_JPAD;
					m_keyBindings[SDL_CONTROLLER_BUTTON_DPAD_UP] = U_JPAD;
					m_keyBindings[SDL_CONTROLLER_BUTTON_DPAD_DOWN] = D_JPAD;
				}
				else
				{
					m_keyBindings[SDL_CONTROLLER_BUTTON_DPAD_LEFT] = L_CBUTTONS;
					m_keyBindings[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] = R_CBUTTONS;
					m_keyBindings[SDL_CONTROLLER_BUTTON_DPAD_UP] = U_CBUTTONS;
					m_keyBindings[SDL_CONTROLLER_BUTTON_DPAD_DOWN] = D_CBUTTONS;
				}
			}

			void resetBindings() override
			{
				resetBindingsImpl();
			}

			void loadKeyBindings()
			{
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
									auto key = SDL_GameControllerGetButtonFromString(itr->name.GetString());
									auto value = getInputValue(itr->value.GetString());

									if(key != SDL_CONTROLLER_BUTTON_INVALID && value)
									{
										m_keyBindings[key] = value;
									}
									else
									{
										// oot::log("could not bind key: \"%s\" -> \"%s\"\n", itr->value.GetString(), itr->name.GetString());
									}
								}
							}
						}
					}
				}
				catch(...)
				{
				}
			}

			void saveKeyBindings()
			{
				try
				{
					rapidjson::Document d;
					d.SetObject();

					rapidjson::Document::AllocatorType& allocator = d.GetAllocator();

					for(const auto i : m_keyBindings)
					{
						rapidjson::Value value(getInputName((oot::hid::Button)i.second), allocator);
						rapidjson::Value key(SDL_GameControllerGetStringForButton(i.first), allocator);
						d.AddMember(key, value, allocator);
					}

					json::save(d, "gamepad1.bindings.json");
				}
				catch(...)
				{
				}
			}

			bool initHaptics()
			{
				if(!g_haptics)
				{
					return false;
				}

				m_haptic = SDL_HapticOpenFromJoystick(SDL_GameControllerGetJoystick(m_context));

				if(!m_haptic)
				{
					m_haptic = SDL_HapticOpen(m_index);
				}

				if(!m_haptic)
				{
					return false;
				}

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

			void closeHaptics()
			{
				if(m_haptic)
				{
					SDL_HapticClose(m_haptic);
					m_haptic = nullptr;
				}
			}

			void vibrate() override
			{
				SDL_GameControllerRumble(this->m_context, 0, m_rumbleStrengh / 255.0f * 0xFFFF, 2 * 1000 / 20);
			}

			void ResetMotorPack() override
			{
				if(m_motorEnabled)
				{
					SDL_HapticRumbleStop(m_haptic);
				}
			}

			void SendMotorVib(int level) override
			{
				SendMotorEvent(30, level);
			}

			static inline int8_t convertToByte(int value, int max)
			{
				int8_t result = value * 0x7F / (max * 1.5);

				return result;
			}

			inline int16_t readAxis(SDL_GameControllerAxis axis)
			{
				return SDL_GameControllerGetAxis(m_context, axis);
			}

			inline int8_t stickLeftX()
			{
				int deadzone = oot::config().controls().stickLeftDeadzone() * 0x7f;
				int value = readAxis(SDL_CONTROLLER_AXIS_LEFTX);
				if(value < -deadzone)
					value += deadzone;
				else if(value > deadzone)
					value -= deadzone;
				else
					value = 0;

				if(abs(value) > g_lstickX_peak)
				{
					g_lstickX_peak = abs(value);
				}

				return convertToByte(value, g_lstickX_peak);
			}

			inline int8_t stickLeftY()
			{
				int deadzone = oot::config().controls().stickLeftDeadzone() * 0x7f;
				auto value = -readAxis(SDL_CONTROLLER_AXIS_LEFTY);
				if(value < -deadzone)
					value += deadzone;
				else if(value > deadzone)
					value -= deadzone;
				else
					value = 0;

				if(abs(value) > g_lstickY_peak)
				{
					g_lstickY_peak = abs(value);
				}

				return convertToByte(value, g_lstickY_peak);
			}

			inline int8_t stickRightX()
			{
				int deadzone = oot::config().controls().stickRightDeadzone() * 0x7f;
				int value = readAxis(SDL_CONTROLLER_AXIS_RIGHTX);
				if(value < -deadzone)
					value += deadzone;
				else if(value > deadzone)
					value -= deadzone;
				else
					value = 0;

				if(abs(value) > g_rstickX_peak)
				{
					g_rstickX_peak = abs(value);
				}

				return convertToByte(value, g_rstickX_peak);
			}

			inline int8_t stickRightY()
			{
				int deadzone = oot::config().controls().stickRightDeadzone() * 0x7f;
				int value = -readAxis(SDL_CONTROLLER_AXIS_RIGHTY);
				if(value < -deadzone)
					value += deadzone;
				else if(value > deadzone)
					value -= deadzone;
				else
					value = 0;

				if(abs(value) > g_rstickY_peak)
				{
					g_rstickY_peak = abs(value);
				}

				return convertToByte(value, g_rstickY_peak);
			}

			bool canRebind(SDL_GameControllerButton button, hid::Button input)
			{
				if(m_keyBindings.count(button) == 0)
				{
					return true;
				}

				auto replacingInput = m_keyBindings[button];
				u64 count = 0;

				if(replacingInput != START_BUTTON && replacingInput != A_BUTTON && replacingInput != B_BUTTON)
				{
					return true;
				}

				if(replacingInput == input)
				{
					return true;
				}

				for(auto i : m_keyBindings)
				{
					if(i.second == replacingInput)
					{
						count++;
					}
				}

				if(count == 1)
				{
					return false;
				}
				return count != 1;
			}

			bool updateRebind(hid::Button input) override
			{
				u8 state[SDL_CONTROLLER_BUTTON_MAX];

				for(int i = 0; i < SDL_CONTROLLER_BUTTON_MAX; i++)
				{
					bool newState = SDL_GameControllerGetButton(m_context, (SDL_GameControllerButton)i);
					state[i] = (m_buttonState[i] ^ newState) & newState;
					m_buttonState[i] = newState;
				}

				for(int i = 0; i < SDL_CONTROLLER_BUTTON_MAX; i++)
				{
					if(state[i] && canRebind((SDL_GameControllerButton)i, input))
					{
						m_keyBindings[(SDL_GameControllerButton)i] = (Button)input;
						saveKeyBindings();
						return true;
					}
				}

				return false;
			}

			void update() override
			{
				if(!init_ok || !m_context || hid::isTasPlaying())
				{
					return;
				}

				m_state.m_walk = false;
				SDL_GameControllerUpdate();

				if(m_context != NULL && !SDL_GameControllerGetAttached(m_context))
				{
					SDL_GameControllerClose(m_context);
					m_context = NULL;
				}

				for(int i = 0; i < SDL_CONTROLLER_BUTTON_MAX; i++)
				{
					m_buttonState[i] = SDL_GameControllerGetButton(m_context, (SDL_GameControllerButton)i);
				}

				m_state.stick_x = stickLeftX();
				m_state.stick_y = stickLeftY();
				m_state.r_stick_x = stickRightX();
				m_state.r_stick_y = stickRightY();

#if SDL_VERSION_ATLEAST(2, 0, 14) != 0
				if(config().controls().enableGyro())
				{
					if(m_hasGyro && isFirstPerson())
					{
						float values[3] = {0, 0, 0};

						if(!SDL_GameControllerGetSensorData(m_context, SDL_SENSOR_GYRO, values, sizeof(values) / sizeof(float)))
						{
							s32 x = m_state.stick_x - (values[2] + values[1]) * oot::config().controls().gyroxScaler();
							s32 y = m_state.stick_y + values[0] * oot::config().controls().gyroyScaler();
							m_state.stick_x = MAX(-0x7F, MIN(0x80, x));
							m_state.stick_y = MAX(-0x7F, MIN(0x80, y));

							memcpy(m_state.gyro, values, sizeof(values));
						}
					}

					if(m_hasAccel && isFirstPerson())
					{
						float values[3] = {0, 0, 0};

						if(!SDL_GameControllerGetSensorData(m_context, SDL_SENSOR_ACCEL, values, sizeof(values) / sizeof(float)))
						{
							float accel_x = values[0] - m_state.accel[0];
							float accel_y = values[2] - m_state.accel[2];

							/*if(accel_x != 0.0f || accel_y != 0.0f)
							{
								s32 x		= m_state.stick_x - accel_x * ACCEL_SENSITIVITY;
								s32 y		= m_state.stick_y - accel_y * ACCEL_SENSITIVITY;
								m_state.stick_x = MAX(-0x7F, MIN(0x80, x));
								m_state.stick_y = MAX(-0x7F, MIN(0x80, y));
							}*/

							memcpy(m_state.accel, values, sizeof(values));
						}
					}
				}
#endif

				for(const auto& [scancode, input] : m_keyBindings)
				{
					if(m_buttonState[scancode])
					{
						processKey(input);
					}

					if(m_lastButtonState[scancode] ^ m_buttonState[scancode])
					{
						if(m_buttonState[scancode])
						{
							processKeyDown(input);
						}
						else
						{
							processKeyUp(input);
						}
					}
				}

				int16_t ltrig = SDL_GameControllerGetAxis(m_context, SDL_CONTROLLER_AXIS_TRIGGERLEFT);
				int16_t rtrig = SDL_GameControllerGetAxis(m_context, SDL_CONTROLLER_AXIS_TRIGGERRIGHT);

				if(ltrig > 30 * 256)
					m_state.button |= Z_TRIG;
				if(rtrig > 30 * 256)
					m_state.button |= R_TRIG;

				if(m_state.m_walk)
				{
					m_state.stick_x *= 0.25f;
					m_state.stick_y *= 0.25f;
				}

				memcpy(m_lastButtonState, m_buttonState, sizeof(m_lastButtonState));
				rumble();
			}

			protected:
			SDL_GameController* m_context;
			int m_index;
			SDL_Haptic* m_haptic;
			std::unordered_map<SDL_GameControllerButton, Button> m_keyBindings;
			u8 m_buttonState[SDL_CONTROLLER_BUTTON_MAX];
			u8 m_lastButtonState[SDL_CONTROLLER_BUTTON_MAX];
		};
	} // namespace controller
	SDL::SDL()
	{
		if(config().controls().useDInput())
		{
			SDL_SetHint(SDL_HINT_XINPUT_ENABLED, "0");
		}

		if(SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER) != 0)
		{
			fprintf(stderr, "SDL init error: %s\n", SDL_GetError());
		}

		g_haptics = SDL_InitSubSystem(SDL_INIT_HAPTIC) == 0;

		// SDL_SetHint(SDL_HINT_JOYSTICK_HIDAPI_XBOX, "1");
	}

	SDL::~SDL()
	{
		SDL_QuitSubSystem(SDL_INIT_HAPTIC);
	}

	void SDL::scan(class Controllers* controllers)
	{
#ifdef __SWITCH__
		// swap A, B and X, Y to correct positions
		SDL_GameControllerAddMapping("53776974636820436F6E74726F6C6C65,Switch Controller,"
					     "a:b0,b:b1,back:b11,"
					     "dpdown:b15,dpleft:b12,dpright:b14,dpup:b13,"
					     "leftshoulder:b6,leftstick:b4,lefttrigger:b8,leftx:a0,lefty:a1,"
					     "rightshoulder:b7,rightstick:b5,righttrigger:b9,rightx:a2,righty:a3,"
					     "start:b10,x:b2,y:b3");
#endif

		init_ok = true;

		if(m_controllers.size() > 0)
		{
			for(auto it = m_controllers.begin(); it != m_controllers.end(); it++)
			{
				players().detach(*it, 0);
			}

			m_controllers.resize(0);
		}

		for(int i = 0; i < SDL_NumJoysticks(); i++)
		{
			if(SDL_IsGameController(i))
			{
				auto context = SDL_GameControllerOpen(i);

				if(context)
				{
					auto controller = std::make_shared<controller::SDL>(context, i);
					m_controllers.push_back(controller);
					players().attach(controller, 0);
				}
			}
		}
	}
} // namespace oot::hid

#endif
