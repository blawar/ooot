#include "global.h"

#if !defined(__GNUC__) && !defined(_MSC_VER)
#define __builtin_sqrtf sqrtf
#endif

#if !defined(_MSC_VER)
f32 sqrtf(f32 f) {
    return __builtin_sqrtf(f);
}
#endif
