#include "../inc/libmx.h"

void mx_pop_back(t_list **head) {
    t_list *temp;

    if (!head || *head == NULL) {
        return;
    }

   temp = *head;

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}




