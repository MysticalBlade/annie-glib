//
// Created by annie on 9/27/25.
//

#include <stdlib.h>

#include "aapa.h"

void aapa_int_free(aapa_int *x) {
    if (!x) return;
    free(x -> limbs);
    x -> limbs = NULL;
    x -> sign = 0;
    x -> len = 0;
    x -> limb_size = 0;
}