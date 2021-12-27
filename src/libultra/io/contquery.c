#define INTERNAL_SRC_LIBULTRA_IO_CONTQUERY_C
#include "global.h"
#include "def/contquery.h"

/**
 * osContStartQuery:
 * Starts to read the values for SI device status and type which are connected to the controller port and joyport
 * connector.
 */
s32 osContStartQuery(struct OSMesgQueue* mq) {
    return 0;
}

/**
 * osContGetQuery:
 * Returns the values from osContStartQuery to status. Both functions must be paired for use.
 */
void osContGetQuery(struct OSContStatus* data) {
}
