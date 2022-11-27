#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int s_len = mx_strlen(s1);
    int s2_len = mx_strlen(s2);

    for(int i = 0; i < s2_len; i++ ) {
        s1[s_len + i] = s2[i];
    }
    s1[s_len + s2_len] = '\0';

    return s1;
}



