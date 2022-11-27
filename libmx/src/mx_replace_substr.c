#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    char *result;
    int count;
    char *temp;
    char *sub_temp;

    if (str == NULL ||
        sub == NULL ) {
        return NULL;
    }

    if (replace == NULL) {
        return NULL;
    }

    count = mx_count_substr(str, sub);
    result = mx_strnew(mx_strlen(str) - mx_strlen(sub) * count + mx_strlen(replace) * count);
    temp = result;
    sub_temp = mx_strstr(str, sub);

    while (sub_temp != NULL)
    {
        mx_strncpy(temp, str, sub_temp - str);
        temp += sub_temp - str;
        str = sub_temp + mx_strlen(sub);
        mx_strcat(temp, replace);
        temp += mx_strlen(replace);
        sub_temp = mx_strstr(str, sub);
    }
    mx_strcat(temp, str);
    
    return result;
}





