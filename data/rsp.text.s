.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text

.balign 16

glabel rspAspMainText
    .incbin "baserom.z64", 0xB89260, 0xFB0

glabel rspS2DEXText
    .incbin "baserom.z64", 0xB8A210, 0x18C0

glabel rspJpegTextStart
    .incbin "baserom.z64", 0xB8BAD0, 0xAF0
