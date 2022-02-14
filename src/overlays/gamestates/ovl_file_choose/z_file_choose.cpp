#define INTERNAL_SRC_OVERLAYS_GAMESTATES_OVL_FILE_CHOOSE_Z_FILE_CHOOSE_C
#include "actor_common.h"
#include "z_kankyo.h"
#include "z_player.h"
#include "z_play.h"
#include "z_file_choose.h"
#include "z_select.h"
#include "framerate.h"
#include "file_choose.h"
#include "segment_symbols.h"
#include "textures/title_static/title_static.h"
#include "textures/parameter_static/parameter_static.h"
#include "def/code_80069420.h"
#include "def/code_80097A00.h"
#include "def/code_800A9F30.h"
#include "def/code_800EC960.h"
#include "def/code_800F7260.h"
#include "def/code_800F9280.h"
#include "def/game.h"
#include "def/graph.h"
#include "def/shrink_window.h"
#include "def/sys_matrix.h"
#include "def/z_common_data.h"
#include "def/z_file_choose.h"
#include "def/z_kanfont.h"
#include "def/z_kankyo.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_sram.h"
#include "def/z_ss_sram.h"
#include "def/z_std_dma.h"
#include "def/z_view.h"
#include "def/z_vr_box.h"
#include "def/z_vr_box_draw.h"
#include "def/z_play.h" // FORCE

extern u16 gSramSlotOffsets[];

static s16 sUnused = 106;

static s16 sScreenFillAlpha = 255;

static Gfx sScreenFillSetupDL[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsDPSetOtherMode(G_AD_DISABLE | G_CD_MAGICSQ | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_NONE | G_TL_TILE |
                         G_TD_CLAMP | G_TP_NONE | G_CYC_1CYCLE | G_PM_1PRIMITIVE,
                     G_AC_NONE | G_ZS_PIXEL | G_RM_CLD_SURF | G_RM_CLD_SURF2),
    gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PRIMITIVE),
    gsSPEndDisplayList(),
};

static s16 sFileInfoBoxPartWidths[] = { 36, 36, 36, 36, 24 };

static s16 sWindowContentColors[2][3] = {
    { 100, 150, 255 }, // blue
    { 100, 100, 100 }, // gray
};

void FileChoose_SetView(FileChooseContext* pthis, f32 eyeX, f32 eyeY, f32 eyeZ) {
    Vec3f eye;
    Vec3f lookAt;
    Vec3f up;

    lookAt.x = lookAt.y = lookAt.z = 0.0f;
    up.x = up.z = 0.0f;

    eye.x = eyeX;
    eye.y = eyeY;
    eye.z = eyeZ;

    up.y = 1.0f;

    func_800AA358(&pthis->view, &eye, &lookAt, &up);
    func_800AAA50(&pthis->view, 0x7F);
}

Gfx* FileChoose_QuadTextureIA8(Gfx* gfx, void* texture, s16 width, s16 height, s16 point) {
    gDPLoadTextureBlock(gfx++, texture, G_IM_FMT_IA, G_IM_SIZ_8b, width, height, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSP1Quadrangle(gfx++, point, point + 2, point + 3, point + 1, 0);

    return gfx;
}

void FileChoose_InitModeUpdate(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;

    if (pthis->menuMode == FS_MENU_MODE_INIT) {
        pthis->menuMode = FS_MENU_MODE_CONFIG;
        pthis->configMode = CM_FADE_IN_START;
        pthis->nextTitleLabel = FS_TITLE_OPEN_FILE;
        osSyncPrintf("SRAM Start-Load >>>>> ");
        Sram_VerifyAndLoadAllSaves(pthis, &pthis->sramCtx);
        osSyncPrintf("Done!!!\n");
    }
}

void FileChoose_InitModeDraw(GameState* pthisx) {
}

/**
 * Fade in the menu window and title label.
 * If a file is occupied fade in the name, name box, and connector.
 * Fade in the copy erase and options button according to the window alpha.
 */
void FileChoose_FadeInMenuElements(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;
    SramContext* sramCtx = &pthis->sramCtx;
    s16 i;

    pthis->titleAlpha[0] += VREG(1);
    pthis->windowAlpha += VREG(2);

    for (i = 0; i < 3; i++) {
        pthis->fileButtonAlpha[i] = pthis->windowAlpha;

        if (SLOT_OCCUPIED(sramCtx, i)) {
            pthis->nameBoxAlpha[i] = pthis->nameAlpha[i] = pthis->windowAlpha;
            pthis->connectorAlpha[i] += VREG(1);
            if (pthis->connectorAlpha[i] >= 255) {
                pthis->connectorAlpha[i] = 255;
            }
        }
    }

    pthis->actionButtonAlpha[FS_BTN_ACTION_COPY] = pthis->actionButtonAlpha[FS_BTN_ACTION_ERASE] =
        pthis->optionButtonAlpha = pthis->windowAlpha;
}

/**
 * Converts a numerical value to ones-tens-hundreds digits
 */
void FileChoose_SplitNumber(u16 value, s16* hundreds, s16* tens, s16* ones) {
    *hundreds = 0;
    *tens = 0;
    *ones = value;

    while (true) {
        if ((*ones - 100) < 0) {
            break;
        }
        (*hundreds)++;
        *ones -= 100;
    }

    while (true) {
        if ((*ones - 10) < 0) {
            break;
        }
        (*tens)++;
        *ones -= 10;
    }
}

/**
 * Reduce the alpha of the black screen fill to create a fade in effect.
 * Additionally, slide the window from the right to the center of the screen.
 * Update function for `CM_FADE_IN_START`
 */
void FileChoose_StartFadeIn(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;

    FileChoose_FadeInMenuElements(&pthis->state);
    sScreenFillAlpha -= 40;
    pthis->windowPosX -= 20;

    if (pthis->windowPosX <= -94) {
        pthis->windowPosX = -94;
        pthis->configMode = CM_FADE_IN_END;
        sScreenFillAlpha = 0;
    }
}

/**
 * Finish fading in the remaining menu elements.
 * Fade in the controls text at the bottom of the screen.
 * Update function for `CM_FADE_IN_END`
 */
void FileChoose_FinishFadeIn(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;

    pthis->controlsAlpha += VREG(1);
    FileChoose_FadeInMenuElements(&pthis->state);

    if (pthis->titleAlpha[0] >= 255) {
        pthis->titleAlpha[0] = 255;
        pthis->controlsAlpha = 255;
        pthis->windowAlpha = 200;
        pthis->configMode = CM_MAIN_MENU;
    }
}

/**
 * Update the cursor and wait for the player to select a button to change menus accordingly.
 * If an empty file is selected, enter the name entry config mode.
 * If an occupied file is selected, enter the `Select` menu mode.
 * If copy, erase, or options is selected, set config mode accordingly.
 * Lastly, set any warning labels if appropriate.
 * Update function for `CM_MAIN_MENU`
 */
void FileChoose_UpdateMainMenu(GameState* pthisx) {
    static u8 emptyName[] = { 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E };
    FileChooseContext* pthis = (FileChooseContext*)pthisx;
    SramContext* sramCtx = &pthis->sramCtx;
    Input* input = &pthis->state.input[0];

    if (CHECK_BTN_ALL(input->press.button, BTN_START) || CHECK_BTN_ALL(input->press.button, BTN_A)) {
        if (pthis->buttonIndex <= FS_BTN_MAIN_FILE_3) {
            osSyncPrintf("REGCK_ALL[%x]=%x,%x,%x,%x,%x,%x\n", pthis->buttonIndex,
                         GET_NEWF(sramCtx, pthis->buttonIndex, 0), GET_NEWF(sramCtx, pthis->buttonIndex, 1),
                         GET_NEWF(sramCtx, pthis->buttonIndex, 2), GET_NEWF(sramCtx, pthis->buttonIndex, 3),
                         GET_NEWF(sramCtx, pthis->buttonIndex, 4), GET_NEWF(sramCtx, pthis->buttonIndex, 5));

            if (!SLOT_OCCUPIED(sramCtx, pthis->buttonIndex)) {
                Audio_PlaySoundGeneral(NA_SE_SY_FSEL_DECIDE_L, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
                pthis->configMode = CM_ROTATE_TO_NAME_ENTRY;
                pthis->kbdButton = FS_KBD_BTN_NONE;
                pthis->charPage = FS_CHAR_PAGE_ENG;
                pthis->kbdX = 0;
                pthis->kbdY = 0;
                pthis->charIndex = 0;
                pthis->charBgAlpha = 0;
                pthis->newFileNameCharCount = 0;
                pthis->nameEntryBoxPosX = 120;
                pthis->nameEntryBoxAlpha = 0;
                MemCopy(&pthis->fileNames[pthis->buttonIndex][0], &emptyName, 8);
            } else if (pthis->n64ddFlags[pthis->buttonIndex] == pthis->n64ddFlag) {
                Audio_PlaySoundGeneral(NA_SE_SY_FSEL_DECIDE_L, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
                pthis->actionTimer = 8;
                pthis->selectMode = SM_FADE_MAIN_TO_SELECT;
                pthis->selectedFileIndex = pthis->buttonIndex;
                pthis->menuMode = FS_MENU_MODE_SELECT;
                pthis->nextTitleLabel = FS_TITLE_OPEN_FILE;
            } else if (!pthis->n64ddFlags[pthis->buttonIndex]) {
                Audio_PlaySoundGeneral(NA_SE_SY_FSEL_ERROR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
            }
        } else {
            if (pthis->warningLabel == FS_WARNING_NONE) {
                Audio_PlaySoundGeneral(NA_SE_SY_FSEL_DECIDE_L, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
                pthis->prevConfigMode = pthis->configMode;

                if (pthis->buttonIndex == FS_BTN_MAIN_COPY) {
                    pthis->configMode = CM_SETUP_COPY_SOURCE;
                    pthis->nextTitleLabel = FS_TITLE_COPY_FROM;
                } else if (pthis->buttonIndex == FS_BTN_MAIN_ERASE) {
                    pthis->configMode = CM_SETUP_ERASE_SELECT;
                    pthis->nextTitleLabel = FS_TITLE_ERASE_FILE;
                } else {
                    pthis->configMode = CM_MAIN_TO_OPTIONS;
                    pthis->kbdButton = 0;
                    pthis->kbdX = 0;
                    pthis->kbdY = 0;
                    pthis->charBgAlpha = 0;
                    pthis->newFileNameCharCount = 0;
                    pthis->nameEntryBoxPosX = 120;
                }

                pthis->actionTimer = 8;
            } else {
                Audio_PlaySoundGeneral(NA_SE_SY_FSEL_ERROR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
            }
        }
    } else {
        if (ABS(pthis->stickRelY) > 30) {
            Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);

            if (pthis->stickRelY > 30) {
                pthis->buttonIndex--;
                if (pthis->buttonIndex < FS_BTN_MAIN_FILE_1) {
                    pthis->buttonIndex = FS_BTN_MAIN_OPTIONS;
                }
            } else {
                pthis->buttonIndex++;
                if (pthis->buttonIndex > FS_BTN_MAIN_OPTIONS) {
                    pthis->buttonIndex = FS_BTN_MAIN_FILE_1;
                }
            }
        }

        if (pthis->buttonIndex == FS_BTN_MAIN_COPY) {
            if (!SLOT_OCCUPIED(sramCtx, 0) && !SLOT_OCCUPIED(sramCtx, 1) && !SLOT_OCCUPIED(sramCtx, 2)) {
                pthis->warningButtonIndex = pthis->buttonIndex;
                pthis->warningLabel = FS_WARNING_NO_FILE_COPY;
                pthis->emptyFileTextAlpha = 255;
            } else if (SLOT_OCCUPIED(sramCtx, 0) && SLOT_OCCUPIED(sramCtx, 1) && SLOT_OCCUPIED(sramCtx, 2)) {
                pthis->warningButtonIndex = pthis->buttonIndex;
                pthis->warningLabel = FS_WARNING_NO_EMPTY_FILES;
                pthis->emptyFileTextAlpha = 255;
            } else {
                pthis->warningLabel = FS_WARNING_NONE;
            }
        } else if (pthis->buttonIndex == FS_BTN_MAIN_ERASE) {
            if (!SLOT_OCCUPIED(sramCtx, 0) && !SLOT_OCCUPIED(sramCtx, 1) && !SLOT_OCCUPIED(sramCtx, 2)) {
                pthis->warningButtonIndex = pthis->buttonIndex;
                pthis->warningLabel = FS_WARNING_NO_FILE_ERASE;
                pthis->emptyFileTextAlpha = 255;
            } else {
                pthis->warningLabel = FS_WARNING_NONE;
            }
        } else {
            pthis->warningLabel = FS_WARNING_NONE;
        }
    }
}

/**
 * Update function for `CM_UNUSED_31`
 */
void FileChoose_UnusedCM31(GameState* pthisx) {
}

/**
 * Delay the next config mode from running until `XREG(73)` reaches 254.
 * Because the timer increments by 2, the delay is 127 frames (assuming the value was not changed by reg editor).
 * Unused in the final game, was possibly used for debugging.
 * Update function for `CM_UNUSED_DELAY`
 */
void FileChoose_UnusedCMDelay(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;

    XREG(73) += 2;

    if (XREG(73) == 254) {
        pthis->configMode = pthis->nextConfigMode;
        XREG(73) = 0;
    }
}

/**
 * Rotate the window from the main menu to the name entry menu.
 * Update function for `CM_ROTATE_TO_NAME_ENTRY`
 */
void FileChoose_RotateToNameEntry(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;

    pthis->windowRot += VREG(16);

    if (pthis->windowRot >= 314.0f) {
        pthis->windowRot = 314.0f;
        pthis->configMode = CM_START_NAME_ENTRY;
    }
}

/**
 * Rotate the window from the main menu to the options menu.
 * Update function for `CM_MAIN_TO_OPTIONS`
 */
void FileChoose_RotateToOptions(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;

    pthis->windowRot += VREG(16);

    if (pthis->windowRot >= 314.0f) {
        pthis->windowRot = 314.0f;
        pthis->configMode = CM_START_OPTIONS;
    }
}

/**
 * Rotate the window from the options menu to the main menu.
 * Update function for `CM_NAME_ENTRY_TO_MAIN` and `CM_OPTIONS_TO_MAIN`
 */
void FileChoose_RotateToMain(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;

    pthis->windowRot += VREG(16);

    if (pthis->windowRot >= 628.0f) {
        pthis->windowRot = 0.0f;
        pthis->configMode = CM_MAIN_MENU;
    }
}

static void (*gConfigModeUpdateFuncs[])(GameState*) = {
    FileChoose_StartFadeIn,        FileChoose_FinishFadeIn,
    FileChoose_UpdateMainMenu,     FileChoose_SetupCopySource,
    FileChoose_SelectCopySource,   FileChoose_SetupCopyDest1,
    FileChoose_SetupCopyDest2,     FileChoose_SelectCopyDest,
    FileChoose_ExitToCopySource1,  FileChoose_ExitToCopySource2,
    FileChoose_SetupCopyConfirm1,  FileChoose_SetupCopyConfirm2,
    FileChoose_CopyConfirm,        FileChoose_ReturnToCopyDest,
    FileChoose_CopyAnim1,          FileChoose_CopyAnim2,
    FileChoose_CopyAnim3,          FileChoose_CopyAnim4,
    FileChoose_CopyAnim5,          FileChoose_ExitCopyToMain,
    FileChoose_SetupEraseSelect,   FileChoose_EraseSelect,
    FileChoose_SetupEraseConfirm1, FileChoose_SetupEraseConfirm2,
    FileChoose_EraseConfirm,       FileChoose_ExitToEraseSelect1,
    FileChoose_ExitToEraseSelect2, FileChoose_EraseAnim1,
    FileChoose_EraseAnim2,         FileChoose_EraseAnim3,
    FileChoose_ExitEraseToMain,    FileChoose_UnusedCM31,
    FileChoose_RotateToNameEntry,  FileChoose_UpdateKeyboardCursor,
    FileChoose_StartNameEntry,     FileChoose_RotateToMain,
    FileChoose_RotateToOptions,    FileChoose_UpdateOptionsMenu,
    FileChoose_StartOptions,       FileChoose_RotateToMain,
    FileChoose_UnusedCMDelay,
};

/**
 * Updates the alpha of the cursor to make it pulsate.
 * On the debug rom, pthis function also handles switching languages with controller 3.
 */
void FileChoose_PulsateCursor(GameState* pthisx) {
    static s16 cursorAlphaTargets[] = { 70, 200 };
    FileChooseContext* pthis = (FileChooseContext*)pthisx;
    s16 alphaStep;
    SramContext* sramCtx = &pthis->sramCtx;
    Input* debugInput = &pthis->state.input[2];

    if (CHECK_BTN_ALL(debugInput->press.button, BTN_DLEFT)) {
        sramCtx->readBuff[SRAM_HEADER_LANGUAGE] = gSaveContext.language = LANGUAGE_ENG;
#ifdef N64_VERSION
        *((u8*)0x80000002) = LANGUAGE_ENG;
#endif
        SsSram_ReadWrite(OS_K1_TO_PHYSICAL(0xA8000000), sramCtx->readBuff, 3, OS_WRITE);
        osSyncPrintf("1:read_buff[]=%x, %x, %x, %x\n", sramCtx->readBuff[SRAM_HEADER_SOUND],
                     sramCtx->readBuff[SRAM_HEADER_ZTARGET], sramCtx->readBuff[SRAM_HEADER_LANGUAGE],
                     sramCtx->readBuff[SRAM_HEADER_MAGIC]);

        SsSram_ReadWrite(OS_K1_TO_PHYSICAL(0xA8000000), sramCtx->readBuff, SRAM_SIZE, OS_READ);
        osSyncPrintf("read_buff[]=%x, %x, %x, %x\n", sramCtx->readBuff[SRAM_HEADER_SOUND],
                     sramCtx->readBuff[SRAM_HEADER_ZTARGET], sramCtx->readBuff[SRAM_HEADER_LANGUAGE],
                     sramCtx->readBuff[SRAM_HEADER_MAGIC]);
    } else if (CHECK_BTN_ALL(debugInput->press.button, BTN_DUP)) {
        sramCtx->readBuff[SRAM_HEADER_LANGUAGE] = gSaveContext.language = LANGUAGE_GER;
#ifdef N64_VERSION
        *((u8*)0x80000002) = LANGUAGE_GER;
#endif

        SsSram_ReadWrite(OS_K1_TO_PHYSICAL(0xA8000000), sramCtx->readBuff, 3, OS_WRITE);
        osSyncPrintf("1:read_buff[]=%x, %x, %x, %x\n", sramCtx->readBuff[SRAM_HEADER_SOUND],
                     sramCtx->readBuff[SRAM_HEADER_ZTARGET], sramCtx->readBuff[SRAM_HEADER_LANGUAGE],
                     sramCtx->readBuff[SRAM_HEADER_MAGIC]);
        SsSram_ReadWrite(OS_K1_TO_PHYSICAL(0xA8000000), sramCtx->readBuff, SRAM_SIZE, OS_READ);
        osSyncPrintf("read_buff[]=%x, %x, %x, %x\n", sramCtx->readBuff[SRAM_HEADER_SOUND],
                     sramCtx->readBuff[SRAM_HEADER_ZTARGET], sramCtx->readBuff[SRAM_HEADER_LANGUAGE],
                     sramCtx->readBuff[SRAM_HEADER_MAGIC]);
    } else if (CHECK_BTN_ALL(debugInput->press.button, BTN_DRIGHT)) {
        sramCtx->readBuff[SRAM_HEADER_LANGUAGE] = gSaveContext.language = LANGUAGE_FRA;
#ifdef N64_VERSION
        *((u8*)0x80000002) = LANGUAGE_FRA;
#endif

        SsSram_ReadWrite(OS_K1_TO_PHYSICAL(0xA8000000), sramCtx->readBuff, 3, OS_WRITE);
        osSyncPrintf("1:read_buff[]=%x, %x, %x, %x\n", sramCtx->readBuff[SRAM_HEADER_SOUND],
                     sramCtx->readBuff[SRAM_HEADER_ZTARGET], sramCtx->readBuff[SRAM_HEADER_LANGUAGE],
                     sramCtx->readBuff[SRAM_HEADER_MAGIC]);

        SsSram_ReadWrite(OS_K1_TO_PHYSICAL(0xA8000000), sramCtx->readBuff, SRAM_SIZE, OS_READ);
        osSyncPrintf("read_buff[]=%x, %x, %x, %x\n", sramCtx->readBuff[SRAM_HEADER_SOUND],
                     sramCtx->readBuff[SRAM_HEADER_ZTARGET], sramCtx->readBuff[SRAM_HEADER_LANGUAGE],
                     sramCtx->readBuff[SRAM_HEADER_MAGIC]);
    }

    alphaStep = ABS(pthis->highlightColor[3] - cursorAlphaTargets[pthis->highlightPulseDir]) / XREG(35);

    if (pthis->highlightColor[3] >= cursorAlphaTargets[pthis->highlightPulseDir]) {
        pthis->highlightColor[3] -= alphaStep;
    } else {
        pthis->highlightColor[3] += alphaStep;
    }

    XREG(35)--;

    if (XREG(35) == 0) {
        pthis->highlightColor[3] = cursorAlphaTargets[pthis->highlightPulseDir];
        XREG(35) = XREG(36 + pthis->highlightPulseDir);
        pthis->highlightPulseDir ^= 1;
    }
}

void FileChoose_ConfigModeUpdate(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;

    gConfigModeUpdateFuncs[pthis->configMode](&pthis->state);
}

void FileChoose_SetWindowVtx(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;
    s16 i;
    s16 j;
    s16 x;
    s16 tmp;
    s16 tmp2;
    s16 tmp3;

    pthis->windowVtx = (Vtx*)Graph_Alloc(pthis->state.gfxCtx, sizeof(Vtx) * 80);
    tmp = pthis->windowPosX - 90;

    for (x = 0, i = 0; i < 4; i++) {
        tmp += 0x40;
        tmp2 = (i == 3) ? 0x30 : 0x40;

        for (j = 0, tmp3 = 0x50; j < 5; j++, x += 4, tmp3 -= 0x20) {
            pthis->windowVtx[x].v.ob[0] = pthis->windowVtx[x + 2].v.ob[0] = tmp;

            pthis->windowVtx[x + 1].v.ob[0] = pthis->windowVtx[x + 3].v.ob[0] = tmp + tmp2;

            pthis->windowVtx[x].v.ob[1] = pthis->windowVtx[x + 1].v.ob[1] = tmp3;

            pthis->windowVtx[x + 2].v.ob[1] = pthis->windowVtx[x + 3].v.ob[1] = tmp3 - 0x20;

            pthis->windowVtx[x].v.ob[2] = pthis->windowVtx[x + 1].v.ob[2] = pthis->windowVtx[x + 2].v.ob[2] =
                pthis->windowVtx[x + 3].v.ob[2] = 0;

            pthis->windowVtx[x].v.flag = pthis->windowVtx[x + 1].v.flag = pthis->windowVtx[x + 2].v.flag =
                pthis->windowVtx[x + 3].v.flag = 0;

            pthis->windowVtx[x].v.tc[0] = pthis->windowVtx[x].v.tc[1] = pthis->windowVtx[x + 1].v.tc[1] =
                pthis->windowVtx[x + 2].v.tc[0] = 0;

            pthis->windowVtx[x + 1].v.tc[0] = pthis->windowVtx[x + 3].v.tc[0] = tmp2 * 0x20;

            pthis->windowVtx[x + 2].v.tc[1] = pthis->windowVtx[x + 3].v.tc[1] = 0x400;

            pthis->windowVtx[x].v.cn[0] = pthis->windowVtx[x + 2].v.cn[0] = pthis->windowVtx[x].v.cn[1] =
                pthis->windowVtx[x + 2].v.cn[1] = pthis->windowVtx[x].v.cn[2] = pthis->windowVtx[x + 2].v.cn[2] =
                    pthis->windowVtx[x + 1].v.cn[0] = pthis->windowVtx[x + 3].v.cn[0] = pthis->windowVtx[x + 1].v.cn[1] =
                        pthis->windowVtx[x + 3].v.cn[1] = pthis->windowVtx[x + 1].v.cn[2] =
                            pthis->windowVtx[x + 3].v.cn[2] = pthis->windowVtx[x].v.cn[3] =
                                pthis->windowVtx[x + 2].v.cn[3] = pthis->windowVtx[x + 1].v.cn[3] =
                                    pthis->windowVtx[x + 3].v.cn[3] = 255;
        }
    }
}

static s16 D_80812818[] = { 0x001A, 0x000A, 0x000A, 0x000A };
static s16 D_80812820[] = { 0x0020, 0x000C, 0x000C, 0x000C };
static s16 D_80812828[] = { 0x0010, 0x000C, 0x000C, 0x000C };
static s16 D_80812830[] = { 0x0040, 0x0054, 0x0068, 0x0274, 0x0278, 0x027C };
static s16 D_8081283C[] = { 0x0040, 0x0054, 0x0068, 0x0278 };
static s16 D_80812844[] = { 0x0274, 0x0278 };
static s16 D_80812848[] = { 0x0274, 0x0278 };

void FileChoose_SetWindowContentVtx(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;
    s16 phi_t2;
    s16 phi_t0;
    s16 phi_t5;
    s16 phi_a1;
    s16 phi_ra;
    s16 temp_t1;
    SramContext* sramCtx = &pthis->sramCtx;

    pthis->windowContentVtx = (Vtx*)Graph_Alloc(pthis->state.gfxCtx, 0x288 * sizeof(Vtx));

    for (phi_t2 = 0; phi_t2 < 0x288; phi_t2 += 4) {
        pthis->windowContentVtx[phi_t2].v.ob[0] = pthis->windowContentVtx[phi_t2 + 2].v.ob[0] = 0x12C;
        pthis->windowContentVtx[phi_t2 + 1].v.ob[0] = pthis->windowContentVtx[phi_t2 + 3].v.ob[0] =
            pthis->windowContentVtx[phi_t2].v.ob[0] + 0x10;

        pthis->windowContentVtx[phi_t2].v.ob[1] = pthis->windowContentVtx[phi_t2 + 1].v.ob[1] = 0;
        pthis->windowContentVtx[phi_t2 + 2].v.ob[1] = pthis->windowContentVtx[phi_t2 + 3].v.ob[1] =
            pthis->windowContentVtx[phi_t2].v.ob[1] - 0x10;

        pthis->windowContentVtx[phi_t2].v.ob[2] = pthis->windowContentVtx[phi_t2 + 1].v.ob[2] =
            pthis->windowContentVtx[phi_t2 + 2].v.ob[2] = pthis->windowContentVtx[phi_t2 + 3].v.ob[2] = 0;

        pthis->windowContentVtx[phi_t2].v.flag = pthis->windowContentVtx[phi_t2 + 1].v.flag =
            pthis->windowContentVtx[phi_t2 + 2].v.flag = pthis->windowContentVtx[phi_t2 + 3].v.flag = 0;

        pthis->windowContentVtx[phi_t2].v.tc[0] = pthis->windowContentVtx[phi_t2].v.tc[1] =
            pthis->windowContentVtx[phi_t2 + 1].v.tc[1] = pthis->windowContentVtx[phi_t2 + 2].v.tc[0] = 0;

        pthis->windowContentVtx[phi_t2 + 1].v.tc[0] = pthis->windowContentVtx[phi_t2 + 2].v.tc[1] =
            pthis->windowContentVtx[phi_t2 + 3].v.tc[0] = pthis->windowContentVtx[phi_t2 + 3].v.tc[1] = 0x200;

        pthis->windowContentVtx[phi_t2].v.cn[0] = pthis->windowContentVtx[phi_t2 + 1].v.cn[0] =
            pthis->windowContentVtx[phi_t2 + 2].v.cn[0] = pthis->windowContentVtx[phi_t2 + 3].v.cn[0] =
                pthis->windowContentVtx[phi_t2].v.cn[1] = pthis->windowContentVtx[phi_t2 + 1].v.cn[1] =
                    pthis->windowContentVtx[phi_t2 + 2].v.cn[1] = pthis->windowContentVtx[phi_t2 + 3].v.cn[1] =
                        pthis->windowContentVtx[phi_t2].v.cn[2] = pthis->windowContentVtx[phi_t2 + 1].v.cn[2] =
                            pthis->windowContentVtx[phi_t2 + 2].v.cn[2] = pthis->windowContentVtx[phi_t2 + 3].v.cn[2] =
                                pthis->windowContentVtx[phi_t2].v.cn[3] = pthis->windowContentVtx[phi_t2 + 1].v.cn[3] =
                                    pthis->windowContentVtx[phi_t2 + 2].v.cn[3] =
                                        pthis->windowContentVtx[phi_t2 + 3].v.cn[3] = 0xFF;
    }

    pthis->windowContentVtx[0].v.ob[0] = pthis->windowContentVtx[2].v.ob[0] = pthis->windowPosX;
    pthis->windowContentVtx[1].v.ob[0] = pthis->windowContentVtx[3].v.ob[0] = pthis->windowContentVtx[0].v.ob[0] + 0x80;
    pthis->windowContentVtx[0].v.ob[1] = pthis->windowContentVtx[1].v.ob[1] = 0x48;
    pthis->windowContentVtx[2].v.ob[1] = pthis->windowContentVtx[3].v.ob[1] = pthis->windowContentVtx[0].v.ob[1] - 0x10;
    pthis->windowContentVtx[1].v.tc[0] = pthis->windowContentVtx[3].v.tc[0] = 0x1000;

    for (phi_a1 = 0, phi_t2 = 4; phi_a1 < 3; phi_a1++) {
        phi_t0 = pthis->windowPosX - 6;

        for (phi_t5 = 0; phi_t5 < 5; phi_t5++, phi_t2 += 4) {
            pthis->windowContentVtx[phi_t2].v.ob[0] = pthis->windowContentVtx[phi_t2 + 2].v.ob[0] = phi_t0;
            pthis->windowContentVtx[phi_t2 + 1].v.ob[0] = pthis->windowContentVtx[phi_t2 + 3].v.ob[0] =
                pthis->windowContentVtx[phi_t2].v.ob[0] + sFileInfoBoxPartWidths[phi_t5];

            pthis->windowContentVtx[phi_t2].v.ob[1] = pthis->windowContentVtx[phi_t2 + 1].v.ob[1] =
                pthis->fileNamesY[phi_a1] + 0x2C;

            pthis->windowContentVtx[phi_t2 + 2].v.ob[1] = pthis->windowContentVtx[phi_t2 + 3].v.ob[1] =
                pthis->windowContentVtx[phi_t2].v.ob[1] - 0x38;

            pthis->windowContentVtx[phi_t2 + 1].v.tc[0] = pthis->windowContentVtx[phi_t2 + 3].v.tc[0] =
                sFileInfoBoxPartWidths[phi_t5] << 5;
            pthis->windowContentVtx[phi_t2 + 2].v.tc[1] = pthis->windowContentVtx[phi_t2 + 3].v.tc[1] = 0x700;
            phi_t0 += sFileInfoBoxPartWidths[phi_t5];
        }
    }

    phi_t0 = pthis->windowPosX - 6;
    phi_ra = 0x2C;

    for (phi_t5 = 0; phi_t5 < 3; phi_t5++, phi_t2 += 20, phi_ra -= 0x10) {
        pthis->windowContentVtx[phi_t2].v.ob[0] = pthis->windowContentVtx[phi_t2 + 2].v.ob[0] = phi_t0;

        pthis->windowContentVtx[phi_t2 + 1].v.ob[0] = pthis->windowContentVtx[phi_t2 + 3].v.ob[0] =
            pthis->windowContentVtx[phi_t2].v.ob[0] + 0x40;

        pthis->windowContentVtx[phi_t2].v.ob[1] = pthis->windowContentVtx[phi_t2 + 1].v.ob[1] =
            pthis->buttonYOffsets[phi_t5] + phi_ra;
        pthis->windowContentVtx[phi_t2 + 2].v.ob[1] = pthis->windowContentVtx[phi_t2 + 3].v.ob[1] =
            pthis->windowContentVtx[phi_t2].v.ob[1] - 0x10;

        pthis->windowContentVtx[phi_t2 + 1].v.tc[0] = pthis->windowContentVtx[phi_t2 + 3].v.tc[0] = 0x800;

        pthis->windowContentVtx[phi_t2 + 4].v.ob[0] = pthis->windowContentVtx[phi_t2 + 6].v.ob[0] = phi_t0 + 0x40;

        pthis->windowContentVtx[phi_t2 + 5].v.ob[0] = pthis->windowContentVtx[phi_t2 + 7].v.ob[0] =
            pthis->windowContentVtx[phi_t2 + 4].v.ob[0] + 0x6C;

        pthis->windowContentVtx[phi_t2 + 4].v.ob[1] = pthis->windowContentVtx[phi_t2 + 5].v.ob[1] =
            pthis->buttonYOffsets[phi_t5] + phi_ra;

        pthis->windowContentVtx[phi_t2 + 6].v.ob[1] = pthis->windowContentVtx[phi_t2 + 7].v.ob[1] =
            pthis->windowContentVtx[phi_t2 + 4].v.ob[1] - 0x10;

        pthis->windowContentVtx[phi_t2 + 5].v.tc[0] = pthis->windowContentVtx[phi_t2 + 7].v.tc[0] = 0xD80;

        if ((pthis->configMode == CM_COPY_ANIM_2) && (phi_t5 == pthis->copyDestFileIndex)) {
            temp_t1 = pthis->fileNamesY[phi_t5] + 0x2C;
        } else if (((pthis->configMode == CM_COPY_ANIM_3) || (pthis->configMode == CM_COPY_ANIM_4)) &&
                   (phi_t5 == pthis->copyDestFileIndex)) {
            temp_t1 = pthis->buttonYOffsets[phi_t5] + phi_ra;
        } else {
            temp_t1 = phi_ra + pthis->buttonYOffsets[phi_t5] + pthis->fileNamesY[phi_t5];
        }

        pthis->windowContentVtx[phi_t2 + 8].v.ob[0] = pthis->windowContentVtx[phi_t2 + 10].v.ob[0] = phi_t0 + 0xA8;

        pthis->windowContentVtx[phi_t2 + 9].v.ob[0] = pthis->windowContentVtx[phi_t2 + 11].v.ob[0] =
            pthis->windowContentVtx[phi_t2 + 8].v.ob[0] + 0x2C;

        pthis->windowContentVtx[phi_t2 + 8].v.ob[1] = pthis->windowContentVtx[phi_t2 + 9].v.ob[1] = temp_t1;
        pthis->windowContentVtx[phi_t2 + 10].v.ob[1] = pthis->windowContentVtx[phi_t2 + 11].v.ob[1] =
            pthis->windowContentVtx[phi_t2 + 8].v.ob[1] - 0x10;

        pthis->windowContentVtx[phi_t2 + 9].v.tc[0] = pthis->windowContentVtx[phi_t2 + 11].v.tc[0] = 0x580;
        pthis->windowContentVtx[phi_t2 + 12].v.ob[0] = pthis->windowContentVtx[phi_t2 + 14].v.ob[0] = phi_t0 + 0x34;
        pthis->windowContentVtx[phi_t2 + 13].v.ob[0] = pthis->windowContentVtx[phi_t2 + 15].v.ob[0] =
            pthis->windowContentVtx[phi_t2 + 12].v.ob[0] + 0x18;

        pthis->windowContentVtx[phi_t2 + 12].v.ob[1] = pthis->windowContentVtx[phi_t2 + 13].v.ob[1] =
            pthis->buttonYOffsets[phi_t5] + phi_ra;

        pthis->windowContentVtx[phi_t2 + 14].v.ob[1] = pthis->windowContentVtx[phi_t2 + 15].v.ob[1] =
            pthis->windowContentVtx[phi_t2 + 12].v.ob[1] - 0x10;

        pthis->windowContentVtx[phi_t2 + 13].v.tc[0] = pthis->windowContentVtx[phi_t2 + 15].v.tc[0] = 0x300;
        pthis->windowContentVtx[phi_t2 + 16].v.ob[0] = pthis->windowContentVtx[phi_t2 + 18].v.ob[0] = phi_t0 + 0x9C;
        pthis->windowContentVtx[phi_t2 + 17].v.ob[0] = pthis->windowContentVtx[phi_t2 + 19].v.ob[0] =
            pthis->windowContentVtx[phi_t2 + 16].v.ob[0] + 0x18;

        pthis->windowContentVtx[phi_t2 + 16].v.ob[1] = pthis->windowContentVtx[phi_t2 + 17].v.ob[1] =
            pthis->buttonYOffsets[phi_t5] + phi_ra;

        pthis->windowContentVtx[phi_t2 + 18].v.ob[1] = pthis->windowContentVtx[phi_t2 + 19].v.ob[1] =
            pthis->windowContentVtx[phi_t2 + 16].v.ob[1] - 0x10;

        pthis->windowContentVtx[phi_t2 + 17].v.tc[0] = pthis->windowContentVtx[phi_t2 + 19].v.tc[0] = 0x300;
    }

    phi_ra = 0x2C;

    for (phi_t5 = 0; phi_t5 < 3; phi_t5++, phi_ra -= WREG(38)) {
        if (SLOT_OCCUPIED(sramCtx, phi_t5)) {
            phi_t0 = pthis->windowPosX - WREG(39);

            if ((pthis->configMode == 0xF) && (phi_t5 == pthis->copyDestFileIndex)) {
                temp_t1 = pthis->fileNamesY[phi_t5] + 0x2C;
            } else if (((pthis->configMode == CM_COPY_ANIM_3) || (pthis->configMode == CM_COPY_ANIM_4)) &&
                       (phi_t5 == pthis->copyDestFileIndex)) {
                temp_t1 = pthis->buttonYOffsets[phi_t5] + phi_ra;
            } else {
                temp_t1 = phi_ra + pthis->buttonYOffsets[phi_t5] + pthis->fileNamesY[phi_t5];
            }

            temp_t1 += 2;

            for (phi_a1 = 0; phi_a1 < 8; phi_a1++, phi_t2 += 4, phi_t0 += WREG(40)) {
                pthis->windowContentVtx[phi_t2].v.ob[0] = pthis->windowContentVtx[phi_t2 + 2].v.ob[0] =
                    WREG(41) + phi_t0 + 0x40;
                pthis->windowContentVtx[phi_t2 + 1].v.ob[0] = pthis->windowContentVtx[phi_t2 + 3].v.ob[0] =
                    pthis->windowContentVtx[phi_t2].v.ob[0] + WREG(42);
                pthis->windowContentVtx[phi_t2].v.ob[1] = pthis->windowContentVtx[phi_t2 + 1].v.ob[1] = temp_t1 - 3;
                pthis->windowContentVtx[phi_t2 + 2].v.ob[1] = pthis->windowContentVtx[phi_t2 + 3].v.ob[1] =
                    pthis->windowContentVtx[phi_t2].v.ob[1] - WREG(43);
            }

            phi_t0 = pthis->windowPosX - 14;
            temp_t1 -= 0x16;

            for (phi_a1 = 0; phi_a1 < 4; phi_a1++, phi_t2 += 4) {
                pthis->windowContentVtx[phi_t2].v.ob[0] = pthis->windowContentVtx[phi_t2 + 2].v.ob[0] = phi_t0;
                pthis->windowContentVtx[phi_t2 + 1].v.ob[0] = pthis->windowContentVtx[phi_t2 + 3].v.ob[0] =
                    pthis->windowContentVtx[phi_t2].v.ob[0] + D_80812820[phi_a1];
                pthis->windowContentVtx[phi_t2].v.ob[1] = pthis->windowContentVtx[phi_t2 + 1].v.ob[1] = temp_t1;
                pthis->windowContentVtx[phi_t2 + 2].v.ob[1] = pthis->windowContentVtx[phi_t2 + 3].v.ob[1] =
                    pthis->windowContentVtx[phi_t2].v.ob[1] - D_80812828[phi_a1];
                phi_t0 += D_80812818[phi_a1];
            }

            pthis->windowContentVtx[phi_t2 - 15].v.tc[0] = pthis->windowContentVtx[phi_t2 - 13].v.tc[0] = 0x400;

            phi_t0 = pthis->windowPosX + 63;
            temp_t1 += 4;

            for (phi_a1 = 0; phi_a1 < 20; phi_a1++, phi_t2 += 4, phi_t0 += 9) {
                pthis->windowContentVtx[phi_t2].v.ob[0] = pthis->windowContentVtx[phi_t2 + 2].v.ob[0] = phi_t0;
                pthis->windowContentVtx[phi_t2 + 1].v.ob[0] = pthis->windowContentVtx[phi_t2 + 3].v.ob[0] =
                    pthis->windowContentVtx[phi_t2].v.ob[0] + 0xA;
                pthis->windowContentVtx[phi_t2].v.ob[1] = pthis->windowContentVtx[phi_t2 + 1].v.ob[1] = temp_t1;
                pthis->windowContentVtx[phi_t2 + 2].v.ob[1] = pthis->windowContentVtx[phi_t2 + 3].v.ob[1] =
                    pthis->windowContentVtx[phi_t2].v.ob[1] - 0xA;

                if (phi_a1 == 9) {
                    phi_t0 = pthis->windowPosX + 54;
                    temp_t1 -= 8;
                }
            }

            phi_t0 = pthis->windowPosX + 4;
            temp_t1 -= 0xA;

            for (phi_a1 = 0; phi_a1 < 10; phi_a1++, phi_t2 += 4, phi_t0 += 0x10) {
                pthis->windowContentVtx[phi_t2].v.ob[0] = pthis->windowContentVtx[phi_t2 + 2].v.ob[0] = phi_t0;
                pthis->windowContentVtx[phi_t2 + 1].v.ob[0] = pthis->windowContentVtx[phi_t2 + 3].v.ob[0] =
                    pthis->windowContentVtx[phi_t2].v.ob[0] + 0x10;
                pthis->windowContentVtx[phi_t2].v.ob[1] = pthis->windowContentVtx[phi_t2 + 1].v.ob[1] = temp_t1;
                pthis->windowContentVtx[phi_t2 + 2].v.ob[1] = pthis->windowContentVtx[phi_t2 + 3].v.ob[1] =
                    pthis->windowContentVtx[phi_t2].v.ob[1] - 0x10;
            }
        } else {
            phi_t2 += 0xA8;
        }
    }

    phi_t0 = pthis->windowPosX - 6;
    phi_ra = -0xC;

    for (phi_t5 = 0; phi_t5 < 2; phi_t5++, phi_t2 += 4, phi_ra -= 0x10) {
        pthis->windowContentVtx[phi_t2].v.ob[0] = pthis->windowContentVtx[phi_t2 + 2].v.ob[0] = phi_t0;
        pthis->windowContentVtx[phi_t2 + 1].v.ob[0] = pthis->windowContentVtx[phi_t2 + 3].v.ob[0] =
            pthis->windowContentVtx[phi_t2].v.ob[0] + 0x40;
        pthis->windowContentVtx[phi_t2].v.ob[1] = pthis->windowContentVtx[phi_t2 + 1].v.ob[1] =
            pthis->buttonYOffsets[phi_t5 + 3] + phi_ra;
        pthis->windowContentVtx[phi_t2 + 2].v.ob[1] = pthis->windowContentVtx[phi_t2 + 3].v.ob[1] =
            pthis->windowContentVtx[phi_t2].v.ob[1] - 0x10;
        pthis->windowContentVtx[phi_t2 + 1].v.tc[0] = pthis->windowContentVtx[phi_t2 + 3].v.tc[0] = 0x800;
    }

    pthis->windowContentVtx[phi_t2].v.ob[0] = pthis->windowContentVtx[phi_t2 + 2].v.ob[0] = phi_t0;
    pthis->windowContentVtx[phi_t2 + 1].v.ob[0] = pthis->windowContentVtx[phi_t2 + 3].v.ob[0] =
        pthis->windowContentVtx[phi_t2].v.ob[0] + 0x40;
    pthis->windowContentVtx[phi_t2].v.ob[1] = pthis->windowContentVtx[phi_t2 + 1].v.ob[1] =
        pthis->buttonYOffsets[5] - 0x34;
    pthis->windowContentVtx[phi_t2 + 2].v.ob[1] = pthis->windowContentVtx[phi_t2 + 3].v.ob[1] =
        pthis->windowContentVtx[phi_t2].v.ob[1] - 0x10;
    pthis->windowContentVtx[phi_t2 + 1].v.tc[0] = pthis->windowContentVtx[phi_t2 + 3].v.tc[0] = 0x800;

    phi_t2 += 4;

    if (((pthis->menuMode == FS_MENU_MODE_CONFIG) && (pthis->configMode >= CM_MAIN_MENU)) ||
        ((pthis->menuMode == FS_MENU_MODE_SELECT) && (pthis->selectMode == SM_CONFIRM_FILE))) {
        if (pthis->menuMode == FS_MENU_MODE_CONFIG) {
            if ((pthis->configMode == CM_SELECT_COPY_SOURCE) || (pthis->configMode == CM_SELECT_COPY_DEST) ||
                (pthis->configMode == CM_ERASE_SELECT)) {
                phi_t5 = D_8081283C[pthis->buttonIndex];
            } else if ((pthis->configMode == CM_ERASE_CONFIRM) || (pthis->configMode == CM_COPY_CONFIRM)) {
                phi_t5 = D_80812844[pthis->buttonIndex];
            } else {
                phi_t5 = D_80812830[pthis->buttonIndex];
            }
        } else {
            phi_t5 = D_80812848[pthis->confirmButtonIndex];
        }

        pthis->windowContentVtx[phi_t2].v.ob[0] = pthis->windowContentVtx[phi_t2 + 2].v.ob[0] = pthis->windowPosX - 0xA;
        pthis->windowContentVtx[phi_t2 + 1].v.ob[0] = pthis->windowContentVtx[phi_t2 + 3].v.ob[0] =
            pthis->windowContentVtx[phi_t2].v.ob[0] + 0x48;
        pthis->windowContentVtx[phi_t2].v.ob[1] = pthis->windowContentVtx[phi_t2 + 1].v.ob[1] =
            pthis->windowContentVtx[phi_t5].v.ob[1] + 4;
        pthis->windowContentVtx[phi_t2 + 2].v.ob[1] = pthis->windowContentVtx[phi_t2 + 3].v.ob[1] =
            pthis->windowContentVtx[phi_t2].v.ob[1] - 0x18;
        pthis->windowContentVtx[phi_t2 + 1].v.tc[0] = pthis->windowContentVtx[phi_t2 + 3].v.tc[0] = 0x900;
        pthis->windowContentVtx[phi_t2 + 2].v.tc[1] = pthis->windowContentVtx[phi_t2 + 3].v.tc[1] = 0x300;
    }

    pthis->windowContentVtx[phi_t2 + 4].v.ob[0] = pthis->windowContentVtx[phi_t2 + 6].v.ob[0] = pthis->windowPosX + 0x3A;
    pthis->windowContentVtx[phi_t2 + 5].v.ob[0] = pthis->windowContentVtx[phi_t2 + 7].v.ob[0] =
        pthis->windowContentVtx[phi_t2 + 4].v.ob[0] + 0x80;
    pthis->windowContentVtx[phi_t2 + 4].v.ob[1] = pthis->windowContentVtx[phi_t2 + 5].v.ob[1] =
        pthis->windowContentVtx[D_80812830[pthis->warningButtonIndex]].v.ob[1];
    pthis->windowContentVtx[phi_t2 + 6].v.ob[1] = pthis->windowContentVtx[phi_t2 + 7].v.ob[1] =
        pthis->windowContentVtx[phi_t2 + 4].v.ob[1] - 0x10;
    pthis->windowContentVtx[phi_t2 + 5].v.tc[0] = pthis->windowContentVtx[phi_t2 + 7].v.tc[0] = 0x1000;
}

static u16 D_8081284C[] = { 0x007C, 0x0124, 0x01CC };

static void* sQuestItemTextures[] = {
    gFileSelKokiriEmeraldTex,   gFileSelGoronRubyTex,       gFileSelZoraSapphireTex,
    gFileSelForestMedallionTex, gFileSelFireMedallionTex,   gFileSelWaterMedallionTex,
    gFileSelSpiritMedallionTex, gFileSelShadowMedallionTex, gFileSelLightMedallionTex,
};

static s16 sQuestItemRed[] = { 255, 255, 255, 0, 255, 0, 255, 200, 200 };
static s16 sQuestItemGreen[] = { 255, 255, 255, 255, 60, 100, 130, 50, 200 };
static s16 sQuestItemBlue[] = { 255, 255, 255, 0, 0, 255, 0, 255, 0 };
static s16 sQuestItemFlags[] = { 0x0012, 0x0013, 0x0014, 0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005 };
static s16 sNamePrimColors[2][3] = { { 255, 255, 255 }, { 100, 100, 100 } };
static void* sHeartTextures[] = { gHeartFullTex, gDefenseHeartFullTex };
static s16 sHeartPrimColors[2][3] = { { 255, 70, 50 }, { 200, 0, 0 } };
static s16 sHeartEnvColors[2][3] = { { 50, 40, 60 }, { 255, 255, 255 } };

void FileChoose_DrawFileInfo(GameState* pthisx, s16 fileIndex, s16 isActive) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;
    Font* sp54 = &pthis->font;
    s32 heartType;
    s16 i;
    s16 vtxOffset;
    s16 j;
    s16 deathCountSplit[3];

    if (1) {}

    OPEN_DISPS(pthis->state.gfxCtx, "../z_file_choose.c", 1709);

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetCombineLERP(POLY_OPA_DISP++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0,
                      PRIMITIVE, 0);

    // draw file name
    if (pthis->nameAlpha[fileIndex] != 0) {
        gSPVertex(POLY_OPA_DISP++, &pthis->windowContentVtx[D_8081284C[fileIndex]], 32, 0);
        gDPSetPrimColor(POLY_OPA_DISP++, 0x00, 0x00, sNamePrimColors[isActive][0], sNamePrimColors[isActive][1],
                        sNamePrimColors[isActive][2], pthis->nameAlpha[fileIndex]);

        for (i = 0, vtxOffset = 0; vtxOffset < 0x20; i++, vtxOffset += 4) {
            FileChoose_DrawCharacter(pthis->state.gfxCtx,
                                     sp54->fontBuf + pthis->fileNames[fileIndex][i] * FONT_CHAR_TEX_SIZE, vtxOffset);
        }
    }

    if ((fileIndex == pthis->selectedFileIndex) || (fileIndex == pthis->copyDestFileIndex)) {
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetCombineLERP(POLY_OPA_DISP++, 1, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, 1, 0, PRIMITIVE, 0, TEXEL0, 0,
                          PRIMITIVE, 0);
        gDPSetPrimColor(POLY_OPA_DISP++, 0x00, 0x00, 255, 255, 255, pthis->fileInfoAlpha[fileIndex]);
        gSPVertex(POLY_OPA_DISP++, &pthis->windowContentVtx[D_8081284C[fileIndex]] + 0x24, 12, 0);

        FileChoose_SplitNumber(pthis->deaths[fileIndex], &deathCountSplit[0], &deathCountSplit[1], &deathCountSplit[2]);

        // draw death count
        for (i = 0, vtxOffset = 0; i < 3; i++, vtxOffset += 4) {
            FileChoose_DrawCharacter(pthis->state.gfxCtx, sp54->fontBuf + deathCountSplit[i] * FONT_CHAR_TEX_SIZE,
                                     vtxOffset);
        }

        gDPPipeSync(POLY_OPA_DISP++);

        heartType = (pthis->defense[fileIndex] == 0) ? 0 : 1;

        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor(POLY_OPA_DISP++, 0x00, 0x00, sHeartPrimColors[heartType][0], sHeartPrimColors[heartType][1],
                        sHeartPrimColors[heartType][2], pthis->fileInfoAlpha[fileIndex]);
        gDPSetEnvColor(POLY_OPA_DISP++, sHeartEnvColors[heartType][0], sHeartEnvColors[heartType][1],
                       sHeartEnvColors[heartType][2], 255);

        i = pthis->healthCapacities[fileIndex] / 0x10;

        // draw hearts
        for (vtxOffset = 0, j = 0; j < i; j++, vtxOffset += 4) {
            gSPVertex(POLY_OPA_DISP++, &pthis->windowContentVtx[D_8081284C[fileIndex] + vtxOffset] + 0x30, 4, 0);

            POLY_OPA_DISP = FileChoose_QuadTextureIA8(POLY_OPA_DISP, sHeartTextures[heartType], 0x10, 0x10, 0);
        }

        gDPPipeSync(POLY_OPA_DISP++);

        // draw quest items
        for (vtxOffset = 0, j = 0; j < 9; j++, vtxOffset += 4) {
            if (pthis->questItems[fileIndex] & gBitFlags[sQuestItemFlags[j]]) {
                gSPVertex(POLY_OPA_DISP++, &pthis->windowContentVtx[D_8081284C[fileIndex] + vtxOffset] + 0x80, 4, 0);
                gDPPipeSync(POLY_OPA_DISP++);
                gDPSetPrimColor(POLY_OPA_DISP++, 0x00, 0x00, sQuestItemRed[j], sQuestItemGreen[j], sQuestItemBlue[j],
                                pthis->fileInfoAlpha[fileIndex]);
                gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);

                if (j < 3) {
                    gDPLoadTextureBlock(POLY_OPA_DISP++, sQuestItemTextures[j], G_IM_FMT_RGBA, G_IM_SIZ_32b, 16, 16, 0,
                                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP,
                                        G_TX_NOMASK, G_TX_NOLOD);
                    gSP1Quadrangle(POLY_OPA_DISP++, 0, 2, 3, 1, 0);

                } else {
                    POLY_OPA_DISP = FileChoose_QuadTextureIA8(POLY_OPA_DISP, sQuestItemTextures[j], 0x10, 0x10, 0);
                }
            }
        }
    }

    CLOSE_DISPS(pthis->state.gfxCtx, "../z_file_choose.c", 1797);
}

static void* sFileInfoBoxTextures[] = {
    gFileSelFileInfoBox1Tex, gFileSelFileInfoBox2Tex, gFileSelFileInfoBox3Tex,
    gFileSelFileInfoBox4Tex, gFileSelFileInfoBox5Tex,
};

static void* sTitleLabels[3][9] = {
    { gFileSelPleaseSelectAFileENGTex, gFileSelOpenThisFileENGTex, gFileSelCopyWhichFileENGTex,
      gFileSelCopyToWhichFileENGTex, gFileSelAreYouSureENGTex, gFileSelFileCopiedENGTex, gFileSelEraseWhichFileENGTex,
      gFileSelAreYouSure2ENGTex, gFileSelFileErasedENGTex },
    { gFileSelPleaseSelectAFileGERTex, gFileSelOpenThisFileGERTex, gFileSelWhichFile1GERTex,
      gFileSelCopyToWhichFileGERTex, gFileSelAreYouSureGERTex, gFileSelFileCopiedGERTex, gFileSelWhichFile2GERTex,
      gFileSelAreYouSure2GERTex, gFileSelFileErasedGERTex },
    { gFileSelPleaseSelectAFileFRATex, gFileSelOpenThisFileFRATex, gFileSelCopyWhichFileFRATex,
      gFileSelCopyToWhichFileFRATex, gFileSelAreYouSureFRATex, gFileSelFileCopiedFRATex, gFileSelEraseWhichFileFRATex,
      gFileSelAreYouSure2FRATex, gFileSelFileErasedFRATex }
};

static void* sWarningLabels[3][5] = {
    { gFileSelNoFileToCopyENGTex, gFileSelNoFileToEraseENGTex, gFileSelNoEmptyFileENGTex, gFileSelFileEmptyENGTex,
      gFileSelFileInUseENGTex },
    { gFileSelNoFileToCopyGERTex, gFileSelNoFileToEraseGERTex, gFileSelNoEmptyFileGERTex, gFileSelFileEmptyGERTex,
      gFileSelFileInUseGERTex },
    { gFileSelNoFileToCopyFRATex, gFileSelNoFileToEraseFRATex, gFileSelNoEmptyFileFRATex, gFileSelFileEmptyFRATex,
      gFileSelFileInUseFRATex },
};

static void* sFileButtonTextures[3][3] = {
    { gFileSelFile1ButtonENGTex, gFileSelFile2ButtonENGTex, gFileSelFile3ButtonENGTex },
    { gFileSelFile1ButtonGERTex, gFileSelFile2ButtonGERTex, gFileSelFile3ButtonGERTex },
    { gFileSelFile1ButtonFRATex, gFileSelFile2ButtonFRATex, gFileSelFile3ButtonFRATex },
};

static void* sActionButtonTextures[3][4] = {
    { gFileSelCopyButtonENGTex, gFileSelEraseButtonENGTex, gFileSelYesButtonENGTex, gFileSelQuitButtonENGTex },
    { gFileSelCopyButtonGERTex, gFileSelEraseButtonGERTex, gFileSelYesButtonGERTex, gFileSelQuitButtonGERTex },
    { gFileSelCopyButtonFRATex, gFileSelEraseButtonFRATex, gFileSelYesButtonFRATex, gFileSelQuitButtonFRATex },
};

static void* sOptionsButtonTextures[] = {
    gFileSelOptionsButtonENGTex,
    gFileSelOptionsButtonGERTex,
    gFileSelOptionsButtonENGTex,
};

/**
 * Draw most window contents including buttons, labels, and icons.
 * Does not include anything from the keyboard and settings windows.
 */
void FileChoose_DrawWindowContents(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;
    s16 fileIndex;
    s16 temp;
    s16 i;
    s16 quadVtxIndex;
    s16 isActive;
    s16 pad;

    OPEN_DISPS(pthis->state.gfxCtx, "../z_file_choose.c", 1940);

    // draw title label
    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE,
                      ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pthis->titleAlpha[0]);
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);
    gSPVertex(POLY_OPA_DISP++, pthis->windowContentVtx, 4, 0);
    gDPLoadTextureBlock(POLY_OPA_DISP++, sTitleLabels[gSaveContext.language][pthis->titleLabel], G_IM_FMT_IA,
                        G_IM_SIZ_8b, 128, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                        G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSP1Quadrangle(POLY_OPA_DISP++, 0, 2, 3, 1, 0);

    // draw next title label
    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pthis->titleAlpha[1]);
    gDPLoadTextureBlock(POLY_OPA_DISP++, sTitleLabels[gSaveContext.language][pthis->nextTitleLabel], G_IM_FMT_IA,
                        G_IM_SIZ_8b, 128, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                        G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSP1Quadrangle(POLY_OPA_DISP++, 0, 2, 3, 1, 0);

    temp = 4;

    gDPPipeSync(POLY_OPA_DISP++);

    // draw file info box (large box when a file is selected)
    for (fileIndex = 0; fileIndex < 3; fileIndex++, temp += 20) {
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, pthis->windowColor[0], pthis->windowColor[1], pthis->windowColor[2],
                        pthis->fileInfoAlpha[fileIndex]);
        gSPVertex(POLY_OPA_DISP++, &pthis->windowContentVtx[temp], 20, 0);

        for (quadVtxIndex = 0, i = 0; i < 5; i++, quadVtxIndex += 4) {
            gDPLoadTextureBlock(POLY_OPA_DISP++, sFileInfoBoxTextures[i], G_IM_FMT_IA, G_IM_SIZ_16b,
                                sFileInfoBoxPartWidths[i], 56, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSP1Quadrangle(POLY_OPA_DISP++, quadVtxIndex, quadVtxIndex + 2, quadVtxIndex + 3, quadVtxIndex + 1, 0);
        }
    }

    for (i = 0; i < 3; i++, temp += 20) {
        // draw file button
        gSPVertex(POLY_OPA_DISP++, &pthis->windowContentVtx[temp], 20, 0);

        isActive = ((pthis->n64ddFlag == pthis->n64ddFlags[i]) || (pthis->nameBoxAlpha[i] == 0)) ? 0 : 1;

        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, sWindowContentColors[isActive][0], sWindowContentColors[isActive][1],
                        sWindowContentColors[isActive][2], pthis->fileButtonAlpha[i]);
        gDPLoadTextureBlock(POLY_OPA_DISP++, sFileButtonTextures[gSaveContext.language][i], G_IM_FMT_IA, G_IM_SIZ_16b,
                            64, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSP1Quadrangle(POLY_OPA_DISP++, 0, 2, 3, 1, 0);

        // draw file name box
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, sWindowContentColors[isActive][0], sWindowContentColors[isActive][1],
                        sWindowContentColors[isActive][2], pthis->nameBoxAlpha[i]);
        gDPLoadTextureBlock(POLY_OPA_DISP++, gFileSelNameBoxTex, G_IM_FMT_IA, G_IM_SIZ_16b, 108, 16, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSP1Quadrangle(POLY_OPA_DISP++, 4, 6, 7, 5, 0);

        // draw disk label for 64DD
        if (pthis->n64ddFlags[i]) {
            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, sWindowContentColors[isActive][0], sWindowContentColors[isActive][1],
                            sWindowContentColors[isActive][2], pthis->nameAlpha[i]);
            gDPLoadTextureBlock(POLY_OPA_DISP++, gFileSelDISKButtonTex, G_IM_FMT_IA, G_IM_SIZ_16b, 44, 16, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            gSP1Quadrangle(POLY_OPA_DISP++, 8, 10, 11, 9, 0);
        }

        // draw connectors
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, sWindowContentColors[isActive][0], sWindowContentColors[isActive][1],
                        sWindowContentColors[isActive][2], pthis->connectorAlpha[i]);
        gDPLoadTextureBlock(POLY_OPA_DISP++, gFileSelConnectorTex, G_IM_FMT_IA, G_IM_SIZ_8b, 24, 16, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSP1Quadrangle(POLY_OPA_DISP++, 12, 14, 15, 13, 0);

        if (pthis->n64ddFlags[i]) {
            gSP1Quadrangle(POLY_OPA_DISP++, 16, 18, 19, 17, 0);
        }
    }

    // draw file info
    for (fileIndex = 0; fileIndex < 3; fileIndex++) {
        isActive = ((pthis->n64ddFlag == pthis->n64ddFlags[fileIndex]) || (pthis->nameBoxAlpha[fileIndex] == 0)) ? 0 : 1;
        FileChoose_DrawFileInfo(&pthis->state, fileIndex, isActive);
    }

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE,
                      ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);
    gSPVertex(POLY_OPA_DISP++, &pthis->windowContentVtx[0x274], 20, 0);

    // draw primary action buttons (copy/erase)
    for (quadVtxIndex = 0, i = 0; i < 2; i++, quadVtxIndex += 4) {
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, pthis->windowColor[0], pthis->windowColor[1], pthis->windowColor[2],
                        pthis->actionButtonAlpha[i]);
        gDPLoadTextureBlock(POLY_OPA_DISP++, sActionButtonTextures[gSaveContext.language][i], G_IM_FMT_IA, G_IM_SIZ_16b,
                            64, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSP1Quadrangle(POLY_OPA_DISP++, quadVtxIndex, quadVtxIndex + 2, quadVtxIndex + 3, quadVtxIndex + 1, 0);
    }

    gDPPipeSync(POLY_OPA_DISP++);

    // draw confirm buttons (yes/quit)
    for (quadVtxIndex = 0, i = 0; i < 2; i++, quadVtxIndex += 4) {
        temp = pthis->confirmButtonTexIndices[i];

        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, pthis->windowColor[0], pthis->windowColor[1], pthis->windowColor[2],
                        pthis->confirmButtonAlpha[i]);
        gDPLoadTextureBlock(POLY_OPA_DISP++, sActionButtonTextures[gSaveContext.language][temp], G_IM_FMT_IA,
                            G_IM_SIZ_16b, 64, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                            G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSP1Quadrangle(POLY_OPA_DISP++, quadVtxIndex, quadVtxIndex + 2, quadVtxIndex + 3, quadVtxIndex + 1, 0);
    }

    // draw options button
    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, pthis->windowColor[0], pthis->windowColor[1], pthis->windowColor[2],
                    pthis->optionButtonAlpha);
    gDPLoadTextureBlock(POLY_OPA_DISP++, sOptionsButtonTextures[gSaveContext.language], G_IM_FMT_IA, G_IM_SIZ_16b, 64,
                        16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                        G_TX_NOLOD, G_TX_NOLOD);
    gSP1Quadrangle(POLY_OPA_DISP++, 8, 10, 11, 9, 0);

    // draw highlight over currently selected button
    if (((pthis->menuMode == FS_MENU_MODE_CONFIG) &&
         ((pthis->configMode == CM_MAIN_MENU) || (pthis->configMode == CM_SELECT_COPY_SOURCE) ||
          (pthis->configMode == CM_SELECT_COPY_DEST) || (pthis->configMode == CM_COPY_CONFIRM) ||
          (pthis->configMode == CM_ERASE_SELECT) || (pthis->configMode == CM_ERASE_CONFIRM))) ||
        ((pthis->menuMode == FS_MENU_MODE_SELECT) && (pthis->selectMode == SM_CONFIRM_FILE))) {
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetCombineLERP(POLY_OPA_DISP++, 1, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, 1, 0, PRIMITIVE, 0, TEXEL0, 0,
                          PRIMITIVE, 0);
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, pthis->highlightColor[0], pthis->highlightColor[1],
                        pthis->highlightColor[2], pthis->highlightColor[3]);
        gDPLoadTextureBlock(POLY_OPA_DISP++, gFileSelBigButtonHighlightTex, G_IM_FMT_I, G_IM_SIZ_8b, 72, 24, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSP1Quadrangle(POLY_OPA_DISP++, 12, 14, 15, 13, 0);
    }

    // draw warning labels
    if (pthis->warningLabel > FS_WARNING_NONE) {
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pthis->emptyFileTextAlpha);
        gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);
        gDPLoadTextureBlock(POLY_OPA_DISP++, sWarningLabels[gSaveContext.language][pthis->warningLabel], G_IM_FMT_IA,
                            G_IM_SIZ_8b, 128, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                            G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSP1Quadrangle(POLY_OPA_DISP++, 16, 18, 19, 17, 0);
    }

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIDECALA, G_CC_MODULATEIDECALA);

    CLOSE_DISPS(pthis->state.gfxCtx, "../z_file_choose.c", 2198);
}

void FileChoose_ConfigModeDraw(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;
    f32 eyeX;
    f32 eyeY;
    f32 eyeZ;

    OPEN_DISPS(pthis->state.gfxCtx, "../z_file_choose.c", 2218);
    gDPPipeSync(POLY_OPA_DISP++);

    eyeX = 1000.0f * Math_CosS(ZREG(11)) - 1000.0f * Math_SinS(ZREG(11));
    eyeY = ZREG(13);
    eyeZ = 1000.0f * Math_SinS(ZREG(11)) + 1000.0f * Math_CosS(ZREG(11));

    FileChoose_SetView(pthis, eyeX, eyeY, eyeZ);
    SkyboxDraw_Draw(&pthis->skyboxCtx, pthis->state.gfxCtx, 1, pthis->envCtx.skyboxBlend, eyeX, eyeY, eyeZ);
    gDPSetTextureLUT(POLY_OPA_DISP++, G_TT_NONE);
    ZREG(11) += ZREG(10);
    Environment_UpdateSkybox(SKYBOX_NORMAL_SKY, &pthis->envCtx, &pthis->skyboxCtx);
    gDPPipeSync(POLY_OPA_DISP++);
    func_800949A8(pthis->state.gfxCtx);
    FileChoose_SetView(pthis, 0.0f, 0.0f, 64.0f);
    FileChoose_SetWindowVtx(&pthis->state);
    FileChoose_SetWindowContentVtx(&pthis->state);

    if ((pthis->configMode != CM_NAME_ENTRY) && (pthis->configMode != CM_START_NAME_ENTRY)) {
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, pthis->windowColor[0], pthis->windowColor[1], pthis->windowColor[2],
                        pthis->windowAlpha);
        gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);

        Matrix_Translate(0.0f, 0.0f, -93.6f, MTXMODE_NEW);
        Matrix_Scale(0.78f, 0.78f, 0.78f, MTXMODE_APPLY);

        if (pthis->windowRot != 0) {
            Matrix_RotateX(pthis->windowRot / 100.0f, MTXMODE_APPLY);
        }

        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(pthis->state.gfxCtx, "../z_file_choose.c", 2282),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gSPVertex(POLY_OPA_DISP++, &pthis->windowVtx[0], 32, 0);
        gSPDisplayList(POLY_OPA_DISP++, gFileSelWindow1DL);

        gSPVertex(POLY_OPA_DISP++, &pthis->windowVtx[32], 32, 0);
        gSPDisplayList(POLY_OPA_DISP++, gFileSelWindow2DL);

        gSPVertex(POLY_OPA_DISP++, &pthis->windowVtx[64], 16, 0);
        gSPDisplayList(POLY_OPA_DISP++, gFileSelWindow3DL);

        gDPPipeSync(POLY_OPA_DISP++);

        FileChoose_DrawWindowContents(&pthis->state);
    }

    // draw name entry menu
    if ((pthis->configMode >= CM_ROTATE_TO_NAME_ENTRY) && (pthis->configMode <= CM_NAME_ENTRY_TO_MAIN)) {
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, pthis->windowColor[0], pthis->windowColor[1], pthis->windowColor[2],
                        pthis->windowAlpha);
        gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);

        Matrix_Translate(0.0f, 0.0f, -93.6f, MTXMODE_NEW);
        Matrix_Scale(0.78f, 0.78f, 0.78f, MTXMODE_APPLY);
        Matrix_RotateX((pthis->windowRot - 314.0f) / 100.0f, MTXMODE_APPLY);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(pthis->state.gfxCtx, "../z_file_choose.c", 2316),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gSPVertex(POLY_OPA_DISP++, &pthis->windowVtx[0], 32, 0);
        gSPDisplayList(POLY_OPA_DISP++, gFileSelWindow1DL);

        gSPVertex(POLY_OPA_DISP++, &pthis->windowVtx[32], 32, 0);
        gSPDisplayList(POLY_OPA_DISP++, gFileSelWindow2DL);

        gSPVertex(POLY_OPA_DISP++, &pthis->windowVtx[64], 16, 0);
        gSPDisplayList(POLY_OPA_DISP++, gFileSelWindow3DL);

        gDPPipeSync(POLY_OPA_DISP++);

        FileChoose_DrawNameEntry(&pthis->state);
    }

    // draw options menu
    if ((pthis->configMode >= CM_MAIN_TO_OPTIONS) && (pthis->configMode <= CM_OPTIONS_TO_MAIN)) {
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, pthis->windowColor[0], pthis->windowColor[1], pthis->windowColor[2],
                        pthis->windowAlpha);
        gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);

        Matrix_Translate(0.0f, 0.0f, -93.6f, MTXMODE_NEW);
        Matrix_Scale(0.78f, 0.78f, 0.78f, MTXMODE_APPLY);
        Matrix_RotateX((pthis->windowRot - 314.0f) / 100.0f, MTXMODE_APPLY);

        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(pthis->state.gfxCtx, "../z_file_choose.c", 2337),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gSPVertex(POLY_OPA_DISP++, &pthis->windowVtx[0], 32, 0);
        gSPDisplayList(POLY_OPA_DISP++, gFileSelWindow1DL);

        gSPVertex(POLY_OPA_DISP++, &pthis->windowVtx[32], 32, 0);
        gSPDisplayList(POLY_OPA_DISP++, gFileSelWindow2DL);

        gSPVertex(POLY_OPA_DISP++, &pthis->windowVtx[64], 16, 0);
        gSPDisplayList(POLY_OPA_DISP++, gFileSelWindow3DL);

        gDPPipeSync(POLY_OPA_DISP++);

        FileChoose_DrawOptions(&pthis->state);
    }

    gDPPipeSync(POLY_OPA_DISP++);
    FileChoose_SetView(pthis, 0.0f, 0.0f, 64.0f);

    CLOSE_DISPS(pthis->state.gfxCtx, "../z_file_choose.c", 2352);
}

/**
 * Fade out the main menu elements to transition to select mode.
 * Update function for `SM_FADE_MAIN_TO_SELECT`
 */
void FileChoose_FadeMainToSelect(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;
    SramContext* sramCtx = &pthis->sramCtx;
    s16 i;

    for (i = 0; i < 3; i++) {
        if (i != pthis->buttonIndex) {
            pthis->fileButtonAlpha[i] -= 25;
            pthis->actionButtonAlpha[FS_BTN_ACTION_COPY] = pthis->actionButtonAlpha[FS_BTN_ACTION_ERASE] =
                pthis->optionButtonAlpha = pthis->fileButtonAlpha[i];

            if (SLOT_OCCUPIED(sramCtx, i)) {
                pthis->nameAlpha[i] = pthis->nameBoxAlpha[i] = pthis->fileButtonAlpha[i];
                pthis->connectorAlpha[i] -= 31;
            }
        }
    }

    pthis->titleAlpha[0] -= 31;
    pthis->titleAlpha[1] += 31;
    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        pthis->actionTimer = 8;
        pthis->selectMode++;
        pthis->confirmButtonIndex = FS_BTN_CONFIRM_YES;
    }
}

/**
 * Moves the selected file to the top of the window.
 * Update function for `SM_MOVE_FILE_TO_TOP`
 */
void FileChoose_MoveSelectedFileToTop(GameState* pthisx) {
    static s16 fileYOffsets[] = { 0, 16, 32 }; // amount to move by to reach the top of the screen
    FileChooseContext* pthis = (FileChooseContext*)pthisx;
    s16 yStep;

    yStep = ABS(pthis->buttonYOffsets[pthis->buttonIndex] - fileYOffsets[pthis->buttonIndex]) / pthis->actionTimer;
    pthis->buttonYOffsets[pthis->buttonIndex] += yStep;
    pthis->actionTimer--;

    if ((pthis->actionTimer == 0) || (pthis->buttonYOffsets[pthis->buttonIndex] == fileYOffsets[pthis->buttonIndex])) {
        pthis->buttonYOffsets[FS_BTN_SELECT_YES] = pthis->buttonYOffsets[FS_BTN_SELECT_QUIT] = -24;
        pthis->actionTimer = 8;
        pthis->selectMode++;
    }
}

/**
 * Fade in the file info for the selected file.
 * Update function for `SM_FADE_IN_FILE_INFO`
 */
void FileChoose_FadeInFileInfo(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;

    pthis->fileInfoAlpha[pthis->buttonIndex] += 25;
    pthis->nameBoxAlpha[pthis->buttonIndex] -= 50;

    if (pthis->nameBoxAlpha[pthis->buttonIndex] <= 0) {
        pthis->nameBoxAlpha[pthis->buttonIndex] = 0;
    }

    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        pthis->fileInfoAlpha[pthis->buttonIndex] = 200;
        pthis->actionTimer = 8;
        pthis->selectMode++;
    }

    pthis->confirmButtonAlpha[FS_BTN_CONFIRM_YES] = pthis->confirmButtonAlpha[FS_BTN_CONFIRM_QUIT] =
        pthis->fileInfoAlpha[pthis->buttonIndex];
}

/**
 * Update the cursor and handle the option that the player picks for confirming the selected file.
 * Update function for `SM_CONFIRM_FILE`
 */
void FileChoose_ConfirmFile(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;
    Input* input = &pthis->state.input[0];

    if (CHECK_BTN_ALL(input->press.button, BTN_START) || (CHECK_BTN_ALL(input->press.button, BTN_A))) {
        if (pthis->confirmButtonIndex == FS_BTN_CONFIRM_YES) {
            func_800AA000(300.0f, 180, 20, 100);
            Audio_PlaySoundGeneral(NA_SE_SY_FSEL_DECIDE_L, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
            pthis->selectMode = SM_FADE_OUT;
            func_800F6964(0xF);
        } else {
            Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CLOSE, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
            pthis->selectMode++;
        }
    } else if (CHECK_BTN_ALL(input->press.button, BTN_B)) {
        Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CLOSE, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        pthis->selectMode++;
    } else if (ABS(pthis->stickRelY) >= 30) {
        Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        pthis->confirmButtonIndex ^= 1;
    }
}

/**
 * Fade out the file info for the selected file before returning to the main menu.
 * Update function for `SM_FADE_OUT_FILE_INFO`
 */
void FileChoose_FadeOutFileInfo(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;

    pthis->fileInfoAlpha[pthis->buttonIndex] -= 25;
    pthis->nameBoxAlpha[pthis->buttonIndex] += 25;
    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        pthis->buttonYOffsets[FS_BTN_SELECT_YES] = pthis->buttonYOffsets[FS_BTN_SELECT_QUIT] = 0;
        pthis->nameBoxAlpha[pthis->buttonIndex] = 200;
        pthis->fileInfoAlpha[pthis->buttonIndex] = 0;
        pthis->nextTitleLabel = FS_TITLE_SELECT_FILE;
        pthis->actionTimer = 8;
        pthis->selectMode++;
    }

    pthis->confirmButtonAlpha[0] = pthis->confirmButtonAlpha[1] = pthis->fileInfoAlpha[pthis->buttonIndex];
}

/**
 * Move the selected file back to the slot position then go to config mode for the main menu.
 * Update function for `SM_MOVE_FILE_TO_SLOT`
 */
void FileChoose_MoveSelectedFileToSlot(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;
    SramContext* sramCtx = &pthis->sramCtx;
    s16 yStep;
    s16 i;

    yStep = ABS(pthis->buttonYOffsets[pthis->buttonIndex]) / pthis->actionTimer;
    pthis->buttonYOffsets[pthis->buttonIndex] -= yStep;

    if (pthis->buttonYOffsets[pthis->buttonIndex] <= 0) {
        pthis->buttonYOffsets[pthis->buttonIndex] = 0;
    }

    for (i = 0; i < 3; i++) {
        if (i != pthis->buttonIndex) {
            pthis->fileButtonAlpha[i] += 25;

            if (pthis->fileButtonAlpha[i] >= 200) {
                pthis->fileButtonAlpha[i] = 200;
            }

            pthis->actionButtonAlpha[FS_BTN_ACTION_COPY] = pthis->actionButtonAlpha[FS_BTN_ACTION_ERASE] =
                pthis->optionButtonAlpha = pthis->fileButtonAlpha[i];

            if (SLOT_OCCUPIED(sramCtx, i)) {
                pthis->nameBoxAlpha[i] = pthis->nameAlpha[i] = pthis->fileButtonAlpha[i];
                pthis->connectorAlpha[i] += 31;
            }
        }
    }

    pthis->titleAlpha[0] -= 31;
    pthis->titleAlpha[1] += 31;
    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        pthis->titleAlpha[0] = 255;
        pthis->titleAlpha[1] = 0;
        pthis->titleLabel = pthis->nextTitleLabel;
        pthis->actionTimer = 8;
        pthis->menuMode = FS_MENU_MODE_CONFIG;
        pthis->configMode = CM_MAIN_MENU;
        pthis->nextConfigMode = CM_MAIN_MENU;
        pthis->selectMode = SM_FADE_MAIN_TO_SELECT;
    }
}

/**
 * Fill the screen with black to fade out.
 * Update function for `SM_FADE_OUT`
 */
void FileChoose_FadeOut(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;

    sScreenFillAlpha += VREG(10);

    if (sScreenFillAlpha >= 255) {
        sScreenFillAlpha = 255;
        pthis->selectMode++;
    }
}

/**
 * Load the save for the appropriate file and start the game.
 * Note: On Debug ROM, File 1 will go to Map Select.
 * Update function for `SM_LOAD_GAME`
 */
void FileChoose_LoadGame(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;
    u16 swordEquipMask;
    s32 pad;

    if (pthis->buttonIndex == FS_BTN_SELECT_FILE_1) {
        Audio_PlaySoundGeneral(NA_SE_SY_FSEL_DECIDE_L, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        gSaveContext.fileNum = pthis->buttonIndex;
        Sram_OpenSave(&pthis->sramCtx);
        gSaveContext.gameMode = 0;
        SET_NEXT_GAMESTATE(&pthis->state, Select_Init, SelectContext);
        pthis->state.running = false;
    } else {
        Audio_PlaySoundGeneral(NA_SE_SY_FSEL_DECIDE_L, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        gSaveContext.fileNum = pthis->buttonIndex;
        Sram_OpenSave(&pthis->sramCtx);
        gSaveContext.gameMode = 0;
        SET_NEXT_GAMESTATE(&pthis->state, Gameplay_Init, GlobalContext);
        pthis->state.running = false;
    }

    gSaveContext.respawn[0].entranceIndex = -1;
    gSaveContext.respawnFlag = 0;
    gSaveContext.seqId = (u8)NA_BGM_DISABLED;
    gSaveContext.natureAmbienceId = 0xFF;
    gSaveContext.showTitleCard = true;
    gSaveContext.dogParams = 0;
    gSaveContext.timer1State = 0;
    gSaveContext.timer2State = 0;
    gSaveContext.eventInf[0] = 0;
    gSaveContext.eventInf[1] = 0;
    gSaveContext.eventInf[2] = 0;
    gSaveContext.eventInf[3] = 0;
    gSaveContext.unk_13EE = 0x32;
    gSaveContext.nayrusLoveTimer = 0;
    gSaveContext.healthAccumulator = 0;
    gSaveContext.unk_13F0 = 0;
    gSaveContext.unk_13F2 = 0;
    gSaveContext.forcedSeqId = NA_BGM_GENERAL_SFX;
    gSaveContext.skyboxTime = 0;
    gSaveContext.nextTransition = 0xFF;
    gSaveContext.nextCutsceneIndex = 0xFFEF;
    gSaveContext.cutsceneTrigger = 0;
    gSaveContext.chamberCutsceneNum = 0;
    gSaveContext.nextDayTime = 0xFFFF;
    gSaveContext.unk_13C3 = 0;

    gSaveContext.buttonStatus[0] = gSaveContext.buttonStatus[1] = gSaveContext.buttonStatus[2] =
        gSaveContext.buttonStatus[3] = gSaveContext.buttonStatus[4] = BTN_ENABLED;

    gSaveContext.unk_13E7 = gSaveContext.unk_13E8 = gSaveContext.unk_13EA = gSaveContext.unk_13EC =
        gSaveContext.unk_13F4 = 0;

    gSaveContext.unk_13F6 = gSaveContext.magic;
    gSaveContext.magic = 0;
    gSaveContext.magicLevel = gSaveContext.magic;

    if (1) {}

    osSyncPrintf(VT_FGCOL(GREEN));
    osSyncPrintf("Z_MAGIC_NOW_NOW=%d  MAGIC_NOW=%d\n", ((void)0, gSaveContext.unk_13F6), gSaveContext.magic);
    osSyncPrintf(VT_RST);

    gSaveContext.naviTimer = 0;

    if ((gSaveContext.equips.buttonItems[0] != ITEM_SWORD_KOKIRI) &&
        (gSaveContext.equips.buttonItems[0] != ITEM_SWORD_MASTER) &&
        (gSaveContext.equips.buttonItems[0] != ITEM_SWORD_BGS) &&
        (gSaveContext.equips.buttonItems[0] != ITEM_SWORD_KNIFE)) {

        gSaveContext.equips.buttonItems[0] = ITEM_NONE;
        swordEquipMask = gEquipMasks[EQUIP_SWORD] & gSaveContext.equips.equipment;
        gSaveContext.equips.equipment &= gEquipNegMasks[EQUIP_SWORD];
        if(swordEquipMask != 0) {
            gSaveContext.inventory.equipment ^= (gBitFlags[swordEquipMask - 1] << gEquipShifts[EQUIP_SWORD]);
        }
    }
}

static void (*gSelectModeUpdateFuncs[])(GameState*) = {
    FileChoose_FadeMainToSelect, FileChoose_MoveSelectedFileToTop,  FileChoose_FadeInFileInfo, FileChoose_ConfirmFile,
    FileChoose_FadeOutFileInfo,  FileChoose_MoveSelectedFileToSlot, FileChoose_FadeOut,        FileChoose_LoadGame,
};

void FileChoose_SelectModeUpdate(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;

    gSelectModeUpdateFuncs[pthis->selectMode](&pthis->state);
}

void FileChoose_SelectModeDraw(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;
    f32 eyeX;
    f32 eyeY;
    f32 eyeZ;

    OPEN_DISPS(pthis->state.gfxCtx, "../z_file_choose.c", 2753);

    gDPPipeSync(POLY_OPA_DISP++);

    eyeX = 1000.0f * Math_CosS(ZREG(11)) - 1000.0f * Math_SinS(ZREG(11));
    eyeY = ZREG(13);
    eyeZ = 1000.0f * Math_SinS(ZREG(11)) + 1000.0f * Math_CosS(ZREG(11));

    FileChoose_SetView(pthis, eyeX, eyeY, eyeZ);
    SkyboxDraw_Draw(&pthis->skyboxCtx, pthis->state.gfxCtx, 1, pthis->envCtx.skyboxBlend, eyeX, eyeY, eyeZ);
    gDPSetTextureLUT(POLY_OPA_DISP++, G_TT_NONE);
    ZREG(11) += ZREG(10);
    Environment_UpdateSkybox(SKYBOX_NORMAL_SKY, &pthis->envCtx, &pthis->skyboxCtx);
    gDPPipeSync(POLY_OPA_DISP++);
    func_800949A8(pthis->state.gfxCtx);
    FileChoose_SetView(pthis, 0.0f, 0.0f, 64.0f);
    FileChoose_SetWindowVtx(&pthis->state);
    FileChoose_SetWindowContentVtx(&pthis->state);

    gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, pthis->windowColor[0], pthis->windowColor[1], pthis->windowColor[2],
                    pthis->windowAlpha);
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);

    Matrix_Translate(0.0f, 0.0f, -93.6f, MTXMODE_NEW);
    Matrix_Scale(0.78f, 0.78f, 0.78f, MTXMODE_APPLY);
    Matrix_RotateX(pthis->windowRot / 100.0f, MTXMODE_APPLY);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(pthis->state.gfxCtx, "../z_file_choose.c", 2810),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPVertex(POLY_OPA_DISP++, &pthis->windowVtx[0], 32, 0);
    gSPDisplayList(POLY_OPA_DISP++, gFileSelWindow1DL);

    gSPVertex(POLY_OPA_DISP++, &pthis->windowVtx[32], 32, 0);
    gSPDisplayList(POLY_OPA_DISP++, gFileSelWindow2DL);

    gSPVertex(POLY_OPA_DISP++, &pthis->windowVtx[64], 16, 0);
    gSPDisplayList(POLY_OPA_DISP++, gFileSelWindow3DL);

    FileChoose_DrawWindowContents(&pthis->state);
    gDPPipeSync(POLY_OPA_DISP++);
    FileChoose_SetView(pthis, 0.0f, 0.0f, 64.0f);

    CLOSE_DISPS(pthis->state.gfxCtx, "../z_file_choose.c", 2834);
}

static void (*gFileSelectDrawFuncs[])(GameState*) = {
    FileChoose_InitModeDraw,
    FileChoose_ConfigModeDraw,
    FileChoose_SelectModeDraw,
};

static void (*gFileSelectUpdateFuncs[])(GameState*) = {
    FileChoose_InitModeUpdate,
    FileChoose_ConfigModeUpdate,
    FileChoose_SelectModeUpdate,
};

void FileChoose_Main(GameState* pthisx) {
    static void* controlsTextures[] = {
        gFileSelControlsENGTex,
        gFileSelControlsGERTex,
        gFileSelControlsFRATex,
    };
    FileChooseContext* pthis = (FileChooseContext*)pthisx;
    Input* input = &pthis->state.input[0];

    OPEN_DISPS(pthis->state.gfxCtx, "../z_file_choose.c", 2898);

    pthis->n64ddFlag = 0;

    gSPSegment(POLY_OPA_DISP++, 0x00, NULL);
    gSPSegment(POLY_OPA_DISP++, 0x01, pthis->staticSegment);
    gSPSegment(POLY_OPA_DISP++, 0x02, pthis->parameterSegment);

    Gfx_ClearDisplay(pthis->state.gfxCtx, 0, 0, 0);

    pthis->stickRelX = input->rel.stick_x;
    pthis->stickRelY = input->rel.stick_y;

    if (pthis->stickRelX < -30) {
        if (pthis->stickXDir == -1) {
            pthis->inputTimerX--;
            if (pthis->inputTimerX < 0) {
                pthis->inputTimerX = 2;
            } else {
                pthis->stickRelX = 0;
            }
        } else {
            pthis->inputTimerX = 10;
            pthis->stickXDir = -1;
        }
    } else if (pthis->stickRelX > 30) {
        if (pthis->stickXDir == 1) {
            pthis->inputTimerX--;
            if (pthis->inputTimerX < 0) {
                pthis->inputTimerX = 2;
            } else {
                pthis->stickRelX = 0;
            }
        } else {
            pthis->inputTimerX = 10;
            pthis->stickXDir = 1;
        }
    } else {
        pthis->stickXDir = 0;
    }

    if (pthis->stickRelY < -30) {
        if (pthis->stickYDir == -1) {
            pthis->inputTimerY -= 1;
            if (pthis->inputTimerY < 0) {
                pthis->inputTimerY = 2;
            } else {
                pthis->stickRelY = 0;
            }
        } else {
            pthis->inputTimerY = 10;
            pthis->stickYDir = -1;
        }
    } else if (pthis->stickRelY > 30) {
        if (pthis->stickYDir == 1) {
            pthis->inputTimerY -= 1;
            if (pthis->inputTimerY < 0) {
                pthis->inputTimerY = 2;
            } else {
                pthis->stickRelY = 0;
            }
        } else {
            pthis->inputTimerY = 10;
            pthis->stickYDir = 1;
        }
    } else {
        pthis->stickYDir = 0;
    }

    pthis->emptyFileTextAlpha = 0;

    FileChoose_PulsateCursor(&pthis->state);
    gFileSelectUpdateFuncs[pthis->menuMode](&pthis->state);
    gFileSelectDrawFuncs[pthis->menuMode](&pthis->state);

    // do not draw controls text in the options menu
    if ((pthis->configMode <= CM_NAME_ENTRY_TO_MAIN) || (pthis->configMode >= CM_UNUSED_DELAY)) {
        func_800944C4(pthis->state.gfxCtx);

        gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 100, 255, 255, pthis->controlsAlpha);
        gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);
        gDPLoadTextureBlock(POLY_OPA_DISP++, controlsTextures[gSaveContext.language], G_IM_FMT_IA, G_IM_SIZ_8b, 144, 16,
                            0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(POLY_OPA_DISP++, 0x0168, 0x0330, 0x03A8, 0x0370, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
    }

    gDPPipeSync(POLY_OPA_DISP++);
    gSPDisplayList(POLY_OPA_DISP++, sScreenFillSetupDL);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 0, 0, 0, sScreenFillAlpha);
    gDPFillRectangle(POLY_OPA_DISP++, 0, 0, gScreenWidth - 1, gScreenHeight - 1);

    CLOSE_DISPS(pthis->state.gfxCtx, "../z_file_choose.c", 3035);
}

void FileChoose_InitContext(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;
    EnvironmentContext* envCtx = &pthis->envCtx;
    SramContext* sramCtx = &pthis->sramCtx;

    Sram_Alloc(&pthis->state, sramCtx);

    ZREG(7) = 32;
    ZREG(8) = 22;
    ZREG(9) = 20;
    ZREG(10) = -10;
    ZREG(11) = 0;
    ZREG(12) = 1000;
    ZREG(13) = -700;
    ZREG(14) = 164;
    ZREG(15) = 104;
    ZREG(16) = 160;
    ZREG(17) = 100;
    ZREG(18) = 162;
    ZREG(19) = 152;
    ZREG(20) = 214;

    XREG(13) = 580;
    XREG(14) = 400;
    XREG(35) = 20;
    XREG(36) = 20;
    XREG(37) = 20;
    XREG(43) = 8;
    XREG(44) = -78;
    XREG(45) = 0;
    XREG(46) = 0;
    XREG(47) = 0;
    XREG(48) = 0;
    XREG(49) = 3;
    XREG(50) = 8;
    XREG(51) = 8;
    XREG(52) = 10;
    XREG(73) = 0;

    VREG(0) = 14;
    VREG(1) = 5;
    VREG(2) = 4;
    VREG(4) = 1;
    VREG(5) = 6;
    VREG(6) = 2;
    VREG(7) = 6;
    VREG(8) = 80;

    sScreenFillAlpha = 255;

    VREG(10) = 10;
    VREG(11) = 30;
    VREG(12) = -100;
    VREG(13) = -85;
    VREG(14) = 4;
    VREG(16) = 25;
    VREG(17) = 1;
    VREG(18) = 1;
    VREG(20) = 92;
    VREG(21) = 171;
    VREG(22) = 11;
    VREG(23) = 10;
    VREG(24) = 26;
    VREG(25) = 2;
    VREG(26) = 1;
    VREG(27) = 0;
    VREG(28) = 0;
    VREG(29) = 160;
    VREG(30) = 64;
    VREG(31) = 154;
    VREG(32) = 152;
    VREG(33) = 106;

    WREG(38) = 16;
    WREG(39) = 9;
    WREG(40) = 10;
    WREG(41) = 14;
    WREG(42) = 11;
    WREG(43) = 12;

    pthis->menuMode = FS_MENU_MODE_INIT;

    pthis->buttonIndex = pthis->selectMode = pthis->selectedFileIndex = pthis->copyDestFileIndex =
        pthis->confirmButtonIndex = 0;

    pthis->confirmButtonTexIndices[0] = 2;
    pthis->confirmButtonTexIndices[1] = 3;
    pthis->titleLabel = FS_TITLE_SELECT_FILE;
    pthis->nextTitleLabel = FS_TITLE_OPEN_FILE;
    pthis->highlightPulseDir = 1;
    pthis->unk_1CAAC = 0xC;
    pthis->highlightColor[0] = 155;
    pthis->highlightColor[1] = 255;
    pthis->highlightColor[2] = 255;
    pthis->highlightColor[3] = 70;
    pthis->configMode = CM_FADE_IN_START;
    pthis->windowRot = 0.0f;
    pthis->stickXDir = pthis->inputTimerX = 0;
    pthis->stickYDir = pthis->inputTimerY = 0;
    pthis->kbdX = pthis->kbdY = pthis->charIndex = 0;
    pthis->kbdButton = FS_KBD_BTN_NONE;

    pthis->windowColor[0] = 100;
    pthis->windowColor[1] = 150;
    pthis->windowColor[2] = 255;

    pthis->windowAlpha = pthis->titleAlpha[0] = pthis->titleAlpha[1] = pthis->fileButtonAlpha[0] =
        pthis->fileButtonAlpha[1] = pthis->fileButtonAlpha[2] = pthis->nameBoxAlpha[0] = pthis->nameBoxAlpha[1] =
            pthis->nameBoxAlpha[2] = pthis->nameAlpha[0] = pthis->nameAlpha[1] = pthis->nameAlpha[2] =
                pthis->connectorAlpha[0] = pthis->connectorAlpha[1] = pthis->connectorAlpha[2] = pthis->fileInfoAlpha[0] =
                    pthis->fileInfoAlpha[1] = pthis->fileInfoAlpha[2] = pthis->actionButtonAlpha[FS_BTN_ACTION_COPY] =
                        pthis->actionButtonAlpha[FS_BTN_ACTION_ERASE] = pthis->confirmButtonAlpha[FS_BTN_CONFIRM_YES] =
                            pthis->confirmButtonAlpha[FS_BTN_CONFIRM_QUIT] = pthis->optionButtonAlpha =
                                pthis->nameEntryBoxAlpha = pthis->controlsAlpha = pthis->emptyFileTextAlpha = 0;

    pthis->windowPosX = 6;
    pthis->actionTimer = 8;
    pthis->warningLabel = FS_WARNING_NONE;

    pthis->warningButtonIndex = pthis->buttonYOffsets[0] = pthis->buttonYOffsets[1] = pthis->buttonYOffsets[2] =
        pthis->buttonYOffsets[3] = pthis->buttonYOffsets[4] = pthis->buttonYOffsets[5] = pthis->fileNamesY[0] =
            pthis->fileNamesY[1] = pthis->fileNamesY[2] = 0;

    pthis->unk_1CAD6[0] = 0;
    pthis->unk_1CAD6[1] = 3;
    pthis->unk_1CAD6[2] = 6;
    pthis->unk_1CAD6[3] = 8;
    pthis->unk_1CAD6[4] = 10;

    ShrinkWindow_SetVal(0);

    gSaveContext.skyboxTime = 0;
    gSaveContext.dayTime = 0;

    Skybox_Init(&pthis->state, &pthis->skyboxCtx, SKYBOX_NORMAL_SKY);

    gTimeIncrement = 10;

    envCtx->unk_19 = 0;
    envCtx->unk_1A = 0;
    envCtx->unk_21 = 0;
    envCtx->unk_22 = 0;
    envCtx->skyboxDmaState = SKYBOX_DMA_INACTIVE;
    envCtx->skybox1Index = 99;
    envCtx->skybox2Index = 99;
    envCtx->unk_1F = 0;
    envCtx->unk_20 = 0;
    envCtx->unk_BD = 0;
    envCtx->unk_17 = 2;
    envCtx->skyboxDisabled = 0;
    envCtx->skyboxBlend = 0;
    envCtx->unk_84 = 0.0f;
    envCtx->unk_88 = 0.0f;

    Environment_UpdateSkybox(SKYBOX_NORMAL_SKY, &pthis->envCtx, &pthis->skyboxCtx);

    gSaveContext.buttonStatus[0] = gSaveContext.buttonStatus[1] = gSaveContext.buttonStatus[2] =
        gSaveContext.buttonStatus[3] = gSaveContext.buttonStatus[4] = BTN_ENABLED;

    pthis->n64ddFlags[0] = pthis->n64ddFlags[1] = pthis->n64ddFlags[2] = pthis->defense[0] = pthis->defense[1] =
        pthis->defense[2] = 0;

    SsSram_ReadWrite(OS_K1_TO_PHYSICAL(0xA8000000), sramCtx->readBuff, SRAM_SIZE, OS_READ);

    gSaveContext.language = sramCtx->readBuff[SRAM_HEADER_LANGUAGE];

    if (gSaveContext.language >= LANGUAGE_MAX) {
        sramCtx->readBuff[SRAM_HEADER_LANGUAGE] = gSaveContext.language = LANGUAGE_ENG;
    }
}

void FileChoose_Destroy(GameState* pthisx) {
}
#include <stdio.h>
void FileChoose_Init(GameState* pthisx) {
    FileChooseContext* pthis = (FileChooseContext*)pthisx;
    u32 size = POINTER_SUB(_title_staticSegmentRomEnd, _title_staticSegmentRomStart);
    s32 pad;

    framerate_set_profile(PROFILE_FILE_CHOOSE);
    osSyncPrintf("SIZE=%x\n", size);

    pthis->staticSegment = (u8*)GameState_Alloc(&pthis->state, size, "../z_file_choose.c", 3392);
    ASSERT(pthis->staticSegment != NULL, "pthis->staticSegment != NULL", "../z_file_choose.c", 3393);
    //DmaMgr_SendRequest1(pthis->staticSegment, (u32)_title_staticSegmentRomStart, size, "../z_file_choose.c", 3394);

    size = POINTER_SUB(_parameter_staticSegmentRomEnd, _parameter_staticSegmentRomStart);
    pthis->parameterSegment = (u8*)GameState_Alloc(&pthis->state, size, "../z_file_choose.c", 3398);
    ASSERT(pthis->parameterSegment != NULL, "pthis->parameterSegment != NULL", "../z_file_choose.c", 3399);
    //DmaMgr_SendRequest1(pthis->parameterSegment, (u32)_parameter_staticSegmentRomStart, size, "../z_file_choose.c",
    //                    3400);

    Matrix_Init(&pthis->state);
    View_Init(&pthis->view, pthis->state.gfxCtx);
    pthis->state.main = FileChoose_Main;
    pthis->state.destroy = FileChoose_Destroy;
    FileChoose_InitContext(&pthis->state);
    Font_LoadOrderedFont(&pthis->font);
    Audio_QueueSeqCmd(0xF << 28 | SEQ_PLAYER_BGM_MAIN << 24 | 0xA);
    func_800F5E18(SEQ_PLAYER_BGM_MAIN, NA_BGM_FILE_SELECT, 0, 7, 1);
}
