#define INTERNAL_SRC_OVERLAYS_GAMESTATES_OVL_FILE_CHOOSE_Z_FILE_COPY_ERASE_C
#include "actor_common.h"
#include "file_choose.h"
#include "z_file_choose.h"
#include "def/code_800A9F30.h"
#include "def/audio_bank.h"
#include "def/z_common_data.h"
#include "def/z_sram.h"

extern u16 gSramSlotOffsets[];

// when choosing a file to copy or erase, the 6 main menu buttons are placed at these offsets
static s16 sChooseFileYOffsets[] = { -48, -48, -48, -24, -24, 0 };

static s16 D_8081248C[3][3] = {
    { 0, -48, -48 },
    { -64, 16, -48 },
    { -64, -64, 32 },
};

static s16 sEraseDelayTimer = 15;

/**
 * Move buttons into place for the select source screen and fade in the proper labels.
 * Update function for `CM_SETUP_COPY_SOURCE`
 */
void FileChoose_SetupCopySource(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    s16 yStep;
    s16 i;

    for (i = 0; i < 5; i++) {
        yStep = (ABS(pthis->buttonYOffsets[i] - sChooseFileYOffsets[i])) / pthis->actionTimer;

        if (pthis->buttonYOffsets[i] >= sChooseFileYOffsets[i]) {
            pthis->buttonYOffsets[i] -= yStep;
        } else {
            pthis->buttonYOffsets[i] += yStep;
        }
    }

    pthis->actionButtonAlpha[FS_BTN_ACTION_COPY] -= 25;
    pthis->actionButtonAlpha[FS_BTN_ACTION_ERASE] -= 25;
    pthis->optionButtonAlpha -= 25;
    pthis->confirmButtonAlpha[FS_BTN_CONFIRM_QUIT] += 25;
    pthis->titleAlpha[0] -= 31;
    pthis->titleAlpha[1] += 31;
    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        pthis->actionTimer = 8;

        pthis->actionButtonAlpha[FS_BTN_ACTION_COPY] = pthis->actionButtonAlpha[FS_BTN_ACTION_ERASE] =
            pthis->optionButtonAlpha = 0;

        pthis->confirmButtonAlpha[FS_BTN_CONFIRM_QUIT] = 200;
        pthis->titleLabel = pthis->nextTitleLabel;

        pthis->titleAlpha[0] = 255;
        pthis->titleAlpha[1] = 0;
        pthis->buttonIndex = FS_BTN_COPY_QUIT;
        pthis->configMode++;
    }
}

/**
 * Allow the player to select a file to copy or exit back to the main menu.
 * Update function for `CM_SELECT_COPY_SOURCE`
 */
void FileChoose_SelectCopySource(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    SramContext* sramCtx = &pthis->sramCtx;
    Input* input = &pthis->state.input[0];

    if (((pthis->buttonIndex == FS_BTN_COPY_QUIT) && CHECK_BTN_ANY(input->press.button, BTN_A | BTN_START)) ||
        CHECK_BTN_ALL(input->press.button, BTN_B)) {
        pthis->actionTimer = 8;
        pthis->buttonIndex = FS_BTN_MAIN_COPY;
        pthis->nextTitleLabel = FS_TITLE_SELECT_FILE;
        pthis->configMode = CM_COPY_RETURN_MAIN;
        pthis->warningLabel = FS_WARNING_NONE;
        Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CLOSE, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
    } else if (CHECK_BTN_ANY(input->press.button, BTN_A | BTN_START)) {
        if (SLOT_OCCUPIED(sramCtx, pthis->buttonIndex)) {
            pthis->actionTimer = 8;
            pthis->selectedFileIndex = pthis->buttonIndex;
            pthis->configMode = CM_SETUP_COPY_DEST_1;
            pthis->nextTitleLabel = FS_TITLE_COPY_TO;
            Audio_PlaySoundGeneral(NA_SE_SY_FSEL_DECIDE_L, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        } else {
            Audio_PlaySoundGeneral(NA_SE_SY_FSEL_ERROR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        }
    } else {
        if (ABS(pthis->stickRelY) >= 30) {
            Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);

            if (pthis->stickRelY >= 30) {
                pthis->buttonIndex--;

                if (pthis->buttonIndex < FS_BTN_COPY_FILE_1) {
                    pthis->buttonIndex = FS_BTN_COPY_QUIT;
                }
            } else {
                pthis->buttonIndex++;

                if (pthis->buttonIndex > FS_BTN_COPY_QUIT) {
                    pthis->buttonIndex = FS_BTN_COPY_FILE_1;
                }
            }
        }

        if (pthis->buttonIndex != FS_BTN_COPY_QUIT) {
            if (!SLOT_OCCUPIED(sramCtx, pthis->buttonIndex)) {
                pthis->warningLabel = FS_WARNING_FILE_EMPTY;
                pthis->warningButtonIndex = pthis->buttonIndex;
                pthis->emptyFileTextAlpha = 255;
            } else {
                pthis->warningLabel = FS_WARNING_NONE;
            }
        }
    }
}

/**
 * Move the menu buttons into place for the copy destination selection and switch titles.
 * Update function for `CM_SETUP_COPY_DEST_1`
 */
void FileChoose_SetupCopyDest1(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    s16 yStep;
    s16 i;

    for (i = 0; i < 3; i++) {
        yStep = ABS(pthis->buttonYOffsets[i] - D_8081248C[pthis->buttonIndex][i]) / pthis->actionTimer;

        if (D_8081248C[pthis->buttonIndex][i] >= pthis->buttonYOffsets[i]) {
            pthis->buttonYOffsets[i] += yStep;
        } else {
            pthis->buttonYOffsets[i] -= yStep;
        }
    }

    pthis->titleAlpha[0] -= 31;
    pthis->titleAlpha[1] += 31;
    pthis->nameBoxAlpha[pthis->buttonIndex] -= 25;

    pthis->actionTimer--;
    if (pthis->actionTimer == 0) {
        pthis->buttonYOffsets[pthis->buttonIndex] = D_8081248C[pthis->buttonIndex][pthis->buttonIndex];
        pthis->titleLabel = pthis->nextTitleLabel;
        pthis->titleAlpha[0] = 255;
        pthis->titleAlpha[1] = 0;
        pthis->actionTimer = 8;
        pthis->configMode++;
    }
}

/**
 * Show the file info of the file selected to copy from.
 * Update function for `CM_SETUP_COPY_DEST_2`
 */
void FileChoose_SetupCopyDest2(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;

    pthis->nameBoxAlpha[pthis->buttonIndex] -= 25;
    pthis->fileInfoAlpha[pthis->buttonIndex] += 25;
    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        pthis->nameBoxAlpha[pthis->buttonIndex] = 0;
        pthis->fileInfoAlpha[pthis->buttonIndex] = 200;
        pthis->buttonIndex = FS_BTN_COPY_QUIT;
        pthis->actionTimer = 8;
        pthis->configMode = CM_SELECT_COPY_DEST;
    }
}

/**
 * Allow the player to select a slot to copy to or exit to the copy select screen.
 * Update function for `CM_SELECT_COPY_DEST`
 */
void FileChoose_SelectCopyDest(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    SramContext* sramCtx = &pthis->sramCtx;
    Input* input = &pthis->state.input[0];

    if (((pthis->buttonIndex == FS_BTN_COPY_QUIT) && CHECK_BTN_ANY(input->press.button, BTN_A | BTN_START)) ||
        CHECK_BTN_ALL(input->press.button, BTN_B)) {
        pthis->buttonIndex = pthis->selectedFileIndex;
        pthis->nextTitleLabel = FS_TITLE_COPY_FROM;
        pthis->actionTimer = 8;
        pthis->configMode = CM_EXIT_TO_COPY_SOURCE_1;
        Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CLOSE, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
    } else if (CHECK_BTN_ANY(input->press.button, BTN_A | BTN_START)) {
        if (!SLOT_OCCUPIED(sramCtx, pthis->buttonIndex)) {
            pthis->copyDestFileIndex = pthis->buttonIndex;
            pthis->nextTitleLabel = FS_TITLE_COPY_CONFIRM;
            pthis->actionTimer = 8;
            pthis->configMode = CM_SETUP_COPY_CONFIRM_1;
            Audio_PlaySoundGeneral(NA_SE_SY_FSEL_DECIDE_L, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        } else {
            Audio_PlaySoundGeneral(NA_SE_SY_FSEL_ERROR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        }
    } else {

        if (ABS(pthis->stickRelY) >= 30) {
            Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);

            if (pthis->stickRelY >= 30) {
                pthis->buttonIndex--;

                if ((pthis->buttonIndex == pthis->selectedFileIndex)) {
                    pthis->buttonIndex--;

                    if (pthis->buttonIndex < FS_BTN_COPY_FILE_1) {
                        pthis->buttonIndex = FS_BTN_COPY_QUIT;
                    }
                } else {
                    if (pthis->buttonIndex < FS_BTN_COPY_FILE_1) {
                        pthis->buttonIndex = FS_BTN_COPY_QUIT;
                    }
                }
            } else {
                pthis->buttonIndex++;

                if (pthis->buttonIndex > FS_BTN_COPY_QUIT) {
                    pthis->buttonIndex = FS_BTN_COPY_FILE_1;
                }

                if (pthis->buttonIndex == pthis->selectedFileIndex) {
                    pthis->buttonIndex++;
                }
            }
        }

        if (pthis->buttonIndex != FS_BTN_COPY_QUIT) {
            if (SLOT_OCCUPIED(sramCtx, pthis->buttonIndex)) {
                pthis->warningLabel = FS_WARNING_FILE_IN_USE;
                pthis->warningButtonIndex = pthis->buttonIndex;
                pthis->emptyFileTextAlpha = 255;
            } else {
                pthis->warningLabel = FS_WARNING_NONE;
            }
        }
    }
}

/**
 * Fade out file info, bring back the name box, and get ready to return to copy source screen.
 * Update function for `CM_EXIT_TO_COPY_SOURCE_1`
 */
void FileChoose_ExitToCopySource1(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;

    pthis->fileInfoAlpha[pthis->buttonIndex] -= 25;
    pthis->nameBoxAlpha[pthis->buttonIndex] += 25;
    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        pthis->nextTitleLabel = FS_TITLE_COPY_FROM;
        pthis->nameBoxAlpha[pthis->buttonIndex] = 200;
        pthis->fileInfoAlpha[pthis->buttonIndex] = 0;
        pthis->actionTimer = 8;
        pthis->configMode++;
    }
}

/**
 * Move the buttons back into place and return to copy source select.
 * Update function for `CM_EXIT_TO_COPY_SOURCE_2`
 */
void FileChoose_ExitToCopySource2(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    SramContext* sramCtx = &pthis->sramCtx;
    s16 i;
    s16 yStep;

    for (i = 0; i < 3; i++) {
        yStep = ABS(pthis->buttonYOffsets[i] - sChooseFileYOffsets[i]) / pthis->actionTimer;

        if (pthis->buttonYOffsets[i] >= sChooseFileYOffsets[i]) {
            pthis->buttonYOffsets[i] -= yStep;
        } else {
            pthis->buttonYOffsets[i] += yStep;
        }
    }

    pthis->titleAlpha[0] -= 31;
    pthis->titleAlpha[1] += 31;
    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        pthis->titleLabel = pthis->nextTitleLabel;
        pthis->titleAlpha[0] = 255;
        pthis->titleAlpha[1] = 0;
        pthis->buttonIndex = 3;
        pthis->configMode = CM_SELECT_COPY_SOURCE;
    }
}

/**
 * Rearrange buttons on the screen to prepare for copy confirmation.
 * Update function for `CM_SETUP_COPY_CONFIRM_1`
 */
void FileChoose_SetupCopyConfirm1(GameState* thisx) {
    static s16 D_808124A4[] = { -56, -40, -24, 0 };
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    SramContext* sramCtx = &pthis->sramCtx;
    s16 i;
    s16 yStep;

    pthis->titleAlpha[0] -= 31;
    pthis->titleAlpha[1] += 31;

    for (i = 0; i < 3; i++) {
        if ((i != pthis->copyDestFileIndex) && (i != pthis->selectedFileIndex)) {
            pthis->fileButtonAlpha[i] -= 25;

            if (SLOT_OCCUPIED(sramCtx, i)) {
                pthis->connectorAlpha[i] -= 31;
                pthis->nameBoxAlpha[i] = pthis->nameAlpha[i] = pthis->fileButtonAlpha[i];
            }
        } else {
            if (pthis->copyDestFileIndex == i) {
                yStep = ABS(pthis->buttonYOffsets[i] - D_808124A4[i]) / pthis->actionTimer;
                pthis->buttonYOffsets[i] += yStep;

                if (pthis->buttonYOffsets[i] >= D_808124A4[i]) {
                    pthis->buttonYOffsets[i] = D_808124A4[i];
                }
            }
        }
    }

    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        pthis->titleLabel = pthis->nextTitleLabel;
        pthis->titleAlpha[0] = 255;
        pthis->titleAlpha[1] = 0;
        pthis->actionTimer = 8;
        pthis->configMode++;
    }
}

/**
 * Fade in the 'Yes' button before allowing the player to decide.
 * Update function for `CM_SETUP_COPY_CONFIRM_2`
 */
void FileChoose_SetupCopyConfirm2(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;

    pthis->confirmButtonAlpha[FS_BTN_CONFIRM_YES] += 25;
    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        pthis->configMode = CM_COPY_CONFIRM;
        pthis->buttonIndex = FS_BTN_CONFIRM_QUIT;
    }
}

/**
 * Allow the player to confirm the copy, or quit back to the destination select.
 * If yes is selected, the actual copy occurs in pthis function before moving on to the animation.
 * Update function for `CM_COPY_CONFIRM`
 */
void FileChoose_CopyConfirm(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    SramContext* sramCtx = &pthis->sramCtx;
    Input* input = &pthis->state.input[0];
    u16 dayTime;

    if (((pthis->buttonIndex != FS_BTN_CONFIRM_YES) && CHECK_BTN_ANY(input->press.button, BTN_A | BTN_START)) ||
        CHECK_BTN_ALL(input->press.button, BTN_B)) {
        pthis->actionTimer = 8;
        pthis->nextTitleLabel = FS_TITLE_COPY_TO;
        pthis->configMode = CM_RETURN_TO_COPY_DEST;
        Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CLOSE, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
    } else if (CHECK_BTN_ANY(input->press.button, BTN_A | BTN_START)) {
        dayTime = gSaveContext.dayTime;
        Sram_CopySave(pthis, sramCtx);
        gSaveContext.dayTime = dayTime;
        pthis->fileInfoAlpha[pthis->copyDestFileIndex] = pthis->nameAlpha[pthis->copyDestFileIndex] = 0;
        pthis->nextTitleLabel = FS_TITLE_COPY_COMPLETE;
        pthis->actionTimer = 8;
        pthis->configMode = CM_COPY_ANIM_1;
        Rumble_Shake(300.0f, 0xB4, 0x14, 0x64);
        Audio_PlaySoundGeneral(NA_SE_SY_FSEL_DECIDE_L, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
    } else if (ABS(pthis->stickRelY) >= 30) {
        Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        pthis->buttonIndex ^= 1;
    }
}

/**
 * Move buttons back in place and return to copy destination select.
 * Update function for `CM_RETURN_TO_COPY_DEST`
 */
void FileChoose_ReturnToCopyDest(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    SramContext* sramCtx = &pthis->sramCtx;
    s16 i;
    s16 yStep;

    pthis->titleAlpha[0] -= 31;
    pthis->titleAlpha[1] += 31;
    pthis->confirmButtonAlpha[FS_BTN_CONFIRM_YES] -= 25;

    for (i = 0; i < 3; i++) {
        if ((i != pthis->copyDestFileIndex) && (i != pthis->selectedFileIndex)) {
            pthis->fileButtonAlpha[i] += 25;

            if (SLOT_OCCUPIED(sramCtx, i)) {
                pthis->nameBoxAlpha[i] = pthis->nameAlpha[i] = pthis->fileButtonAlpha[i];
                pthis->connectorAlpha[i] += 31;
            }
        }

        yStep = ABS(pthis->buttonYOffsets[i] - D_8081248C[pthis->selectedFileIndex][i]) / pthis->actionTimer;

        if (D_8081248C[pthis->selectedFileIndex][i] >= pthis->buttonYOffsets[i]) {
            pthis->buttonYOffsets[i] += yStep;
        } else {
            pthis->buttonYOffsets[i] -= yStep;
        }
    }

    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        pthis->titleLabel = pthis->nextTitleLabel;
        pthis->titleAlpha[0] = 255;
        pthis->titleAlpha[1] = 0;
        pthis->actionTimer = 8;
        pthis->buttonIndex = FS_BTN_COPY_QUIT;
        pthis->configMode = CM_SELECT_COPY_DEST;
    }
}

/**
 * Hide title
 * Update function for `CM_COPY_ANIM_1`
 */
void FileChoose_CopyAnim1(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;

    pthis->titleAlpha[0] -= 31;
    pthis->confirmButtonAlpha[FS_BTN_CONFIRM_YES] -= 25;
    pthis->confirmButtonAlpha[FS_BTN_CONFIRM_QUIT] -= 25;
    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        pthis->titleAlpha[0] = 0;
        pthis->actionTimer = 8;
        pthis->configMode++;
        osSyncPrintf("connect_alpha=%d  decision_alpha[%d]=%d\n", pthis->connectorAlpha[pthis->copyDestFileIndex],
                     pthis->copyDestFileIndex, pthis->fileInfoAlpha[pthis->copyDestFileIndex]);
    }
}

/**
 * Move a copy of the file window down and fade in the file info.
 * Update function for `CM_COPY_ANIM_2`
 */
void FileChoose_CopyAnim2(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    s16 yStep;

    pthis->fileInfoAlpha[pthis->copyDestFileIndex] += 25;
    pthis->nameAlpha[pthis->copyDestFileIndex] += 25;
    pthis->titleAlpha[1] += 31;
    yStep = ABS(pthis->fileNamesY[pthis->copyDestFileIndex] + 56) / pthis->actionTimer;
    pthis->fileNamesY[pthis->copyDestFileIndex] -= yStep;

    if (pthis->fileNamesY[pthis->copyDestFileIndex] <= -56) {
        pthis->fileNamesY[pthis->copyDestFileIndex] = -56;
    }

    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        pthis->actionTimer = 90;
        pthis->titleLabel = pthis->nextTitleLabel;
        pthis->titleAlpha[0] = 255;
        pthis->titleAlpha[1] = 0;
        pthis->configMode++;
    }
}

/**
 * Play sound to indicate that the copy has completed. Wait for a timer or for
 * the player to press a button before moving on.
 * Update function for `CM_COPY_ANIM_3`
 */
void FileChoose_CopyAnim3(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    Input* input = &pthis->state.input[0];

    if (pthis->actionTimer == 75) {
        pthis->connectorAlpha[pthis->copyDestFileIndex] = 255;
        Audio_PlaySoundGeneral(NA_SE_EV_DIAMOND_SWITCH, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
    }

    pthis->actionTimer--;

    if (pthis->actionTimer < 74) {
        if (CHECK_BTN_ANY(input->press.button, BTN_A | BTN_B | BTN_START) || (pthis->actionTimer == 0)) {
            pthis->actionTimer = 8;
            pthis->nextTitleLabel = FS_TITLE_SELECT_FILE;
            pthis->configMode++;
            Audio_PlaySoundGeneral(NA_SE_SY_FSEL_DECIDE_L, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        }
    }
}

/**
 * Fade out the info boxes for both files and bring in their name boxes. Fade out title.
 * Update function for `CM_COPY_ANIM_4`
 */
void FileChoose_CopyAnim4(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;

    pthis->fileInfoAlpha[pthis->selectedFileIndex] -= 25;
    pthis->fileInfoAlpha[pthis->copyDestFileIndex] -= 25;
    pthis->nameBoxAlpha[pthis->selectedFileIndex] += 25;
    pthis->nameBoxAlpha[pthis->copyDestFileIndex] += 25;
    pthis->titleAlpha[0] -= 31;
    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        pthis->fileNamesY[pthis->copyDestFileIndex] = pthis->buttonYOffsets[3] = 0;
        pthis->actionTimer = 8;
        pthis->titleAlpha[0] = 0;
        pthis->configMode++;
    }
}

/**
 * Restore all buttons and labels back to their original place and go back to the main menu.
 * Update function for `CM_COPY_ANIM_5`
 */
void FileChoose_CopyAnim5(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    SramContext* sramCtx = &pthis->sramCtx;
    s16 i;
    s16 yStep;

    for (i = 0; i < 5; i++) {
        yStep = ABS(pthis->buttonYOffsets[i]) / pthis->actionTimer;

        if (pthis->buttonYOffsets[i] >= 0) {
            pthis->buttonYOffsets[i] -= yStep;
        } else {
            pthis->buttonYOffsets[i] += yStep;
        }
    }

    for (i = 0; i < 3; i++) {
        if (i != pthis->buttonIndex) {
            pthis->fileButtonAlpha[i] += 25;

            if (SLOT_OCCUPIED(sramCtx, i)) {
                pthis->nameBoxAlpha[i] = pthis->nameAlpha[i] = pthis->fileButtonAlpha[i];
                pthis->connectorAlpha[i] += 31;
            }
        }
    }

    pthis->actionButtonAlpha[FS_BTN_ACTION_COPY] += 25;
    pthis->actionButtonAlpha[FS_BTN_ACTION_ERASE] += 25;
    pthis->optionButtonAlpha += 25;
    pthis->titleAlpha[1] += 31;
    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        for (i = 0; i < 3; i++) {
            pthis->connectorAlpha[i] = 0;
            pthis->fileButtonAlpha[i] = 200;
            pthis->nameBoxAlpha[i] = pthis->nameAlpha[i] = pthis->connectorAlpha[i];

            if (SLOT_OCCUPIED(sramCtx, i)) {
                pthis->connectorAlpha[i] = 255;
                pthis->nameBoxAlpha[i] = pthis->nameAlpha[i] = pthis->fileButtonAlpha[i];
            }
        }

        pthis->fileNamesY[pthis->selectedFileIndex] = 0;
        pthis->highlightColor[3] = 70;
        pthis->highlightPulseDir = 1;
        XREG(35) = XREG(36);
        pthis->titleLabel = pthis->nextTitleLabel;
        pthis->titleAlpha[0] = 255;
        pthis->titleAlpha[1] = 0;
        pthis->configMode = CM_MAIN_MENU;
    }
}

/**
 * Exit from the copy source screen to the main menu. Return all buttons and labels to their original place.
 * Update function for `CM_COPY_RETURN_MAIN`
 */
void FileChoose_ExitCopyToMain(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    s16 i;
    s16 yStep;

    for (i = 0; i < 5; i++) {
        yStep = ABS(pthis->buttonYOffsets[i]) / pthis->actionTimer;

        if (pthis->buttonYOffsets[i] >= 0) {
            pthis->buttonYOffsets[i] -= yStep;
        } else {
            pthis->buttonYOffsets[i] += yStep;
        }
    }

    pthis->actionButtonAlpha[FS_BTN_ACTION_COPY] += 25;
    pthis->confirmButtonAlpha[FS_BTN_CONFIRM_QUIT] -= 25;
    pthis->titleAlpha[0] -= 31;
    pthis->titleAlpha[1] += 31;
    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        pthis->actionButtonAlpha[FS_BTN_ACTION_COPY] = 200;
        pthis->confirmButtonAlpha[FS_BTN_CONFIRM_QUIT] = 0;
        pthis->titleLabel = pthis->nextTitleLabel;
        pthis->titleAlpha[0] = 255;
        pthis->titleAlpha[1] = 0;
        pthis->configMode = CM_MAIN_MENU;
    }

    pthis->optionButtonAlpha = pthis->actionButtonAlpha[FS_BTN_ACTION_ERASE] =
        pthis->actionButtonAlpha[FS_BTN_ACTION_COPY];
}

/**
 * Move buttons into place for the erase select screen and fade in the proper labels.
 * Update function for `CM_SETUP_ERASE_SELECT`
 */
void FileChoose_SetupEraseSelect(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    s16 i;
    s16 yStep;

    for (i = 0; i < 5; i++) {
        yStep = ABS(pthis->buttonYOffsets[i] - sChooseFileYOffsets[i]) / pthis->actionTimer;

        if (pthis->buttonYOffsets[i] >= sChooseFileYOffsets[i]) {
            pthis->buttonYOffsets[i] -= yStep;
        } else {
            pthis->buttonYOffsets[i] += yStep;
        }
    }

    pthis->actionButtonAlpha[FS_BTN_ACTION_COPY] -= 50;
    pthis->actionButtonAlpha[FS_BTN_ACTION_ERASE] -= 50;
    pthis->optionButtonAlpha -= 50;
    pthis->confirmButtonAlpha[FS_BTN_CONFIRM_QUIT] += 25;

    if (pthis->actionButtonAlpha[FS_BTN_ACTION_COPY] <= 0) {
        pthis->actionButtonAlpha[FS_BTN_ACTION_COPY] = pthis->actionButtonAlpha[FS_BTN_ACTION_ERASE] =
            pthis->optionButtonAlpha = 0;
    }

    pthis->titleAlpha[0] -= 31;
    pthis->titleAlpha[1] += 31;
    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        pthis->highlightColor[3] = 70;
        pthis->highlightPulseDir = 1;
        XREG(35) = XREG(36);
        pthis->actionButtonAlpha[FS_BTN_ACTION_COPY] = pthis->actionButtonAlpha[FS_BTN_ACTION_ERASE] =
            pthis->optionButtonAlpha = 0;
        pthis->confirmButtonAlpha[1] = 200;
        pthis->titleLabel = pthis->nextTitleLabel;
        pthis->titleAlpha[0] = 255;
        pthis->titleAlpha[1] = 0;
        pthis->buttonIndex = FS_BTN_ERASE_QUIT;
        pthis->configMode++;
    }
}

/**
 * Allow the player to select a file to erase or exit back to the main menu.
 * Update function for `CM_ERASE_SELECT`
 */
void FileChoose_EraseSelect(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    SramContext* sramCtx = &pthis->sramCtx;
    Input* input = &pthis->state.input[0];

    if (((pthis->buttonIndex == FS_BTN_COPY_QUIT) && CHECK_BTN_ANY(input->press.button, BTN_A | BTN_START)) ||
        CHECK_BTN_ALL(input->press.button, BTN_B)) {
        pthis->buttonIndex = FS_BTN_MAIN_ERASE;
        pthis->actionTimer = 8;
        pthis->nextTitleLabel = FS_TITLE_SELECT_FILE;
        pthis->configMode = CM_EXIT_ERASE_TO_MAIN;
        pthis->warningLabel = FS_WARNING_NONE;
        Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CLOSE, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
    } else if (CHECK_BTN_ANY(input->press.button, BTN_A | BTN_START)) {
        if (SLOT_OCCUPIED(sramCtx, pthis->buttonIndex)) {
            pthis->actionTimer = 8;
            pthis->selectedFileIndex = pthis->buttonIndex;
            pthis->configMode = CM_SETUP_ERASE_CONFIRM_1;
            pthis->nextTitleLabel = FS_TITLE_ERASE_CONFIRM;
            Audio_PlaySoundGeneral(NA_SE_SY_FSEL_DECIDE_L, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        } else {
            Audio_PlaySoundGeneral(NA_SE_SY_FSEL_ERROR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        }
    } else {
        if (ABS(pthis->stickRelY) >= 30) {
            Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);

            if (pthis->stickRelY >= 30) {
                pthis->buttonIndex--;
                if (pthis->buttonIndex < FS_BTN_ERASE_FILE_1) {
                    pthis->buttonIndex = FS_BTN_ERASE_QUIT;
                }
            } else {
                pthis->buttonIndex++;
                if (pthis->buttonIndex > FS_BTN_ERASE_QUIT) {
                    pthis->buttonIndex = FS_BTN_ERASE_FILE_1;
                }
            }
        }

        if (pthis->buttonIndex != FS_BTN_ERASE_QUIT) {
            if (!SLOT_OCCUPIED(sramCtx, pthis->buttonIndex)) {
                pthis->warningLabel = FS_WARNING_FILE_EMPTY;
                pthis->warningButtonIndex = pthis->buttonIndex;
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
 * ...
 * Update function for `CM_SETUP_ERASE_CONFIRM_1`
 */
void FileChoose_SetupEraseConfirm1(GameState* thisx) {
    static s16 D_808124AC[] = { 0, 16, 32 };
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    SramContext* sramCtx = &pthis->sramCtx;
    s16 i;
    s16 yStep;

    for (i = 0; i < 3; i++) {
        if (i != pthis->buttonIndex) {
            pthis->fileButtonAlpha[i] -= 25;

            if (SLOT_OCCUPIED(sramCtx, i)) {
                pthis->connectorAlpha[i] -= 31;
                pthis->nameBoxAlpha[i] = pthis->nameAlpha[i] = pthis->fileButtonAlpha[i];
            }
        } else {
            pthis->nameBoxAlpha[i] -= 25;
        }
    }
    pthis->titleAlpha[0] -= 15;
    pthis->titleAlpha[1] += 15;

    yStep = ABS(pthis->buttonYOffsets[pthis->buttonIndex] - D_808124AC[pthis->buttonIndex]) / pthis->actionTimer;

    if (pthis->buttonYOffsets[pthis->buttonIndex] >= D_808124AC[pthis->buttonIndex]) {
        pthis->buttonYOffsets[pthis->buttonIndex] -= yStep;
    } else {
        pthis->buttonYOffsets[pthis->buttonIndex] += yStep;
    }

    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        for (i = 0; i < 3; i++) {
            if (i != pthis->buttonIndex) {
                pthis->fileButtonAlpha[i] = 0;

                if (SLOT_OCCUPIED(sramCtx, i)) {
                    pthis->connectorAlpha[i] = 0;
                    pthis->nameBoxAlpha[i] = pthis->nameAlpha[i] = pthis->fileButtonAlpha[i] = 0;
                }
            } else {
                pthis->nameBoxAlpha[i] = 0;
            }
        }

        pthis->buttonYOffsets[pthis->buttonIndex] = D_808124AC[pthis->buttonIndex];
        pthis->actionTimer = 8;
        pthis->configMode++;
    }
}

/**
 * Show the file info of the file selected to erase.
 * Update function for `CM_SETUP_ERASE_CONFIRM_2`
 */
void FileChoose_SetupEraseConfirm2(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;

    pthis->confirmButtonAlpha[FS_BTN_CONFIRM_YES] += 25;
    pthis->titleAlpha[0] -= 15;
    pthis->titleAlpha[1] += 15;
    pthis->fileInfoAlpha[pthis->buttonIndex] += 25;
    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        pthis->actionTimer = 8;
        pthis->titleLabel = pthis->nextTitleLabel;
        pthis->fileInfoAlpha[pthis->buttonIndex] = pthis->titleAlpha[0] = 255;
        pthis->titleAlpha[1] = 0;
        pthis->confirmButtonAlpha[FS_BTN_CONFIRM_YES] = 200;
        pthis->buttonIndex = FS_BTN_ERASE_FILE_2;
        pthis->configMode = CM_ERASE_CONFIRM;
    }
}

/**
 * Allow the player to confirm their chioce to erase or return back to erase select.
 * Update function for `CM_ERASE_CONFIRM`
 */
void FileChoose_EraseConfirm(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    Input* input = &pthis->state.input[0];

    if (((pthis->buttonIndex != FS_BTN_CONFIRM_YES) && CHECK_BTN_ANY(input->press.button, BTN_A | BTN_START)) ||
        CHECK_BTN_ALL(input->press.button, BTN_B)) {
        pthis->buttonIndex = pthis->selectedFileIndex;
        pthis->nextTitleLabel = FS_TITLE_ERASE_FILE;
        pthis->configMode = CM_EXIT_TO_ERASE_SELECT_1;
        pthis->actionTimer = 8;
        Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CLOSE, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
    } else if (CHECK_BTN_ANY(input->press.button, BTN_A | BTN_START)) {
        pthis->n64ddFlags[pthis->selectedFileIndex] = pthis->connectorAlpha[pthis->selectedFileIndex] = 0;
        Audio_PlaySoundGeneral(NA_SE_EV_DIAMOND_SWITCH, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        pthis->actionTimer = 8;
        pthis->configMode = CM_ERASE_ANIM_1;
        pthis->nextTitleLabel = FS_TITLE_ERASE_COMPLETE;
        Rumble_Shake(200.0f, 0xFF, 0x14, 0x96);
        sEraseDelayTimer = 15;
    } else if (ABS(pthis->stickRelY) >= 30) {
        Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        pthis->buttonIndex ^= 1;
    }
}

/**
 * Fade out file info, bring back the name box, and get ready to return to erase select screen.
 * Update function for `CM_EXIT_TO_ERASE_SELECT_1`
 */
void FileChoose_ExitToEraseSelect1(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;

    pthis->fileInfoAlpha[pthis->buttonIndex] -= 25;
    pthis->nameBoxAlpha[pthis->buttonIndex] += 25;
    pthis->confirmButtonAlpha[FS_BTN_CONFIRM_YES] -= 25;
    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        pthis->actionTimer = 8;
        pthis->fileInfoAlpha[pthis->buttonIndex] = 0;
        pthis->configMode++;
    }
}

/**
 * Move the buttons back into place and return to erase select.
 * Update function for `CM_EXIT_TO_ERASE_SELECT_2`
 */
void FileChoose_ExitToEraseSelect2(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    SramContext* sramCtx = &pthis->sramCtx;
    s16 i;
    s16 yStep;

    yStep = ABS(pthis->buttonYOffsets[pthis->buttonIndex] - sChooseFileYOffsets[pthis->buttonIndex]) / pthis->actionTimer;

    if (pthis->buttonYOffsets[pthis->buttonIndex] >= sChooseFileYOffsets[pthis->buttonIndex]) {
        pthis->buttonYOffsets[pthis->buttonIndex] -= yStep;
    } else {
        pthis->buttonYOffsets[pthis->buttonIndex] += yStep;
    }

    for (i = 0; i < 3; i++) {
        if (i != pthis->buttonIndex) {
            pthis->fileButtonAlpha[i] += 25;

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
        pthis->buttonYOffsets[pthis->buttonIndex] = sChooseFileYOffsets[pthis->buttonIndex];
        pthis->actionTimer = 8;
        pthis->buttonIndex = FS_BTN_ERASE_QUIT;
        pthis->titleLabel = pthis->nextTitleLabel;
        pthis->titleAlpha[0] = 255;
        pthis->titleAlpha[1] = 0;
        pthis->configMode = CM_ERASE_SELECT;
    }
}

/**
 * Wait for an initial delay, then start fading out the selected file.
 * The actual file deletion occurs in pthis function
 * Update function for `CM_ERASE_ANIM_1`
 */
void FileChoose_EraseAnim1(GameState* thisx) {
    static s16 D_80813800;
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    SramContext* sramCtx = &pthis->sramCtx;

    if (sEraseDelayTimer == 0) {
        if (pthis->actionTimer == 8) {
            D_80813800 = 1;
        }

        if (pthis->actionTimer != 0) {
            pthis->titleAlpha[0] -= 31;
            pthis->titleAlpha[1] += 31;
            pthis->fileInfoAlpha[pthis->selectedFileIndex] -= 25;
            pthis->confirmButtonAlpha[FS_BTN_CONFIRM_YES] -= 25;
            pthis->confirmButtonAlpha[FS_BTN_CONFIRM_QUIT] -= 25;
        }

        pthis->fileNamesY[pthis->selectedFileIndex] -= D_80813800;
        pthis->actionTimer--;
        D_80813800 += 2;

        if (pthis->actionTimer == 0) {
            Sram_EraseSave(pthis, sramCtx);
            pthis->titleLabel = pthis->nextTitleLabel;
            pthis->titleAlpha[0] = 255;
            pthis->titleAlpha[1] = pthis->connectorAlpha[pthis->selectedFileIndex] = 0;

            // probably a fake match, there should be a better chained assignment
            pthis->confirmButtonAlpha[0] = pthis->confirmButtonAlpha[1] = 0;
            if (1) {}
            pthis->fileInfoAlpha[pthis->selectedFileIndex] = pthis->nameBoxAlpha[pthis->selectedFileIndex] =
                pthis->confirmButtonAlpha[1];

            pthis->configMode++;
            pthis->actionTimer = 90;
        }
    } else {
        sEraseDelayTimer--;

        if (sEraseDelayTimer == 0) {
            Audio_PlaySoundGeneral(NA_SE_OC_ABYSS, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        }
    }
}

/**
 * Wait for a delay timer or for the palyer to press a button before returning to the main menu.
 * Update function for `CM_ERASE_ANIM_2`
 */
void FileChoose_EraseAnim2(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    Input* input = &pthis->state.input[0];

    if (CHECK_BTN_ANY(input->press.button, BTN_A | BTN_B | BTN_START) || (--pthis->actionTimer == 0)) {
        pthis->buttonYOffsets[3] = 0;
        pthis->actionTimer = 8;
        pthis->nextTitleLabel = FS_TITLE_SELECT_FILE;
        pthis->configMode++;
        Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CLOSE, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
    }
}

/**
 * Exit from the erase animation to the main menu. Return all buttons and labels to their original place.
 * Update function for `CM_ERASE_ANIM_3`
 */
void FileChoose_EraseAnim3(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    SramContext* sramCtx = &pthis->sramCtx;
    s16 i;
    s16 yStep;

    for (i = 0; i < 5; i++) {
        yStep = ABS(pthis->buttonYOffsets[i]) / pthis->actionTimer;

        if (pthis->buttonYOffsets[i] >= 0) {
            pthis->buttonYOffsets[i] -= yStep;
        } else {
            pthis->buttonYOffsets[i] += yStep;
        }
    }

    for (i = 0; i < 3; i++) {
        pthis->fileButtonAlpha[i] += 25;

        if (SLOT_OCCUPIED(sramCtx, i)) {
            pthis->nameBoxAlpha[i] = pthis->nameAlpha[i] = pthis->fileButtonAlpha[i];
            pthis->connectorAlpha[i] += 31;
        }
    }

    if (pthis->fileButtonAlpha[pthis->selectedFileIndex] >= 200) {
        pthis->fileButtonAlpha[pthis->selectedFileIndex] = 200;
    }

    pthis->titleAlpha[0] -= 31;
    pthis->titleAlpha[1] += 31;
    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        pthis->fileNamesY[pthis->selectedFileIndex] = 0;
        pthis->highlightColor[3] = 70;
        pthis->highlightPulseDir = 1;
        XREG(35) = XREG(36);
        pthis->actionButtonAlpha[FS_BTN_ACTION_COPY] = 200;
        pthis->confirmButtonAlpha[0] = pthis->confirmButtonAlpha[1] = 0;
        pthis->titleLabel = pthis->nextTitleLabel;
        pthis->titleAlpha[0] = 255;
        pthis->titleAlpha[1] = 0;
        pthis->configMode = CM_MAIN_MENU;
    }

    pthis->optionButtonAlpha = pthis->actionButtonAlpha[FS_BTN_ACTION_ERASE] =
        pthis->actionButtonAlpha[FS_BTN_ACTION_COPY];
}

/**
 * Exit from the erase select screen to the main menu. Return all buttons and labels to their original place.
 * Update function for `CM_EXIT_ERASE_TO_MAIN`
 */
void FileChoose_ExitEraseToMain(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    s16 i;
    s16 yStep;

    for (i = 0; i < 5; i++) {
        yStep = ABS(pthis->buttonYOffsets[i]) / pthis->actionTimer;

        if (pthis->buttonYOffsets[i] >= 0) {
            pthis->buttonYOffsets[i] -= yStep;
        } else {
            pthis->buttonYOffsets[i] += yStep;
        }
    }

    pthis->actionButtonAlpha[FS_BTN_ACTION_COPY] += 25;
    pthis->actionButtonAlpha[FS_BTN_ACTION_ERASE] += 25;
    pthis->optionButtonAlpha += 25;
    pthis->confirmButtonAlpha[FS_BTN_CONFIRM_QUIT] -= 50;

    if (pthis->confirmButtonAlpha[FS_BTN_CONFIRM_QUIT] <= 0) {
        pthis->confirmButtonAlpha[FS_BTN_CONFIRM_QUIT] = 0;
    }

    pthis->titleAlpha[0] -= 31;
    pthis->titleAlpha[1] += 31;
    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        pthis->highlightColor[3] = 70;
        pthis->highlightPulseDir = 1;
        XREG(35) = XREG(36);
        pthis->actionButtonAlpha[FS_BTN_ACTION_COPY] = 200;
        pthis->confirmButtonAlpha[FS_BTN_CONFIRM_QUIT] = 0;
        pthis->titleLabel = pthis->nextTitleLabel;
        pthis->titleAlpha[0] = 255;
        pthis->titleAlpha[1] = 0;
        pthis->configMode = CM_MAIN_MENU;
    }

    pthis->optionButtonAlpha = pthis->actionButtonAlpha[FS_BTN_ACTION_ERASE] =
        pthis->actionButtonAlpha[FS_BTN_ACTION_COPY];
}
