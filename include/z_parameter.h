#pragma once
#include "ultra64/types.h"

void Interface_ChangeAlpha(u16 alphaType);
void Interface_SetSceneRestrictions(struct GlobalContext* globalCtx);
void Inventory_SwapAgeEquipment(void);
void Interface_InitHorsebackArchery(struct GlobalContext* globalCtx);
void func_800849EC(struct GlobalContext* globalCtx);
void Interface_LoadItemIcon1(struct GlobalContext* globalCtx, u16 button);
void Interface_LoadItemIcon2(struct GlobalContext* globalCtx, u16 button);
void func_80084BF4(struct GlobalContext* globalCtx, u16 flag);
u8 Item_Give(struct GlobalContext* globalCtx, u8 item);
u8 Item_CheckObtainability(u8 item);
void Inventory_DeleteItem(u16 item, u16 invSlot);
s32 Inventory_ReplaceItem(struct GlobalContext* globalCtx, u16 oldItem, u16 newItem);
s32 Inventory_HasEmptyBottle(void);
s32 Inventory_HasSpecificBottle(u8 bottleItem);
void Inventory_UpdateBottleItem(struct GlobalContext* globalCtx, u8 item, u8 cButton);
s32 Inventory_ConsumeFairy(struct GlobalContext* globalCtx);
void Interface_SetDoAction(struct GlobalContext* globalCtx, u16 action);
void Interface_SetNaviCall(struct GlobalContext* globalCtx, u16 naviCallState);
void Interface_LoadActionLabelB(struct GlobalContext* globalCtx, u16 action);
s32 Health_ChangeBy(struct GlobalContext* globalCtx, s16 healthChange);
void Rupees_ChangeBy(s16 rupeeChange);
void Inventory_ChangeAmmo(s16 item, s16 ammoChange);
void Magic_Fill(struct GlobalContext* globalCtx);
void func_800876C8(struct GlobalContext* globalCtx);
s32 func_80087708(struct GlobalContext* globalCtx, s16 arg1, s16 arg2);
void func_80088AA0(s16 seconds);
void func_80088AF0(struct GlobalContext* globalCtx);
void func_80088B34(s16 arg0);
void Interface_Draw(struct GlobalContext* globalCtx);
void Interface_Update(struct GlobalContext* globalCtx);

