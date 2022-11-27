#pragma once 

#include <libmx.h>
#include <limits.h>

typedef struct s_graph {
    t_list *islands;
    t_list *bridges;
}              t_graph;

typedef struct s_bridge {
    int from;
    int to;
    int length;
}              t_bridge;

typedef struct s_path {
    char *node;
    int index;
    int dist;
    bool visit;
    t_list *previous;
}              t_path;

t_graph *create_graph();
int find_in_list(t_list *list, void *elem, bool (*cmp)(void *, void *));
int get_index(t_graph *graph, char *str);
t_list *get_elem(t_list *list, int index);
bool connect_islands(t_graph *graph, char *island1, char *island2, int len_of_bridge);
long sum_of_bridges(t_graph *graph);

void clear_graph(t_graph *graph);

bool is_file(const char *filename);
bool is_empty_file(const char *filename);
t_graph *read_file(const char *filename);

void mx_printerr(const char *s);
void check_err(int argc, char* argv[]);
void line_err(int number_of_line);
void islands_error();
void sum_error();
void duplicate_error();

t_path *dijkstra(t_graph *graph, int from);
void print_routes(t_graph *graph);


