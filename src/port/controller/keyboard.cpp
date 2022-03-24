#include "ultra64/types.h"
#include "keyboard.h"
#include "def/z_player_lib.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"
#include <rapidjson/istreamwrapper.h>
#include <fstream>
#include <unordered_map>

#if !defined(DISABLE_SDL_CONTROLLER)
#include <SDL2/SDL.h>
#endif
#include "../player/players.h"
#include "../options.h"

extern "C"
{
	void set_fullscreen(bool value);
}

bool saveJson(rapidjson::Document& doc, const std::string& jsonFilePath)
{
	rapidjson::StringBuffer buffer;
	rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);

	if(!doc.Accept(writer))
	{
		return false;
	}

	std::ofstream out(jsonFilePath.c_str(), std::ofstream::trunc);
	out << buffer.GetString();

	return true;
}

namespace oot::hid
{
	namespace controller
	{
		const char* getInputName(Button input)
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

		class Keyboard : public Controller
		{
			public:
			Keyboard() : Controller()
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

				m_keyBindings[SDL_SCANCODE_F1] = Button::BOOTS_TOGGLE;
				m_keyBindings[SDL_SCANCODE_F2] = Button::SWORD_TOGGLE;
				m_keyBindings[SDL_SCANCODE_F3] = Button::SHIELD_TOGGLE;
				m_keyBindings[SDL_SCANCODE_F4] = Button::TUNIC_TOGGLE;

#ifndef __SWITCH__
				loadKeyBindings();
#endif
			}

			void resetBindings() override
			{
				m_keyBindings.clear();
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

				m_keyBindings[SDL_SCANCODE_F1] = Button::BOOTS_TOGGLE;
				m_keyBindings[SDL_SCANCODE_F2] = Button::SWORD_TOGGLE;
				m_keyBindings[SDL_SCANCODE_F3] = Button::SHIELD_TOGGLE;
				m_keyBindings[SDL_SCANCODE_F4] = Button::TUNIC_TOGGLE;
			}

			void loadKeyBindings()
			{
				try
				{
					std::ifstream ifs("keyboard1.bindings.json", std::ifstream::in);

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
									auto key = SDL_GetScancodeFromName(itr->name.GetString());
									auto value = getInputValue(itr->value.GetString());

									if(key != SDL_SCANCODE_UNKNOWN && value)
									{
										m_keyBindings[key] = value;
									}
									else
									{
										// TODO FIX oot::log("could not bind key: \"%s\" -> \"%s\"\n", itr->value.GetString(), itr->name.GetString());
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
#ifdef ENABLE_JSON
				try
				{
					rapidjson::Document d;
					d.SetObject();

					rapidjson::Document::AllocatorType& allocator = d.GetAllocator();

					for(const auto i : m_keyBindings)
					{
						rapidjson::Value value(getInputName(i.second), allocator);
						rapidjson::Value key(SDL_GetScancodeName(i.first), allocator);
						d.AddMember(key, value, allocator);
					}

					saveJson(d, "keyboard1.bindings.json");
				}
				catch(...)
				{
				}
#endif
			}

			void clearRebindMode()
			{
			}

			void resetRebinds()
			{
			}

			bool hasMouse() const
			{
				return true;
				return m_state.has_mouse;
			}

			int keyboard_buttons_down;

			int keyboard_map_scancode(SDL_Scancode scancode)
			{
				if(m_keyBindings.count(scancode))
				{
					return m_keyBindings[scancode];
				}
				return 0;
			}

			bool on_key_down(SDL_Scancode scancode)
			{
				int mapped = keyboard_map_scancode(scancode);
				keyboard_buttons_down |= mapped;
				return mapped != 0;
			}

			bool on_key_up(SDL_Scancode scancode)
			{
				int mapped = keyboard_map_scancode(scancode);
				keyboard_buttons_down &= ~mapped;
				return mapped != 0;
			}

			void on_all_keys_up()
			{
				keyboard_buttons_down = 0;
			}

			void enableMouse()
			{
				this->state().has_mouse = true;
			}

			bool canRebind(SDL_Scancode scancode, int input)
			{
				if(m_keyBindings.count(scancode) == 0)
				{
					return true;
				}

				auto replacingInput = m_keyBindings[scancode];
				u64 count = 0;

				for(auto i : m_keyBindings)
				{
					if(i.second == replacingInput)
					{
						count++;
					}
				}

				return count != 1;
			}

			bool updateRebind(int input) override
			{
				int count = 0;
				auto state = SDL_GetKeyboardState(&count);
				u64 changed = 0;

				for(int i = 0; i < std::min(MAX_KEY_STATE, count); i++)
				{
					m_lastKeyState[i] = (state[i] ^ m_lastKeyState[i]) & state[i];
				}

				for(int i = 0; i < std::min(MAX_KEY_STATE, count); i++)
				{
					if(m_lastKeyState[i] && canRebind((SDL_Scancode)i, input))
					{
						m_keyBindings[(SDL_Scancode)i] = input;
						changed++;
						saveKeyBindings();
					}
				}

				memcpy(m_lastKeyState, state, std::min(MAX_KEY_STATE, count));
				return changed != 0;
			}

			void update()
			{
				bool walk = false;
				int count = 0;
				auto state = SDL_GetKeyboardState(&count);

				if(state[SDL_SCANCODE_F10] && (m_lastKeyState[SDL_SCANCODE_F10] ^ state[SDL_SCANCODE_F10]))
				{
					oot::config().game().fullscreen() = !oot::config().game().fullscreen();
					set_fullscreen(oot::config().game().fullscreen());
				}

				if(state[SDL_SCANCODE_ESCAPE] && (m_lastKeyState[SDL_SCANCODE_ESCAPE] ^ state[SDL_SCANCODE_ESCAPE]))
				{
					if(oot::config().game().fullscreen())
					{
						oot::config().game().fullscreen() = false;
						set_fullscreen(oot::config().game().fullscreen());
					}
				}

				if(hid::isTasPlaying())
				{
					return;
				}

				for(const auto& [scancode, input] : m_keyBindings)
				{
					if(scancode < count)
					{
						if(state[scancode])
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
										walk = true;
										break;
								}

								if((u32)input >= (u32)Button::OCARINA && (u32)input <= (u32)Button::TUNIC_TOGGLE)
								{
									if(!m_lastKeyState[scancode])
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
										}
									}
								}
							}
							else
							{
								this->state().button |= input;
							}
						}
					}
				}

#ifdef ENABLE_MOUSE
				int mouse_delta_x = 0;
				int mouse_delta_y = 0;

				auto buttons = SDL_GetRelativeMouseState(&mouse_delta_x, &mouse_delta_y);
				this->enableMouse();

				if(buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
				{
					m_state.button |= B_BUTTON;
				}

				if(buttons & SDL_BUTTON(SDL_BUTTON_RIGHT))
				{
					m_state.button |= A_BUTTON;
				}

				if(buttons & SDL_BUTTON(SDL_BUTTON_MIDDLE))
				{
					walk = true;
				}

				m_state.mouse_x += mouse_delta_x * 4;
				m_state.mouse_y += mouse_delta_y * 4;

				if(mouse_delta_x > 10)
				{
					int yy = 0;
				}
#endif

				if(walk)
				{
					m_state.stick_x *= 0.25f;
					m_state.stick_y *= 0.25f;
				}
				memcpy(m_lastKeyState, state, std::min(MAX_KEY_STATE, count));
			}

			protected:
			std::unordered_map<SDL_Scancode, int> m_keyBindings;
			u8 m_lastKeyState[MAX_KEY_STATE];
		};
	} // namespace controller

	Keyboard::Keyboard() : Driver()
	{
	}

	Keyboard::~Keyboard()
	{
	}

	void Keyboard::scan(class Controllers* controllers)
	{
		if(!size())
		{
#ifdef ENABLE_MOUSE
			// SDL_SetRelativeMouseMode(SDL_TRUE);
#endif
			auto controller = std::make_shared<controller::Keyboard>();
#ifdef ENABLE_MOUSE

			controller->enableMouse();
#endif
			m_controllers.push_back(controller);
			players().attach(controller, 0);
		}
	}

	void Keyboard::update()
	{
		for(auto& keyboard : m_controllers)
		{
			((controller::Keyboard*)keyboard.get())->update();
		}
	}

	void Keyboard::resetBindings()
	{
		for(auto& keyboard : m_controllers)
		{
			keyboard->resetBindings();
		}
	}
} // namespace oot::hid
