#define INTERNAL_SRC_OVERLAYS_GAMESTATES_OVL_TITLE_Z_TITLE_C
#include <malloc.h>
#include "actor_common.h"
#include "framerate.h"
#include "def/z_opening.h"
#include "def/z_title.h"

/*
 * File: z_title.c
 * Overlay: ovl_title
 * Description: Displays the Nintendo Logo
 */

const char gBuildTeam[] = "Open Ocarina Team";
const char gBuildDate[] = __DATE__;
const char gBuildTime[] = __TIME__;
const char gBuildMakeOption[] = "";

#include "global.h"
#include "segment_symbols.h"
#include "textures/nintendo_rogo_static/nintendo_rogo_static.h"
#include "z64alloca.h"
#include "def/game.h"
#include "def/gfxprint.h"
#include "def/sys_matrix.h"
#include "def/xprintf.h"
#include "def/z_actor.h"
#include "def/z_kankyo.h"
#include "def/z_rcp.h"
#include "def/z_std_dma.h"
#include "def/z_title.h"
#include "def/z_view.h"

namespace oot::gamestate
{
	Title::Title(GraphicsContext* gfxCtx) : Base(gfxCtx)
	{
	}

	void Title::init()
	{
		framerate_set_profile(PROFILE_TITLE);
		Matrix_Init(this);
		View_Init(&view, gfxCtx);
		exit = false;
		gSaveContext.fileNum = 0xFF;
		this->ult = 0;
		this->unk_1D4 = 0x14;
		this->coverAlpha = 255;
		this->addAlpha = -3;
		this->visibleDuration = 0x3C;
	}

	Title::~Title()
	{
		gSaveContext.file.init(this);
	}

	Base* Title::next()
	{
		return new Title(gfxCtx);
	}

	void Title_PrintBuildInfo(Gfx** gfxp)
	{
		Gfx* g;
		GfxPrint* printer;

		g = *gfxp;
		g = func_8009411C(g);
		printer = (GfxPrint*)alloca(sizeof(GfxPrint));
		GfxPrint_Init(printer);
		GfxPrint_Open(printer, g);
		GfxPrint_SetColor(printer, 255, 155, 255, 255);
		GfxPrint_SetPos(printer, 9, 21);
		GfxPrint_Printf(printer, "");
		GfxPrint_SetColor(printer, 255, 255, 255, 255);
		GfxPrint_SetPos(printer, 7, 23);
		GfxPrint_Printf(printer, "[Creator:%s]", gBuildTeam);
		GfxPrint_SetPos(printer, 5, 24);
		GfxPrint_Printf(printer, "[Date:%s Time:%s]", gBuildDate, gBuildTime);
		g = GfxPrint_Close(printer);
		GfxPrint_Destroy(printer);
		*gfxp = g;
	}

	// Note: In other rom versions pthis function also updates unk_1D4, coverAlpha, addAlpha, visibleDuration to calculate
	// the fade-in/fade-out + the duration of the n64 logo animation
	void Title::calc()
	{
		Input* input = &this->input[0];

		if(CHECK_BTN_ALL(input->press.button, BTN_START))
		{
			this->exit = true;
		}

		if(this->coverAlpha == 0 && this->visibleDuration != 0)
		{
			this->visibleDuration--;
			this->unk_1D4--;
			if(this->unk_1D4 == 0)
			{
				this->unk_1D4 = 0x190;
			}
		}
		else
		{
			this->coverAlpha += this->addAlpha;

			if(this->coverAlpha <= 0)
			{
				this->coverAlpha = 0;
				this->addAlpha = 3;
			}
			else if(this->coverAlpha >= 0xFF)
			{
				this->coverAlpha = 0xFF;
				this->exit = true;
			}
		}

		this->uls = this->ult & 0x7F;
		this->ult++;
		// this->exit = true;
	}

	void Title::setupView(f32 x, f32 y, f32 z)
	{
		View* view = &this->view;
		Vec3f eye;
		Vec3f lookAt;
		Vec3f up;

		eye.x = x;
		eye.y = y;
		eye.z = z;
		up.x = up.z = 0.0f;
		lookAt.x = lookAt.y = lookAt.z = 0.0f;
		up.y = 1.0f;

		func_800AA460(view, 30.0f, 10.0f, 12800.0f);
		func_800AA358(view, &eye, &lookAt, &up);
		func_800AAA50(view, 0xF);
	}

	void Title::draw()
	{
		static s16 sTitleRotY = 0;
		static Lights1 sTitleLights = gdSPDefLights1(0x64, 0x64, 0x64, 0xFF, 0xFF, 0xFF, 0x45, 0x45, 0x45);

		u16 y;
		u16 idx;
		s32 pad1;
		Vec3f v3;
		Vec3f v1;
		Vec3f v2;
		s32 pad2[2];

		OPEN_DISPS(this->gfxCtx, "../z_title.c", 395);

		v3.x = 69;
		v3.y = 69;
		v3.z = 69;
		v2.x = -4949.148;
		v2.y = 4002.5417;
		v1.x = 0;
		v1.y = 0;
		v1.z = 0;
		v2.z = 1119.0837;

		func_8002EABC(&v1, &v2, &v3, this->gfxCtx);
		gSPSetLights1(POLY_OPA_DISP++, sTitleLights);
		setupView(0, 150.0, 300.0);
		func_80093D18(this->gfxCtx);
		Matrix_Translate(-53.0, -5.0, 0, MTXMODE_NEW);
		Matrix_Scale(1.0, 1.0, 1.0, MTXMODE_APPLY);
		Matrix_RotateZYX(0, sTitleRotY, 0, MTXMODE_APPLY);

		gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(this->gfxCtx, "../z_title.c", 424), G_MTX_LOAD);
		gSPDisplayList(POLY_OPA_DISP++, gNintendo64LogoDL);
		func_800944C4(this->gfxCtx);
		gDPPipeSync(POLY_OPA_DISP++);
		gDPSetCycleType(POLY_OPA_DISP++, G_CYC_2CYCLE);
		gDPSetRenderMode(POLY_OPA_DISP++, G_RM_XLU_SURF2, G_RM_OPA_CI | CVG_DST_WRAP);
		gDPSetCombineLERP(POLY_OPA_DISP++, TEXEL1, PRIMITIVE, ENV_ALPHA, TEXEL0, 0, 0, 0, TEXEL0, PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, COMBINED, 0, PRIMITIVE, 0);
		gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 170, 255, 255, 255);
		gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 255, 128);

		gDPLoadMultiBlock(POLY_OPA_DISP++, nintendo_rogo_static_Tex_001800, 0x100, 1, G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, 2, 11);

		for(idx = 0, y = 94; idx < 16; idx++, y += 2)
		{
			gDPLoadTextureBlock(POLY_OPA_DISP++, &((u8*)nintendo_rogo_static_Tex_000000)[0x180 * idx], G_IM_FMT_I, G_IM_SIZ_8b, 192, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

			gDPSetTileSize(POLY_OPA_DISP++, 1, this->uls, (this->ult & 0x7F) - idx * 4, 0, 0);
			gSPTextureRectangle(POLY_OPA_DISP++, 388, y << 2, 1156, (y + 2) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
		}

		Environment_FillScreen(this->gfxCtx, 0, 0, 0, (s16)this->coverAlpha, FILL_SCREEN_XLU);

		sTitleRotY += 300;

		CLOSE_DISPS(this->gfxCtx, "../z_title.c", 483);
	}

	void Title::main()
	{
		OPEN_DISPS(this->gfxCtx, "../z_title.c", 494);

		gSPSegment(POLY_OPA_DISP++, 0, NULL);
		gSPSegment(POLY_OPA_DISP++, 1, NULL);
		Gfx_ClearDisplay(this->gfxCtx, 0, 0, 0);

		calc();
		draw();

		if(gIsCtrlr2Valid)
		{
			Gfx* gfx = POLY_OPA_DISP;
			s32 pad;

			Title_PrintBuildInfo(&gfx);
			POLY_OPA_DISP = gfx;
		}

		if(this->exit)
		{
			gSaveContext.seqId = (u8)NA_BGM_DISABLED;
			gSaveContext.natureAmbienceId = 0xFF;
			gSaveContext.gameMode = 1;
			this->running = false;
			Graph_SetNextGameState(new Opening(gfxCtx));
		}

		CLOSE_DISPS(this->gfxCtx, "../z_title.c", 541);
	}


	
} // namespace oot::gamestate