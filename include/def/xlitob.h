#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_RMON_XLITOB_C
void _Litob(_Pft* args, u8 type);
#else
void _Litob(struct _Pft* args, u8 type);
#endif
