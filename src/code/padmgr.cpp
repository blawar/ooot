#define INTERNAL_SRC_CODE_PADMGR_C
#include "global.h"
#include "padmgr.h"
#include "n64fault.h"
#include "vt.h"
#include "def/padmgr.h"
#include "def/padutils.h"

extern "C"
{
	void hid_init();
	void hid_update();
}

s32 D_8012D280 = 1;

OSMesgQueue* PadMgr_LockSerialMesgQueue(PadMgr* padMgr) {
    return 0;
}

void PadMgr_UnlockSerialMesgQueue(PadMgr* padMgr, OSMesgQueue* ctrlrQ) {
}

void PadMgr_LockPadData(PadMgr* padMgr) {
}

void PadMgr_UnlockPadData(PadMgr* padMgr) {
}

void PadMgr_RumbleControl(PadMgr* padMgr) {
}

void PadMgr_RumbleStop(PadMgr* padMgr) {
}

void PadMgr_RumbleReset(PadMgr* padMgr) {
}

void PadMgr_RumbleSetSingle(PadMgr* padMgr, u32 ctrlr, u32 rumble) {
}

void PadMgr_RumbleSet(PadMgr* padMgr, u8* ctrlrRumbles) {
}

void PadMgr_ProcessInputs(PadMgr* padMgr) {
}

void PadMgr_HandleRetraceMsg(PadMgr* padMgr) {
}

void PadMgr_HandlePreNMI(PadMgr* padMgr) {
}

void PadMgr_RequestPadData(PadMgr* padMgr, Input* inputs, s32 mode) {
    hid_update();
    s32 i;
    Input* ogInput;
    Input* newInput;
    s32 buttonDiff;

    ogInput = &padMgr->inputs[0];
    newInput = &inputs[0];

    if (ogInput->cur.button) {
        int y = 0;
    }

    for (i = 0; i < 4; i++) {
        if (mode != 0 && 0) {
            *newInput = *ogInput;
            ogInput->press.button = 0;
            ogInput->press.stick_x = 0;
            ogInput->press.stick_y = 0;
            ogInput->rel.button = 0;

            newInput->prev = newInput->cur;
            newInput->cur = ogInput->cur;
            buttonDiff = newInput->prev.button ^ newInput->cur.button;

            if(buttonDiff)
            {
                int y = 0;
            }
            newInput->press.button = newInput->cur.button & buttonDiff;
            newInput->rel.button = newInput->prev.button & buttonDiff;
            PadUtils_UpdateRelXY(newInput);
            newInput->press.stick_x += (s8)(newInput->cur.stick_x - newInput->prev.stick_x);
            newInput->press.stick_y += (s8)(newInput->cur.stick_y - newInput->prev.stick_y);
            *newInput = *ogInput;
        } else {
            newInput->prev = newInput->cur;
            newInput->cur = ogInput->cur;
            buttonDiff = newInput->prev.button ^ newInput->cur.button;
            newInput->press.button = newInput->cur.button & buttonDiff;
            newInput->rel.button = newInput->prev.button & buttonDiff;
            PadUtils_UpdateRelXY(newInput);
            newInput->press.stick_x += (s8)(newInput->cur.stick_x - newInput->prev.stick_x);
            newInput->press.stick_y += (s8)(newInput->cur.stick_y - newInput->prev.stick_y);
        }
        ogInput++;
        newInput++;
    }

    PadMgr_UnlockPadData(padMgr);
}

void PadMgr_ThreadEntry(PadMgr* padMgr) {
}

void PadMgr_Init(PadMgr* padMgr, OSMesgQueue* siIntMsgQ, IrqMgr* irqMgr, OSId id, OSPri priority, void* stack) {
}
