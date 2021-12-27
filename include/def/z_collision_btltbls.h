#pragma once
#ifdef INTERNAL_SRC_CODE_Z_COLLISION_BTLTBLS_C
void DamageTable_Clear(DamageTable* table);
DamageTable* DamageTable_Get(s32 index);
#else
void DamageTable_Clear(struct DamageTable* table);
struct DamageTable* DamageTable_Get(s32 index);
#endif
