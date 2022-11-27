#include "libmx.h"

int mx_atoi(const char *str) {
    long int res = 0;
    int a = 0;
    
    if (str[a] == '+') {
        a++;
    } 

    for (; mx_isdigit(str[a]); a++) {
        if (9223372036854775807 / (str[a] / 10) < res) {
            return -1;
        }
        res = res * 10;
        if (9223372036854775807 - (str[a] - 48) < res) {
            return -1;
        }
        res += str[a] - '0';
    }

    if (str[a] != '\0'){
        return -1;
    }
    
    return res;
}


