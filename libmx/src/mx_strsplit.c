#include "../inc/libmx.h"

char **mx_strsplit(char const *s, char c) {
    if (s == NULL) {
        return NULL;
    }

    int count = mx_count_words(s, c);
    char **str = (char **)malloc(sizeof(char *) * (count + 1));
    int start = 0;
    int end = 0;

    for (int i = 0; i < count; i++) {
        start = end;

        while (s[start] == c) {
            start++;
        }
        end = start;
        while (s[end] != c && s[end] != '\0') {
            end++;
        }
        str[i] = mx_strnew(end - start);
        mx_strncpy(str[i], &s[start], end - start);
    }
    str[count] = NULL;
    return str;
}





