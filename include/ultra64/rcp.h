#ifndef ULTRA64_RCP_H
#define ULTRA64_RCP_H

uintptr_t& hw_reg(u32 reg);
//#define HW_REG(reg, type) *(type*)((reg) | 0xA0000000)
#define HW_REG(reg, type) hw_reg(reg)

const u32 AI_DRAM_ADDR_REG = 0x04500000;
const u32 AI_LEN_REG = 0x04500004;
const u32 AI_CONTROL_REG = 0x04500008;
const u32 AI_STATUS_REG = 0x0450000C;
const u32 AI_DACRATE_REG = 0x04500010;
const u32 AI_BITRATE_REG = 0x04500014;

#define AI_STATUS_AI_FULL (1 << 31)
#define AI_STATUS_AI_BUSY (1 << 30)

const u32 VI_STATUS_REG = 0x04400000; 

#define VI_CONTROL_REG          VI_STATUS_REG
const u32 VI_ORIGIN_REG = 0x04400004; 

#define VI_DRAM_ADDR_REG        VI_ORIGIN_REG
const u32 VI_WIDTH_REG = 0x04400008; 

#define VI_H_WIDTH_REG          VI_WIDTH_REG
const u32 VI_INTR_REG = 0x0440000C; 

#define VI_V_INTER_REG          VI_H_WIDTH_REG
const u32 VI_CURRENT_REG = 0x04400010; 

#define VI_V_CURRENT_LINE_REG   VI_CURRENT_REG
const u32 VI_BURST_REG = 0x04400014; 

#define VI_TIMING_REG           VI_BURST_REG
const u32 VI_V_SYNC_REG = 0x04400018;   //VI vertical sync

const u32 VI_H_SYNC_REG = 0x0440001C;   //VI horizontal sync

const u32 VI_LEAP_REG = 0x04400020;   //VI horizontal sync leap

#define VI_H_SYNC_LEAP_REG      VI_LEAP_REG
const u32 VI_H_START_REG = 0x04400024;   //VI horizontal video

#define VI_H_VIDEO_REG          VI_H_START_REG
const u32 VI_V_START_REG = 0x04400028;   //VI vertical video

#define VI_V_VIDEO_REG          VI_V_START_REG
const u32 VI_V_BURST_REG = 0x0440002C;   //VI vertical burst

const u32 VI_X_SCALE_REG = 0x04400030;   //VI x-scale

const u32 VI_Y_SCALE_REG = 0x04400034;   //VI y-scale


#define SP_IMEM_START           0x04001000
#define SP_DMEM_START           0x04000000

const u32 SP_MEM_ADDR_REG = 0x04040000; 

const u32 SP_DRAM_ADDR_REG = 0x04040004; 

const u32 SP_RD_LEN_REG = 0x04040008; 

const u32 SP_WR_LEN_REG = 0x0404000C; 

const u32 SP_STATUS_REG = 0x04040010; 

const u32 SP_PC_REG = 0x04080000; 


const u32 PI_DRAM_ADDR_REG = 0x04600000;   //PI DRAM address

const u32 PI_CART_ADDR_REG = 0x04600004;   //PI pbus (cartridge) address

const u32 PI_RD_LEN_REG = 0x04600008;   //PI read length

const u32 PI_WR_LEN_REG = 0x0460000C;   //PI write length

const u32 PI_STATUS_REG = 0x04600010;   //PI status

const u32 PI_BSD_DOM1_LAT_REG = 0x04600014;   //PI dom1 latency

const u32 PI_DOMAIN1_REG = 0x04600014; 

const u32 PI_BSD_DOM1_PWD_REG = 0x04600018;   //PI dom1 pulse width

const u32 PI_BSD_DOM1_PGS_REG = 0x0460001C;   //PI dom1 page size

const u32 PI_BSD_DOM1_RLS_REG = 0x04600020;   //PI dom1 release

const u32 PI_BSD_DOM2_LAT_REG = 0x04600024;   //PI dom2 latency

const u32 PI_DOMAIN2_REG = 0x04600024; 

const u32 PI_BSD_DOM2_PWD_REG = 0x04600028;   //PI dom2 pulse width

const u32 PI_BSD_DOM2_PGS_REG = 0x0460002C;   //PI dom2 page size

const u32 PI_BSD_DOM2_RLS_REG = 0x04600030;   //PI dom2 release


#define PI_STATUS_BUSY          0x1
#define PI_STATUS_IOBUSY        0x2
#define PI_STATUS_ERROR         0x4

#define PI_STATUS_RESET_CONTROLLER  0x1
#define PI_STATUS_CLEAR_INTR        0x2

const u32 SI_DRAM_ADDR_REG = 0x04800000; 

const u32 SI_PIF_ADDR_RD64B_REG = 0x04800004; 

const u32 SI_PIF_ADDR_WR64B_REG = 0x04800010; 

const u32 SI_STATUS_REG = 0x04800018; 


#define SI_STATUS_DMA_BUSY      0x1
#define SI_STATUS_IO_READ_BUSY  0x2
#define SI_STATUS_DMA_ERROR     0x8
#define SI_STATUS_INTERRUPT     (1 << 12)

#define PIF_RAM_START           0x1FC007C0

const u32 MI_INIT_MODE_REG = 0x04300000; 

#define MI_MODE_REG             MI_INIT_MODE_REG
const u32 MI_VERSION_REG = 0x04300004; 

const u32 MI_INTR_REG = 0x04300008; 

const u32 MI_INTR_MASK_REG = 0x0430000C; 


#define VI_NTSC_CLOCK           48681812    /* Hz = 48.681812 MHz */
#define VI_PAL_CLOCK            49656530    /* Hz = 49.656530 MHz */
#define VI_MPAL_CLOCK           48628316    /* Hz = 48.628316 MHz */

#endif
