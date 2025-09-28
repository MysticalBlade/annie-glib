//
// Created by annie on 9/27/25.
//

#include <stdlib.h>
#include "aapa.h"

// dest is the destination of set, src is the source value
int aapa_int_set(aapa_int *dest, aapa_int *src) {
    if (dest == src) {
        return AAPA_VALID;
    }

    // Fast zeroing
    if (src -> len == 0) {
        dest -> sign = 0;
        dest -> len = 0;
        return AAPA_VALID;
    }

    // Reallocating limb size to fit bigger ints
    if (dest -> limb_size < src -> len) {
        aapa_limb_size *value = (aapa_limb_size *) realloc(dest -> limbs,
                                                            src -> len * sizeof(*value));
        if (!value) {
            return AAPA_OOM;
        }
        dest -> limbs = value;
        dest -> limb_size = src -> len;
    }

    // Copy
    for (size_t i = 0; i < src -> len; i++) {
        dest -> limbs[i] = src -> limbs[i];
    }

    dest -> len = src -> len;
    dest -> sign = src -> sign;
    return AAPA_VALID;
};