#include "../inc/libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
    if (s1 == NULL && s2 == NULL)
        return NULL;
    else if (s1 == NULL)
        return mx_strdup(s2);
    else if (s2 == NULL)
        return mx_strdup(s1);
    else {
        int space_needed = mx_strlen(s1) + mx_strlen(s2);
        char *res = mx_strnew(space_needed);

        mx_strcpy(res, s1);
        mx_strcpy(res + mx_strlen(s1), s2);
        return res;
    }
}




