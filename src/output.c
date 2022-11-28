#include "pathfinder.h"

void print_boundary(void) {
    for (int i = 0; i < 40; i++) {
        mx_printchar('=');
    }
    mx_printchar('\n');
}

static void print_route(t_list *path) {
    mx_printstr("Route: ");
    while (path != NULL) {
        t_path *path_node = path->data;
        mx_printstr(path_node->node);
        if (path->next != NULL) {
              mx_printstr(" -> ");
        }
        path = path->next;
    }
    mx_printchar('\n');
}

static void print_dist(t_list *path) {
    int size = mx_list_size(path);

    mx_printstr("Distance: ");
    while(path != NULL && path->next != NULL) {
        t_path *path_node = path->data;
        t_path *next_path_node = path->next->data;
        int distance = next_path_node->dist - path_node->dist;
        mx_printint(distance);
        if (path->next->next != NULL) {
            mx_printstr(" + ");
        } 
        else if (size > 2){
            mx_printstr(" = ");
            mx_printint(next_path_node->dist);
        }
        path = path->next;
    }
    mx_printchar('\n');
}

static void print_path(t_list *path) {
    mx_printstr("Path: ");
    mx_printstr(((t_path*)path->data)->node);
    mx_printstr(" -> ");
    mx_printstr(((t_path*)get_elem(path, mx_list_size(path) - 1)->data)->node);
    mx_printchar('\n');
    print_route(path);
    print_dist(path);
}

static t_list *copy_list(t_list *list) {
    t_list *temp = NULL;
    while (list != NULL) {
        mx_push_back(&temp, list->data);
        list = list->next;
    }
    return temp;
}

static void print_shortest_paths_rec(t_list *path, t_list **paths) {
    t_list *temp = ((t_path*)path->data)->previous;
    
    while(temp != NULL) {
        t_path *node = temp->data;
        mx_push_front(&path, node);
        print_shortest_paths_rec(path, paths);
        mx_pop_front(&path);   
        temp = temp->next;
    }

    if (((t_path*)path->data)->dist == 0) {
        mx_push_back(paths, copy_list(path));
    }
}

static bool cmp_paths(void *a, void *b) {
    t_list *path_a = a;
    t_list *path_b = b;

    while (path_a != NULL) {
        int index_a = ((t_path*)path_a->data)->index;
        int index_b = ((t_path*)path_b->data)->index;
        if (index_a != index_b) {
            return index_a > index_b;
        }
        path_a = path_a->next;
        path_b = path_b->next;
    }
    return false;
}


static void print_shortest_paths(t_path *nodes, int to) {
    t_list *paths = NULL;
    t_list *path = mx_create_node(&nodes[to]);

    print_shortest_paths_rec(path, &paths);
    mx_sort_list(paths, cmp_paths);

    t_list *temp = paths;
    while (temp != NULL) {
        print_boundary();
        print_path(temp->data);
        print_boundary();
        mx_clear_list((t_list**)&temp->data);
        temp = temp->next;
    }
    
    mx_clear_list(&path);
    mx_clear_list(&paths);
}

void print_routes(t_graph *graph) {
    int size = mx_list_size(graph->islands);

    for (int i = 0; i < size ; i++) {
        for (int j = i + 1; j < size; j++) {
            t_path *path = dijkstra(graph, i);
            print_shortest_paths(path, j);
            for (int c = 0; c < size; c++) {
                mx_clear_list(&path[c].previous);
            }
            free(path);
        }
    }
}

