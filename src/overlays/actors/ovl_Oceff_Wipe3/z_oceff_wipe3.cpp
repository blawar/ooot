#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OCEFF_WIPE3_Z_OCEFF_WIPE3_C
#include "actor_common.h"
/*
 * File: z_oceff_wipe3.c
 * Overlay: ovl_Oceff_Wipe3
 * Description: Saria's Song Effect
 */

#include "gfx_align.h"
#include "vt.h"
#include "z_oceff_wipe3.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_lib.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_25)

void OceffWipe3_Init(Actor* thisx, GlobalContext* globalCtx);
void OceffWipe3_Reset(Actor* pthisx, GlobalContext* globalCtx);
void OceffWipe3_Destroy(Actor* thisx, GlobalContext* globalCtx);
void OceffWipe3_Update(Actor* thisx, GlobalContext* globalCtx);
void OceffWipe3_Draw(Actor* thisx, GlobalContext* globalCtx);

ActorInit Oceff_Wipe3_InitVars = {
    ACTOR_OCEFF_WIPE3, ACTORCAT_ITEMACTION, FLAGS, OBJECT_GAMEPLAY_KEEP, ACTOR_FACTORY(OceffWipe3), (ActorFunc)OceffWipe3_Init, (ActorFunc)OceffWipe3_Destroy, (ActorFunc)OceffWipe3_Update, (ActorFunc)OceffWipe3_Draw, (ActorFunc)OceffWipe3_Reset,
};

#include "overlays/ovl_Oceff_Wipe3/ovl_Oceff_Wipe3.cpp"

void OceffWipe3_Init(Actor* thisx, GlobalContext* globalCtx)
{
	OceffWipe3* pthis = (OceffWipe3*)thisx;

	Actor_SetScale(&pthis->actor, 0.1f);
	pthis->counter = 0;
	pthis->actor.world.pos = GET_ACTIVE_CAM(globalCtx)->eye;
	// it's actually WIPE3...
	osSyncPrintf(VT_FGCOL(CYAN) " WIPE2 arg_data = %d\n" VT_RST, pthis->actor.params);
}

void OceffWipe3_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
	OceffWipe3* pthis = (OceffWipe3*)thisx;
	Player* player = GET_PLAYER(globalCtx);

	func_800876C8(globalCtx);
	if(gSaveContext.nayrusLoveTimer != 0)
	{
		player->stateFlags3 |= PLAYER_STATE3_6;
	}
}

void OceffWipe3_Update(Actor* thisx, GlobalContext* globalCtx)
{
	OceffWipe3* pthis = (OceffWipe3*)thisx;

	pthis->actor.world.pos = GET_ACTIVE_CAM(globalCtx)->eye;
	if(pthis->counter < 100)
	{
		pthis->counter++;
	}
	else
	{
		Actor_Kill(&pthis->actor);
	}
}

void OceffWipe3_Draw(Actor* thisx, GlobalContext* globalCtx)
{
	u32 scroll = globalCtx->frames & 0xFFF;
	OceffWipe3* pthis = (OceffWipe3*)thisx;
	f32 z;
	u8 alpha;
	s32 pad[2];
	Vec3f eye;
	Vtx* vtxPtr;
	Vec3f vec;

	eye = GET_ACTIVE_CAM(globalCtx)->eye;
	Camera_GetSkyboxOffset(&vec, GET_ACTIVE_CAM(globalCtx));
	if(pthis->counter < 32)
	{
		z = Math_SinS(pthis->counter << 9) * 1330;
	}
	else
	{
		z = 1330;
	}

	vtxPtr = sFrustumVtx;
	if(pthis->counter >= 80)
	{
		alpha = 12 * (100 - pthis->counter);
	}
	else
	{
		alpha = 255;
	}

	vtxPtr[1].v.cn[3] = vtxPtr[3].v.cn[3] = vtxPtr[5].v.cn[3] = vtxPtr[7].v.cn[3] = vtxPtr[9].v.cn[3] = vtxPtr[11].v.cn[3] = vtxPtr[13].v.cn[3] = vtxPtr[15].v.cn[3] = vtxPtr[17].v.cn[3] = vtxPtr[19].v.cn[3] = vtxPtr[21].v.cn[3] = alpha;

	OPEN_DISPS(globalCtx->gfxCtx, "../z_oceff_wipe3.c", 343);

	func_80093D84(globalCtx->gfxCtx);

	Matrix_Translate(eye.x + vec.x, eye.y + vec.y, eye.z + vec.z, MTXMODE_NEW);
	const float correction_factor = (gfx_width() * 3.0f) / (gfx_height() * 4.0f); // Should be 1 on a 4:3 display
	Matrix_Scale(0.1f * correction_factor, 0.1f, 0.1f, MTXMODE_APPLY);
	func_800D1FD4(&globalCtx->billboardMtxF);
	Matrix_Translate(0.0f, 0.0f, -z, MTXMODE_APPLY);

	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_oceff_wipe3.c", 353), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 170, 255);
	gDPSetEnvColor(POLY_XLU_DISP++, 100, 200, 0, 128);
	gSPDisplayList(POLY_XLU_DISP++, sMaterialDL);
	gSPDisplayList(POLY_XLU_DISP++, Gfx_TwoTexScroll(globalCtx->gfxCtx, 0, scroll * 12, scroll * (-12), 64, 64, 1, scroll * 8, scroll * (-8), 64, 64));
	gSPDisplayList(POLY_XLU_DISP++, sFrustumDL);

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_oceff_wipe3.c", 370);
}

void OceffWipe3_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	Oceff_Wipe3_InitVars = {
	    ACTOR_OCEFF_WIPE3, ACTORCAT_ITEMACTION, FLAGS, OBJECT_GAMEPLAY_KEEP, ACTOR_FACTORY(OceffWipe3), (ActorFunc)OceffWipe3_Init, (ActorFunc)OceffWipe3_Destroy, (ActorFunc)OceffWipe3_Update, (ActorFunc)OceffWipe3_Draw, (ActorFunc)OceffWipe3_Reset,
	};
}
