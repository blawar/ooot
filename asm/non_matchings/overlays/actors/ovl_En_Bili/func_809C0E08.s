glabel func_809C0E08
/* 01568 809C0E08 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 0156C 809C0E0C AFBF001C */  sw      $ra, 0x001C($sp)           
/* 01570 809C0E10 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 01574 809C0E14 8C820190 */  lw      $v0, 0x0190($a0)           ## 00000190
/* 01578 809C0E18 3C0E809C */  lui     $t6, %hi(func_809C02B8)    ## $t6 = 809C0000
/* 0157C 809C0E1C 44857000 */  mtc1    $a1, $f14                  ## $f14 = 0.00
/* 01580 809C0E20 25CE02B8 */  addiu   $t6, $t6, %lo(func_809C02B8) ## $t6 = 809C02B8
/* 01584 809C0E24 15C2000E */  bne     $t6, $v0, .L809C0E60       
/* 01588 809C0E28 00C08025 */  or      $s0, $a2, $zero            ## $s0 = 00000000
/* 0158C 809C0E2C 3C01809C */  lui     $at, %hi(D_809C1754)       ## $at = 809C0000
/* 01590 809C0E30 C4241754 */  lwc1    $f4, %lo(D_809C1754)($at)  
/* 01594 809C0E34 460E2302 */  mul.s   $f12, $f4, $f14            
/* 01598 809C0E38 0C0400A4 */  jal     sinf
              
/* 0159C 809C0E3C 00000000 */  nop
/* 015A0 809C0E40 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 015A4 809C0E44 44811000 */  mtc1    $at, $f2                   ## $f2 = 1.00
/* 015A8 809C0E48 3C01809C */  lui     $at, %hi(D_809C1758)       ## $at = 809C0000
/* 015AC 809C0E4C C4261758 */  lwc1    $f6, %lo(D_809C1758)($at)  
/* 015B0 809C0E50 46060202 */  mul.s   $f8, $f0, $f6              
/* 015B4 809C0E54 46081281 */  sub.s   $f10, $f2, $f8             
/* 015B8 809C0E58 1000006C */  beq     $zero, $zero, .L809C100C   
/* 015BC 809C0E5C E60A0004 */  swc1    $f10, 0x0004($s0)          ## 00000004
.L809C0E60:
/* 015C0 809C0E60 3C0F809C */  lui     $t7, %hi(func_809C04B4)    ## $t7 = 809C0000
/* 015C4 809C0E64 25EF04B4 */  addiu   $t7, $t7, %lo(func_809C04B4) ## $t7 = 809C04B4
/* 015C8 809C0E68 15E20044 */  bne     $t7, $v0, .L809C0F7C       
/* 015CC 809C0E6C 3C18809C */  lui     $t8, %hi(func_809C0980)    ## $t8 = 809C0000
/* 015D0 809C0E70 3C014100 */  lui     $at, 0x4100                ## $at = 41000000
/* 015D4 809C0E74 44810000 */  mtc1    $at, $f0                   ## $f0 = 8.00
/* 015D8 809C0E78 3C014190 */  lui     $at, 0x4190                ## $at = 41900000
/* 015DC 809C0E7C 4600703E */  c.le.s  $f14, $f0                  
/* 015E0 809C0E80 00000000 */  nop
/* 015E4 809C0E84 4502000F */  bc1fl   .L809C0EC4                 
/* 015E8 809C0E88 44811000 */  mtc1    $at, $f2                   ## $f2 = 18.00
/* 015EC 809C0E8C 3C01809C */  lui     $at, %hi(D_809C175C)       ## $at = 809C0000
/* 015F0 809C0E90 C430175C */  lwc1    $f16, %lo(D_809C175C)($at) 
/* 015F4 809C0E94 460E8302 */  mul.s   $f12, $f16, $f14           
/* 015F8 809C0E98 0C041184 */  jal     cosf
              
/* 015FC 809C0E9C 00000000 */  nop
/* 01600 809C0EA0 3C01809C */  lui     $at, %hi(D_809C1760)       ## $at = 809C0000
/* 01604 809C0EA4 C4321760 */  lwc1    $f18, %lo(D_809C1760)($at) 
/* 01608 809C0EA8 3C01809C */  lui     $at, %hi(D_809C1764)       ## $at = 809C0000
/* 0160C 809C0EAC C4261764 */  lwc1    $f6, %lo(D_809C1764)($at)  
/* 01610 809C0EB0 46120102 */  mul.s   $f4, $f0, $f18             
/* 01614 809C0EB4 46062200 */  add.s   $f8, $f4, $f6              
/* 01618 809C0EB8 1000002D */  beq     $zero, $zero, .L809C0F70   
/* 0161C 809C0EBC E6080004 */  swc1    $f8, 0x0004($s0)           ## 00000004
/* 01620 809C0EC0 44811000 */  mtc1    $at, $f2                   ## $f2 = -0.00
.L809C0EC4:
/* 01624 809C0EC4 3C01809C */  lui     $at, %hi(D_809C1778)       ## $at = 809C0000
/* 01628 809C0EC8 4602703E */  c.le.s  $f14, $f2                  
/* 0162C 809C0ECC 00000000 */  nop
/* 01630 809C0ED0 45020017 */  bc1fl   .L809C0F30                 
/* 01634 809C0ED4 46027101 */  sub.s   $f4, $f14, $f2             
/* 01638 809C0ED8 46007281 */  sub.s   $f10, $f14, $f0            
/* 0163C 809C0EDC 3C01809C */  lui     $at, %hi(D_809C1768)       ## $at = 809C0000
/* 01640 809C0EE0 C4301768 */  lwc1    $f16, %lo(D_809C1768)($at) 
/* 01644 809C0EE4 46105302 */  mul.s   $f12, $f10, $f16           
/* 01648 809C0EE8 0C041184 */  jal     cosf
              
/* 0164C 809C0EEC 00000000 */  nop
/* 01650 809C0EF0 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 01654 809C0EF4 44811000 */  mtc1    $at, $f2                   ## $f2 = 1.00
/* 01658 809C0EF8 3C01809C */  lui     $at, %hi(D_809C176C)       ## $at = 809C0000
/* 0165C 809C0EFC C432176C */  lwc1    $f18, %lo(D_809C176C)($at) 
/* 01660 809C0F00 3C01809C */  lui     $at, %hi(D_809C1770)       ## $at = 809C0000
/* 01664 809C0F04 46009102 */  mul.s   $f4, $f18, $f0             
/* 01668 809C0F08 46041181 */  sub.s   $f6, $f2, $f4              
/* 0166C 809C0F0C E6060004 */  swc1    $f6, 0x0004($s0)           ## 00000004
/* 01670 809C0F10 C4281770 */  lwc1    $f8, %lo(D_809C1770)($at)  
/* 01674 809C0F14 3C01809C */  lui     $at, %hi(D_809C1774)       ## $at = 809C0000
/* 01678 809C0F18 C4301774 */  lwc1    $f16, %lo(D_809C1774)($at) 
/* 0167C 809C0F1C 46004282 */  mul.s   $f10, $f8, $f0             
/* 01680 809C0F20 46105480 */  add.s   $f18, $f10, $f16           
/* 01684 809C0F24 10000012 */  beq     $zero, $zero, .L809C0F70   
/* 01688 809C0F28 E6120000 */  swc1    $f18, 0x0000($s0)          ## 00000000
/* 0168C 809C0F2C 46027101 */  sub.s   $f4, $f14, $f2             
.L809C0F30:
/* 01690 809C0F30 C4261778 */  lwc1    $f6, %lo(D_809C1778)($at)  
/* 01694 809C0F34 46062302 */  mul.s   $f12, $f4, $f6             
/* 01698 809C0F38 0C041184 */  jal     cosf
              
/* 0169C 809C0F3C 00000000 */  nop
/* 016A0 809C0F40 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 016A4 809C0F44 44811000 */  mtc1    $at, $f2                   ## $f2 = 1.00
/* 016A8 809C0F48 3C01809C */  lui     $at, %hi(D_809C177C)       ## $at = 809C0000
/* 016AC 809C0F4C C428177C */  lwc1    $f8, %lo(D_809C177C)($at)  
/* 016B0 809C0F50 3C01809C */  lui     $at, %hi(D_809C1780)       ## $at = 809C0000
/* 016B4 809C0F54 46004282 */  mul.s   $f10, $f8, $f0             
/* 016B8 809C0F58 46025400 */  add.s   $f16, $f10, $f2            
/* 016BC 809C0F5C E6100004 */  swc1    $f16, 0x0004($s0)          ## 00000004
/* 016C0 809C0F60 C4321780 */  lwc1    $f18, %lo(D_809C1780)($at) 
/* 016C4 809C0F64 46009102 */  mul.s   $f4, $f18, $f0             
/* 016C8 809C0F68 46041181 */  sub.s   $f6, $f2, $f4              
/* 016CC 809C0F6C E6060000 */  swc1    $f6, 0x0000($s0)           ## 00000000
.L809C0F70:
/* 016D0 809C0F70 C6080000 */  lwc1    $f8, 0x0000($s0)           ## 00000000
/* 016D4 809C0F74 10000025 */  beq     $zero, $zero, .L809C100C   
/* 016D8 809C0F78 E6080008 */  swc1    $f8, 0x0008($s0)           ## 00000008
.L809C0F7C:
/* 016DC 809C0F7C 27180980 */  addiu   $t8, $t8, %lo(func_809C0980) ## $t8 = 00000980
/* 016E0 809C0F80 17020017 */  bne     $t8, $v0, .L809C0FE0       
/* 016E4 809C0F84 3C01809C */  lui     $at, %hi(D_809C178C)       ## $at = 809C0000
/* 016E8 809C0F88 84990196 */  lh      $t9, 0x0196($a0)           ## 00000196
/* 016EC 809C0F8C 3C01809C */  lui     $at, %hi(D_809C1784)       ## $at = 809C0000
/* 016F0 809C0F90 C4321784 */  lwc1    $f18, %lo(D_809C1784)($at) 
/* 016F4 809C0F94 44995000 */  mtc1    $t9, $f10                  ## $f10 = 0.00
/* 016F8 809C0F98 00000000 */  nop
/* 016FC 809C0F9C 46805420 */  cvt.s.w $f16, $f10                 
/* 01700 809C0FA0 46128302 */  mul.s   $f12, $f16, $f18           
/* 01704 809C0FA4 0C0400A4 */  jal     sinf
              
/* 01708 809C0FA8 00000000 */  nop
/* 0170C 809C0FAC 3C01809C */  lui     $at, %hi(D_809C1788)       ## $at = 809C0000
/* 01710 809C0FB0 C4241788 */  lwc1    $f4, %lo(D_809C1788)($at)  
/* 01714 809C0FB4 C6060000 */  lwc1    $f6, 0x0000($s0)           ## 00000000
/* 01718 809C0FB8 C60A0004 */  lwc1    $f10, 0x0004($s0)          ## 00000004
/* 0171C 809C0FBC 46040082 */  mul.s   $f2, $f0, $f4              
/* 01720 809C0FC0 C6120008 */  lwc1    $f18, 0x0008($s0)          ## 00000008
/* 01724 809C0FC4 46023201 */  sub.s   $f8, $f6, $f2              
/* 01728 809C0FC8 46025400 */  add.s   $f16, $f10, $f2            
/* 0172C 809C0FCC E6080000 */  swc1    $f8, 0x0000($s0)           ## 00000000
/* 01730 809C0FD0 46029101 */  sub.s   $f4, $f18, $f2             
/* 01734 809C0FD4 E6100004 */  swc1    $f16, 0x0004($s0)          ## 00000004
/* 01738 809C0FD8 1000000C */  beq     $zero, $zero, .L809C100C   
/* 0173C 809C0FDC E6040008 */  swc1    $f4, 0x0008($s0)           ## 00000008
.L809C0FE0:
/* 01740 809C0FE0 C426178C */  lwc1    $f6, %lo(D_809C178C)($at)  
/* 01744 809C0FE4 460E3302 */  mul.s   $f12, $f6, $f14            
/* 01748 809C0FE8 0C041184 */  jal     cosf
              
/* 0174C 809C0FEC 00000000 */  nop
/* 01750 809C0FF0 3C01809C */  lui     $at, %hi(D_809C1790)       ## $at = 809C0000
/* 01754 809C0FF4 C4281790 */  lwc1    $f8, %lo(D_809C1790)($at)  
/* 01758 809C0FF8 3C01809C */  lui     $at, %hi(D_809C1794)       ## $at = 809C0000
/* 0175C 809C0FFC C4301794 */  lwc1    $f16, %lo(D_809C1794)($at) 
/* 01760 809C1000 46080282 */  mul.s   $f10, $f0, $f8             
/* 01764 809C1004 46105480 */  add.s   $f18, $f10, $f16           
/* 01768 809C1008 E6120004 */  swc1    $f18, 0x0004($s0)          ## 00000004
.L809C100C:
/* 0176C 809C100C 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 01770 809C1010 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 01774 809C1014 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 01778 809C1018 03E00008 */  jr      $ra                        
/* 0177C 809C101C 00000000 */  nop

