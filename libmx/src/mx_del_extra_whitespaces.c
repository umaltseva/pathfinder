#include "../inc/libmx.h"

char *mx_del_extra_whitespaces(const char *str) {
    char *str_new;
    if (str == NULL) {
        return NULL;
    }
    int length = 0;
    bool space = false;
    str_new = mx_strtrim(str);

    for (int i = 0; i < mx_strlen(str_new); i++) {
        if (!mx_isspace(str_new[i])) {
            str_new[length] = str_new[i];
            length++;
            space = false;
        }
        else if (mx_isspace(str_new[i]) && space == false) {
            str_new[length] = ' ';
            length++;
            space = true;
        }
    }
    char *str1 = mx_strnew(length);
    mx_strncpy(str1, str_new, length);
    mx_strdel(&str_new);
    return str1;
}








