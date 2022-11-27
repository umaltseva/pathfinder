#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    int i = 0;

    if (*arr == NULL) {
        return;
    }
    if (delim == NULL) {
        return;
    }
    while (arr[i] != NULL) {

        mx_printstr(arr[i]);
        if (arr[i + 1] != NULL) {
            mx_printstr(delim);
        }
        else {
            mx_printchar('\n');
        }
        i++;
    }
}




