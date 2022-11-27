#include "../inc/libmx.h"

static int get_size(int number) {
    int count = 0;

    if (number == 0) {
        return 1;
    }

    if (number < 0) {
        count++;
    }

    while (number != 0) {
        count++;
        number /= 10;
    }

    return count;
}

char *mx_itoa(int number) {
    long long num = number;
    const int size = get_size(number);
    char *str = mx_strnew(size);
    int i = 0;

    if (num == 0) {
        str[i] = '0';
        return str;
    }

    if (num < 0) {
        str[i] = '-';
        num *= -1;
    }

    while (num != 0) {
        int rem = num % 10;
        str[size - i - 1] = rem + 48;
        num /= 10;
        i++;
    }

    return str;
}


