#pragma once

#define SRAM_SIZE 0x8000
#define SRAM_HEADER_SIZE 0x10

enum SramHeaderField
{
	/* 0x00 */ SRAM_HEADER_SOUND,
	/* 0x01 */ SRAM_HEADER_ZTARGET,
	/* 0x02 */ SRAM_HEADER_LANGUAGE,
	/* 0x03 */ SRAM_HEADER_MAGIC // must be the value of `sZeldaMagic` for save to be considered valid
};
