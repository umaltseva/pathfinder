#include "../inc/libmx.h"

int mx_count_words(const char *str, char delimiter) {
    int count = 0;

    if (str == NULL) {
        return -1;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != delimiter
            && (i == 0
            || str[i - 1] == delimiter)) {
            count++;
        }
    }

    return count;
}



