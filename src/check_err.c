#include "pathfinder.h"

void check_err(int argc, char* argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
    if (!is_file(argv[1])) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        exit(1);
    }
    if(is_empty_file(argv[1])) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(1);
    }
}

void line_err(int number_of_line) {
    char *temp = mx_itoa(number_of_line);
    mx_printerr("error: line ");
    mx_printerr(temp);
    mx_printerr(" is not valid\n");
    mx_strdel(&temp);
    exit(1);
}

void islands_error() {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
}

void sum_error() {
    mx_printerr("error: sum of bridges lengths is too big\n");
    exit(1);
}

void duplicate_error() {
    mx_printerr("error: duplicate bridges\n");
    exit(1);
}


