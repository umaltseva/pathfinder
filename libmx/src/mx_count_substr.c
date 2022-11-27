#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;

    if ((!str) || (!sub))
        return -1;

    if (mx_strlen(sub) == 0) {
        return 0;
    }

    if (mx_strlen(str) >= mx_strlen(sub)) {
        while (*str) {
            if (!mx_strncmp((char *)str, (char *)sub, mx_strlen(sub)))
                count++;
            str++;
        }
    }
    return count;
}



