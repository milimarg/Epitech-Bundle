/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04pm-florent.guittre
** File description:
** int_list_the_end.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"

bool int_list_del_elem_at_front(int_list_t **front_ptr)
{
    int_list_t *delete = NULL;
    if (front_ptr == NULL || (front_ptr && *front_ptr == NULL)) {
        return false;
    }
    delete = *front_ptr;
    *front_ptr = (*front_ptr)->next;
    free(delete);
    return true;
}

bool int_list_del_elem_at_back(int_list_t **front_ptr)
{
    int_list_t *temp = NULL;

    if (front_ptr == NULL || (front_ptr && *front_ptr == NULL)) {
        return false;
    }
    for (temp = *front_ptr; temp->next->next != NULL; temp = temp->next);
    temp->next = temp->next->next;
    return true;
}

bool int_list_del_elem_at_position(int_list_t **front_ptr,
    unsigned int position)
{
    int_list_t *temp = NULL;
    int_list_t *delete = NULL;
    if (front_ptr == NULL || (front_ptr && *front_ptr == NULL)) {
        return false;
    }
    if (position == 0) {
        return int_list_del_elem_at_front(front_ptr);
    }
    temp = *front_ptr;
    for (unsigned int i = 0; i < position - 1; i++) {
        if (temp == NULL || (temp && temp->next == NULL) ||
        (temp && temp->next && temp->next->next == NULL)) {
            return false;
        }
        temp = temp->next;
    }
    delete = temp->next;
    temp->next = temp->next->next;
    free(delete);
    return true;
}
