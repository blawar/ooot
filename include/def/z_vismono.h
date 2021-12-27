#pragma once
#ifdef INTERNAL_SRC_CODE_Z_VISMONO_C
void VisMono_Destroy(VisMono* this);
void VisMono_Draw(VisMono* this, Gfx** gfxp);
void VisMono_DrawOld(VisMono* this);
Gfx* VisMono_DrawTexture(VisMono* this, Gfx* gfx);
void VisMono_Init(VisMono* this);
void VisMono_UpdateTexture(VisMono* this, u16* tex);
#else
void VisMono_Destroy(struct VisMono* this);
void VisMono_Draw(struct VisMono* this, Gfx** gfxp);
void VisMono_DrawOld(struct VisMono* this);
Gfx* VisMono_DrawTexture(struct VisMono* this, Gfx* gfx);
void VisMono_Init(struct VisMono* this);
void VisMono_UpdateTexture(struct VisMono* this, u16* tex);
#endif
