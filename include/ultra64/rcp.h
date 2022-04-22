#ifndef ULTRA64_RCP_H
#define ULTRA64_RCP_H

struct HardwareRegisters
{
	uintptr_t SP_MEM_ADDR_REG = 0; // = 0x04040000;
	uintptr_t SP_DRAM_ADDR_REG = 0; // = 0x04040004;
	uintptr_t SP_RD_LEN_REG = 0; // = 0x04040008;
	uintptr_t SP_WR_LEN_REG = 0; // = 0x0404000C;
	uintptr_t SP_STATUS_REG = 0; // = 0x04040010;
	uintptr_t SP_PC_REG = 0; // = 0x04080000;

	uintptr_t MI_INIT_MODE_REG = 0; // = 0x04300000;
	uintptr_t MI_VERSION_REG = 0; // = 0x04300004;
	uintptr_t MI_INTR_REG = 0; // = 0x04300008;
	uintptr_t MI_INTR_MASK_REG = 0; // = 0x0430000C; 

	uintptr_t VI_STATUS_REG = 0; // = 0x04400000;
	uintptr_t VI_ORIGIN_REG = 0; // = 0x04400004;
	uintptr_t VI_WIDTH_REG = 0; // = 0x04400008;
	uintptr_t VI_INTR_REG = 0; // = 0x0440000C;
	uintptr_t VI_CURRENT_REG = 0; // = 0x04400010;
	uintptr_t VI_BURST_REG = 0; // = 0x04400014;
	uintptr_t VI_V_SYNC_REG = 0; // = 0x04400018; // VI vertical sync

	uintptr_t VI_H_SYNC_REG = 0; // = 0x0440001C; // VI horizontal sync
	uintptr_t VI_LEAP_REG = 0; // = 0x04400020; // VI horizontal sync leap
	uintptr_t VI_H_START_REG = 0; // = 0x04400024; // VI horizontal video
	uintptr_t VI_V_START_REG = 0; // = 0x04400028; // VI vertical video
	uintptr_t VI_V_BURST_REG = 0; // = 0x0440002C; // VI vertical burst
	uintptr_t VI_X_SCALE_REG = 0; // = 0x04400030; // VI x-scale
	uintptr_t VI_Y_SCALE_REG = 0; // = 0x04400034; // VI y-scale

	uintptr_t AI_DRAM_ADDR_REG = 0; // = 0x04500000;
	uintptr_t AI_LEN_REG = 0; // = 0x04500004;
	uintptr_t AI_CONTROL_REG = 0; // = 0x04500008;
	intptr_t  AI_STATUS_REG = 0; // = 0x0450000C;
	uintptr_t AI_DACRATE_REG = 0; // = 0x04500010;
	uintptr_t AI_BITRATE_REG = 0; // = 0x04500014;
};

extern HardwareRegisters hw_regs;

#define AI_STATUS_AI_FULL (1 << 31)
#define AI_STATUS_AI_BUSY (1 << 30)


#define PI_STATUS_BUSY          0x1
#define PI_STATUS_IOBUSY        0x2
#define PI_STATUS_ERROR         0x4

#define PI_STATUS_RESET_CONTROLLER  0x1
#define PI_STATUS_CLEAR_INTR        0x2


#define SI_STATUS_DMA_BUSY      0x1
#define SI_STATUS_IO_READ_BUSY  0x2
#define SI_STATUS_DMA_ERROR     0x8
#define SI_STATUS_INTERRUPT     (1 << 12)

#define PIF_RAM_START           0x1FC007C0

#define VI_NTSC_CLOCK           48681812    /* Hz = 48.681812 MHz */
#define VI_PAL_CLOCK            49656530    /* Hz = 49.656530 MHz */
#define VI_MPAL_CLOCK           48628316    /* Hz = 48.628316 MHz */

#endif
