#pragma once
#include <string>
#include <unordered_map>
#include <SDL2/SDL.h>
#include "controllers.h"



class SDL
{
public:
	SDL(SDL_GameController* controller);
	void scan();

private:
	std::vector<std::shared_ptr<N64Controller>> m_controllers;
};



class Joypad : public N64Controller, public InputDevice
{
public:
	Joypad();
	virtual ~Joypad();

	virtual void scan() override;

	void loadKeyBindings();
	void saveKeyBindings();			

	void ResetMotorPack() override;

	void SendMotorVib(int level) override;

	static inline int8_t convertToByte(int value, int max);

	static inline int8_t invert(const int8_t value);

	inline int8_t stickLeftX();
	inline int8_t stickLeftY();
	inline int8_t stickRightX();
	inline int8_t stickRightY();

	bool canRebind(SDL_GameControllerButton button, int input);

	bool updateRebind(int input) override;

	void update() override;

private:
	bool initHaptics();
	void closeHaptics();

	void SendMotorEvent(short time, short level) override;
	void SendMotorDecay(short level) override {};

	SDL_GameController* m_context = nullptr;
	SDL_Haptic* m_haptic = nullptr;
	std::unordered_map<SDL_GameControllerButton, int> m_keyBindings;
	u8 m_buttonState[SDL_CONTROLLER_BUTTON_MAX];
};