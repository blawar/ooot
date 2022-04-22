#define INTERNAL_SRC_CODE_Z_ACTOR_DLFTBLS_C
#include "global.h"
#include "z64actor.h"
#include "n64fault.h"
#include "segment_symbols.h"

// Linker symbol declarations (used in the table below)
#define DEFINE_ACTOR(name, _1, _2) DECLARE_OVERLAY_SEGMENT(name)
#define DEFINE_ACTOR_INTERNAL(_0, _1, _2)
#define DEFINE_ACTOR_UNSET(_0)

#include "tables/actor_table.h"

#undef DEFINE_ACTOR
#undef DEFINE_ACTOR_INTERNAL
#undef DEFINE_ACTOR_UNSET

// Init Vars declarations (also used in the table below)
#define DEFINE_ACTOR(name, _1, _2) extern ActorInit name##_InitVars;
#define DEFINE_ACTOR_INTERNAL(name, _1, _2) extern ActorInit name##_InitVars;
#define DEFINE_ACTOR_UNSET(_0)

#include "tables/actor_table.h"
#include "def/fault.h"
#include "def/fault_drawer.h"
#include "def/xprintf.h"
#include "def/z_actor_dlftbls.h"

#undef DEFINE_ACTOR
#undef DEFINE_ACTOR_INTERNAL
#undef DEFINE_ACTOR_UNSET

// Actor Overlay Table definition
#define DEFINE_ACTOR(name, _1, allocType) \
    { (uintptr_t)_ovl_##name##SegmentRomStart,  \
      (uintptr_t)_ovl_##name##SegmentRomEnd,    \
      _ovl_##name##SegmentStart,          \
      _ovl_##name##SegmentEnd,            \
      NULL,                               \
      &name##_InitVars,                   \
      #name,                              \
      allocType,                          \
      0 },

#define DEFINE_ACTOR_INTERNAL(name, _1, allocType) { 0, 0, NULL, NULL, NULL, &name##_InitVars, #name, allocType, 0 },

#define DEFINE_ACTOR_UNSET(_0) { 0 },

ActorOverlay gActorOverlayTable[] = {
#include "tables/actor_table.h"
};

#undef DEFINE_ACTOR
#undef DEFINE_ACTOR_INTERNAL
#undef DEFINE_ACTOR_UNSET

s32 gMaxActorId = 0;

static FaultClient sFaultClient;

void ActorOverlayTable_LogPrint(void) {
    ActorOverlay* overlayEntry;
    u32 i;

    osSyncPrintf("actor_dlftbls %u\n", gMaxActorId);
    osSyncPrintf("RomStart RomEnd   SegStart SegEnd   allocp   profile  segname\n");

    for (i = 0, overlayEntry = &gActorOverlayTable[0]; i < (u32)gMaxActorId; i++, overlayEntry++) {
        osSyncPrintf("%08x %08x %08x %08x %08x %08x %s\n", overlayEntry->vromStart, overlayEntry->vromEnd,
                     overlayEntry->vramStart, overlayEntry->vramEnd, overlayEntry->loadedRamAddr,
                     &overlayEntry->initInfo->id, overlayEntry->name != NULL ? overlayEntry->name : "?");
    }
}

void ActorOverlayTable_FaultPrint(void* arg0, void* arg1) {
}

void ActorOverlayTable_Init(void) {
    gMaxActorId = ACTOR_ID_MAX;
    Fault_AddClient(&sFaultClient, ActorOverlayTable_FaultPrint, NULL, NULL);
}

void ActorOverlayTable_Cleanup(void) {
    Fault_RemoveClient(&sFaultClient);
    gMaxActorId = 0;
}
