#pragma once

extern u32 gBitFlags[32];
extern u16 gEquipMasks[4];
extern u16 gEquipNegMasks[4];
extern u8 gEquipShifts[4];
extern u32 gGsFlagsMasks[4];
extern u32 gGsFlagsShifts[4];
extern void* gItemIcons[0x82];
#ifndef N64_VERSION
extern u8* gItemIconsGray[86][32*32];
extern void* gItemIconsCurrent[86];//Points to either the original or the grayscale version
#endif
extern u8 gItemSlots[56];
extern u16 gUpgradeCapacities[8][4];
extern u32 gUpgradeMasks[8];
extern u8 gUpgradeShifts[8];

#ifdef INTERNAL_SRC_CODE_CODE_80097A00_C
void Inventory_ChangeEquipment(s16 equipment, u16 value);
void Inventory_ChangeUpgrade(s16 upgrade, s16 value);
u8 Inventory_DeleteEquipment(GlobalContext* globalCtx, s16 equipment);
#else
void Inventory_ChangeEquipment(s16 equipment, u16 value);
void Inventory_ChangeUpgrade(s16 upgrade, s16 value);
u8 Inventory_DeleteEquipment(struct GlobalContext* globalCtx, s16 equipment);
#endif
