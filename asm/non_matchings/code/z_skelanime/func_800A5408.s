glabel func_800A5408
/* B1C5A8 800A5408 C486001C */  lwc1  $f6, 0x1c($a0)
/* B1C5AC 800A540C C480000C */  lwc1  $f0, 0xc($a0)
/* B1C5B0 800A5410 C4840010 */  lwc1  $f4, 0x10($a0)
/* B1C5B4 800A5414 46003207 */  neg.s $f8, $f6
/* B1C5B8 800A5418 E4800010 */  swc1  $f0, 0x10($a0)
/* B1C5BC 800A541C E488001C */  swc1  $f8, 0x1c($a0)
/* B1C5C0 800A5420 03E00008 */  jr    $ra
/* B1C5C4 800A5424 E484000C */   swc1  $f4, 0xc($a0)
