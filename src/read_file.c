#include "pathfinder.h"

char *find_delim(char **end, char *str, char delim) {
    if (str == NULL
        || mx_strlen(str) == 0) {
        return NULL;
    }

    char *temp = mx_strchr(str, delim);

    if (temp == NULL) {
        *end = NULL;  
    }
    else {
        *temp = '\0';
        *end = temp + 1;
    }

    return str;
}

bool is_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return false;
    }
    close(fd);
    return true;
}

bool is_empty_file(const char *filename) {
    char buf;
    int fd = open(filename, O_RDONLY);
    ssize_t res = read(fd, &buf, 1);
    close (fd);
    return res != 1;
}

bool check_island(char *str) {
    if (str == NULL) {
        return false;
    }
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (!mx_isalpha(str[i])) {
            return false;
        }
    }
    
    return mx_strlen(str) != 0;
}

void read_line(t_graph *graph, char *str, int number_of_line) {
    char *island1 = find_delim(&str, str, '-');
    if (!check_island(island1)) {
        line_err(number_of_line);
    }
    char *island2 = find_delim(&str, str, ',');
    if (!check_island(island2)
        || mx_strcmp(island1, island2) == 0) {
        line_err(number_of_line);
    }
    int len_of_bridge = mx_atoi(str);
    if (len_of_bridge <= 0) {
        line_err(number_of_line);
    }
    if (!connect_islands(graph, island1, island2, len_of_bridge)) {
        duplicate_error();
    }
}

t_graph *read_file(const char *filename) {
    char *str = mx_file_to_str(filename);
    char *end = str;
    char *line = find_delim(&end, end, '\n');
    int number_of_islands = mx_atoi(line);

    if (number_of_islands <= 0) {
        line_err(1);
    }
    t_graph *graph = create_graph();
    
    for (int i = 2; (line = find_delim(&end, end, '\n')) != NULL; i++) {
        read_line(graph, line, i);
    }
    
    if (mx_list_size(graph->islands) != number_of_islands) {
        islands_error();
    }

    if (sum_of_bridges(graph) > INT_MAX) {
        sum_error();
    }

    mx_strdel(&str);
    return graph;
}
