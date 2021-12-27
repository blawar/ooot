#pragma once
#ifdef INTERNAL_SRC_CODE_Z_DLF_C
void Overlay_FreeGameState(GameStateOverlay* overlayEntry);
void Overlay_LoadGameState(GameStateOverlay* overlayEntry);
#else
void Overlay_FreeGameState(struct GameStateOverlay* overlayEntry);
void Overlay_LoadGameState(struct GameStateOverlay* overlayEntry);
#endif
