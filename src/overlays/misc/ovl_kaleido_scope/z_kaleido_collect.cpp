#define INTERNAL_SRC_OVERLAYS_MISC_OVL_KALEIDO_SCOPE_Z_KALEIDO_COLLECT_C
#include "actor_common.h"
#include "z_kaleido_scope.h"
#include "z64audio.h"
#include "textures/parameter_static/parameter_static.h"
#include "textures/icon_item_static/icon_item_static.h"
#include "hack.h"
#include "def/inventory.h"
#include "def/audio.h"
#include "def/audio_bank.h"
#include "def/z_common_data.h"
#include "def/z_message_PAL.h"

void KaleidoScope_DrawQuestStatus(GlobalContext* globalCtx, GraphicsContext* gfxCtx, oot::pause::Page* page)
{
	Vtx* questVtx = page->auxVtx();
	static s16 D_8082A070[][4] = {
	    {255, 0, 0, 255},
	    {255, 70, 0, 150},
	    {255, 70, 0, 150},
	    {255, 0, 0, 255},
	};
	static s16 D_8082A090[][3] = {
	    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 60, 0}, {90, 0, 0}, {0, 40, 110}, {80, 40, 0}, {70, 0, 90}, {90, 90, 0},
	};
	static s16 D_8082A0D8[] = {255, 255, 255, 255, 255, 255};
	static s16 D_8082A0E4[] = {255, 255, 255, 255, 255, 255};
	static s16 D_8082A0F0[] = {150, 150, 150, 150, 150, 150};
	static s16 D_8082A0FC = 20;
	static s16 D_8082A100 = 0;
	static s16 D_8082A104 = 0;
	static s16 D_8082A108 = 0;
	static s16 D_8082A10C = 0;
	static s16 D_8082A110 = 0;
	static s16 D_8082A114 = 20;
	static s16 D_8082A118 = 0;
	static s16 D_8082A11C = 0;
	static s16 D_8082A120 = 0;
	static u8 D_8082A124[] = {
	    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};
	static void* D_8082A130[] = {
	    gOcarinaATex, gOcarinaCDownTex, gOcarinaCRightTex, gOcarinaCLeftTex, gOcarinaCUpTex,
	};
	static u16 D_8082A144[] = {
	    0xFFCC, 0xFFCC, 0xFFCC, 0xFFCC, 0xFFCC,
	};
	static s16 D_8082A150[] = {
	    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};
	static s16 D_8082A164[] = {
	    150, 255, 100, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	};
	static s16 D_8082A17C[] = {
	    255, 80, 150, 160, 100, 240, 255, 255, 255, 255, 255, 255,
	};
	static s16 D_8082A194[] = {
	    100, 40, 255, 0, 255, 100, 255, 255, 255, 255, 255, 255,
	};
	static s8 D_8082A1AC[][4] = {
	    {0x05, 0x01, 0x05, 0xFE}, {0x00, 0x02, 0x02, 0xFE}, {0xFF, 0x13, 0x03, 0x01}, {0x04, 0x02, 0x11, 0x02}, {0x05, 0x03, 0x18, 0x05}, {0xFF, 0xFF, 0x04, 0x00}, {0x0C, 0xFF, 0xFD, 0x07}, {0x0D, 0xFF, 0x06, 0x08}, {0x0E, 0xFF, 0x07, 0x09},
	    {0x0F, 0xFF, 0x08, 0x0A}, {0x10, 0xFF, 0x09, 0x0B}, {0x11, 0xFF, 0x0A, 0x12}, {0x17, 0x06, 0xFD, 0x0D}, {0x17, 0x07, 0x0C, 0x0E}, {0x17, 0x08, 0x0D, 0x0F}, {0x18, 0x09, 0x0E, 0x10}, {0x18, 0x0A, 0x0F, 0x11}, {0x18, 0x0B, 0x10, 0x03},
	    {0x02, 0xFF, 0x0B, 0x13}, {0x02, 0xFF, 0x12, 0x14}, {0x02, 0xFF, 0x13, 0xFE}, {0xFF, 0x17, 0xFD, 0x16}, {0xFF, 0x17, 0x15, 0x18}, {0x15, 0x0C, 0xFD, 0x18}, {0xFF, 0x10, 0x16, 0x04}, {0x00, 0x00, 0x00, 0x00},
	};
	PauseContext* pauseCtx = &globalCtx->pauseCtx;
	Input* input = &globalCtx->state.input[0];
	s16 sp226;
	s16 sp224;
	s16 sp222;
	s16 sp220;
	s16 phi_s0;
	s16 phi_s3;
	s16 sp21A;
	s16 sp218;
	s16 sp216 = 0;
	s16 pad1;
	s16 phi_v1;
	s16 pad2;
	s16 phi_s0_2;
	s16 sp208[3];

	auto current = KaleidoScope_CurrentPage();

	OPEN_DISPS(gfxCtx, "../z_kaleido_collect.c", 248);

	if((!pauseCtx->unk_1E4 || (pauseCtx->unk_1E4 == 5) || (pauseCtx->unk_1E4 == 8)) && page == KaleidoScope_CurrentPage())
	{
		pauseCtx->cursorColorSet = 0;

		if(pauseCtx->cursorSpecialPos == 0)
		{
			pauseCtx->nameColorSet = 0;

			if((pauseCtx->state != 6) || ((pauseCtx->stickRelX == 0) && (pauseCtx->stickRelY == 0)))
			{
				sp216 = page->cursorSlot();
			}
			else
			{
				phi_s3 = page->cursorPoint();

				if(pauseCtx->stickRelX < -30)
				{
					phi_s0 = D_8082A1AC[phi_s3][2];
					if(phi_s0 == -3)
					{
						KaleidoScope_MoveCursorToSpecialPos(globalCtx, PAUSE_CURSOR_PAGE_LEFT);
						pauseCtx->unk_1E4 = 0;
					}
					else
					{
						while(phi_s0 >= 0)
						{
							if((s16)KaleidoScope_UpdateQuestStatusPoint(page, phi_s0) != 0)
							{
								break;
							}
							phi_s0 = D_8082A1AC[phi_s0][2];
						}
					}
				}
				else if(pauseCtx->stickRelX > 30)
				{
					phi_s0 = D_8082A1AC[phi_s3][3];
					if(phi_s0 == -2)
					{
						KaleidoScope_MoveCursorToSpecialPos(globalCtx, PAUSE_CURSOR_PAGE_RIGHT);
						pauseCtx->unk_1E4 = 0;
					}
					else
					{
						while(phi_s0 >= 0)
						{
							if((s16)KaleidoScope_UpdateQuestStatusPoint(page, phi_s0) != 0)
							{
								break;
							}
							phi_s0 = D_8082A1AC[phi_s0][3];
						}
					}
				}

				if(pauseCtx->stickRelY < -30)
				{
					phi_s0 = D_8082A1AC[phi_s3][1];
					while(phi_s0 >= 0)
					{
						if((s16)KaleidoScope_UpdateQuestStatusPoint(page, phi_s0) != 0)
						{
							break;
						}
						phi_s0 = D_8082A1AC[phi_s0][1];
					}
				}
				else if(pauseCtx->stickRelY > 30)
				{
					phi_s0 = D_8082A1AC[phi_s3][0];
					while(phi_s0 >= 0)
					{
						if((s16)KaleidoScope_UpdateQuestStatusPoint(page, phi_s0) != 0)
						{
							break;
						}
						phi_s0 = D_8082A1AC[phi_s0][0];
					}
				}

				if(phi_s3 != page->cursorPoint())
				{
					pauseCtx->unk_1E4 = 0;
					Audio_PlaySoundGeneral(NA_SE_SY_CURSOR, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
				}

				if(page->cursorPoint() != 0x18)
				{
					if(CHECK_QUEST_ITEM(page->cursorPoint()))
					{
						if(page->cursorPoint() < 6)
						{
							phi_s0_2 = page->cursorPoint() + 0x66;
							osSyncPrintf("000 ccc=%d\n", phi_s0_2);
						}
						else if(page->cursorPoint() < 0x12)
						{
							phi_s0_2 = page->cursorPoint() + 0x54;
							osSyncPrintf("111 ccc=%d\n", phi_s0_2);
						}
						else
						{
							phi_s0_2 = page->cursorPoint() + 0x5A;
							osSyncPrintf("222 ccc=%d (%d, %d, %d)\n", phi_s0_2, page->cursorPoint(), 0x12, 0x6C);
						}
					}
					else
					{
						phi_s0_2 = PAUSE_ITEM_NONE;
						osSyncPrintf("999 ccc=%d (%d,  %d)\n", PAUSE_ITEM_NONE, page->cursorPoint(), 0x18);
					}
				}
				else
				{
					if((gSaveContext.inventory.questItems & 0xF0000000) != 0)
					{
						phi_s0_2 = 0x72;
					}
					else
					{
						phi_s0_2 = PAUSE_ITEM_NONE;
					}
					osSyncPrintf("888 ccc=%d (%d,  %d,  %x)\n", phi_s0_2, page->cursorPoint(), 0x72, gSaveContext.inventory.questItems & 0xF0000000);
				}

				sp216 = page->cursorPoint();
				current->cursorItem() = phi_s0_2;
				current->cursorSlot() = sp216;
			}

			KaleidoScope_SetCursorVtx(pauseCtx, sp216 * 4, questVtx);

			if((pauseCtx->state == 6) && (pauseCtx->unk_1E4 == 0) && (pauseCtx->cursorSpecialPos == 0))
			{
				if((sp216 >= QUEST_SONG_MINUET) && (sp216 < QUEST_KOKIRI_EMERALD))
				{
					if(CHECK_QUEST_ITEM(page->cursorPoint()))
					{
						sp216 = page->cursorSlot();
						pauseCtx->ocarinaSongIdx = gOcarinaSongItemMap[sp216 - QUEST_SONG_MINUET];
						D_8082A120 = 10;

						for(phi_s3 = 0; phi_s3 < 8; phi_s3++)
						{
							D_8082A124[phi_s3] = 0xFF;
							D_8082A150[phi_s3] = 0;
						}

						D_8082A11C = 0;
						Audio_OcaSetInstrument(1);
						func_800ECC04((1 << pauseCtx->ocarinaSongIdx) + 0x8000);
						pauseCtx->ocarinaStaff = Audio_OcaGetDisplayingStaff();
						pauseCtx->ocarinaStaff->pos = 0;
						pauseCtx->ocarinaStaff->state = 0xFF;
						VREG(21) = -62;
						VREG(22) = -56;
						VREG(23) = -49;
						VREG(24) = -46;
						VREG(25) = -41;
						pauseCtx->unk_1E4 = 8;
						Audio_OcaSetInstrument(0);
					}
				}
			}
			else if(pauseCtx->unk_1E4 == 5)
			{
				if((pauseCtx->stickRelX != 0) || (pauseCtx->stickRelY != 0))
				{
					pauseCtx->unk_1E4 = 0;
					Audio_OcaSetInstrument(0);
				}
			}
			else if(pauseCtx->unk_1E4 == 8)
			{
				if(CHECK_BTN_ALL(input->press.button, BTN_A) && (sp216 >= QUEST_SONG_MINUET) && (sp216 < QUEST_KOKIRI_EMERALD))
				{
					pauseCtx->unk_1E4 = 9;
					D_8082A120 = 10;
				}
			}
		}
		else if(pauseCtx->cursorSpecialPos == PAUSE_CURSOR_PAGE_LEFT)
		{
			if(pauseCtx->stickRelX > 30)
			{
				page->cursorPoint() = 0x15;
				pauseCtx->nameDisplayTimer = 0;
				pauseCtx->cursorSpecialPos = 0;
				sp216 = page->cursorPoint();
				KaleidoScope_SetCursorVtx(pauseCtx, sp216 * 4, questVtx);
				Audio_PlaySoundGeneral(NA_SE_SY_CURSOR, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
				if(CHECK_QUEST_ITEM(page->cursorPoint()))
				{
					phi_s0_2 = page->cursorPoint() + 0x5A;
				}
				else
				{
					phi_s0_2 = PAUSE_ITEM_NONE;
				}
				sp216 = page->cursorPoint();
				current->cursorItem() = phi_s0_2;
				current->cursorSlot() = sp216;
			}
		}
		else
		{
			if(pauseCtx->stickRelX < -30)
			{
				page->cursorPoint() = 0;
				pauseCtx->nameDisplayTimer = 0;
				pauseCtx->cursorSpecialPos = 0;
				sp216 = page->cursorPoint();
				KaleidoScope_SetCursorVtx(pauseCtx, sp216 * 4, questVtx);
				Audio_PlaySoundGeneral(NA_SE_SY_CURSOR, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
				if(CHECK_QUEST_ITEM(page->cursorPoint()))
				{
					if(page->cursorPoint() < 6)
					{
						phi_s0_2 = page->cursorPoint() + 0x66;
					}
					else if(page->cursorPoint() < 0xC)
					{
						phi_s0_2 = page->cursorPoint() + 0x4E;
					}
					else
					{
						phi_s0_2 = page->cursorPoint() + 0x69;
					}
				}
				else
				{
					phi_s0_2 = PAUSE_ITEM_NONE;
				}
				sp216 = page->cursorPoint();
				current->cursorItem() = phi_s0_2;
				current->cursorSlot() = sp216;
			}
		}
	}
	else
	{
		if(pauseCtx->unk_1E4 == 9)
		{
			pauseCtx->cursorColorSet = 8;

			if(--D_8082A120 == 0)
			{
				for(phi_s3 = 0; phi_s3 < 8; phi_s3++)
				{
					D_8082A124[phi_s3] = 0xFF;
					D_8082A150[phi_s3] = 0;
				}

				D_8082A11C = 0;
				VREG(21) = -62;
				VREG(22) = -56;
				VREG(23) = -49;
				VREG(24) = -46;
				VREG(25) = -41;
				sp216 = page->cursorSlot();
				Audio_OcaSetInstrument(1);
				Audio_OcaSetInstrument(1);
				pauseCtx->ocarinaSongIdx = gOcarinaSongItemMap[sp216 - QUEST_SONG_MINUET];
				Audio_OcaSetSongPlayback(pauseCtx->ocarinaSongIdx + 1, 1);
				pauseCtx->unk_1E4 = 2;
				pauseCtx->ocarinaStaff = Audio_OcaGetDisplayingStaff();
				pauseCtx->ocarinaStaff->pos = 0;
				sp216 = page->cursorSlot();
				KaleidoScope_SetCursorVtx(pauseCtx, sp216 * 4, questVtx);
			}
		}
		else
		{
			sp216 = page->cursorSlot();
			KaleidoScope_SetCursorVtx(pauseCtx, sp216 * 4, questVtx);
		}
	}

	gDPPipeSync(POLY_OPA_DISP++);
	gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->alpha);
	gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);

	D_8082A0FC--;

	for(sp218 = 0, sp21A = 0; sp218 < 6; sp218++, sp21A += 4)
	{
		if((D_8082A100 != 1) && (D_8082A100 != 3))
		{
			phi_v1 = (D_8082A100 != 0) ? sp218 + 6 : sp218;

			if(D_8082A0FC != 0)
			{
				sp226 = ABS(D_8082A0D8[sp218] - D_8082A090[phi_v1][0]) / D_8082A0FC;
				sp224 = ABS(D_8082A0E4[sp218] - D_8082A090[phi_v1][1]) / D_8082A0FC;
				sp222 = ABS(D_8082A0F0[sp218] - D_8082A090[phi_v1][2]) / D_8082A0FC;
				if(D_8082A0D8[sp218] >= D_8082A090[phi_v1][0])
				{
					D_8082A0D8[sp218] -= sp226;
				}
				else
				{
					D_8082A0D8[sp218] += sp226;
				}
				if(D_8082A0E4[sp218] >= D_8082A090[phi_v1][1])
				{
					D_8082A0E4[sp218] -= sp224;
				}
				else
				{
					D_8082A0E4[sp218] += sp224;
				}
				if(D_8082A0F0[sp218] >= D_8082A090[phi_v1][2])
				{
					D_8082A0F0[sp218] -= sp222;
				}
				else
				{
					D_8082A0F0[sp218] += sp222;
				}
			}
			else
			{
				D_8082A0D8[sp218] = D_8082A090[phi_v1][0];
				D_8082A0E4[sp218] = D_8082A090[phi_v1][1];
				D_8082A0F0[sp218] = D_8082A090[phi_v1][2];
			}
		}

		if(CHECK_QUEST_ITEM(sp218))
		{
			gDPPipeSync(POLY_OPA_DISP++);
			gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->alpha);
			gDPSetEnvColor(POLY_OPA_DISP++, D_8082A0D8[sp218], D_8082A0E4[sp218], D_8082A0F0[sp218], 0);
			gSPVertex(POLY_OPA_DISP++, &questVtx[sp21A], 4, 0);

			KaleidoScope_DrawQuadTextureRGBA32(gfxCtx, gItemIcons[ITEM_MEDALLION_FOREST + sp218], 24, 24, 0);
		}
	}

	if(D_8082A0FC == 0)
	{
		D_8082A0FC = ZREG(61 + D_8082A100);
		if(++D_8082A100 >= 4)
		{
			D_8082A100 = 0;
		}
	}

	gDPPipeSync(POLY_OPA_DISP++);
	gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->alpha);
	gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);

	gDPLoadTextureBlock(POLY_OPA_DISP++, gSongNoteTex, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 24, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

	for(sp218 = 0; sp218 < QUEST_KOKIRI_EMERALD - QUEST_SONG_MINUET; sp218++, sp21A += 4)
	{
		if(CHECK_QUEST_ITEM(sp218 + QUEST_SONG_MINUET))
		{
			if((sp218 + QUEST_SONG_MINUET) == sp216)
			{
				questVtx[sp21A + 0].v.ob[0] = questVtx[sp21A + 2].v.ob[0] = questVtx[sp21A + 0].v.ob[0] - 2;

				questVtx[sp21A + 1].v.ob[0] = questVtx[sp21A + 3].v.ob[0] = questVtx[sp21A + 1].v.ob[0] + 4;

				questVtx[sp21A + 0].v.ob[1] = questVtx[sp21A + 1].v.ob[1] = questVtx[sp21A + 0].v.ob[1] + 2;

				questVtx[sp21A + 2].v.ob[1] = questVtx[sp21A + 3].v.ob[1] = questVtx[sp21A + 2].v.ob[1] - 4;
			}

			gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, D_8082A164[sp218], D_8082A17C[sp218], D_8082A194[sp218], pauseCtx->alpha);
			gSPVertex(POLY_OPA_DISP++, &questVtx[sp21A], 4, 0);
			gSP1Quadrangle(POLY_OPA_DISP++, 0, 2, 3, 1, 0);
		}
	}

	gDPPipeSync(POLY_OPA_DISP++);
	gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->alpha);
	gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);

	for(sp218 = 0; sp218 < 3; sp218++, sp21A += 4)
	{
		if(CHECK_QUEST_ITEM(sp218 + 0x12))
		{
			gSPVertex(POLY_OPA_DISP++, &questVtx[sp21A], 4, 0);
			KaleidoScope_DrawQuadTextureRGBA32(gfxCtx, gItemIcons[ITEM_KOKIRI_EMERALD + sp218], 24, 24, 0);
		}
	}

	gDPPipeSync(POLY_OPA_DISP++);
	gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->alpha);

	for(sp218 = 0; sp218 < 3; sp218++, sp21A += 4)
	{
		if(CHECK_QUEST_ITEM(sp218 + 0x15))
		{
			gSPVertex(POLY_OPA_DISP++, &questVtx[sp21A], 4, 0);
			gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->alpha);
			KaleidoScope_DrawQuadTextureRGBA32(gfxCtx, gItemIcons[ITEM_STONE_OF_AGONY + sp218], 24, 24, 0);
		}
	}

	sp226 = ABS(D_8082A104 - D_8082A070[D_8082A118][0]) / D_8082A114;
	sp224 = ABS(D_8082A108 - D_8082A070[D_8082A118][1]) / D_8082A114;
	sp222 = ABS(D_8082A10C - D_8082A070[D_8082A118][2]) / D_8082A114;
	sp220 = ABS(D_8082A110 - D_8082A070[D_8082A118][3]) / D_8082A114;
	if(D_8082A104 >= D_8082A070[D_8082A118][0])
	{
		D_8082A104 -= sp226;
	}
	else
	{
		D_8082A104 += sp226;
	}
	if(D_8082A108 >= D_8082A070[D_8082A118][1])
	{
		D_8082A108 -= sp224;
	}
	else
	{
		D_8082A108 += sp224;
	}
	if(D_8082A10C >= D_8082A070[D_8082A118][2])
	{
		D_8082A10C -= sp222;
	}
	else
	{
		D_8082A10C += sp222;
	}
	if(D_8082A110 >= D_8082A070[D_8082A118][3])
	{
		D_8082A110 -= sp220;
	}
	else
	{
		D_8082A110 += sp220;
	}

	if(--D_8082A114 == 0)
	{
		D_8082A104 = D_8082A070[D_8082A118][0];
		D_8082A108 = D_8082A070[D_8082A118][1];
		D_8082A10C = D_8082A070[D_8082A118][2];
		D_8082A110 = D_8082A070[D_8082A118][3];
		D_8082A114 = ZREG(24 + D_8082A118);
		if(++D_8082A118 >= 4)
		{
			D_8082A118 = 0;
		}
	}

	if((gSaveContext.inventory.questItems >> 0x1C) != 0)
	{
		gDPPipeSync(POLY_OPA_DISP++);
		gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);

		if((pauseCtx->state == 4) || (pauseCtx->state == 0x12))
		{
			gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, D_8082A070[0][0], D_8082A070[0][1], D_8082A070[0][2], pauseCtx->alpha);
		}
		else
		{
			gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, D_8082A104, D_8082A108, D_8082A10C, D_8082A110);
		}

		gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
		gSPVertex(POLY_OPA_DISP++, &questVtx[sp21A], 4, 0);

		POLY_OPA_DISP = KaleidoScope_QuadTextureIA8(POLY_OPA_DISP, gItemIcons[0x79 + (((gSaveContext.inventory.questItems & 0xF0000000) & 0xF0000000) >> 0x1C)], 48, 48, 0);
	}

	if(pauseCtx->state == 6)
	{
		gDPPipeSync(POLY_OPA_DISP++);
		gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

		sp21A += 4;
		if((pauseCtx->cursorSpecialPos == 0) && (sp216 >= 6) && (sp216 < 0x12))
		{
			if((pauseCtx->unk_1E4 < 3) || (pauseCtx->unk_1E4 == 5) || (pauseCtx->unk_1E4 == 8))
			{
				if(current->cursorItem() != PAUSE_ITEM_NONE)
				{
					pauseCtx->cursorColorSet = 8;
					if((pauseCtx->unk_1E4 >= 2) && (pauseCtx->unk_1E4 < 7))
					{
						pauseCtx->cursorColorSet = 0;
					}
				}
			}
		}

		if(pauseCtx->unk_1E4 == 2)
		{
			pauseCtx->ocarinaStaff = Audio_OcaGetDisplayingStaff();

			if(pauseCtx->ocarinaStaff->pos != 0)
			{
				if(D_8082A11C + 1 == pauseCtx->ocarinaStaff->pos)
				{
					D_8082A11C++;
					D_8082A124[pauseCtx->ocarinaStaff->pos - 1] = pauseCtx->ocarinaStaff->noteIdx;
				}

				for(sp218 = 0, phi_s3 = 0; sp218 < 8; sp218++, phi_s3 += 4, sp21A += 4)
				{
					if(D_8082A124[sp218] == 0xFF)
					{
						break;
					}

					if(D_8082A150[sp218] != 255)
					{
						D_8082A150[sp218] += VREG(50);
						if(D_8082A150[sp218] >= 255)
						{
							D_8082A150[sp218] = 255;
						}
					}

					questVtx[sp21A + 0].v.ob[1] = questVtx[sp21A + 1].v.ob[1] = VREG(21 + D_8082A124[sp218]);

					questVtx[sp21A + 2].v.ob[1] = questVtx[sp21A + 3].v.ob[1] = questVtx[sp21A + 0].v.ob[1] - 12;

					gDPPipeSync(POLY_OPA_DISP++);

					if(D_8082A124[sp218] == 0)
					{
						gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 80, 150, 255, D_8082A150[sp218]);
					}
					else
					{
						gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 50, D_8082A150[sp218]);
					}

					gDPSetEnvColor(POLY_OPA_DISP++, 10, 10, 10, 0);
					gSPVertex(POLY_OPA_DISP++, &questVtx[sp21A], 4, 0);

					gDPLoadTextureBlock(POLY_OPA_DISP++, D_8082A130[D_8082A124[sp218]], G_IM_FMT_IA, G_IM_SIZ_8b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

					gSP1Quadrangle(POLY_OPA_DISP++, 0, 2, 3, 1, 0);
				}
			}
		}
		else if(((pauseCtx->unk_1E4 >= 4) && (pauseCtx->unk_1E4 <= 6)) || (pauseCtx->unk_1E4 == 8))
		{
			sp224 = pauseCtx->ocarinaSongIdx;
			sp226 = gOcarinaSongNotes[sp224].len;

			for(sp218 = sp21A, phi_s3 = 0; phi_s3 < sp226; phi_s3++, sp21A += 4)
			{
				questVtx[sp21A + 0].v.ob[1] = questVtx[sp21A + 1].v.ob[1] = VREG(21 + gOcarinaSongNotes[sp224].notesIdx[phi_s3]);

				questVtx[sp21A + 2].v.ob[1] = questVtx[sp21A + 3].v.ob[1] = questVtx[sp21A + 0].v.ob[1] - 12;

				gDPPipeSync(POLY_OPA_DISP++);

				if(pauseCtx->unk_1E4 == 8)
				{
					if(gOcarinaSongNotes[sp224].notesIdx[phi_s3] == 0)
					{
						gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 80, 150, 255, 200);
					}
					else
					{
						gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 50, 200);
					}
				}
				else
				{
					gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 150, 150, 150, 150);
				}

				gDPSetEnvColor(POLY_OPA_DISP++, 10, 10, 10, 0);

				gSPVertex(POLY_OPA_DISP++, &questVtx[sp21A], 4, 0);

				gDPLoadTextureBlock(
				    POLY_OPA_DISP++, D_8082A130[gOcarinaSongNotes[sp224].notesIdx[phi_s3]], G_IM_FMT_IA, G_IM_SIZ_8b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

				gSP1Quadrangle(POLY_OPA_DISP++, 0, 2, 3, 1, 0);
			}

			if(pauseCtx->unk_1E4 != 8)
			{
				pauseCtx->ocarinaStaff = Audio_OcaGetPlayingStaff();

				if(pauseCtx->ocarinaStaff->pos != 0)
				{
					if(D_8082A11C == (pauseCtx->ocarinaStaff->pos - 1))
					{
						if((pauseCtx->ocarinaStaff->noteIdx >= OCARINA_NOTE_A) && (pauseCtx->ocarinaStaff->noteIdx <= OCARINA_NOTE_C_UP))
						{
							D_8082A124[pauseCtx->ocarinaStaff->pos - 1] = pauseCtx->ocarinaStaff->noteIdx;
							D_8082A124[pauseCtx->ocarinaStaff->pos] = 0xFF;
							D_8082A11C++;
						}
					}
				}

				sp21A = sp218 + 32;
				phi_s3 = 0;
				for(; phi_s3 < 8; phi_s3++, sp21A += 4)
				{
					if(D_8082A124[phi_s3] == 0xFF)
					{
						continue;
					}

					if(D_8082A150[phi_s3] != 255)
					{
						D_8082A150[phi_s3] += VREG(50);
						if(D_8082A150[phi_s3] >= 255)
						{
							D_8082A150[phi_s3] = 255;
						}
					}
					questVtx[sp21A + 0].v.ob[1] = questVtx[sp21A + 1].v.ob[1] = VREG(21 + D_8082A124[phi_s3]);

					questVtx[sp21A + 2].v.ob[1] = questVtx[sp21A + 3].v.ob[1] = questVtx[sp21A + 0].v.ob[1] - 12;

					gDPPipeSync(POLY_OPA_DISP++);

					if(D_8082A124[phi_s3] == 0)
					{
						gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 80, 150, 255, D_8082A150[phi_s3]);
					}
					else
					{
						gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 50, D_8082A150[phi_s3]);
					}

					gDPSetEnvColor(POLY_OPA_DISP++, 10, 10, 10, 0);

					gSPVertex(POLY_OPA_DISP++, &questVtx[sp21A], 4, 0);

					gDPLoadTextureBlock(POLY_OPA_DISP++, D_8082A130[D_8082A124[phi_s3]], G_IM_FMT_IA, G_IM_SIZ_8b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

					gSP1Quadrangle(POLY_OPA_DISP++, 0, 2, 3, 1, 0);
				}

				if(pauseCtx->unk_1E4 == 4)
				{
					for(phi_s3 = 0; phi_s3 < 8; phi_s3++)
					{
						D_8082A124[phi_s3] = 0xFF;
						D_8082A150[phi_s3] = 0;
					}

					D_8082A11C = 0;
					Audio_OcaSetInstrument(1);
					func_800ECC04((1 << pauseCtx->ocarinaSongIdx) + 0x8000);
					pauseCtx->ocarinaStaff = Audio_OcaGetDisplayingStaff();
					pauseCtx->ocarinaStaff->pos = 0;
					pauseCtx->ocarinaStaff->state = 0xFE;
					pauseCtx->unk_1E4 = 5;
				}
			}
		}
	}

	if(CHECK_QUEST_ITEM(QUEST_SKULL_TOKEN))
	{
		gDPPipeSync(POLY_OPA_DISP++);
		gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
		gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);

		sp208[0] = sp208[1] = 0;
		sp208[2] = gSaveContext.inventory.gsTokens;

		while(sp208[2] >= 100)
		{
			sp208[0]++;
			sp208[2] -= 100;
		}

		while(sp208[2] >= 10)
		{
			sp208[1]++;
			sp208[2] -= 10;
		}

		gSPVertex(POLY_OPA_DISP++, &questVtx[164], 24, 0);

		for(phi_s3 = 0, sp218 = 0, sp21A = 0; phi_s3 < 2; phi_s3++)
		{
			if(phi_s3 == 0)
			{
				gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 0, 0, 0, pauseCtx->alpha);
			}
			else if(gSaveContext.inventory.gsTokens == 100)
			{
				gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 200, 50, 50, pauseCtx->alpha);
			}
			else
			{
				gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->alpha);
			}

			phi_s0 = 0;
			for(sp21A = 0; sp21A < 3; sp21A++, sp218 += 4)
			{
				if((sp21A >= 2) || (sp208[sp21A] != 0) || (phi_s0 != 0))
				{
					gDPLoadTextureBlock(
					    POLY_OPA_DISP++, ((u8*)gCounterDigit0Tex + (8 * 16 * sp208[sp21A])), G_IM_FMT_I, G_IM_SIZ_8b, 8, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

					gSP1Quadrangle(POLY_OPA_DISP++, sp218, sp218 + 2, sp218 + 3, sp218 + 1, 0);

					phi_s0 = 1;
				}
			}
		}
	}

	CLOSE_DISPS(gfxCtx, "../z_kaleido_collect.c", 863);
}

s32 KaleidoScope_UpdateQuestStatusPoint(oot::pause::Page* page, s32 point)
{
	page->cursorPoint() = point;

	return 1;
}
