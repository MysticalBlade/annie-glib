//
// Created by annie on 9/27/25.
//

#ifndef AAPA_H
#define AAPA_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>
#include <stddef.h>

// Limb size always 64 bits because who uses 32-bit computers anymore
#define AAPA_LIMB_BITS 64

// Status codes
typedef enum {
    AAPA_VALID = 0,
    AAPA_INVALID = 1,
    AAPA_OOM = 2
} aapa_status;

typedef uint64_t aapa_limb_size;

// Main big integer struct
typedef struct {
    int sign;
    size_t len;
    size_t limb_size;
    aapa_limb_size *limbs;
} aapa_int;

// API
void aapa_int_init(aapa_int *x);
void aapa_int_free(aapa_int *x);
void aapa_int_clear(aapa_int *x);
int aapa_int_reserve(aapa_int *x, size_t size);
int aapa_int_set(aapa_int *dest, aapa_int *src);
int aapa_int_set_u64(aapa_int *dest, uint64_t u);
int aapa_int_set_i64(aapa_int *x, int64_t u);

#ifdef __cplusplus
}
#endif
#endif //AAPA_H

