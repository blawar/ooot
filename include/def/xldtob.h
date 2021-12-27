#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_RMON_XLDTOB_C
void _Ldtob(_Pft* args, u8 type);
#else
void _Ldtob(struct _Pft* args, u8 type);
#endif
