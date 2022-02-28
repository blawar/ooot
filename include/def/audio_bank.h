#pragma once
struct Vec3f;
struct AudioPlayer;
struct ActiveSound;
struct AudioContext;
struct SoundBankEntry;

extern char D_80133390[];
extern char D_80133398[];
extern Vec3f gAudioDefaultPos;
extern f32 D_801333E0;
extern s8 gReverbAdd2;
extern u8 D_801333F0;
extern u8 gAudioPlayerInfoNum[4];
extern AudioPlayer gAudioPlayers[4];
extern ActiveSound gActiveSounds[7][3]; // MAX_CHANNELS_PER_BANK = 3
extern AudioContext gAudioContext;
extern u8 gAudioSfxSwapMode[10];
extern u8 gAudioSfxSwapOff;
extern u16 gAudioSfxSwapSource[10];
extern u16 gAudioSfxSwapTarget[10];
extern u8 gSfxChannelLayout;
extern u8 gSoundBankMuted[];
extern SoundBankEntry* gSoundBanks[7];
extern u32 sAudioSeqCmds[0x100];

void Audio_ChooseActiveSounds(u8 bankId);
void Audio_ClearBGMMute(u8 channelIdx);
u8 Audio_IsSfxPlaying(u32 sfxId);
void Audio_PlayActiveSounds(u8 bankId);
void Audio_PlaySoundGeneral(u16 sfxId, Vec3f* pos, u8 token, f32* freqScale, f32* a4, s8* reverbAdd);
void Audio_ProcessSoundRequest(void);
void Audio_ProcessSoundRequests(void);
void Audio_QueueSeqCmdMute(u8 channelIdx);
void Audio_ResetSounds(void);
void Audio_SetSoundBanksMute(u16 muteMask);
void Audio_StopSfxByBank(u8 bankId);
void Audio_StopSfxById(u32 sfxId);
void Audio_StopSfxByPos(Vec3f*);
void Audio_StopSfxByPosAndBank(u8, Vec3f*);
void Audio_StopSfxByPosAndId(Vec3f* pos, u16 sfxId);
void Audio_StopSfxByTokenAndId(u8, u16);
void Audio_StopByBankIDAndPos(u8, Vec3f*);
void Audio_UpdateActiveSounds(void);
void Audio_StopAllBanks(void);
