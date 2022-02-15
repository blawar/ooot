#pragma once
#include <SDL2/SDL.h>
#include <unordered_map>
#include <string>
#include "controllers.h"

#define MAX_KEY_STATE (16*1024)


namespace hid
{
	class Keyboard : public N64Controller, public InputDevice
	{
	public:
		Keyboard();
		virtual ~Keyboard() {}
		void scan();
		void update() override;
		bool defaultOnly() override { return true; }
		bool updateRebind(Button input) override;

		void clearRebindMode() {}
		void resetRebinds() {}
		bool hasMouse() const;

		void enableMouse() { state().has_mouse = true; }
		bool canRebind(SDL_Scancode scancode, Button input);

		Button keyboard_map_scancode(SDL_Scancode scancode);

		bool on_key_down(SDL_Scancode scancode);
		bool on_key_up(SDL_Scancode scancode);
		void on_all_keys_up() { keyboard_buttons_down = 0; }

		void loadKeyBindings();
		void saveKeyBindings();

		int keyboard_buttons_down;

	private:
		const char* getInputName(Button input);
		Button getInputValue(const std::string& input);

		std::unordered_map<SDL_Scancode, Button> m_keyBindings;
		u8 m_lastKeyState[MAX_KEY_STATE];
	};
}