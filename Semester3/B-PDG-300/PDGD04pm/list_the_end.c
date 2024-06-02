/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04pm-florent.guittre
** File description:
** list_the_end.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

bool list_del_elem_at_front(list_t **front_ptr)
{
    list_t *delete = NULL;
    if (front_ptr == NULL || (front_ptr && *front_ptr == NULL)) {
        return false;
    }
    delete = *front_ptr;
    *front_ptr = (*front_ptr)->next;
    free(delete);
    return true;
}

bool list_del_elem_at_back(list_t **front_ptr)
{
    list_t *temp = NULL;
    list_t *delete = NULL;
    if (front_ptr == NULL || (front_ptr && *front_ptr == NULL)) {
        return false;
    }
    for (temp = *front_ptr; temp->next->next != NULL; temp = temp->next);
    delete = temp->next;
    temp->next = temp->next->next;
    free(delete);
    return true;
}

bool list_del_elem_at_position(list_t **front_ptr,
    unsigned int position)
{
    list_t *temp = NULL;
    list_t *delete = NULL;
    if (front_ptr == NULL || (front_ptr && *front_ptr == NULL)) {
        return false;
    }
    if (position == 0) {
        list_del_elem_at_front(front_ptr);
    }
    temp = *front_ptr;
    for (unsigned int i = 0; i < position - 1; i++) {
        if (temp == NULL || temp->next == NULL || temp->next->next == NULL) {
            return false;
        }
        temp = temp->next;
    }
    delete = temp->next;
    temp->next = temp->next->next;
    free(delete);
    return true;
}
