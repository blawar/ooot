#pragma once
struct GlobalContext;

extern u32 gBitFlags[32];
extern u16 gEquipMasks[4];
extern u16 gEquipNegMasks[4];
extern u8 gEquipShifts[4];
extern u32 gGsFlagsMasks[4];
extern u32 gGsFlagsShifts[4];
extern void* gItemIcons[0x82];
extern void* gItemIconsCurrent[86];
extern void* gItemIconsGray[86][32*32];
extern u8 gItemSlots[56];
extern u16 gUpgradeCapacities[8][4];
extern u32 gUpgradeMasks[8];
extern u8 gUpgradeShifts[8];

void Inventory_ChangeEquipment(s16 equipment, u16 value);
void Inventory_ChangeUpgrade(s16 upgrade, s16 value);
u8 Inventory_DeleteEquipment(GlobalContext* globalCtx, s16 equipment);
