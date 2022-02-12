#define INTERNAL_SRC_DMADATA_DMADATA_C
#include "z64dma.h"

// Linker symbol declarations (used in the table below)
#define DEFINE_DMA_ENTRY(name)            \
    static u8 _##name##SegmentRomStart[1]; \
    static u8 _##name##SegmentRomEnd[1];

#include "tables/dmadata_table.h"
#include "def/dmadata.h"

#undef DEFINE_DMA_ENTRY

// dmadata Table definition
#define DEFINE_DMA_ENTRY(name) \
    { (void*)_##name##SegmentRomStart, (void*)_##name##SegmentRomEnd, (void*)_##name##SegmentRomStart, 0 },

DmaEntry gDmaDataTable[] = {
#include "tables/dmadata_table.h"
    { 0 },
};

#undef DEFINE_DMA_ENTRY

// Additional padding?
u8 sDmaDataPadding[0xF0] = { 0 };
