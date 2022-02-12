#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OBJ_MAKEKINSUTA_Z_OBJ_MAKEKINSUTA_C
#include "actor_common.h"
/*
 * File: z_obj_makekinsuta.c
 * Overlay: ovl_Obj_Makekinsuta
 * Description: Skulltula Sprouting from Bean Spot
 */

#include "z_obj_makekinsuta.h"
#include "vt.h"
#include "def/z_actor.h"

#define FLAGS ACTOR_FLAG_4

void ObjMakekinsuta_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjMakekinsuta_Update(Actor* thisx, GlobalContext* globalCtx);

void func_80B98320(ObjMakekinsuta* pthis, GlobalContext* globalCtx);
void ObjMakekinsuta_DoNothing(ObjMakekinsuta* pthis, GlobalContext* globalCtx);

ActorInit Obj_Makekinsuta_InitVars = {
    ACTOR_OBJ_MAKEKINSUTA,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ObjMakekinsuta),
    (ActorFunc)ObjMakekinsuta_Init,
    (ActorFunc)Actor_Noop,
    (ActorFunc)ObjMakekinsuta_Update,
    NULL,
};

void ObjMakekinsuta_Init(Actor* thisx, GlobalContext* globalCtx) {
    ObjMakekinsuta* pthis = (ObjMakekinsuta*)thisx;

    if ((pthis->actor.params & 0x6000) == 0x4000) {
        osSyncPrintf(VT_FGCOL(BLUE));
        // "Gold Star Enemy(arg_data %x)"
        osSyncPrintf("金スタ発生敵(arg_data %x)\n", pthis->actor.params);
        osSyncPrintf(VT_RST);
    } else {
        osSyncPrintf(VT_COL(YELLOW, BLACK));
        // "Invalid Argument (arg_data %x)(%s %d)"
        osSyncPrintf("引数不正 (arg_data %x)(%s %d)\n", pthis->actor.params, "../z_obj_makekinsuta.c", 119);
        osSyncPrintf(VT_RST);
    }
    pthis->actionFunc = func_80B98320;
}

void func_80B98320(ObjMakekinsuta* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_152 != 0) {
        if (pthis->timer >= 60 && !func_8002DEEC(GET_PLAYER(globalCtx))) {
            Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_SW, pthis->actor.world.pos.x, pthis->actor.world.pos.y,
                        pthis->actor.world.pos.z, 0, pthis->actor.shape.rot.y, 0, (pthis->actor.params | 0x8000));
            pthis->actionFunc = ObjMakekinsuta_DoNothing;
        } else {
            pthis->timer++;
        }
    } else {
        pthis->timer = 0;
    }
}

void ObjMakekinsuta_DoNothing(ObjMakekinsuta* pthis, GlobalContext* globalCtx) {
}

void ObjMakekinsuta_Update(Actor* thisx, GlobalContext* globalCtx) {
    ObjMakekinsuta* pthis = (ObjMakekinsuta*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}
