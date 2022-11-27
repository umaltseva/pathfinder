#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char *cdst = (unsigned char *)dst;
    unsigned char *csrc = (unsigned char *)src;

    for (size_t i = 0; i < n; i++) {
        cdst[i] = csrc[i];

        if (csrc[i] == (unsigned char)c) {
            return &((unsigned char*)cdst)[i + 1];
        }
    }

    return NULL;
}










