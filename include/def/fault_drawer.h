#pragma once

s32 FaultDrawer_ColorToPrintColor(u16);
void FaultDrawer_DrawChar(char);
void FaultDrawer_DrawRecImpl(s32, s32, s32, s32, u16);
void FaultDrawer_DrawText(s32, s32, const char*, ...);
void FaultDrawer_FillScreen();
void* FaultDrawer_FormatStringFunc(void*, const char*, u32);
void FaultDrawer_Printf(const char*, ...);
void FaultDrawer_SetBackColor(u16);
void FaultDrawer_SetCharPad(s8, s8);
void FaultDrawer_SetCursor(s32, s32);
void FaultDrawer_SetDefault();
void FaultDrawer_SetDrawerFB(void*, u16, u16);
void FaultDrawer_SetFontColor(u16);
void FaultDrawer_SetForeColor(u16);
void FaultDrawer_SetInputCallback(void (*)());
void FaultDrawer_SetOsSyncPrintfEnabled(u32);
void FaultDrawer_UpdatePrintColor();
void FaultDrawer_VPrintf(const char*, char*);
