#ifndef AUDIO_SDL_H
#define AUDIO_SDL_H
#if(defined(TARGET_WEB) || (defined(WIN32) || defined(WIN64)) || defined(__SWITCH__)) && !defined(DISABLE_SDL_AUDIO) && !defined(DISABLE_SDL_AUDIO)
#define ENABLE_SDL_AUDIO
extern struct AudioAPI audio_sdl;
#endif

#endif
