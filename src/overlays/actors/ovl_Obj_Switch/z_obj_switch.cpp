#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OBJ_SWITCH_Z_OBJ_SWITCH_C
#include "actor_common.h"
/*
 * File: z_obj_switch.c
 * Overlay: ovl_Obj_Switch
 * Description: Switches
 */

#include "vt.h"
#include "z_obj_switch.h"
#include "def/code_80043480.h"
#include "def/code_800A9F30.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "objects/gameplay_dangeon_keep/gameplay_dangeon_keep.h"

#define FLAGS ACTOR_FLAG_4

// type:        (pthis->dyna.actor.params & 7)
// subtype:     (pthis->dyna.actor.params >> 4 & 7)
// switch flag: (pthis->dyna.actor.params >> 8 & 0x3F)
// frozen:      pthis->dyna.actor.params >> 7 & 1

void ObjSwitch_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjSwitch_Reset(Actor* pthisx, GlobalContext* globalCtx);
void ObjSwitch_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjSwitch_Update(Actor* thisx, GlobalContext* globalCtx);
void ObjSwitch_Draw(Actor* thisx, GlobalContext* globalCtx);

void ObjSwitch_FloorUpInit(ObjSwitch* pthis);
void ObjSwitch_FloorUp(ObjSwitch* pthis, GlobalContext* globalCtx);
void ObjSwitch_FloorPressInit(ObjSwitch* pthis);
void ObjSwitch_FloorPress(ObjSwitch* pthis, GlobalContext* globalCtx);
void ObjSwitch_FloorDownInit(ObjSwitch* pthis);
void ObjSwitch_FloorDown(ObjSwitch* pthis, GlobalContext* globalCtx);
void ObjSwitch_FloorReleaseInit(ObjSwitch* pthis);
void ObjSwitch_FloorRelease(ObjSwitch* pthis, GlobalContext* globalCtx);

void ObjSwitch_EyeFrozenInit(ObjSwitch* pthis);
void ObjSwitch_EyeInit(ObjSwitch* pthis, GlobalContext* globalCtx);
void ObjSwitch_EyeOpenInit(ObjSwitch* pthis);
void ObjSwitch_EyeOpen(ObjSwitch* pthis, GlobalContext* globalCtx);
void ObjSwitch_EyeClosingInit(ObjSwitch* pthis);
void ObjSwitch_EyeClosing(ObjSwitch* pthis, GlobalContext* globalCtx);
void ObjSwitch_EyeClosedInit(ObjSwitch* pthis);
void ObjSwitch_EyeClosed(ObjSwitch* pthis, GlobalContext* globalCtx);
void ObjSwitch_EyeOpeningInit(ObjSwitch* pthis);
void ObjSwitch_EyeOpening(ObjSwitch* pthis, GlobalContext* globalCtx);

void ObjSwitch_CrystalOffInit(ObjSwitch* pthis);
void ObjSwitch_CrystalOff(ObjSwitch* pthis, GlobalContext* globalCtx);
void ObjSwitch_CrystalTurnOnInit(ObjSwitch* pthis);
void ObjSwitch_CrystalTurnOn(ObjSwitch* pthis, GlobalContext* globalCtx);
void ObjSwitch_CrystalOnInit(ObjSwitch* pthis);
void ObjSwitch_CrystalOn(ObjSwitch* pthis, GlobalContext* globalCtx);
void ObjSwitch_CrystalTurnOffInit(ObjSwitch* pthis);
void ObjSwitch_CrystalTurnOff(ObjSwitch* pthis, GlobalContext* globalCtx);

static Gfx* floorSwitchDLists_102[] = {gFloorSwitch1DL, gFloorSwitch3DL, gFloorSwitch2DL, gFloorSwitch2DL};

static void* eyeTextures_104[][4] = {
    {gEyeSwitchGoldOpenTex, gEyeSwitchGoldOpeningTex, gEyeSwitchGoldClosingTex, gEyeSwitchGoldClosedTex},
    {gEyeSwitchSilverOpenTex, gEyeSwitchSilverHalfTex, gEyeSwitchSilverClosedTex, gEyeSwitchSilverClosedTex},
};

static Gfx* eyeDlists_104[] = {gEyeSwitch1DL, gEyeSwitch2DL};

static Gfx* xluDLists_105[] = {gCrystalSwitchCoreXluDL, gCrystalSwitchDiamondXluDL, NULL, NULL, gCrystalSwitchCoreXluDL};

static Gfx* opaDLists_105[] = {gCrystalSwitchCoreOpaDL, gCrystalSwitchDiamondOpaDL, NULL, NULL, gCrystalSwitchCoreOpaDL};

ActorInit Obj_Switch_InitVars = {
    ACTOR_OBJ_SWITCH, ACTORCAT_SWITCH, FLAGS, OBJECT_GAMEPLAY_DANGEON_KEEP, ACTOR_FACTORY(ObjSwitch), (ActorFunc)ObjSwitch_Init, (ActorFunc)ObjSwitch_Destroy, (ActorFunc)ObjSwitch_Update, (ActorFunc)ObjSwitch_Draw, (ActorFunc)ObjSwitch_Reset,
};

static f32 sHeights[] = {10, 10, 0, 30, 30};

static ColliderTrisElementInit D_80B9EC34[2] = {
    {
	{
	    ELEMTYPE_UNK0,
	    {0x00000000, 0x00, 0x00},
	    {0x40000040, 0x00, 0x00},
	    TOUCH_NONE,
	    BUMP_ON,
	    OCELEM_NONE,
	},
	{{{-20.0f, 19.0f, -20.0f}, {-20.0f, 19.0f, 20.0f}, {20.0f, 19.0f, 20.0f}}},
    },
    {
	{
	    ELEMTYPE_UNK0,
	    {0x00000000, 0x00, 0x00},
	    {0x40000040, 0x00, 0x00},
	    TOUCH_NONE,
	    BUMP_ON,
	    OCELEM_NONE,
	},
	{{{20.0f, 19.0f, 20.0f}, {20.0f, 19.0f, -20.0f}, {-20.0f, 19.0f, -20.0f}}},
    },
};

static ColliderTrisInit sRustyFloorTrisInit = {
    {
	COLTYPE_NONE,
	AT_NONE,
	AC_ON | AC_TYPE_PLAYER,
	OC1_NONE,
	OC2_NONE,
	COLSHAPE_TRIS,
    },
    2,
    D_80B9EC34,
};

static ColliderTrisElementInit D_80B9ECBC[2] = {
    {
	{
	    ELEMTYPE_UNK4,
	    {0x00000000, 0x00, 0x00},
	    {0x0001F824, 0x00, 0x00},
	    TOUCH_NONE,
	    BUMP_ON,
	    OCELEM_NONE,
	},
	{{{0.0f, 23.0f, 8.5f}, {-23.0f, 0.0f, 8.5f}, {0.0f, -23.0f, 8.5f}}},
    },
    {
	{
	    ELEMTYPE_UNK0,
	    {0x00000000, 0x00, 0x00},
	    {0x0001F824, 0x00, 0x00},
	    TOUCH_NONE,
	    BUMP_ON,
	    OCELEM_NONE,
	},
	{{{0.0f, 23.0f, 8.5f}, {0.0f, -23.0f, 8.5f}, {23.0f, 0.0f, 8.5f}}},
    },
};

static ColliderTrisInit trisColliderEye = {
    {
	COLTYPE_NONE,
	AT_NONE,
	AC_ON | AC_TYPE_PLAYER,
	OC1_NONE,
	OC2_NONE,
	COLSHAPE_TRIS,
    },
    2,
    D_80B9ECBC,
};

static ColliderJntSphElementInit D_80B9ED44[1] = {
    {
	{
	    ELEMTYPE_UNK0,
	    {0x00000000, 0x00, 0x00},
	    {0xEFC1FFFE, 0x00, 0x00},
	    TOUCH_NONE,
	    BUMP_ON,
	    OCELEM_ON,
	},
	{0, {{0, 300, 0}, 20}, 100},
    },
};

static ColliderJntSphInit sCyrstalJntSphereInit = {
    {
	COLTYPE_METAL,
	AT_NONE,
	AC_ON | AC_TYPE_PLAYER,
	OC1_ON | OC1_TYPE_ALL,
	OC2_TYPE_2,
	COLSHAPE_JNTSPH,
    },
    1,
    D_80B9ED44,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 2000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 400, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 2000, ICHAIN_STOP),
};

void ObjSwitch_RotateY(Vec3f* dest, Vec3f* src, s16 angle)
{
	f32 s = Math_SinS(angle);
	f32 c = Math_CosS(angle);

	dest->x = src->z * s + src->x * c;
	dest->y = src->y;
	dest->z = src->z * c - src->x * s;
}

void ObjSwitch_InitDynapoly(ObjSwitch* pthis, GlobalContext* globalCtx, CollisionHeader* collision, s32 moveFlag)
{
	s32 pad;
	CollisionHeader* colHeader = NULL;
	s32 pad2;

	DynaPolyActor_Init(&pthis->dyna, moveFlag);
	CollisionHeader_GetVirtual(collision, &colHeader);
	pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);

	if(pthis->dyna.bgId == BG_ACTOR_MAX)
	{
		// "Warning : move BG registration failure"
		osSyncPrintf("Warning : move BG 登録失敗(%s %d)(name %d)(arg_data 0x%04x)\n", "../z_obj_switch.c", 531, pthis->dyna.actor.id, pthis->dyna.actor.params);
	}
}

void ObjSwitch_InitJntSphCollider(ObjSwitch* pthis, GlobalContext* globalCtx, ColliderJntSphInit* colliderJntSphInit)
{
	ColliderJntSph* colliderJntSph = &pthis->jntSph.col;

	Collider_InitJntSph(globalCtx, colliderJntSph);
	Collider_SetJntSph(globalCtx, colliderJntSph, &pthis->dyna.actor, colliderJntSphInit, pthis->jntSph.items);
	func_800D1694(pthis->dyna.actor.world.pos.x, pthis->dyna.actor.world.pos.y + pthis->dyna.actor.shape.yOffset * pthis->dyna.actor.scale.y, pthis->dyna.actor.world.pos.z, &pthis->dyna.actor.shape.rot);
	Matrix_Scale(pthis->dyna.actor.scale.x, pthis->dyna.actor.scale.y, pthis->dyna.actor.scale.z, MTXMODE_APPLY);
	Collider_UpdateSpheres(0, colliderJntSph);
}

void ObjSwitch_InitTrisCollider(ObjSwitch* pthis, GlobalContext* globalCtx, ColliderTrisInit* colliderTrisInit)
{
	ColliderTris* colliderTris = &pthis->tris.col;
	s32 i;
	s32 j;
	Vec3f pos[3];

	Collider_InitTris(globalCtx, colliderTris);
	Collider_SetTris(globalCtx, colliderTris, &pthis->dyna.actor, colliderTrisInit, pthis->tris.items);

	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 3; j++)
		{
			ObjSwitch_RotateY(&pos[j], &colliderTrisInit->elements[i].dim.vtx[j], pthis->dyna.actor.home.rot.y);
			Math_Vec3f_Sum(&pos[j], &pthis->dyna.actor.world.pos, &pos[j]);
		}

		Collider_SetTrisVertices(colliderTris, i, &pos[0], &pos[1], &pos[2]);
	}
}

Actor* ObjSwitch_SpawnIce(ObjSwitch* pthis, GlobalContext* globalCtx)
{
	Actor* thisx = &pthis->dyna.actor;

	return Actor_SpawnAsChild(
	    &globalCtx->actorCtx, thisx, globalCtx, ACTOR_OBJ_ICE_POLY, thisx->world.pos.x, thisx->world.pos.y, thisx->world.pos.z, thisx->world.rot.x, thisx->world.rot.y, thisx->world.rot.z, (pthis->dyna.actor.params >> 8 & 0x3F) << 8);
}

void ObjSwitch_SetOn(ObjSwitch* pthis, GlobalContext* globalCtx)
{
	s32 pad;
	s32 subType;

	if(Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8 & 0x3F)))
	{
		pthis->cooldownOn = false;
	}
	else
	{
		subType = (pthis->dyna.actor.params >> 4 & 7);
		Flags_SetSwitch(globalCtx, (pthis->dyna.actor.params >> 8 & 0x3F));

		if(subType == 0 || subType == 4)
		{
			OnePointCutscene_AttentionSetSfx(globalCtx, &pthis->dyna.actor, NA_SE_SY_CORRECT_CHIME);
		}
		else
		{
			OnePointCutscene_AttentionSetSfx(globalCtx, &pthis->dyna.actor, NA_SE_SY_TRE_BOX_APPEAR);
		}

		pthis->cooldownOn = true;
	}
}

void ObjSwitch_SetOff(ObjSwitch* pthis, GlobalContext* globalCtx)
{
	pthis->cooldownOn = false;

	if(Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8 & 0x3F)))
	{
		Flags_UnsetSwitch(globalCtx, (pthis->dyna.actor.params >> 8 & 0x3F));

		if((pthis->dyna.actor.params >> 4 & 7) == 1)
		{
			OnePointCutscene_AttentionSetSfx(globalCtx, &pthis->dyna.actor, NA_SE_SY_TRE_BOX_APPEAR);
			pthis->cooldownOn = true;
		}
	}
}

void ObjSwitch_UpdateTwoTexScrollXY(ObjSwitch* pthis)
{
	pthis->x1TexScroll = (pthis->x1TexScroll - 1) & 0x7F;
	pthis->y1TexScroll = (pthis->y1TexScroll + 1) & 0x7F;
	pthis->x2TexScroll = (pthis->x2TexScroll + 1) & 0x7F;
	pthis->y2TexScroll = (pthis->y2TexScroll - 1) & 0x7F;
}

void ObjSwitch_Init(Actor* thisx, GlobalContext* globalCtx)
{
	ObjSwitch* pthis = (ObjSwitch*)thisx;
	s32 switchFlagSet;
	s32 type;

	switchFlagSet = Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8 & 0x3F));
	type = (pthis->dyna.actor.params & 7);

	if(type == OBJSWITCH_TYPE_FLOOR || type == OBJSWITCH_TYPE_FLOOR_RUSTY)
	{
		ObjSwitch_InitDynapoly(pthis, globalCtx, &gFloorSwitchCol, DPM_PLAYER);
	}

	Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);

	if(type == OBJSWITCH_TYPE_FLOOR || type == OBJSWITCH_TYPE_FLOOR_RUSTY)
	{
		pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y + 1.0f;
	}

	Actor_SetFocus(&pthis->dyna.actor, sHeights[type]);

	if(type == OBJSWITCH_TYPE_FLOOR_RUSTY)
	{
		ObjSwitch_InitTrisCollider(pthis, globalCtx, &sRustyFloorTrisInit);
	}
	else if(type == OBJSWITCH_TYPE_EYE)
	{
		ObjSwitch_InitTrisCollider(pthis, globalCtx, &trisColliderEye);
	}
	else if(type == OBJSWITCH_TYPE_CRYSTAL || type == OBJSWITCH_TYPE_CRYSTAL_TARGETABLE)
	{
		ObjSwitch_InitJntSphCollider(pthis, globalCtx, &sCyrstalJntSphereInit);
	}

	if(type == OBJSWITCH_TYPE_CRYSTAL_TARGETABLE)
	{
		pthis->dyna.actor.flags |= ACTOR_FLAG_VISIBLE;
		pthis->dyna.actor.targetMode = 4;
	}

	pthis->dyna.actor.colChkInfo.mass = MASS_IMMOVABLE;

	if((pthis->dyna.actor.params >> 7 & 1) && (ObjSwitch_SpawnIce(pthis, globalCtx) == NULL))
	{
		osSyncPrintf(VT_FGCOL(RED));
		osSyncPrintf("Error : 氷発生失敗 (%s %d)\n", "../z_obj_switch.c", 732);
		osSyncPrintf(VT_RST);
		pthis->dyna.actor.params &= ~0x80;
	}

	if(pthis->dyna.actor.params >> 7 & 1)
	{
		ObjSwitch_EyeFrozenInit(pthis);
	}
	else if(type == OBJSWITCH_TYPE_FLOOR || type == OBJSWITCH_TYPE_FLOOR_RUSTY)
	{
		if(switchFlagSet)
		{
			ObjSwitch_FloorDownInit(pthis);
		}
		else
		{
			ObjSwitch_FloorUpInit(pthis);
		}
	}
	else if(type == OBJSWITCH_TYPE_EYE)
	{
		if(switchFlagSet)
		{
			ObjSwitch_EyeClosedInit(pthis);
		}
		else
		{
			ObjSwitch_EyeOpenInit(pthis);
		}
	}
	else if(type == OBJSWITCH_TYPE_CRYSTAL || type == OBJSWITCH_TYPE_CRYSTAL_TARGETABLE)
	{
		if(switchFlagSet)
		{
			ObjSwitch_CrystalOnInit(pthis);
		}
		else
		{
			ObjSwitch_CrystalOffInit(pthis);
		}
	}

	osSyncPrintf("(Dungeon switch)(arg_data 0x%04x)\n", pthis->dyna.actor.params);
}

void ObjSwitch_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
	ObjSwitch* pthis = (ObjSwitch*)thisx;

	switch((pthis->dyna.actor.params & 7))
	{
		case OBJSWITCH_TYPE_FLOOR:
		case OBJSWITCH_TYPE_FLOOR_RUSTY:
			DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
			break;
	}

	switch((pthis->dyna.actor.params & 7))
	{
		case OBJSWITCH_TYPE_FLOOR_RUSTY:
		case OBJSWITCH_TYPE_EYE:
			Collider_DestroyTris(globalCtx, &pthis->tris.col);
			break;
		case OBJSWITCH_TYPE_CRYSTAL:
		case OBJSWITCH_TYPE_CRYSTAL_TARGETABLE:
			Collider_DestroyJntSph(globalCtx, &pthis->jntSph.col);
			break;
	}
}

void ObjSwitch_FloorUpInit(ObjSwitch* pthis)
{
	pthis->dyna.actor.scale.y = 33.0f / 200.0f;
	pthis->actionFunc = ObjSwitch_FloorUp;
}

void ObjSwitch_FloorUp(ObjSwitch* pthis, GlobalContext* globalCtx)
{
	if((pthis->dyna.actor.params & 7) == OBJSWITCH_TYPE_FLOOR_RUSTY)
	{
		if(pthis->tris.col.base.acFlags & AC_HIT)
		{
			ObjSwitch_FloorPressInit(pthis);
			ObjSwitch_SetOn(pthis, globalCtx);
			pthis->tris.col.base.acFlags &= ~AC_HIT;
		}
		else
		{
			CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->tris.col.base);
		}
	}
	else
	{
		switch((pthis->dyna.actor.params >> 4 & 7))
		{
			case OBJSWITCH_SUBTYPE_FLOOR_0:
				if(func_8004356C(&pthis->dyna))
				{
					ObjSwitch_FloorPressInit(pthis);
					ObjSwitch_SetOn(pthis, globalCtx);
				}
				break;
			case OBJSWITCH_SUBTYPE_FLOOR_1:
				if((pthis->dyna.unk_160 & 2) && !(pthis->unk_17F & 2))
				{
					ObjSwitch_FloorPressInit(pthis);
					ObjSwitch_SetOn(pthis, globalCtx);
				}
				break;
			case OBJSWITCH_SUBTYPE_FLOOR_2:
				if(func_800435B4(&pthis->dyna))
				{
					ObjSwitch_FloorPressInit(pthis);
					ObjSwitch_SetOn(pthis, globalCtx);
				}
				break;
			case OBJSWITCH_SUBTYPE_FLOOR_3:
				if(func_800435B4(&pthis->dyna))
				{
					ObjSwitch_FloorPressInit(pthis);
					ObjSwitch_SetOff(pthis, globalCtx);
				}
				break;
		}
	}
}

void ObjSwitch_FloorPressInit(ObjSwitch* pthis)
{
	pthis->actionFunc = ObjSwitch_FloorPress;
	pthis->cooldownTimer = 100;
}

void ObjSwitch_FloorPress(ObjSwitch* pthis, GlobalContext* globalCtx)
{
	if((pthis->dyna.actor.params >> 4 & 7) == OBJSWITCH_SUBTYPE_FLOOR_3 || !pthis->cooldownOn || func_8005B198() == pthis->dyna.actor.category || pthis->cooldownTimer <= 0)
	{
		pthis->dyna.actor.scale.y -= 99.0f / 2000.0f;
		if(pthis->dyna.actor.scale.y <= 33.0f / 2000.0f)
		{
			ObjSwitch_FloorDownInit(pthis);
			Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_FOOT_SWITCH);
			Rumble_Shake(pthis->dyna.actor.xyzDistToPlayerSq, 120, 20, 10);
		}
	}
}

void ObjSwitch_FloorDownInit(ObjSwitch* pthis)
{
	pthis->dyna.actor.scale.y = 33.0f / 2000.0f;
	pthis->releaseTimer = 6;
	pthis->actionFunc = ObjSwitch_FloorDown;
}

void ObjSwitch_FloorDown(ObjSwitch* pthis, GlobalContext* globalCtx)
{
	switch((pthis->dyna.actor.params >> 4 & 7))
	{
		case OBJSWITCH_SUBTYPE_FLOOR_0:
			if(!Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8 & 0x3F)))
			{
				ObjSwitch_FloorReleaseInit(pthis);
			}
			break;
		case OBJSWITCH_SUBTYPE_FLOOR_1:
			if((pthis->dyna.unk_160 & 2) && !(pthis->unk_17F & 2))
			{
				ObjSwitch_FloorReleaseInit(pthis);
				ObjSwitch_SetOff(pthis, globalCtx);
			}
			break;
		case OBJSWITCH_SUBTYPE_FLOOR_2:
		case OBJSWITCH_SUBTYPE_FLOOR_3:
			if(!func_800435B4(&pthis->dyna) && !Player_InCsMode(globalCtx))
			{
				if(pthis->releaseTimer <= 0)
				{
					ObjSwitch_FloorReleaseInit(pthis);
					if((pthis->dyna.actor.params >> 4 & 7) == OBJSWITCH_SUBTYPE_FLOOR_2)
					{
						ObjSwitch_SetOff(pthis, globalCtx);
					}
					else
					{
						ObjSwitch_SetOn(pthis, globalCtx);
					}
				}
			}
			else
			{
				pthis->releaseTimer = 6;
			}
			break;
	}
}

void ObjSwitch_FloorReleaseInit(ObjSwitch* pthis)
{
	pthis->actionFunc = ObjSwitch_FloorRelease;
	pthis->cooldownTimer = 100;
}

void ObjSwitch_FloorRelease(ObjSwitch* pthis, GlobalContext* globalCtx)
{
	s16 subType = (pthis->dyna.actor.params >> 4 & 7);

	if(((subType != OBJSWITCH_SUBTYPE_FLOOR_1) && (subType != OBJSWITCH_SUBTYPE_FLOOR_3)) || !pthis->cooldownOn || func_8005B198() == pthis->dyna.actor.category || pthis->cooldownTimer <= 0)
	{
		pthis->dyna.actor.scale.y += 99.0f / 2000.0f;
		if(pthis->dyna.actor.scale.y >= 33.0f / 200.0f)
		{
			ObjSwitch_FloorUpInit(pthis);
			Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_FOOT_SWITCH);
			if(subType == OBJSWITCH_SUBTYPE_FLOOR_1)
			{
				Rumble_Shake(pthis->dyna.actor.xyzDistToPlayerSq, 120, 20, 10);
			}
		}
	}
}

s32 ObjSwitch_EyeIsHit(ObjSwitch* pthis)
{
	Actor* collidingActor;
	s16 yawDiff;

	if((pthis->tris.col.base.acFlags & AC_HIT) && !(pthis->unk_17F & 2))
	{
		collidingActor = pthis->tris.col.base.ac;
		if(collidingActor != NULL)
		{
			yawDiff = collidingActor->world.rot.y - pthis->dyna.actor.shape.rot.y;
			if(ABS(yawDiff) > 0x5000)
			{
				return 1;
			}
		}
	}
	return 0;
}

void ObjSwitch_EyeFrozenInit(ObjSwitch* pthis)
{
	pthis->actionFunc = ObjSwitch_EyeInit;
}

void ObjSwitch_EyeInit(ObjSwitch* pthis, GlobalContext* globalCtx)
{
	if(Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8 & 0x3F)))
	{
		ObjSwitch_EyeClosedInit(pthis);
	}
	else
	{
		ObjSwitch_EyeOpenInit(pthis);
	}
}

void ObjSwitch_EyeOpenInit(ObjSwitch* pthis)
{
	pthis->actionFunc = ObjSwitch_EyeOpen;
	pthis->eyeTexIndex = 0;
}

void ObjSwitch_EyeOpen(ObjSwitch* pthis, GlobalContext* globalCtx)
{
	if(ObjSwitch_EyeIsHit(pthis) || (pthis->dyna.actor.params >> 7 & 1))
	{
		ObjSwitch_EyeClosingInit(pthis);
		ObjSwitch_SetOn(pthis, globalCtx);
		pthis->dyna.actor.params &= ~0x80;
	}
}

void ObjSwitch_EyeClosingInit(ObjSwitch* pthis)
{
	pthis->actionFunc = ObjSwitch_EyeClosing;
	pthis->cooldownTimer = 100;
}

void ObjSwitch_EyeClosing(ObjSwitch* pthis, GlobalContext* globalCtx)
{
	if(!pthis->cooldownOn || func_8005B198() == pthis->dyna.actor.category || pthis->cooldownTimer <= 0)
	{
		pthis->eyeTexIndex++;
		if(pthis->eyeTexIndex >= 3)
		{
			ObjSwitch_EyeClosedInit(pthis);
			Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_FOOT_SWITCH);
		}
	}
}

void ObjSwitch_EyeClosedInit(ObjSwitch* pthis)
{
	pthis->actionFunc = ObjSwitch_EyeClosed;
	pthis->eyeTexIndex = 3;
}

void ObjSwitch_EyeClosed(ObjSwitch* pthis, GlobalContext* globalCtx)
{
	switch((pthis->dyna.actor.params >> 4 & 7))
	{
		case OBJSWITCH_SUBTYPE_EYE_0:
			if(!Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8 & 0x3F)))
			{
				ObjSwitch_EyeOpeningInit(pthis);
				pthis->dyna.actor.params &= ~0x80;
			}
			break;
		case OBJSWITCH_SUBTYPE_EYE_1:
			if(ObjSwitch_EyeIsHit(pthis) || (pthis->dyna.actor.params >> 7 & 1))
			{
				ObjSwitch_EyeOpeningInit(pthis);
				ObjSwitch_SetOff(pthis, globalCtx);
				pthis->dyna.actor.params &= ~0x80;
			}
			break;
	}
}

void ObjSwitch_EyeOpeningInit(ObjSwitch* pthis)
{
	pthis->actionFunc = ObjSwitch_EyeOpening;
	pthis->cooldownTimer = 100;
}

void ObjSwitch_EyeOpening(ObjSwitch* pthis, GlobalContext* globalCtx)
{
	if((pthis->dyna.actor.params >> 4 & 7) != OBJSWITCH_SUBTYPE_EYE_1 || !pthis->cooldownOn || func_8005B198() == pthis->dyna.actor.category || pthis->cooldownTimer <= 0)
	{
		pthis->eyeTexIndex--;
		if(pthis->eyeTexIndex <= 0)
		{
			ObjSwitch_EyeOpenInit(pthis);
			Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_FOOT_SWITCH);
		}
	}
}

void ObjSwitch_CrystalOffInit(ObjSwitch* pthis)
{
	pthis->crystalColor.r = 0;
	pthis->crystalColor.g = 0;
	pthis->crystalColor.b = 0;
	pthis->crystalSubtype1texture = gCrstalSwitchRedTex;
	pthis->actionFunc = ObjSwitch_CrystalOff;
}

void ObjSwitch_CrystalOff(ObjSwitch* pthis, GlobalContext* globalCtx)
{
	switch((pthis->dyna.actor.params >> 4 & 7))
	{
		case OBJSWITCH_SUBTYPE_CRYSTAL_0:
			if((pthis->jntSph.col.base.acFlags & AC_HIT) && pthis->disableAcTimer <= 0)
			{
				pthis->disableAcTimer = 10;
				ObjSwitch_SetOn(pthis, globalCtx);
				ObjSwitch_CrystalTurnOnInit(pthis);
			}
			break;
		case OBJSWITCH_SUBTYPE_CRYSTAL_4:
			if(((pthis->jntSph.col.base.acFlags & AC_HIT) && pthis->disableAcTimer <= 0) || Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8 & 0x3F)))
			{
				pthis->disableAcTimer = 10;
				ObjSwitch_SetOn(pthis, globalCtx);
				ObjSwitch_CrystalTurnOnInit(pthis);
			}
			break;
		case OBJSWITCH_SUBTYPE_CRYSTAL_1:
			if((pthis->jntSph.col.base.acFlags & AC_HIT) && !(pthis->unk_17F & 2) && pthis->disableAcTimer <= 0)
			{
				pthis->disableAcTimer = 10;
				ObjSwitch_SetOn(pthis, globalCtx);
				ObjSwitch_CrystalTurnOnInit(pthis);
			}
			ObjSwitch_UpdateTwoTexScrollXY(pthis);
			break;
	}
}

void ObjSwitch_CrystalTurnOnInit(ObjSwitch* pthis)
{
	pthis->actionFunc = ObjSwitch_CrystalTurnOn;
	pthis->cooldownTimer = 100;
}

void ObjSwitch_CrystalTurnOn(ObjSwitch* pthis, GlobalContext* globalCtx)
{
	if(!pthis->cooldownOn || func_8005B198() == pthis->dyna.actor.category || pthis->cooldownTimer <= 0)
	{
		ObjSwitch_CrystalOnInit(pthis);
		if((pthis->dyna.actor.params >> 4 & 7) == OBJSWITCH_SUBTYPE_CRYSTAL_1)
		{
			ObjSwitch_UpdateTwoTexScrollXY(pthis);
		}
		Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_DIAMOND_SWITCH);
	}
}

void ObjSwitch_CrystalOnInit(ObjSwitch* pthis)
{
	pthis->crystalColor.r = 255;
	pthis->crystalColor.g = 255;
	pthis->crystalColor.b = 255;
	pthis->crystalSubtype1texture = gCrstalSwitchBlueTex;
	pthis->actionFunc = ObjSwitch_CrystalOn;
}

void ObjSwitch_CrystalOn(ObjSwitch* pthis, GlobalContext* globalCtx)
{
	switch((pthis->dyna.actor.params >> 4 & 7))
	{
		case OBJSWITCH_SUBTYPE_CRYSTAL_0:
		case OBJSWITCH_SUBTYPE_CRYSTAL_4:
			if(!Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8 & 0x3F)))
			{
				ObjSwitch_CrystalTurnOffInit(pthis);
			}
			break;
		case OBJSWITCH_SUBTYPE_CRYSTAL_1:
			if((pthis->jntSph.col.base.acFlags & AC_HIT) && !(pthis->unk_17F & 2) && pthis->disableAcTimer <= 0)
			{
				pthis->disableAcTimer = 10;
				globalCtx = globalCtx;
				ObjSwitch_CrystalTurnOffInit(pthis);
				ObjSwitch_SetOff(pthis, globalCtx);
			}
			break;
	}
	ObjSwitch_UpdateTwoTexScrollXY(pthis);
}

void ObjSwitch_CrystalTurnOffInit(ObjSwitch* pthis)
{
	pthis->actionFunc = ObjSwitch_CrystalTurnOff;
	pthis->cooldownTimer = 100;
}

void ObjSwitch_CrystalTurnOff(ObjSwitch* pthis, GlobalContext* globalCtx)
{
	if((pthis->dyna.actor.params >> 4 & 7) != OBJSWITCH_SUBTYPE_CRYSTAL_1 || !pthis->cooldownOn || func_8005B198() == pthis->dyna.actor.category || pthis->cooldownTimer <= 0)
	{
		ObjSwitch_CrystalOffInit(pthis);
		ObjSwitch_UpdateTwoTexScrollXY(pthis);
		Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_DIAMOND_SWITCH);
	}
}

void ObjSwitch_Update(Actor* thisx, GlobalContext* globalCtx)
{
	ObjSwitch* pthis = (ObjSwitch*)thisx;

	if(pthis->releaseTimer > 0)
	{
		pthis->releaseTimer--;
	}
	if(pthis->cooldownTimer > 0)
	{
		pthis->cooldownTimer--;
	}

	pthis->actionFunc(pthis, globalCtx);

	switch((pthis->dyna.actor.params & 7))
	{
		case OBJSWITCH_TYPE_FLOOR:
		case OBJSWITCH_TYPE_FLOOR_RUSTY:
			pthis->unk_17F = pthis->dyna.unk_160;
			break;
		case OBJSWITCH_TYPE_EYE:
			pthis->unk_17F = pthis->tris.col.base.acFlags;
			pthis->tris.col.base.acFlags &= ~AC_HIT;
			CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->tris.col.base);
			break;
		case OBJSWITCH_TYPE_CRYSTAL:
		case OBJSWITCH_TYPE_CRYSTAL_TARGETABLE:
			if(!Player_InCsMode(globalCtx) && pthis->disableAcTimer > 0)
			{
				pthis->disableAcTimer--;
			}
			pthis->unk_17F = pthis->jntSph.col.base.acFlags;
			pthis->jntSph.col.base.acFlags &= ~AC_HIT;
			if(pthis->disableAcTimer <= 0)
			{
				CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->jntSph.col.base);
			}
			CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->jntSph.col.base);
			break;
	}
}

void ObjSwitch_DrawFloor(ObjSwitch* pthis, GlobalContext* globalCtx)
{
	Gfx_DrawDListOpa(globalCtx, floorSwitchDLists_102[(pthis->dyna.actor.params >> 4 & 7)]);
}

void ObjSwitch_DrawFloorRusty(ObjSwitch* pthis, GlobalContext* globalCtx)
{
	Gfx_DrawDListOpa(globalCtx, gRustyFloorSwitchDL);
}

void ObjSwitch_DrawEye(ObjSwitch* pthis, GlobalContext* globalCtx)
{
	s32 pad;
	s32 subType = (pthis->dyna.actor.params >> 4 & 7);

	OPEN_DISPS(globalCtx->gfxCtx, "../z_obj_switch.c", 1459);

	func_80093D18(globalCtx->gfxCtx);
	gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_obj_switch.c", 1462), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTextures_104[subType][pthis->eyeTexIndex]));
	gSPDisplayList(POLY_OPA_DISP++, eyeDlists_104[subType]);

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_obj_switch.c", 1471);
}

void ObjSwitch_DrawCrystal(ObjSwitch* pthis, GlobalContext* globalCtx)
{
	s32 pad1;
	s32 pad2;
	s32 subType;

	subType = (pthis->dyna.actor.params >> 4 & 7);
	func_8002ED80(&pthis->dyna.actor, globalCtx, 0);

	if(1)
	{
	}

	OPEN_DISPS(globalCtx->gfxCtx, "../z_obj_switch.c", 1494);

	func_80093D84(globalCtx->gfxCtx);
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_obj_switch.c", 1497), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	gSPDisplayList(POLY_XLU_DISP++, xluDLists_105[subType]);

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_obj_switch.c", 1502);

	OPEN_DISPS(globalCtx->gfxCtx, "../z_obj_switch.c", 1507);

	func_80093D18(globalCtx->gfxCtx);
	gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_obj_switch.c", 1511), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

	if(subType == OBJSWITCH_SUBTYPE_CRYSTAL_1)
	{
		gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(pthis->crystalSubtype1texture));
	}

	gDPSetEnvColor(POLY_OPA_DISP++, pthis->crystalColor.r, pthis->crystalColor.g, pthis->crystalColor.b, 128);
	gSPSegment(POLY_OPA_DISP++, 0x08, Gfx_TwoTexScroll(globalCtx->gfxCtx, 0, pthis->x1TexScroll, pthis->y1TexScroll, 0x20, 0x20, 1, pthis->x2TexScroll, pthis->y2TexScroll, 0x20, 0x20));
	gSPDisplayList(POLY_OPA_DISP++, opaDLists_105[subType]);

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_obj_switch.c", 1533);
}

static ObjSwitchActionFunc sDrawFuncs[] = {
    ObjSwitch_DrawFloor, ObjSwitch_DrawFloorRusty, ObjSwitch_DrawEye, ObjSwitch_DrawCrystal, ObjSwitch_DrawCrystal,
};

void ObjSwitch_Draw(Actor* thisx, GlobalContext* globalCtx)
{
	ObjSwitch* pthis = (ObjSwitch*)thisx;

	sDrawFuncs[(pthis->dyna.actor.params & 7)](pthis, globalCtx);
}

void ObjSwitch_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	Obj_Switch_InitVars = {
	    ACTOR_OBJ_SWITCH, ACTORCAT_SWITCH, FLAGS, OBJECT_GAMEPLAY_DANGEON_KEEP, ACTOR_FACTORY(ObjSwitch), (ActorFunc)ObjSwitch_Init, (ActorFunc)ObjSwitch_Destroy, (ActorFunc)ObjSwitch_Update, (ActorFunc)ObjSwitch_Draw, (ActorFunc)ObjSwitch_Reset,
	};

	sRustyFloorTrisInit = {
	    {
		COLTYPE_NONE,
		AT_NONE,
		AC_ON | AC_TYPE_PLAYER,
		OC1_NONE,
		OC2_NONE,
		COLSHAPE_TRIS,
	    },
	    2,
	    D_80B9EC34,
	};

	trisColliderEye = {
	    {
		COLTYPE_NONE,
		AT_NONE,
		AC_ON | AC_TYPE_PLAYER,
		OC1_NONE,
		OC2_NONE,
		COLSHAPE_TRIS,
	    },
	    2,
	    D_80B9ECBC,
	};

	sCyrstalJntSphereInit = {
	    {
		COLTYPE_METAL,
		AT_NONE,
		AC_ON | AC_TYPE_PLAYER,
		OC1_ON | OC1_TYPE_ALL,
		OC2_TYPE_2,
		COLSHAPE_JNTSPH,
	    },
	    1,
	    D_80B9ED44,
	};
}
