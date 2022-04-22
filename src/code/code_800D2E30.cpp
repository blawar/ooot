#define INTERNAL_SRC_CODE_CODE_800D2E30_C
#include "global.h"
#include "padmgr.h"
#include <string.h>
#include "def/code_800D2E30.h"

void Rumble_Update(RumbleStruct* rumbleCtx) {
    static u8 reset_needed = 1;
    s32 i;
    s32 temp;
    s32 index = -1;//Index into the list with the most rumble

    for (i = 0; i < 4; i++) {
        rumbleCtx->rumbleOn[i] = 0;
    }

    if (rumbleCtx->reset == 0) {
        if (reset_needed != 0) {
            for (i = 0; i < 4; i++) {
                gPadMgr.pakType[i] = 0;
            }
        }
        reset_needed = rumbleCtx->reset;//Don't reset again next frame
        return;
    }

    reset_needed = rumbleCtx->reset;//Allow resetting

    if (rumbleCtx->state == 2) {//Perform full clear of all data
        for (i = 0; i < 4; ++i) {
            gPadMgr.pakType[i] = 0;
        }

        for (i = 0; i < 0x40; i++) {
            rumbleCtx->strengthList_easing[i] = 0;
            rumbleCtx->decayList[i]    = 0;
            rumbleCtx->lengthList[i]   = 0;
            rumbleCtx->strengthList[i] = 0;
        }
        rumbleCtx->timer1 = rumbleCtx->timer2 = rumbleCtx->strength = rumbleCtx->length = rumbleCtx->decay = rumbleCtx->strength_easing = 0;
        rumbleCtx->state = 1;//Normal operation mode
    }
    if (rumbleCtx->state != 0) {
        for (i = 0; i < 0x40; i++) {
            if (rumbleCtx->strengthList[i] != 0) {
                if (rumbleCtx->lengthList[i] > 0) {
                    rumbleCtx->lengthList[i]--;
                }
                else {
                    temp = rumbleCtx->strengthList[i] - rumbleCtx->decayList[i];
                    if (temp > 0) {
                        rumbleCtx->strengthList[i] = temp;
                    }
                    else {
                        rumbleCtx->strengthList[i] = 0;
                    }
                }

                temp = rumbleCtx->strengthList_easing[i] + rumbleCtx->strengthList[i];
                rumbleCtx->strengthList_easing[i] = temp;
                if (index == -1) {
                    index = i;
                    rumbleCtx->rumbleOn[0] = (temp >= 0x100);
                }
                else if (rumbleCtx->strengthList[index] < rumbleCtx->strengthList[i]) {
                    index = i;
                    rumbleCtx->rumbleOn[0] = (temp >= 0x100);
                }
            }
        }
        if (rumbleCtx->strength != 0) {
            if (rumbleCtx->length > 0) {
                rumbleCtx->length--;
            }
            else {
                temp = rumbleCtx->strength - rumbleCtx->decay;
                if (temp > 0) {
                    rumbleCtx->strength = temp;
                }
                else {
                    rumbleCtx->strength = 0;
                }
            }
            temp = rumbleCtx->strength_easing + rumbleCtx->strength;
            rumbleCtx->strength_easing = temp;
            rumbleCtx->rumbleOn[0] = (temp >= 0x100);
        }
        if (rumbleCtx->strength != 0) {
            temp = rumbleCtx->strength;
        }
        else {
            //Write the largest rumble value in temp
            if (index == -1) {
                temp = 0;
            }
            else {
                temp = rumbleCtx->strengthList[index];
            }
        }
        if (temp == 0) {//No rumble
            if ((++rumbleCtx->timer2) >= 6) {
                rumbleCtx->timer1 = 0;//Clear emergency timer
                rumbleCtx->timer2 = 5;
            }
        }
        else {
            rumbleCtx->timer2 = 0;
            if ((++rumbleCtx->timer1) >= 0x1C21) {//Has been rumbling for a very long time?
                rumbleCtx->state = 0;//Clear rumble data
            }
        }
    }
    else {//Clear rumble data
        for (i = 0; i < 0x40; i++) {
            rumbleCtx->strengthList_easing[i] = 0;
            rumbleCtx->strengthList[i] = 0;
            rumbleCtx->lengthList[i]   = 0;
            rumbleCtx->decayList[i]    = 0;
        }

        rumbleCtx->timer1 = rumbleCtx->timer2 = rumbleCtx->strength = rumbleCtx->length = rumbleCtx->decay = rumbleCtx->strength_easing = 0;
    }
}