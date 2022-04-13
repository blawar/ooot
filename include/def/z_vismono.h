#pragma once
struct VisMono;

void VisMono_Destroy(VisMono* pthis);
void VisMono_Draw(VisMono* pthis, Gfx** gfxp);
void VisMono_DrawOld(VisMono* pthis);
Gfx* VisMono_DesaturateDList(VisMono* pthis, Gfx* gfx);
void VisMono_Init(VisMono* pthis);
void VisMono_DesaturateTLUT(VisMono* pthis, u16* tex);
