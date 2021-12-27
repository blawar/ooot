#define INTERNAL_SRC_LIBULTRA_GU_NORMALIZE_C
#include "global.h"
#include <math.h>
#include "def/normalize.h"

void guNormalize(f32 *x, f32 *y, f32 *z) {
    f32 tmp = 1.0f / sqrtf(*x * *x + *y * *y + *z * *z);
    *x = *x * tmp;
    *y = *y * tmp;
    *z = *z * tmp;
}
