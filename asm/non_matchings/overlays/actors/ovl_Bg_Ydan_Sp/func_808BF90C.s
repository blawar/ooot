glabel func_808BF90C
/* 004FC 808BF90C 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 00500 808BF910 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 00504 808BF914 AFA5001C */  sw      $a1, 0x001C($sp)           
/* 00508 808BF918 240E001E */  addiu   $t6, $zero, 0x001E         ## $t6 = 0000001E
/* 0050C 808BF91C 00803025 */  or      $a2, $a0, $zero            ## $a2 = 00000000
/* 00510 808BF920 A48E016A */  sh      $t6, 0x016A($a0)           ## 0000016A
/* 00514 808BF924 AFA60018 */  sw      $a2, 0x0018($sp)           
/* 00518 808BF928 0C01E221 */  jal     func_80078884              
/* 0051C 808BF92C 24044802 */  addiu   $a0, $zero, 0x4802         ## $a0 = 00004802
/* 00520 808BF930 8FA60018 */  lw      $a2, 0x0018($sp)           
/* 00524 808BF934 8FA4001C */  lw      $a0, 0x001C($sp)           
/* 00528 808BF938 0C00B2DD */  jal     Flags_SetSwitch
              
/* 0052C 808BF93C 90C50168 */  lbu     $a1, 0x0168($a2)           ## 00000168
/* 00530 808BF940 8FA60018 */  lw      $a2, 0x0018($sp)           
/* 00534 808BF944 3C18808C */  lui     $t8, %hi(func_808BF97C)    ## $t8 = 808C0000
/* 00538 808BF948 3C19808C */  lui     $t9, %hi(func_808C012C)    ## $t9 = 808C0000
/* 0053C 808BF94C 84CF001C */  lh      $t7, 0x001C($a2)           ## 0000001C
/* 00540 808BF950 2718F97C */  addiu   $t8, $t8, %lo(func_808BF97C) ## $t8 = 808BF97C
/* 00544 808BF954 2739012C */  addiu   $t9, $t9, %lo(func_808C012C) ## $t9 = 808C012C
/* 00548 808BF958 55E00004 */  bnel    $t7, $zero, .L808BF96C     
/* 0054C 808BF95C ACD90164 */  sw      $t9, 0x0164($a2)           ## 00000164
/* 00550 808BF960 10000002 */  beq     $zero, $zero, .L808BF96C   
/* 00554 808BF964 ACD80164 */  sw      $t8, 0x0164($a2)           ## 00000164
/* 00558 808BF968 ACD90164 */  sw      $t9, 0x0164($a2)           ## 00000164
.L808BF96C:
/* 0055C 808BF96C 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 00560 808BF970 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 00564 808BF974 03E00008 */  jr      $ra                        
/* 00568 808BF978 00000000 */  nop

