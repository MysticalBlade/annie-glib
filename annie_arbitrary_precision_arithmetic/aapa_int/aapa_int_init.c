//
// Created by annie on 9/27/25.
//


#include "aapa.h"

// Basic initialization for integers

void aapa_int_init(aapa_int *x) {
    x -> sign = 0;
    x -> len = 0;
    x -> limbs = NULL;
    x -> limb_size = 0;
}