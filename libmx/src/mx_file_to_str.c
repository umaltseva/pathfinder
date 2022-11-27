#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    char *str = NULL;
    char *buf = mx_strnew(129);
    buf [128] = '\0';
    int filename = open(file, O_RDONLY);
    ssize_t result = 0;
    
    if (filename != -1) {
        while ((result = read(filename, buf, 128)) > 0) {
            char *temp = str;
            
            buf[result] = '\0';
            str = mx_strjoin(str, buf);
            mx_strdel(&temp);
        }
        close(filename);
    }

    if (buf != NULL) {
        free(buf);
    }
    
    if (result == -1) {
      mx_strdel(&str);
    }
    return str; 
  
}



