#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    int number_of_bytes = 0;
    static char *end = NULL;
    char *buf = mx_strnew(buf_size);
    char *str = NULL;
    ssize_t res = 0;

    if (end) {
        char *temp = NULL;

        str = mx_find_delim(&end,end, delim);
        number_of_bytes = mx_strlen(str);
        temp = str;
        str = mx_strdup(str);
        mx_strdel(&temp);
        if (end) {
            if (mx_strlen(end) == 0) {
                mx_strdel(&end);
            }
            *lineptr = str;
            mx_strdel(&buf);
            return number_of_bytes;
        }
    }

    while ((res = read(fd, buf, buf_size)) > 0) {
        char *temp = NULL;

        buf[res] = '\0';
        mx_find_delim(&end, buf, delim);
        number_of_bytes += mx_strlen(buf);
        temp = str;
        str = mx_strjoin(str, buf);
        mx_strdel(&temp);
        if (end) {
            if (mx_strlen(end) == 0) {
                mx_strdel(&end);
            }
             break;
      }
    }
    mx_strdel(&buf);
    
    if (buf_size == 0 || res == -1) {
        mx_strdel(&str);
        mx_strdel(&end);
        return -2;
    }

    if (!str) {
      return -1;
    }

    *lineptr = str;
    return number_of_bytes;
}
