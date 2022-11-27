#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    unsigned char *cdst = (unsigned char *)dst;
    unsigned char *csrc = (unsigned char *)src;
    unsigned char *temp = malloc(len);
 
    for (size_t i = 0; i < len; i++) {
        temp[i] = csrc[i];
    }
    
    for (size_t i = 0; i < len; i++) {
        cdst[i] = temp[i]; 
    }

    free(temp);
    return cdst;
}
 
