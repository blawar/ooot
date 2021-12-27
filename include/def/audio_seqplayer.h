#pragma once
#ifdef INTERNAL_SRC_CODE_AUDIO_SEQPLAYER_C
void* AudioSeq_AudioListPopBack(AudioListItem* list);
void AudioSeq_AudioListPushBack(AudioListItem* list, AudioListItem* item);
void AudioSeq_InitSequencePlayerChannels(s32 playerIdx);
void AudioSeq_InitSequencePlayers(void);
void AudioSeq_ProcessSequences(s32 arg0);
void AudioSeq_ResetSequencePlayer(SequencePlayer* seqPlayer);
void AudioSeq_SequenceChannelDisable(SequenceChannel* channel);
void AudioSeq_SequencePlayerDisable(SequencePlayer* seqPlayer);
void AudioSeq_SequencePlayerDisableAsFinished(SequencePlayer* seqPlayer);
void AudioSeq_SkipForwardSequence(SequencePlayer* seqPlayer);
#else
void* AudioSeq_AudioListPopBack(struct AudioListItem* list);
void AudioSeq_AudioListPushBack(struct AudioListItem* list, struct AudioListItem* item);
void AudioSeq_InitSequencePlayerChannels(s32 playerIdx);
void AudioSeq_InitSequencePlayers(void);
void AudioSeq_ProcessSequences(s32 arg0);
void AudioSeq_ResetSequencePlayer(struct SequencePlayer* seqPlayer);
void AudioSeq_SequenceChannelDisable(struct SequenceChannel* channel);
void AudioSeq_SequencePlayerDisable(struct SequencePlayer* seqPlayer);
void AudioSeq_SequencePlayerDisableAsFinished(struct SequencePlayer* seqPlayer);
void AudioSeq_SkipForwardSequence(struct SequencePlayer* seqPlayer);
#endif
