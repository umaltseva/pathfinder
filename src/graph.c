#include "pathfinder.h"

t_graph *create_graph() {
    t_graph *graph = malloc(sizeof(t_graph));
    graph->islands = NULL;
    graph->bridges = NULL;
    return graph;
}

t_bridge *create_bridge(int from, int to, int length) {
    t_bridge *bridge = malloc(sizeof(t_bridge));
    bridge->from = from;
    bridge->to = to;
    bridge->length = length;
    return bridge;
}

int find_in_list(t_list *list, void *elem, bool (*cmp)(void *, void *)) {
    if (elem == NULL || cmp == NULL) {
        return -1;
    }

    for (int i = 0; list != NULL; i++) {
        if (cmp(list->data, elem)) { 
            return i;
        }
        list = list->next;
    }
    return -1;
}

static bool cmp(void *a, void *b) {
    return mx_strcmp(a, b) == 0;
}

static bool cmp_bridges(void *a, void *b) {
    t_bridge *bridge1 = a;
    t_bridge *bridge2 = b; 
    return bridge1->from == bridge2->from && bridge1->to == bridge2->to;
}


bool connect_islands(t_graph *graph, char *island1, char *island2, int len_of_bridge) {
    int index1 = get_index(graph, island1);
    int index2 = get_index(graph, island2);

    t_list **list = (t_list**)&get_elem(graph->bridges, index1)->data;
    t_bridge *bridge1 = create_bridge(index1, index2, len_of_bridge);
    if (find_in_list(*list, bridge1, cmp_bridges) != -1) {
        free(bridge1);
        return false;
    }
    mx_push_back(list, bridge1);
    mx_push_back((t_list**)&get_elem(graph->bridges, index2)->data, create_bridge(index2, index1, len_of_bridge));
    return true;
}

int get_index(t_graph *graph, char *str) {
    int index = find_in_list(graph->islands, str, cmp);
    if (index == -1) {
        mx_push_back(&graph->islands, mx_strdup(str));
        mx_push_back(&graph->bridges, NULL);
        index = mx_list_size(graph->islands) - 1;
    }
    return index;
}

t_list *get_elem(t_list *list, int index) {
    for (int i = 0; i < index && list; i++) {
        list = list->next;
    }
    return list;
}

long sum_of_bridges(t_graph *graph) {
    t_list *list1 = graph->bridges;
    long sum = 0;
    while (list1 != NULL) {
        t_list *list2 = list1->data;
        while (list2 != NULL) {  
            sum += ((t_bridge*)list2->data)->length;
            list2 = list2->next; 
        }
        list1 = list1->next;
    }
    return sum / 2;
}

void free_data(t_list *node) {
    free(node->data);
}

void del_list(t_list *node) {
    t_list *data = node->data;
    mx_foreach_list(data, free_data);
    mx_clear_list(&data);
}

void clear_graph(t_graph *graph) {
    mx_foreach_list(graph->islands, free_data);
    mx_foreach_list(graph->bridges, del_list);
    mx_clear_list(&graph->islands);
    mx_clear_list(&graph->bridges);
    free(graph);
}
