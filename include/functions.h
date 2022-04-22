#pragma once
/*
#define POINTER_ADD(a, b) ((uintptr_t)a + (uintptr_t)b)
#define POINTER_SUB(a, b) ((uintptr_t)a - (uintptr_t)b)

#include "z64.h"
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

void Main_ThreadEntry(void* arg);
void Idle_ThreadEntry(void* arg);
void ViConfig_UpdateVi(u32 mode);
void ViConfig_UpdateBlack(void);
s32 DmaMgr_CompareName(const char* name1, const char* name2);
s32 DmaMgr_DmaRomToRam(void* rom, void* ram, uintptr_t size);
s32 DmaMgr_DmaHandler(OSPiHandle* pihandle, OSIoMesg* mb, s32 direction);
void DmaMgr_Error(DmaRequest* req, const char* file, const char* errorName, const char* errorDesc);
const char* DmaMgr_GetFileNameImpl(void* vrom);
const char* DmaMgr_GetFileName(void* vrom);
void DmaMgr_ProcessMsg(DmaRequest* req);
void DmaMgr_ThreadEntry(void* arg0);
s32 DmaMgr_SendRequestImpl(DmaRequest* req, void* ram, void* vrom, uintptr_t size, u32 unk, OSMesgQueue* queue, OSMesg msg);
s32 DmaMgr_SendRequest0(void* ram, void* vrom, uintptr_t size);
void DmaMgr_Init(void);
s32 DmaMgr_SendRequest2(DmaRequest* req, void* ram, void* vrom, uintptr_t size, u32 unk5, OSMesgQueue* queue, OSMesg msg,
                        const char* file, s32 line);
s32 DmaMgr_SendRequest1(void* ram0, void* vrom, uintptr_t size, const char* file, s32 line);
void* Yaz0_FirstDMA(void);
void* Yaz0_NextDMA(void* curSrcPos);
void Yaz0_DecompressImpl(Yaz0Header* hdr, u8* dst);
void Yaz0_Decompress(uintptr_t romStart, void* dst, u32 size);
void Locale_Init(void);
void Locale_ResetRegion(void);
u32 func_80001F48(void);
u32 func_80001F8C(void);
u32 Locale_IsRegionNative(void);

void isPrintfInit(void);
#if defined(_IS_DEBUG) || 1
void osSyncPrintf(const char* fmt, ...);
#else
#define osSyncPrintf(a, ...) (0)
#endif
void rmonPrintf(const char* fmt, ...);
void* is_proutSyncPrintf(void* arg, const char* str, u32 count);
void func_80002384(const char* exp, const char* file, u32 line);
OSPiHandle* osDriveRomInit(void);
void Mio0_Decompress(Yaz0Header* hdr, u8* dst);
void StackCheck_Init(StackEntry* entry, void* stackTop, void* stackBottom, u32 initValue, s32 minSpace,
                     const char* name);
void StackCheck_Cleanup(StackEntry* entry);
StackStatus StackCheck_GetState(StackEntry* entry);
u32 StackCheck_CheckAll(void);
u32 StackCheck_Check(StackEntry* entry);

s32 vsprintf(char* dst, const char* fmt, va_list args);
s32 sprintf(char* dst, const char* fmt, ...);
void __osPiCreateAccessQueue(void);
void __osPiGetAccess(void);
void __osPiRelAccess(void);
void osStopThread(OSThread* thread);
void osViExtendVStart(u32 arg0);
s32 osRecvMesg(OSMesgQueue* mq, OSMesg* msg, s32 flag);
void __osInitialize_common(void);
void __osInitialize_autodetect(void);
void __osExceptionPreamble();
// ? __osException(?);
void __osEnqueueAndYield(OSThread**);
void __osEnqueueThread(OSThread**, OSThread*);
OSThread* __osPopThread(OSThread**);
// ? __osNop(?);
void __osDispatchThread();
void __osCleanupThread(void);
void __osDequeueThread(OSThread** queue, OSThread* thread);
void osDestroyThread(OSThread* thread);



void osCreateThread(OSThread* thread, OSId id, void (*entry)(void*), void* arg, void* sp, OSPri pri);
void __osSetSR(u32);
u32 __osGetSR();
void osWritebackDCache(void* vaddr, s32 nbytes);
void* osViGetNextFramebuffer(void);
void osCreatePiManager(OSPri pri, OSMesgQueue* cmdQ, OSMesg* cmdBuf, s32 cmdMsgCnt);
void __osDevMgrMain(void* arg);
s32 __osPiRawStartDma(s32 dir, uintptr_t cartAddr, void* dramAddr, size_t size);
uintptr_t osVirtualToPhysical(void* vaddr);
void osViBlack(u8 active);
s32 __osSiRawReadIo(void* devAddr, u32* dst);
OSId osGetThreadId(OSThread* thread);
void osViSetMode(OSViMode* mode);
u32 __osProbeTLB(void*);
u32 osGetMemSize(void);
void osSetEventMesg(OSEvent e, OSMesgQueue* mq, OSMesg msg);
s32 _Printf(PrintCallback, void* arg, const char* fmt, va_list ap);
void osUnmapTLBAll(void);
s32 osEPiStartDma(OSPiHandle* handle, OSIoMesg* mb, s32 direction);
void osInvalICache(void* vaddr, s32 nbytes);
void osCreateMesgQueue(OSMesgQueue* mq, OSMesg* msg, s32 count);
void osInvalDCache(void* vaddr, s32 nbytes);
s32 osSendMesg(OSMesgQueue* mq, OSMesg msg, s32 flag);
s32 __osSiDeviceBusy(void);
s32 osJamMesg(OSMesgQueue* mq, OSMesg mesg, s32 flag);
void osSetThreadPri(OSThread* thread, OSPri pri);
OSPri osGetThreadPri(OSThread* thread);
s32 __osEPiRawReadIo(OSPiHandle* handle, uintptr_t devAddr, u32* data);
void osViSwapBuffer(void* vaddr);
s32 __osEPiRawStartDma(OSPiHandle* handle, s32 direction, uintptr_t cartAddr, void* dramAddr, size_t size);
u32 bcmp(void* __sl, void* __s2, u32 __n);
OSTime osGetTime(void);
void __osTimerServicesInit(void);
void __osTimerInterrupt(void);
void __osSetTimerIntr(OSTime time);
OSTime __osInsertTimer(OSTimer* timer);
u32 osGetCount(void);
void __osSetGlobalIntMask(OSHWIntr mask);
void __osSetCompare(u32);
void __osResetGlobalIntMask(OSHWIntr mask);
s32 __osDisableInt(void);
void __osRestoreInt(s32);
void __osViInit(void);
void __osViSwapContext(void);
OSMesgQueue* osPiGetCmdQueue(void);
s32 osEPiReadIo(OSPiHandle* handle, uintptr_t devAddr, u32* data);
void osViSetSpecialFeatures(u32 func);
OSPiHandle* osCartRomInit(void);
void __osSetFpcCsr(u32);
u32 __osGetFpcCsr();
s32 osEPiWriteIo(OSPiHandle* handle, uintptr_t devAddr, u32 data);
void osMapTLBRdb(void);
void osYieldThread(void);
u32 __osGetCause();
s32 __osEPiRawWriteIo(OSPiHandle* handle, uintptr_t devAddr, u32 data);
void _Litob(_Pft* args, u8 type);
void _Ldtob(_Pft* args, u8 type);
s32 __osSiRawWriteIo(void* devAddr, u32 val);
void osCreateViManager(OSPri pri);
OSViContext* __osViGetCurrentContext(void);
void osStartThread(OSThread* thread);
void osViSetYScale(f32 scale);
void osViSetXScale(f32 value);
void __osSetWatchLo(u32);

EnItem00* Item_DropCollectible(GlobalContext* globalCtx, Vec3f* spawnPos, s16 params);
EnItem00* Item_DropCollectible2(GlobalContext* globalCtx, Vec3f* spawnPos, s16 params);
void Item_DropCollectibleRandom(GlobalContext* globalCtx, Actor* fromActor, Vec3f* spawnPos, s16 params);











void FlagSet_Update(GlobalContext* globalCtx);
void Overlay_LoadGameState(GameStateOverlay* overlayEntry);
void Overlay_FreeGameState(GameStateOverlay* overlayEntry);










DamageTable* DamageTable_Get(s32 index);
void DamageTable_Clear(DamageTable* table);

void SaveContext_Init(void);
s32 func_800635D0(s32);
void func_800636C0(void);
void func_8006375C(s32 arg0, s32 arg1, const char* text);
void func_8006376C(u8 x, u8 y, u8 colorId, const char* text);
// ? func_80063828(?);
void func_8006390C(Input* input);
// ? func_80063C04(?);
void func_80063D7C(GraphicsContext* gfxCtx);




void* MemCopy(void* dest, void* src, s32 size);
void GetItem_Draw(GlobalContext* globalCtx, s16 drawId);
void func_8006BA00(GlobalContext* globalCtx);
void func_8006BA30(GlobalContext* globalCtx);
void Audio_PlaySoundAtPosition(GlobalContext* globalCtx, Vec3f* pos, s32 duration, u16 sfxId);
u16 ElfMessage_GetSariaText(GlobalContext* globalCtx);
u16 ElfMessage_GetCUpText(GlobalContext* globalCtx);
u16 Text_GetFaceReaction(GlobalContext* globalCtx, u32 reactionSet);
void Flags_UnsetAllEnv(GlobalContext* globalCtx);
void Flags_SetEnv(GlobalContext* globalCtx, s16 flag);
void Flags_UnsetEnv(GlobalContext* globalCtx, s16 flag);
s32 Flags_GetEnv(GlobalContext* globalCtx, s16 flag);
f32 func_8006C5A8(f32 target, TransformData* transData, s32 refIdx);
void SkelCurve_Clear(SkelAnimeCurve* skelCurve);
s32 SkelCurve_Init(GlobalContext* globalCtx, SkelAnimeCurve* skelCurve, SkelCurveLimbList* limbListSeg,
                   TransformUpdateIndex* transUpdIdx);
void SkelCurve_Destroy(GlobalContext* globalCtx, SkelAnimeCurve* skelCurve);
void SkelCurve_SetAnim(SkelAnimeCurve* skelCurve, TransformUpdateIndex* transUpdIdx, f32 arg2, f32 animFinalFrame,
                       f32 animCurFrame, f32 animSpeed);
s32 SkelCurve_Update(GlobalContext* globalCtx, SkelAnimeCurve* skelCurve);
void SkelCurve_Draw(Actor* actor, GlobalContext* globalCtx, SkelAnimeCurve* skelCurve,
                    OverrideCurveLimbDraw overrideLimbDraw, PostCurveLimbDraw postLimbDraw, s32 lod, void* data);
s32 func_8006CFC0(s32 scene);
void func_8006D074(GlobalContext* globalCtx);
void func_8006D0AC(GlobalContext* globalCtx);
void func_8006D0EC(GlobalContext* globalCtx, Player* player);
void func_8006D684(GlobalContext* globalCtx, Player* player);
void func_8006DC68(GlobalContext* globalCtx, Player* player);
void func_8006DD9C(Actor* actor, Vec3f* arg1, s16 arg2);
s32 Jpeg_Decode(void* data, void* zbuffer, void* workBuff, u32 workSize);
void KaleidoSetup_Update(GlobalContext* globalCtx);
void KaleidoSetup_Init(GlobalContext* globalCtx);
void KaleidoSetup_Destroy(GlobalContext* globalCtx);
void func_8006EE50(Font* font, u16 arg1, u16 arg2);
void Font_LoadChar(Font* font, u8 character, u16 codePointIndex);
void Font_LoadMessageBoxIcon(Font* font, u16 icon);
void Font_LoadOrderedFont(Font* font);



void Lib_MemSet(u8* dest, size_t size, u8 val);

void func_80077D10(f32* arg0, s16* arg1, Input* input);
s16 Rand_S16Offset(s16 base, s16 range);

void Actor_ProcessInitChain(Actor* actor, InitChainEntry* initChain);

void Color_RGBA8_Copy(Color_RGBA8* dst, Color_RGBA8* src);
void Common_PlaySfx(u16 sfxId);
void Common_PlaySfx2(u16 sfxId);
void Common_PlaySfxAtPos(Vec3f* arg0, u16 sfxId);
void HealthMeter_Init(GlobalContext* globalCtx);
void HealthMeter_Update(GlobalContext* globalCtx);
void HealthMeter_Draw(GlobalContext* globalCtx);
void HealthMeter_UpdateBeatingHeart(GlobalContext* globalCtx);
u32 HealthMeter_IsCritical(void);

void ZeldaArena_CheckPointer(void* ptr, u32 size, const char* name, const char* action);
void* ZeldaArena_Malloc(u32 size);
void* ZeldaArena_MallocDebug(u32 size, const char* file, s32 line);
void* ZeldaArena_MallocR(u32 size);
void* ZeldaArena_MallocRDebug(u32 size, const char* file, s32 line);
void* ZeldaArena_Realloc(void* ptr, u32 newSize);
void* ZeldaArena_ReallocDebug(void* ptr, u32 newSize, const char* file, s32 line);
void ZeldaArena_Free(void* ptr);
void ZeldaArena_FreeDebug(void* ptr, const char* file, s32 line);
void* ZeldaArena_Calloc(u32 num, u32 size);
void ZeldaArena_Display();
void ZeldaArena_GetSizes(u32* outMaxFree, u32* outFree, u32* outAlloc);
void ZeldaArena_Check();
void ZeldaArena_Init(void* start, u32 size);
void ZeldaArena_Cleanup();
u8 ZeldaArena_IsInitalized();
void MapMark_Init(GlobalContext* globalCtx);
void MapMark_ClearPointers(GlobalContext* globalCtx);
void MapMark_Draw(GlobalContext* globalCtx);
void PreNmiBuff_Init(PreNmiBuff* thiss);
void PreNmiBuff_SetReset(PreNmiBuff* thiss);
u32 PreNmiBuff_IsResetting(PreNmiBuff* thiss);
void MsgEvent_SendNullTask(void);
f32 OLib_Vec3fDist(Vec3f* a, Vec3f* b);
f32 OLib_Vec3fDistXZ(Vec3f* a, Vec3f* b);
f32 OLib_ClampMinDist(f32 val, f32 min);
f32 OLib_ClampMaxDist(f32 val, f32 max);
Vec3f* OLib_Vec3fDistNormalize(Vec3f* dest, Vec3f* a, Vec3f* b);
Vec3f* OLib_VecSphGeoToVec3f(Vec3f* dest, VecSph* sph);
VecSph* OLib_Vec3fToVecSph(VecSph* dest, Vec3f* vec);
VecSph* OLib_Vec3fToVecSphGeo(VecSph* arg0, Vec3f* arg1);
VecSph* OLib_Vec3fDiffToVecSphGeo(VecSph* arg0, Vec3f* a, Vec3f* b);
Vec3f* OLib_Vec3fDiffRad(Vec3f* dest, Vec3f* a, Vec3f* b);







Path* Path_GetByIndex(GlobalContext* globalCtx, s16 index, s16 max);
f32 Path_OrientAndGetDistSq(Actor* actor, Path* path, s16 waypoint, s16* yaw);
void Path_CopyLastPoint(Path* path, Vec3f* dest);













void func_80095AA0(GlobalContext* globalCtx, Room* room, Input* arg2, UNK_TYPE arg3); // z_play
void func_8009638C(Gfx** displayList, void* source, void* tlut, u16 width, u16 height, u8 fmt, u8 siz, u16 mode0,
                   u16 tlutCount, f32 frameX, f32 frameY);
void func_80096FD4(GlobalContext* globalCtx, Room* room);
s32 func_8009728C(GlobalContext* globalCtx, RoomContext* roomCtx, s32 roomNum);
s32 func_800973FC(GlobalContext* globalCtx, RoomContext* roomCtx);
void Room_Draw(GlobalContext* globalCtx, Room* room, u32 flags);
void func_80097534(GlobalContext* globalCtx, RoomContext* roomCtx);
void Sample_Destroy(GameState* thissx);
void Sample_Init(GameState* thissx);
void Inventory_ChangeEquipment(s16 equipment, u16 value);
u8 Inventory_DeleteEquipment(GlobalContext* globalCtx, s16 equipment);
void Inventory_ChangeUpgrade(s16 upgrade, s16 value);
void Object_InitBank(GlobalContext* globalCtx, ObjectContext* objectCtx);
void Object_UpdateBank(ObjectContext* objectCtx);
s32 Object_GetIndex(ObjectContext* objectCtx, s16 objectId);
s32 Object_IsLoaded(ObjectContext* objectCtx, s32 bankIndex);
void func_800981B8(ObjectContext* objectCtx);
s32 Scene_ExecuteCommands(GlobalContext* globalCtx, SceneCmd* sceneCmd);
void TransitionActor_InitContext(GameState* state, TransitionActorContext* transiActorCtx);
void func_800994A0(GlobalContext* globalCtx);
void Scene_Draw(GlobalContext* globalCtx);






void func_800A57C0(MtxF* mtx, Struct_800A57C0* arg1, Struct_800A598C* arg2, Vtx* arg3, Vec3f* arg4);
void func_800A598C(GraphicsContext* gfxCtx, PSkinAwb* skin, s32 limbIndex, s32 arg3);
void func_800A5E28(GraphicsContext* gfxCtx, PSkinAwb* skin, s32 limbIndex, s32 arg3, s32 arg4);
void func_800A5F60(GraphicsContext* gfxCtx, PSkinAwb* skin, s32 limbIndex, Gfx* arg3, s32 arg4);
void func_800A60D8(Actor* actor, GlobalContext* globalCtx, PSkinAwb* skin, SkinCallback callback, SkinCallback2 arg4,
                   s32 arg5, s32 arg6, s32 arg7);
void func_800A6330(Actor* actor, GlobalContext* globalCtx, PSkinAwb* skin, SkinCallback callback, s32 arg4);
void func_800A6360(Actor* thiss, GlobalContext* globalCtx, PSkinAwb* skin, SkinCallback callback, SkinCallback2 arg4,
                   s32 arg5);
void func_800A63CC(Actor* actor, GlobalContext* globalCtx, PSkinAwb* skin, SkinCallback callback, SkinCallback2 arg4,
                   s32 arg5, s32 arg6, s32 arg7);
void func_800A6408(PSkinAwb* skin, s32 joint, Vec3f* arg2, Vec3f* arg3);
void func_800A6460(GlobalContext* globalCtx, PSkinAwb* skin, s32 arg2);
void func_800A663C(GlobalContext* globalCtx, PSkinAwb* skin, SkeletonHeader* skeletonHeader,
                   AnimationHeader* animationHeader);
void func_800A6888(GlobalContext* globalCtx, PSkinAwb* skin);
s32 func_800A698C(PSkinAwb* skin, SkinLimb** limbs, MtxF* arg2, u8 arg3, u8 arg4);
s32 func_800A6AC4(PSkinAwb* skin, MtxF* arg1, Actor* actor, s32 arg3);



void func_800A7EC0(MtxF* mf, s16 a, f32 x, f32 y, f32 z);
void Sram_InitNewSave(void);
void Sram_InitDebugSave(void);
void Sram_OpenSave(SramContext* sramCtx);
void Sram_WriteSave(SramContext* sramCtx);
void Sram_VerifyAndLoadAllSaves(FileChooseContext* fileChoose, SramContext* sramCtx);
void Sram_InitSave(FileChooseContext* fileChoose, SramContext* sramCtx);
void Sram_EraseSave(FileChooseContext* fileChoose, SramContext* sramCtx);
void Sram_CopySave(FileChooseContext* fileChoose, SramContext* sramCtx);
void Sram_WriteSramHeader(SramContext* sramCtx);
void Sram_InitSram(GameState* gameState, SramContext* sramCtx);
void Sram_Alloc(GameState* gameState, SramContext* sramCtx);
void Sram_Init(GlobalContext* globalCtx, SramContext* sramCtx);
void SsSram_Init(uintptr_t addr, u8 handleType, u8 handleDomain, u8 handleLatency, u8 handlePageSize,
                 u8 handleRelDuration,
                 u8 handlePulse, u32 handleSpeed);
void SsSram_Dma(void* dramAddr, size_t size, s32 direction);
void SsSram_ReadWrite(uintptr_t addr, void* dramAddr, size_t size, s32 direction);
void Rumble_Init(PadMgr*, s32);
void Rumble_Shake2(f32, u8, u8, u8);
void Rumble_Shake(f32, u8, u8, u8);
void Rumble_Reset();
void Rumble_Destroy(void);
u32 Rumble_IsEnabled();
void Rumble_Stop();
void Rumble_Clear();
void Rumble_Enable(u32);




void ViMode_LogPrint(OSViMode* viMode);
void ViMode_Configure(ViMode* viMode, s32 mode, s32 type, s32 unk_70, s32 unk_74, s32 unk_78, s32 unk_7C, s32 width,
                      s32 height, s32 unk_left, s32 unk_right, s32 unk_top, s32 unk_bottom);
void ViMode_Save(ViMode* viMode);
void ViMode_Load(ViMode* viMode);
void ViMode_Init(ViMode* viMode);
void ViMode_Destroy(ViMode* viMode);
void ViMode_ConfigureFeatures(ViMode* viMode, s32 viFeatures);*/
void ViMode_Update(ViMode* viMode, Input* input);
/*void func_800ACE70(struct_801664F0* thiss);
void func_800ACE90(struct_801664F0* thiss);
void func_800ACE98(struct_801664F0* thiss, Gfx** gfxp);
void VisMono_Init(VisMono* thiss);
void VisMono_Destroy(VisMono* thiss);
void VisMono_DesaturateTLUT(VisMono* thiss, u16* tex);
Gfx* VisMono_DesaturateDList(VisMono* thiss, Gfx* gfx);
void VisMono_Draw(VisMono* thiss, Gfx** gfxp);
void VisMono_DrawOld(VisMono* thiss);
void func_800AD920(struct_80166500* thiss);
void func_800AD950(struct_80166500* thiss);
void func_800AD958(struct_80166500* thiss, Gfx** gfxp);
void Skybox_Init(GameState* state, SkyboxContext* skyboxCtx, s16 skyboxId);
Mtx* SkyboxDraw_UpdateMatrix(SkyboxContext* skyboxCtx, f32 x, f32 y, f32 z);
void SkyboxDraw_Draw(SkyboxContext* skyboxCtx, GraphicsContext* gfxCtx, s16 skyboxId, s16 blend, f32 x, f32 y, f32 z);
void SkyboxDraw_Update(SkyboxContext* skyboxCtx);
void PlayerCall_InitFuncPtrs(void);
void TransitionUnk_InitGraphics(TransitionUnk* thiss);
void TransitionUnk_InitData(TransitionUnk* thiss);
void TransitionUnk_Destroy(TransitionUnk* thiss);
TransitionUnk* TransitionUnk_Init(TransitionUnk* thiss, s32 row, s32 col);
void TransitionUnk_SetData(TransitionUnk* thiss);
void TransitionUnk_Draw(TransitionUnk* thiss, Gfx**);
void func_800B23E8(TransitionUnk* thiss);


// ? DbCamera_AddVecSph(?);
// ? DbCamera_CalcUpFromPitchYawRoll(?);
// ? DbCamera_SetTextValue(?);
// ? DbCamera_Vec3SToF(?);
// ? DbCamera_Vec3FToS(?);
// ? DbCamera_CopyVec3f(?);
// ? DbCamera_Vec3SToF2(?);
// ? func_800B3F94(?);
// ? func_800B3FF4(?);
// ? func_800B404C(?);
// ? func_800B4088(?);
// ? func_800B41DC(?);
// ? func_800B42C0(?);
// ? func_800B4370(?);
// ? func_800B44E0(?);
// ? DbCamera_PrintPoints(?);
// ? DbCamera_PrintF32Bytes(?);
// ? DbCamera_PrintU16Bytes(?);
// ? DbCamera_PrintS16Bytes(?);
// ? DbCamera_PrintCutBytes(?);
void DbCamera_Init(DbCamera* dbCamera, Camera* cameraPtr);
void DbgCamera_Enable(DbCamera* dbCamera, Camera* cam);
void DbCamera_Update(DbCamera* dbCamera, Camera* cam);
// ? DbCamera_GetFirstAvailableLetter(?);
// ? DbCamera_InitCut(?);
// ? DbCamera_ResetCut(?);
// ? DbCamera_CalcMempakAllocSize(?);
// ? DbCamera_GetMempakAllocSize(?);
// ? DbCamera_DrawSlotLetters(?);
// ? DbCamera_PrintAllCuts(?);
// ? func_800B91B0(?);
void DbCamera_Reset(Camera* cam, DbCamera* dbCam);
// ? DbCamera_UpdateDemoControl(?);
void func_800BB0A0(f32 u, Vec3f* pos, f32* roll, f32* viewAngle, f32* point0, f32* point1, f32* point2, f32* point3);
s32 func_800BB2B4(Vec3f* pos, f32* roll, f32* fov, CutsceneCameraPoint* point, s16* keyframe, f32* curFrame);
s32 Mempak_Init(s32 controllerNb);
s32 Mempak_GetFreeBytes(s32 controllerNb);
s32 Mempak_FindFile(s32 controllerNb, char start, char end);
s32 Mempak_Write(s32 controllerNb, char idx, void* buffer, s32 offset, s32 size);
s32 Mempak_Read(s32 controllerNb, char idx, void* buffer, s32 offset, s32 size);
s32 Mempak_Alloc(s32 controllerNb, char* idx, s32 size);
s32 Mempak_DeleteFile(s32 controllerNb, char idx);
s32 Mempak_GetFileSize(s32 controllerNb, char idx);
void KaleidoManager_LoadOvl(KaleidoMgrOverlay* ovl);
void KaleidoManager_ClearOvl(KaleidoMgrOverlay* ovl);
void KaleidoManager_Init(GlobalContext* globalCtx);
void KaleidoManager_Destroy();
void* KaleidoManager_GetRamAddr(void* vram);
void KaleidoScopeCall_LoadPlayer();
void KaleidoScopeCall_Init(GlobalContext* globalCtx);
void KaleidoScopeCall_Destroy(GlobalContext* globalCtx);
void KaleidoScopeCall_Update(GlobalContext* globalCtx);
void KaleidoScopeCall_Draw(GlobalContext* globalCtx);
void func_800BC490(GlobalContext* globalCtx, s16 point);
s32 func_800BC56C(GlobalContext* globalCtx, s16 arg1);
void func_800BC590(GlobalContext* globalCtx);
void func_800BC5E0(GlobalContext* globalCtx, s32 arg1);

s32 func_800C0CB8(GlobalContext* globalCtx);
s32 FrameAdvance_IsEnabled(GlobalContext* globalCtx);
s32 func_800C0D34(GlobalContext* globalCtx, Actor* actor, s16* yaw);
s32 func_800C0DB4(GlobalContext* globalCtx, Vec3f* pos);
void PreRender_SetValuesSave(PreRender* thiss, u32 width, u32 height, void* fbuf, void* zbuf, void* cvg);
void PreRender_Init(PreRender* thiss);
void PreRender_SetValues(PreRender* thiss, u32 width, u32 height, void* fbuf, void* zbuf);
void PreRender_Destroy(PreRender* thiss);
void func_800C0F28(PreRender* thiss, Gfx** gfxp, void* buf, void* bufSave);
void func_800C1258(PreRender* thiss, Gfx** gfxp);
void func_800C170C(PreRender* thiss, Gfx** gfxp, void* fbuf, void* fbufSave, u32 r, u32 g, u32 b, u32 a);
void func_800C1AE8(PreRender* thiss, Gfx** gfxp, void* fbuf, void* fbufSave);
void func_800C1B24(PreRender* thiss, Gfx** gfxp, void* fbuf, void* cvgSave);
void func_800C1E9C(PreRender* thiss, Gfx** gfxp);
void func_800C1F20(PreRender* thiss, Gfx** gfxp);
void func_800C1FA4(PreRender* thiss, Gfx** gfxp);
void func_800C20B4(PreRender* thiss, Gfx** gfxp);
void func_800C2118(PreRender* thiss, Gfx** gfxp);
void func_800C213C(PreRender* thiss, Gfx** gfxp);
void func_800C24BC(PreRender* thiss, Gfx** gfxp);
void func_800C24E0(PreRender* thiss, Gfx** gfxp);
void func_800C2500(PreRender* thiss, s32 x, s32 y);
void func_800C2FE4(PreRender* thiss);
void PreRender_Calc(PreRender* thiss);
void THGA_Ct(TwoHeadGfxArena* thga, Gfx* start, u32 size);
void THGA_Dt(TwoHeadGfxArena* thga);
u32 THGA_IsCrash(TwoHeadGfxArena* thga);
void THGA_Init(TwoHeadGfxArena* thga);
s32 THGA_GetSize(TwoHeadGfxArena* thga);
Gfx* THGA_GetHead(TwoHeadGfxArena* thga);
void THGA_SetHead(TwoHeadGfxArena* thga, Gfx* start);
Gfx* THGA_GetTail(TwoHeadGfxArena* thga);
Gfx* THGA_AllocStartArray8(TwoHeadGfxArena* thga, u32 count);
Gfx* THGA_AllocStart8(TwoHeadGfxArena* thga);
Gfx* THGA_AllocStart8Wrapper(TwoHeadGfxArena* thga);
Gfx* THGA_AllocEnd(TwoHeadGfxArena* thga, u32 size);
Gfx* THGA_AllocEndArray64(TwoHeadGfxArena* thga, u32 count);
Gfx* THGA_AllocEnd64(TwoHeadGfxArena* thga);
Gfx* THGA_AllocEndArray16(TwoHeadGfxArena* thga, u32 count);
Gfx* THGA_AllocEnd16(TwoHeadGfxArena* thga);

void Audio_StopAllBanks(void);
void func_800C3C80(AudioMgr* audioMgr);
void AudioMgr_HandleRetrace(AudioMgr* audioMgr);
void AudioMgr_HandlePRENMI(AudioMgr* audioMgr);
void AudioMgr_ThreadEntry(void* arg0);
void AudioMgr_Unlock(AudioMgr* audioMgr);
void AudioMgr_Init(AudioMgr* audioMgr, void* stack, OSPri pri, OSId id, SchedContext* sched, IrqMgr* irqMgr);
void TitleSetup_InitImpl(GameState* gameState);
void TitleSetup_Destroy(GameState* gameState);
void TitleSetup_Init(GameState* gameState);




ListAlloc* ListAlloc_Init(ListAlloc* thiss);
void* ListAlloc_Alloc(ListAlloc* thiss, u32 size);
void ListAlloc_Free(ListAlloc* thiss, void* data);
void ListAlloc_FreeAll(ListAlloc* thiss);
void Main_LogSystemHeap(void);
void Main(void* arg);
OSMesgQueue* PadMgr_LockSerialMesgQueue(PadMgr* padmgr);
void PadMgr_UnlockSerialMesgQueue(PadMgr* padmgr, OSMesgQueue* ctrlrqueue);
void PadMgr_LockPadData(PadMgr* padmgr);
void PadMgr_UnlockPadData(PadMgr* padmgr);
void PadMgr_RumbleControl(PadMgr* padmgr);
void PadMgr_RumbleStop(PadMgr* padmgr);
void PadMgr_RumbleReset(PadMgr* padmgr);
void PadMgr_RumbleSet(PadMgr* padmgr, u8* ctrlrRumbles);
void PadMgr_ProcessInputs(PadMgr* padmgr);
void PadMgr_HandleRetraceMsg(PadMgr* padmgr);
void PadMgr_HandlePreNMI(PadMgr* padmgr);
// This function must remain commented out, because it is called incorrectly in
// fault.c (actual bug in game), and the compiler notices and won't compile it
// void PadMgr_RequestPadData(PadMgr* padmgr, Input* inputs, s32 mode);
void PadMgr_Init(PadMgr* padmgr, OSMesgQueue* siIntMsgQ, IrqMgr* irqMgr, OSId id, OSPri priority, void* stack);
void Sched_SwapFrameBuffer(CfbInfo* cfbInfo);
void func_800C84E4(SchedContext* sc, CfbInfo* cfbInfo);
void Sched_HandleReset(SchedContext* sc);
void Sched_HandleStart(SchedContext* sc);
void Sched_QueueTask(SchedContext* sc, OSScTask* task);
void Sched_Yield(SchedContext* sc);
OSScTask* func_800C89D4(SchedContext* sc, OSScTask* task);
s32 Sched_Schedule(SchedContext* sc, OSScTask** sp, OSScTask** dp, s32 state);
void func_800C8BC4(SchedContext* sc, OSScTask* task);
u32 Sched_IsComplete(SchedContext* sc, OSScTask* task);
void Sched_RunTask(SchedContext* sc, OSScTask* spTask, OSScTask* dpTask);
void Sched_HandleEntry(SchedContext* sc);
void Sched_HandleRetrace(SchedContext* sc);
void Sched_HandleRSPDone(SchedContext* sc);
void Sched_HandleRDPDone(SchedContext* sc);
void Sched_SendEntryMsg(SchedContext* sc);
void Sched_ThreadEntry(void* arg);
void Sched_Init(SchedContext* sc, void* stack, OSPri priority, UNK_TYPE arg3, UNK_TYPE arg4, IrqMgr* irqMgr);
void SpeedMeter_InitImpl(SpeedMeter* thiss, u32 arg1, u32 y);
void SpeedMeter_Init(SpeedMeter* thiss);
void SpeedMeter_Destroy(SpeedMeter* thiss);
void SpeedMeter_DrawTimeEntries(SpeedMeter* thiss, GraphicsContext* gfxCtx);
void SpeedMeter_InitAllocEntry(SpeedMeterAllocEntry* entry, u32 maxval, u32 val, u16 backColor, u16 foreColor, u32 ulx,
                               u32 lrx, u32 uly, u32 lry);
void SpeedMeter_DrawAllocEntry(SpeedMeterAllocEntry* thiss, GraphicsContext* gfxCtx);
void SpeedMeter_DrawAllocEntries(SpeedMeter* meter, GraphicsContext* gfxCtx, GameState* state);

void Matrix_ScaleTrans(Mtx* mtx, f32 scaleX, f32 scaleY, f32 scaleZ, f32 posX, f32 posY, f32 posZ) ;
u64* SysUcode_GetUCodeBoot(void);
u64 SysUcode_GetUCodeBootSize(void);
u64* SysUcode_GetUCode(void);
u64* SysUcode_GetUCodeData(void);
void Rumble_Update(RumbleStruct* arg0);
void func_800D3140(RumbleStruct* arg0);
void func_800D3178(RumbleStruct* arg0);
void func_800D31A0(void);
void func_800D31F0(void);
void func_800D3210(void);
void IrqMgr_AddClient(IrqMgr* thiss, IrqMgrClient* c, OSMesgQueue* msgQ);
void IrqMgr_RemoveClient(IrqMgr* thiss, IrqMgrClient* c);
void IrqMgr_SendMesgForClient(IrqMgr* thiss, OSMesg msg);
void IrqMgr_JamMesgForClient(IrqMgr* thiss, OSMesg msg);
void IrqMgr_HandlePreNMI(IrqMgr* thiss);
void IrqMgr_CheckStack();
void IrqMgr_HandlePRENMI450(IrqMgr* thiss);
void IrqMgr_HandlePRENMI480(IrqMgr* thiss);
void IrqMgr_HandlePRENMI500(IrqMgr* thiss);
void IrqMgr_HandleRetrace(IrqMgr* thiss);
void IrqMgr_ThreadEntry(void* arg0);
void IrqMgr_Init(IrqMgr* thiss, void* stack, OSPri pri, u8 retraceCount);

void DebugArena_CheckPointer(void* ptr, u32 size, const char* name, const char* action);
void* DebugArena_Malloc(u32 size);
void* DebugArena_MallocDebug(u32 size, const char* file, s32 line);
void* DebugArena_MallocR(u32 size);
void* DebugArena_MallocRDebug(u32 size, const char* file, s32 line);
void* DebugArena_Realloc(void* ptr, u32 newSize);
void* DebugArena_ReallocDebug(void* ptr, u32 newSize, const char* file, s32 line);
void DebugArena_Free(void* ptr);
void DebugArena_FreeDebug(void* ptr, const char* file, s32 line);
void* DebugArena_Calloc(u32 num, u32 size);
void DebugArena_Display(void);
void DebugArena_GetSizes(u32* outMaxFree, u32* outFree, u32* outAlloc);
void DebugArena_Check(void);
void DebugArena_Init(void* start, u32 size);
void DebugArena_Cleanup(void);
u8 DebugArena_IsInitalized(void);


void Fault_SleepImpl(u32);
void Fault_ClientProcessThread(void* arg);
void Fault_ProcessClientContext(FaultClientContext*);
u32 Fault_ProcessClient(u32, u32, u32);
void Fault_AddClient(FaultClient*, void*, void*, void*);
void Fault_RemoveClient(FaultClient*);
void Fault_AddAddrConvClient(FaultAddrConvClient*, void*, void*);
void Fault_RemoveAddrConvClient(FaultAddrConvClient*);
u32 Fault_ConvertAddress(FaultAddrConvClient*);
void Fault_Sleep(u32);
void Fault_PadCallback(Input*);
void Fault_UpdatePadImpl();
u32 Fault_WaitForInputImpl();
void Fault_WaitForInput();
void Fault_DrawRec(s32, s32, s32, s32, u16);
void Fault_FillScreenBlack();
void Fault_FillScreenRed();
void Fault_DrawCornerRec(u16);
void Fault_PrintFReg(s32, f32*);
void Fault_LogFReg(s32, f32*);
void Fault_PrintFPCR(u32);
void Fault_LogFPCR(u32);
void Fault_PrintThreadContext(OSThread*);
void Fault_LogThreadContext(OSThread*);
OSThread* Fault_FindFaultedThread();
void Fault_Wait5Seconds();
void Fault_WaitForButtonCombo();
void Fault_DrawMemDumpPage(const char*, u32*, u32);
void Fault_DrawMemDump(u32, u32, u32, u32);
void Fault_WalkStack(u32* spPtr, u32* pcPtr, u32* raPtr);
void Fault_DrawStackTrace(OSThread* thread, s32 x, s32 y, s32 height);
void Fault_LogStackTrace(OSThread* thread, s32 height);
void Fault_ResumeThread(OSThread*);
void Fault_CommitFB();
void Fault_ProcessClients();
void Fault_UpdatePad();
void Fault_ThreadEntry(void*);
void Fault_SetFB(void*, u16, u16);
void Fault_Init(void);
void Fault_HangupFaultClient(const char*, const char*);
void Fault_AddHungupAndCrashImpl(const char*, const char*);
void Fault_AddHungupAndCrash(const char*, u32);
void FaultDrawer_SetOsSyncPrintfEnabled(u32);
void FaultDrawer_DrawRecImpl(s32, s32, s32, s32, u16);
void FaultDrawer_DrawChar(char);
s32 FaultDrawer_ColorToPrintColor(u16);
void FaultDrawer_UpdatePrintColor();
void FaultDrawer_SetForeColor(u16);
void FaultDrawer_SetBackColor(u16);
void FaultDrawer_SetFontColor(u16);
void FaultDrawer_SetCharPad(s8, s8);
void FaultDrawer_SetCursor(s32, s32);
void FaultDrawer_FillScreen();
void* FaultDrawer_FormatStringFunc(void*, const char*, u32);
void FaultDrawer_VPrintf(const char*, char*);
void FaultDrawer_Printf(const char*, ...);
void FaultDrawer_DrawText(s32, s32, const char*, ...);
void FaultDrawer_SetDrawerFB(void*, u16, u16);
void FaultDrawer_SetInputCallback(void (*)());
void FaultDrawer_SetDefault();


void GfxPrint_SetColor(GfxPrint* thiss, u32 r, u32 g, u32 b, u32 a);
void GfxPrint_SetPosPx(GfxPrint* thiss, s32 x, s32 y);
void GfxPrint_SetPos(GfxPrint* thiss, s32 x, s32 y);
void GfxPrint_SetBasePosPx(GfxPrint* thiss, s32 x, s32 y);
void GfxPrint_Init(GfxPrint* thiss);
void GfxPrint_Destroy(GfxPrint* thiss);
void GfxPrint_Open(GfxPrint* thiss, Gfx* dList);
Gfx* GfxPrint_Close(GfxPrint* thiss);
s32 GfxPrint_Printf(GfxPrint* thiss, const char* fmt, ...);
void func_800FBCE0();
void func_800FBFD8(void);
void* Overlay_AllocateAndLoad(void* vRomStart, void* vRomEnd, void* vRamStart, void* vRamEnd);
void MtxConv_F2L(Mtx* m1, MtxF* m2);
void MtxConv_L2F(MtxF* m1, Mtx* m2);
void Overlay_Relocate(void* allocatedVRamAddress, OverlayRelocationSection* overlayInfo, void* vRamAddress);
s32 Overlay_Load(void* vRomStart, void* vRomEnd, void* vRamStart, void* vRamEnd, void* allocatedVRamAddress);
// ? func_800FC800(?);
// ? func_800FC83C(?);
// ? func_800FCAB4(?);
void SystemHeap_Init(void* start, u32 size);
void PadUtils_Init(Input* input);
void func_800FCB70(void);
void PadUtils_ResetPressRel(Input* input);
u32 PadUtils_CheckCurExact(Input* input, u16 value);
u32 PadUtils_CheckCur(Input* input, u16 key);
u32 PadUtils_CheckPressed(Input* input, u16 key);
u32 PadUtils_CheckReleased(Input* input, u16 key);
u16 PadUtils_GetCurButton(Input* input);
u16 PadUtils_GetPressButton(Input* input);
s8 PadUtils_GetCurX(Input* input);
s8 PadUtils_GetCurY(Input* input);
void PadUtils_SetRelXY(Input* input, s32 x, s32 y);
s8 PadUtils_GetRelXImpl(Input* input);
s8 PadUtils_GetRelYImpl(Input* input);
s8 PadUtils_GetRelX(Input* input);
s8 PadUtils_GetRelY(Input* input);
void PadUtils_UpdateRelXY(Input* input);
s32 PadSetup_Init(OSMesgQueue* mq, u8* outMask, OSContStatus* status);

f32 ceilf(f32 x);
f32 truncf(f32 x);
f32 roundf(f32 x);
f32 nearbyintf(f32 x);

u32 Rand_Next(void);
void Rand_Seed(u32 seed);
f32 Rand_ZeroOne(void);
f32 Rand_Centered(void);
u32 Rand_Next_Variable(u32* rndNum);
f32 Rand_ZeroOne_Variable(u32* rndNum);
f32 Rand_Centered_Variable(u32* rndNum);

#ifndef USE_NATIVE_MALLOC
u32 ArenaImpl_GetFillAllocBlock(Arena* arena);
u32 ArenaImpl_GetFillFreeBlock(Arena* arena);
u32 ArenaImpl_GetCheckFreeBlock(Arena* arena);
void ArenaImpl_SetFillAllocBlock(Arena* arena);
void ArenaImpl_SetFillFreeBlock(Arena* arena);
void ArenaImpl_SetCheckFreeBlock(Arena* arena);
void ArenaImpl_UnsetFillAllocBlock(Arena* arena);
void ArenaImpl_UnsetFillFreeBlock(Arena* arena);
void ArenaImpl_UnsetCheckFreeBlock(Arena* arena);
void ArenaImpl_SetDebugInfo(ArenaNode* node, const char* file, s32 line, Arena* arena);
void ArenaImpl_LockInit(Arena* arena);
void ArenaImpl_Lock(Arena* arena);
void ArenaImpl_Unlock(Arena* arena);
ArenaNode* ArenaImpl_GetNextBlock(ArenaNode* node);
ArenaNode* ArenaImpl_GetPrevBlock(ArenaNode* node);
ArenaNode* ArenaImpl_GetLastBlock(Arena* arena);
void __osMallocInit(Arena* arena, void* start, u32 size);
void __osMallocAddBlock(Arena* arena, void* start, s32 size);
void ArenaImpl_RemoveAllBlocks(Arena* arena);
void __osMallocCleanup(Arena* arena);
u8 __osMallocIsInitalized(Arena* arena);
void __osMalloc_FreeBlockTest(Arena* arena, ArenaNode* node);
void* __osMalloc_NoLockDebug(Arena* arena, u32 size, const char* file, s32 line);
void* __osMallocDebug(Arena* arena, u32 size, const char* file, s32 line);
void* __osMallocRDebug(Arena* arena, u32 size, const char* file, s32 line);
void* __osMalloc_NoLock(Arena* arena, u32 size);
void* __osMalloc(Arena* arena, u32 size);
void* __osMallocR(Arena* arena, u32 size);
void __osFree_NoLock(Arena* arena, void* ptr);
void __osFree(Arena* arena, void* ptr);
void __osFree_NoLockDebug(Arena* arena, void* ptr, const char* file, s32 line);
void __osFreeDebug(Arena* arena, void* ptr, const char* file, s32 line);
void* __osRealloc(Arena* arena, void* ptr, u32 newSize);
void* __osReallocDebug(Arena* arena, void* ptr, u32 newSize, const char* file, s32 line);
void ArenaImpl_GetSizes(Arena* arena, u32* outMaxFree, u32* outFree, u32* outAlloc);
void __osDisplayArena(Arena* arena);
void ArenaImpl_FaultClient(Arena* arena);
u32 __osCheckArena(Arena* arena);
u8 func_800FF334(Arena* arena);
#endif

s32 PrintUtils_VPrintf(PrintCallback* pfn, const char* fmt, va_list args);
s32 PrintUtils_Printf(PrintCallback* pfn, const char* fmt, ...);
void Sleep_Cycles(OSTime cycles);
void Sleep_Nsec(u32 nsec);
void Sleep_Usec(u32 usec);
void Sleep_Msec(u32 ms);
void Sleep_Sec(u32 sec);

s32 osPfsFreeBlocks(OSPfs* pfs, s32* leftoverBytes);

s16 sins(u16);
OSTask* _VirtualToPhysicalTask(OSTask* intp);
void osSpTaskLoad(OSTask* task);
void osSpTaskStartGo(OSTask* task);
void __osSiCreateAccessQueue(void);
void __osSiGetAccess(void);
void __osSiRelAccess(void);
s32 osContInit(OSMesgQueue* mq, u8* ctl_present_bitfield, OSContStatus* status);
void __osContGetInitData(u8* ctl_present_bitfield, OSContStatus* status);
void __osPackRequestData(u8 poll);
s32 osContStartReadData(OSMesgQueue* mq);
void osContGetReadData(OSContPad* pad);
void __osPackReadData(void);

s32 __osSpRawStartDma(s32 direction, void* devAddr, void* dramAddr, u32 size);
s32 __osSiRawStartDma(s32 dir, void* addr);
void osSpTaskYield(void);
s32 __osPfsGetNextPage(OSPfs* pfs, u8* bank, __OSInode* inode, __OSInodeUnit* page);
s32 osPfsReadWriteFile(OSPfs* pfs, s32 fileNo, u8 flag, s32 offset, s32 size, u8* data);
s32 __osPfsGetStatus(OSMesgQueue* queue, s32 channel);
void __osPfsRequestOneChannel(s32 channel, u8 poll);
void __osPfsGetOneChannelData(s32 channel, OSContStatus* contData);

s32 osPfsAllocateFile(OSPfs* pfs, u16 companyCode, u32 gameCode, u8* gameName, u8* extName, s32 length, s32* fileNo);
s32 __osPfsDeclearPage(OSPfs* pfs, __OSInode* inode, s32 fileSizeInPages, s32* startPage, u8 bank, s32* decleared,
                       s32* finalPage);

u16 __osSumcalc(u8* ptr, s32 length);
s32 __osIdCheckSum(u16* ptr, u16* csum, u16* icsum);
s32 __osRepairPackId(OSPfs* pfs, __OSPackId* badid, __OSPackId* newid);
s32 __osCheckPackId(OSPfs* pfs, __OSPackId* check);
s32 __osGetId(OSPfs* pfs);
s32 __osCheckId(OSPfs* pfs);
s32 __osPfsRWInode(OSPfs* pfs, __OSInode* inode, u8 flag, u8 bank);
s32 osPfsFindFile(OSPfs* pfs, u16 companyCode, u32 gameCode, u8* gameName, u8* extName, s32* fileNo);
s32 osAfterPreNMI(void);
s32 osContStartQuery(OSMesgQueue* mq);
void osContGetQuery(OSContStatus* data);

OSYieldResult osSpTaskYielded(OSTask* task);
u32 __osSpDeviceBusy(void);
s32 osAiSetFrequency(u32 frequency);
OSThread* __osGetActiveQueue(void);


u32 osDpGetStatus(void);
void osDpSetStatus(u32 status);
s32 osPfsDeleteFile(OSPfs* pfs, u16 companyCode, u32 gameCode, u8* gameName, u8* extName);
s32 __osPfsReleasePages(OSPfs* pfs, __OSInode* inode, u8 initialPage, u8 bank, __OSInodeUnit* finalPage);

f32 cosf(f32);
s16 coss(u16);
void osViSetEvent(OSMesgQueue* mq, OSMesg m, u32 retraceCount);
s32 osPfsIsPlug(OSMesgQueue* mq, u8* pattern);
void __osPfsRequestData(u8 poll);
void __osPfsGetInitData(u8* pattern, OSContStatus* contData);
void guS2DInitBg(uObjBg* bg);
s32 __osPfsSelectBank(OSPfs* pfs, u8 bank);
s32 osContSetCh(u8 ch);
s32 osPfsFileState(OSPfs* pfs, s32 fileNo, OSPfsState* state);
s32 osPfsInitPak(OSMesgQueue* mq, OSPfs* pfs, s32 channel);
s32 __osPfsCheckRamArea(OSPfs* pfs);
s32 osPfsChecker(OSPfs* pfs);
s32 func_80105788(OSPfs* pfs, __OSInodeCache* cache);
s32 func_80105A60(OSPfs* pfs, __OSInodeUnit fpage, __OSInodeCache* cache);
u32 osAiGetLength(void);

s32 __osContRamWrite(OSMesgQueue* mq, s32 channel, u16 address, u8* buffer, s32 force);
s32 __osContRamRead(OSMesgQueue* ctrlrqueue, s32 channel, u16 addr, u8* data);
u8 __osContAddressCrc(u16 addr);
u8 __osContDataCrc(u8* data);
s32 osSetTimer(OSTimer* timer, OSTime countdown, OSTime interval, OSMesgQueue* mq, OSMesg msg);
u32 __osSpGetStatus(void);
void __osSpSetStatus(u32 status);
void osWritebackDCacheAll(void);
OSThread* __osGetCurrFaultedThread(void);

// ? __d_to_ll(?);
// ? __f_to_ll(?);
// ? __d_to_ull(?);
// ? __f_to_ull(?);
// ? __ll_to_d(?);
// ? __ll_to_f(?);
// ? __ull_to_d(?);
// ? __ull_to_f(?);
u32* osViGetCurrentFramebuffer(void);
s32 __osSpSetPc(void* pc);
f32 absf(f32);
void* func_80106860(void* ptr, s32 val, size_t size);
void* func_801068B0(void* dst, void* src, size_t size);
void Message_UpdateOcarinaGame(GlobalContext* globalCtx);
u8 Message_ShouldAdvance(GlobalContext* globalCtx);
void Message_CloseTextbox(GlobalContext*);
void Message_StartTextbox(GlobalContext* globalCtx, u16 textId, Actor* actor);
void Message_ContinueTextbox(GlobalContext* globalCtx, u16 textId);
void func_8010BD58(GlobalContext* globalCtx, u16 arg1);
void func_8010BD88(GlobalContext* globalCtx, u16 arg1);
u8 Message_GetState(MessageContext* msgCtx);
void Message_Draw(GlobalContext* globalCtx);
void Message_Update(GlobalContext* globalCtx);
void Message_SetTables(void);
void GameOver_Init(GlobalContext* globalCtx);
void GameOver_FadeInLights(GlobalContext* globalCtx);
void GameOver_Update(GlobalContext* globalCtx);
void func_80110990(GlobalContext* globalCtx);
void func_801109B0(GlobalContext* globalCtx);
void Message_Init(GlobalContext* globalCtx);
void func_80112098(GlobalContext* globalCtx);

void Title_Init(GameState* thissx);
void Title_Destroy(GameState* thissx);
void Select_Init(GameState* thissx);
void Select_Destroy(GameState* thissx);

#ifdef __cplusplus
}
#endif

*/