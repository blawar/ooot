#ifndef NX_H
#define NX_H

#ifdef __SWITCH__
#ifndef BUILD_NRO
#define TITLE_ID 0x054507E0B7552000

int mountSaveData();
int unmountSaveData();
int commitSave();
#endif
#endif

#endif
