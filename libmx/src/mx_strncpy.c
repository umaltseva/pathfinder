#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int a;

    for (a = 0; a < len && src[a] != '\0'; a++) 
        dst[a] = src[a];
    for ( ; a < len; a++)
        dst[a] = '\0';

    return dst;
}

