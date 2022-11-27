#include "../inc/libmx.h"

t_list *mx_create_node(void *data) {

    t_list *new_list =  malloc(sizeof(t_list));
    if(!new_list) return NULL;

    new_list -> data = data;
    new_list -> next = NULL;

    return new_list;
}


