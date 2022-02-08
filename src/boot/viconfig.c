#include "global.h"
#include "vt.h"
#include "ultra64/pi.h"
#include "ultra64/vi.h"
#include "padmgr.h"
#include "functions.h"

extern u32 osTvType;
extern u8 gViConfigAdditionalScanLines;
extern u32 gViConfigFeatures;

extern f32 gViConfigXScale;
extern f32 gViConfigYScale;
extern vu8 gViConfigUseDefault;

extern OSViMode osViModePalLan1;
extern OSViMode gViConfigMode;

// this should probably go elsewhere but right now viconfig.o is the only object between idle and z_std_dma
OSPiHandle* gCartHandle = 0;


