#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_VISETMODE_C
void osViSetMode(OSViMode* mode);
#else
void osViSetMode(struct OSViMode* mode);
#endif
