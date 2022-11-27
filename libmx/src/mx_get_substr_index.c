#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    int index = 0;
    int sublen = 0;
    
    if (sub == NULL || str == NULL) {
        return -2;
    }
    else {
        sublen = mx_strlen(sub);
        while (*str) {
            if (mx_strncmp(str, sub, sublen) == 0)
                return index;
            index++;
            str++;
        }

        return -1;
    }

}




