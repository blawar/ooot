#pragma once
struct GlobalContext;

extern s16 gSpoilingItemReverts[3];
extern s16 gSpoilingItems[3];

s32 Health_ChangeBy(GlobalContext* globalCtx, s16 healthChange);
void Interface_ChangeAlpha(u16 alphaType);
void Interface_Draw(GlobalContext* globalCtx);
void Interface_InitHorsebackArchery(GlobalContext* globalCtx);
void Interface_LoadActionLabelB(GlobalContext* globalCtx, u16 action);
void Interface_LoadItemIcon1(GlobalContext* globalCtx, u16 button);
void Interface_LoadItemIcon2(GlobalContext* globalCtx, u16 button);
void Interface_SetDoAction(GlobalContext* globalCtx, u16 action);
void Interface_SetNaviCall(GlobalContext* globalCtx, u16 naviCallState);
void Interface_SetSceneRestrictions(GlobalContext* globalCtx);
void Interface_Update(GlobalContext* globalCtx);
void Inventory_ChangeAmmo(s16 item, s16 ammoChange);
s32 Inventory_ConsumeFairy(GlobalContext* globalCtx);
void Inventory_DeleteItem(u16 item, u16 invSlot);
s32 Inventory_HasEmptyBottle(void);
s32 Inventory_HasSpecificBottle(u8 bottleItem);
s32 Inventory_ReplaceItem(GlobalContext* globalCtx, u16 oldItem, u16 newItem);
void Inventory_SwapAgeEquipment(void);
void Inventory_UpdateBottleItem(GlobalContext* globalCtx, u8 item, u8 cButton);
u8 Item_CheckObtainability(u8 item);
u8 Item_Give(GlobalContext* globalCtx, u8 item);
void Magic_Fill(GlobalContext* globalCtx);
void Rupees_ChangeBy(s16 rupeeChange);
void func_800849EC(GlobalContext* globalCtx);
void func_80084BF4(GlobalContext* globalCtx, u16 flag);
void func_800876C8(GlobalContext* globalCtx);
s32 func_80087708(GlobalContext* globalCtx, s16 arg1, s16 arg2);
void func_80088AA0(s16 seconds);
void func_80088AF0(GlobalContext* globalCtx);
void func_80088B34(s16 arg0);
