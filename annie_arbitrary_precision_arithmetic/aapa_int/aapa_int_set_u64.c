//
// Created by annie on 9/28/25.
//

#include "aapa.h"
#include <stdlib.h>

int aapa_int_set_u64(aapa_int *dest, const uint64_t value) {

    // Fast zeroing
    if (value == 0) {
        dest -> sign = 0;
        dest -> len = 0;
        return AAPA_VALID;
    }


    aapa_limb_size *value = realloc(dest->limbs, 1 * sizeof *dest->limbs);
    if (!value) {
        return AAPA_OOM;
    }
    dest->limbs = value;
    dest->limb_size = 1;

    dest -> limbs[0] = (aapa_limb_size)value;
    dest -> len = 1;
    dest -> sign = 1;
    return AAPA_VALID;
}