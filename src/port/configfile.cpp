// configfile.c - handles loading and saving the configuration options
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "configfile.h"
#include <SDL2/SDL.h>

#define ARRAY_LEN(arr) (sizeof(arr) / sizeof(arr[0]))

enum ConfigOptionType
{
	CONFIG_TYPE_BOOL,
	CONFIG_TYPE_UINT,
	CONFIG_TYPE_FLOAT,
};

struct ConfigOption
{
	const char* name;
	enum ConfigOptionType type;
	union
	{
		bool* boolValue;
		unsigned int* uintValue;
		float* floatValue;
	};
};

/*
 *Config options and default values
 */
bool configFullscreen	  = false;
unsigned int configWidth  = 1920;
unsigned int configHeight = 1080;
// Keyboard mappings (scancode values)
unsigned int configKeyA		 = SDL_SCANCODE_SPACE;
unsigned int configKeyB		 = SDL_SCANCODE_F;
unsigned int configKeyStart	 = SDL_SCANCODE_RETURN;
unsigned int configKeyR		 = SDL_SCANCODE_V;
unsigned int configKeyZ		 = SDL_SCANCODE_LSHIFT;
unsigned int configKeyCUp	 = SDL_SCANCODE_UP;
unsigned int configKeyCDown	 = SDL_SCANCODE_DOWN;
unsigned int configKeyCLeft	 = SDL_SCANCODE_LEFT;
unsigned int configKeyCRight	 = SDL_SCANCODE_RIGHT;
unsigned int configKeyStickUp	 = SDL_SCANCODE_W;
unsigned int configKeyStickDown	 = SDL_SCANCODE_S;
unsigned int configKeyStickLeft	 = SDL_SCANCODE_A;
unsigned int configKeyStickRight = SDL_SCANCODE_D;
