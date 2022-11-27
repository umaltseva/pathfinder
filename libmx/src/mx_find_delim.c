#include "../inc/libmx.h"

char *mx_find_delim(char **end, char *str, char delim) {
    char *temp = mx_strchr(str, delim);

    if (temp == NULL) {
         *end = NULL;  
    }
    else {
       *temp = '\0';
        *end = mx_strdup(temp + 1);
    }

    return str;
}

