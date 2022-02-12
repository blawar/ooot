#pragma once
struct VisMono;

void VisMono_Destroy(VisMono* pthis);
void VisMono_Draw(VisMono* pthis, Gfx** gfxp);
void VisMono_DrawOld(VisMono* pthis);
Gfx* VisMono_DrawTexture(VisMono* pthis, Gfx* gfx);
void VisMono_Init(VisMono* pthis);
void VisMono_UpdateTexture(VisMono* pthis, u16* tex);
