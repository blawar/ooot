glabel func_80B07E18
/* 008D8 80B07E18 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 008DC 80B07E1C AFBF001C */  sw      $ra, 0x001C($sp)           
/* 008E0 80B07E20 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 008E4 80B07E24 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 008E8 80B07E28 0C00BC65 */  jal     func_8002F194              
/* 008EC 80B07E2C AFA50024 */  sw      $a1, 0x0024($sp)           
/* 008F0 80B07E30 10400007 */  beq     $v0, $zero, .L80B07E50     
/* 008F4 80B07E34 3C0E8016 */  lui     $t6, 0x8016                ## $t6 = 80160000
/* 008F8 80B07E38 3C0580B0 */  lui     $a1, %hi(func_80B07AF4)    ## $a1 = 80B00000
/* 008FC 80B07E3C 24A57AF4 */  addiu   $a1, $a1, %lo(func_80B07AF4) ## $a1 = 80B07AF4
/* 00900 80B07E40 0C2C1D50 */  jal     func_80B07540              
/* 00904 80B07E44 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00908 80B07E48 10000015 */  beq     $zero, $zero, .L80B07EA0   
/* 0090C 80B07E4C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
.L80B07E50:
/* 00910 80B07E50 85CEE730 */  lh      $t6, -0x18D0($t6)          ## FFFFE730
/* 00914 80B07E54 240F0020 */  addiu   $t7, $zero, 0x0020         ## $t7 = 00000020
/* 00918 80B07E58 2418001F */  addiu   $t8, $zero, 0x001F         ## $t8 = 0000001F
/* 0091C 80B07E5C 29C10032 */  slti    $at, $t6, 0x0032           
/* 00920 80B07E60 10200003 */  beq     $at, $zero, .L80B07E70     
/* 00924 80B07E64 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00928 80B07E68 10000002 */  beq     $zero, $zero, .L80B07E74   
/* 0092C 80B07E6C A60F010E */  sh      $t7, 0x010E($s0)           ## 0000010E
.L80B07E70:
/* 00930 80B07E70 A618010E */  sh      $t8, 0x010E($s0)           ## 0000010E
.L80B07E74:
/* 00934 80B07E74 3C0142C8 */  lui     $at, 0x42C8                ## $at = 42C80000
/* 00938 80B07E78 44810000 */  mtc1    $at, $f0                   ## $f0 = 100.00
/* 0093C 80B07E7C C6040090 */  lwc1    $f4, 0x0090($s0)           ## 00000090
/* 00940 80B07E80 4600203C */  c.lt.s  $f4, $f0                   
/* 00944 80B07E84 00000000 */  nop
/* 00948 80B07E88 45020005 */  bc1fl   .L80B07EA0                 
/* 0094C 80B07E8C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00950 80B07E90 44060000 */  mfc1    $a2, $f0                   
/* 00954 80B07E94 0C00BCB3 */  jal     func_8002F2CC              
/* 00958 80B07E98 8FA50024 */  lw      $a1, 0x0024($sp)           
/* 0095C 80B07E9C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
.L80B07EA0:
/* 00960 80B07EA0 0C2C1E78 */  jal     func_80B079E0              
/* 00964 80B07EA4 8FA50024 */  lw      $a1, 0x0024($sp)           
/* 00968 80B07EA8 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 0096C 80B07EAC 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 00970 80B07EB0 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 00974 80B07EB4 03E00008 */  jr      $ra                        
/* 00978 80B07EB8 00000000 */  nop

