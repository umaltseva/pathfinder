#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL)
    return NULL;

    int length = 0;

    while (mx_isspace(*str))
        str++;

    length = mx_strlen(str) - 1;

    while (length >= 0 && mx_isspace(str[length]))

        length--;

    char *temp = mx_strnew(length + 1);
    return mx_strncpy(temp, str, length + 1);
}






