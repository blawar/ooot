.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .rodata

.balign 16

glabel gSoundFontTable
    .incbin "baserom.z64", 0xBCC270, 0x270

glabel gSequenceFontTable
    .incbin "baserom.z64", 0xBCC4E0, 0x1C0

glabel gSequenceTable
    .incbin "baserom.z64", 0xBCC6A0, 0x6F0

glabel gSampleBankTable
    .incbin "baserom.z64", 0xBCCD90, 0x80

glabel rspAspMainData
    .incbin "baserom.z64", 0xBCCE10, 0x2E0
glabel rspAspMainDataEnd

glabel rspF3DZEXText
    .incbin "baserom.z64", 0xBCD0F0, 0x1630

glabel rspF3DZEXData
    .incbin "baserom.z64", 0xBCE720, 0x420

glabel rspS2DEXData
    .incbin "baserom.z64", 0xBCEB40, 0x390

glabel rspJpegData
    .incbin "baserom.z64", 0xBCEED0, 0x60
