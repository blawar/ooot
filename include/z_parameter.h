#pragma once
#include "ultra64/types.h"

void Interface_ChangeAlpha(u16 alphaType);
void Interface_SetSceneRestrictions(GlobalContext* globalCtx);
void Inventory_SwapAgeEquipment(void);
void Interface_InitHorsebackArchery(GlobalContext* globalCtx);
void func_800849EC(GlobalContext* globalCtx);
void Interface_LoadItemIcon1(GlobalContext* globalCtx, u16 button);
void Interface_LoadItemIcon2(GlobalContext* globalCtx, u16 button);
void func_80084BF4(GlobalContext* globalCtx, u16 flag);
u8 Item_Give(GlobalContext* globalCtx, u8 item);
u8 Item_CheckObtainability(u8 item);
void Inventory_DeleteItem(u16 item, u16 invSlot);
s32 Inventory_ReplaceItem(GlobalContext* globalCtx, u16 oldItem, u16 newItem);
s32 Inventory_HasEmptyBottle(void);
s32 Inventory_HasSpecificBottle(u8 bottleItem);
void Inventory_UpdateBottleItem(GlobalContext* globalCtx, u8 item, u8 cButton);
s32 Inventory_ConsumeFairy(GlobalContext* globalCtx);
void Interface_SetDoAction(GlobalContext* globalCtx, u16 action);
void Interface_SetNaviCall(GlobalContext* globalCtx, u16 naviCallState);
void Interface_LoadActionLabelB(GlobalContext* globalCtx, u16 action);
s32 Health_ChangeBy(GlobalContext* globalCtx, s16 healthChange);
void Rupees_ChangeBy(s16 rupeeChange);
void Inventory_ChangeAmmo(s16 item, s16 ammoChange);
void Magic_Fill(GlobalContext* globalCtx);
void func_800876C8(GlobalContext* globalCtx);
s32 func_80087708(GlobalContext* globalCtx, s16 arg1, s16 arg2);
void func_80088AA0(s16 seconds);
void func_80088AF0(GlobalContext* globalCtx);
void func_80088B34(s16 arg0);
void Interface_Draw(GlobalContext* globalCtx);
void Interface_Update(GlobalContext* globalCtx);
