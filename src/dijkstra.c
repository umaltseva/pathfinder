#include "pathfinder.h"

bool cmp_nodes(void *node1, void *node2) {
    return ((t_path*)node1)->dist > ((t_path*)node2)->dist;
}

bool cmp_pointers(void *node1, void *node2) {
    return node1 == node2;
}

t_path *dijkstra(t_graph *graph, int from) {
    int vertices = mx_list_size(graph->islands);
    t_path *array = malloc(sizeof(t_path) * vertices);
    for (int i = 0; i < vertices; i++) {
        array[i].dist = -1;
        array[i].node = get_elem(graph->islands, i)->data;
        array[i].visit = false;
        array[i].previous = NULL;
        array[i].index = i;
    }
    array[from].dist = 0;
    t_list *nodes = mx_create_node(&array[from]);
    
    while (nodes != NULL) {
        t_path *path = nodes->data;
        mx_pop_front(&nodes);
        path->visit = true;

        t_list *bridges = get_elem(graph->bridges, path->index)->data;

        while (bridges != NULL) {
            t_bridge *bridge = bridges->data;
            t_path *to_node = &array[bridge->to];

            if (!to_node->visit) {
                int temp_distance = path->dist + bridge->length;
                if (temp_distance <= to_node->dist || to_node->dist == -1) {
                    if (temp_distance < to_node->dist) {
                        mx_clear_list(&to_node->previous);
                    }
                    to_node->dist = temp_distance;
                    mx_push_back(&to_node->previous, path);
                }
                if (find_in_list(nodes, to_node, cmp_pointers) == -1) {
                    mx_push_back(&nodes, to_node);
                }
            }
            bridges = bridges->next;
        }

        mx_sort_list(nodes, cmp_nodes);
    }
    return array;
}

