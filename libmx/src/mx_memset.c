#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char *ch = b;
    while (len--) {
        *ch++ = (unsigned char)c;
    }
    return b;
}




