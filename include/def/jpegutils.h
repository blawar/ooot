#pragma once
#ifdef INTERNAL_SRC_CODE_JPEGUTILS_C
s32 JpegUtils_GetHuffmanCodes(u8* codesLengths, u16* codes);
s32 JpegUtils_ParseHuffmanCodesLengths(u8* ptr, u8* codesLengths);
u32 JpegUtils_ProcessHuffmanTable(u8* dht, JpegHuffmanTable* ht, u8* codesLengths, u16* codes, u8 count);
u32 JpegUtils_ProcessHuffmanTableImpl(u8* data, JpegHuffmanTable* ht, u8* codesLengths, u16* codes, u8 isAc);
u32 JpegUtils_ProcessHuffmanTableImplOld(u8* dht, JpegHuffmanTableOld* ht, u8* codesLengths, u16* codes);
void JpegUtils_ProcessQuantizationTable(u8* dqt, JpegQuantizationTable* qt, u8 count);
s32 JpegUtils_SetHuffmanTable(u8* data, JpegHuffmanTable* ht, u16* codes);
void JpegUtils_SetHuffmanTableOld(u8* data, JpegHuffmanTableOld* ht, u8* codesLengths, u16* codes, s16 count, u8 isAc);
#else
s32 JpegUtils_GetHuffmanCodes(u8* codesLengths, u16* codes);
s32 JpegUtils_ParseHuffmanCodesLengths(u8* ptr, u8* codesLengths);
u32 JpegUtils_ProcessHuffmanTable(u8* dht, struct JpegHuffmanTable* ht, u8* codesLengths, u16* codes, u8 count);
u32 JpegUtils_ProcessHuffmanTableImpl(u8* data, struct JpegHuffmanTable* ht, u8* codesLengths, u16* codes, u8 isAc);
u32 JpegUtils_ProcessHuffmanTableImplOld(u8* dht, struct JpegHuffmanTableOld* ht, u8* codesLengths, u16* codes);
void JpegUtils_ProcessQuantizationTable(u8* dqt, struct JpegQuantizationTable* qt, u8 count);
s32 JpegUtils_SetHuffmanTable(u8* data, struct JpegHuffmanTable* ht, u16* codes);
void JpegUtils_SetHuffmanTableOld(u8* data, struct JpegHuffmanTableOld* ht, u8* codesLengths, u16* codes, s16 count, u8 isAc);
#endif
