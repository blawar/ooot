#pragma once
#ifdef INTERNAL_SRC_CODE_JPEGDECODER_C
s32 JpegDecoder_Decode(JpegDecoder* decoder, u16* mcuBuff, s32 count, u8 isFollowing, JpegDecoderState* state);
s32 JpegDecoder_ParseNextSymbol(JpegHuffmanTable* hTable, s16* outCoeff, s8* outZeroCount);
s32 JpegDecoder_ProcessMcu(JpegHuffmanTable* hTable0, JpegHuffmanTable* hTable1, u16* mcu, s16* unk);
u16 JpegDecoder_ReadBits(u8 len);
#else
s32 JpegDecoder_Decode(struct JpegDecoder* decoder, u16* mcuBuff, s32 count, u8 isFollowing, struct JpegDecoderState* state);
s32 JpegDecoder_ParseNextSymbol(struct JpegHuffmanTable* hTable, s16* outCoeff, s8* outZeroCount);
s32 JpegDecoder_ProcessMcu(struct JpegHuffmanTable* hTable0, struct JpegHuffmanTable* hTable1, u16* mcu, s16* unk);
u16 JpegDecoder_ReadBits(u8 len);
#endif
