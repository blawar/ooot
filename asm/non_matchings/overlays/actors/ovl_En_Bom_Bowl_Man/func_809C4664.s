glabel func_809C4664
/* 01034 809C4664 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 01038 809C4668 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 0103C 809C466C AFB00018 */  sw      $s0, 0x0018($sp)           
/* 01040 809C4670 AFA40020 */  sw      $a0, 0x0020($sp)           
/* 01044 809C4674 00A08025 */  or      $s0, $a1, $zero            ## $s0 = 00000000
/* 01048 809C4678 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 0104C 809C467C 2484014C */  addiu   $a0, $a0, 0x014C           ## $a0 = 0000014C
/* 01050 809C4680 0C042F6F */  jal     func_8010BDBC              
/* 01054 809C4684 260420D8 */  addiu   $a0, $s0, 0x20D8           ## $a0 = 000020D8
/* 01058 809C4688 8FAE0020 */  lw      $t6, 0x0020($sp)           
/* 0105C 809C468C 85CF022E */  lh      $t7, 0x022E($t6)           ## 0000022E
/* 01060 809C4690 55E20024 */  bnel    $t7, $v0, .L809C4724       
/* 01064 809C4694 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 01068 809C4698 0C041AF2 */  jal     func_80106BC8              
/* 0106C 809C469C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01070 809C46A0 50400020 */  beql    $v0, $zero, .L809C4724     
/* 01074 809C46A4 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 01078 809C46A8 0C041B33 */  jal     func_80106CCC              
/* 0107C 809C46AC 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01080 809C46B0 861807A0 */  lh      $t8, 0x07A0($s0)           ## 000007A0
/* 01084 809C46B4 0018C880 */  sll     $t9, $t8,  2               
/* 01088 809C46B8 02194021 */  addu    $t0, $s0, $t9              
/* 0108C 809C46BC 0C016C69 */  jal     func_8005B1A4              
/* 01090 809C46C0 8D040790 */  lw      $a0, 0x0790($t0)           ## 00000790
/* 01094 809C46C4 8FAA0020 */  lw      $t2, 0x0020($sp)           
/* 01098 809C46C8 24090001 */  addiu   $t1, $zero, 0x0001         ## $t1 = 00000001
/* 0109C 809C46CC 3C038016 */  lui     $v1, 0x8016                ## $v1 = 80160000
/* 010A0 809C46D0 A5490232 */  sh      $t1, 0x0232($t2)           ## 00000232
/* 010A4 809C46D4 8C63FA90 */  lw      $v1, -0x0570($v1)          ## 8015FA90
/* 010A8 809C46D8 3C04809C */  lui     $a0, %hi(D_809C4C2C)       ## $a0 = 809C0000
/* 010AC 809C46DC 3C050001 */  lui     $a1, 0x0001                ## $a1 = 00010000
/* 010B0 809C46E0 846B12D8 */  lh      $t3, 0x12D8($v1)           ## 801612D8
/* 010B4 809C46E4 00B02821 */  addu    $a1, $a1, $s0              
/* 010B8 809C46E8 24844C2C */  addiu   $a0, $a0, %lo(D_809C4C2C)  ## $a0 = 809C4C2C
/* 010BC 809C46EC 11600002 */  beq     $t3, $zero, .L809C46F8     
/* 010C0 809C46F0 00000000 */  nop
/* 010C4 809C46F4 A46012D8 */  sh      $zero, 0x12D8($v1)         ## 801612D8
.L809C46F8:
/* 010C8 809C46F8 0C00084C */  jal     osSyncPrintf
              
/* 010CC 809C46FC 80A51E5D */  lb      $a1, 0x1E5D($a1)           ## 00011E5D
/* 010D0 809C4700 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 010D4 809C4704 00002825 */  or      $a1, $zero, $zero          ## $a1 = 00000000
/* 010D8 809C4708 0C00B7D5 */  jal     func_8002DF54              
/* 010DC 809C470C 24060007 */  addiu   $a2, $zero, 0x0007         ## $a2 = 00000007
/* 010E0 809C4710 8FAD0020 */  lw      $t5, 0x0020($sp)           
/* 010E4 809C4714 3C0C809C */  lui     $t4, %hi(func_809C3D40)    ## $t4 = 809C0000
/* 010E8 809C4718 258C3D40 */  addiu   $t4, $t4, %lo(func_809C3D40) ## $t4 = 809C3D40
/* 010EC 809C471C ADAC0214 */  sw      $t4, 0x0214($t5)           ## 00000214
/* 010F0 809C4720 8FBF001C */  lw      $ra, 0x001C($sp)           
.L809C4724:
/* 010F4 809C4724 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 010F8 809C4728 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 010FC 809C472C 03E00008 */  jr      $ra                        
/* 01100 809C4730 00000000 */  nop

