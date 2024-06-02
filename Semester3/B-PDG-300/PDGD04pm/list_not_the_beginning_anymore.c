/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04pm-florent.guittre
** File description:
** list_not_the_beginning_anymore.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

bool list_add_elem_at_front(list_t **front_ptr, void *elem)
{
    list_t *node = malloc(sizeof(list_t));

    if (front_ptr == NULL || node == NULL) {
        return false;
    }
    node->value = elem;
    node->next = *front_ptr;
    *front_ptr = node;
    return true;
}

bool list_add_elem_at_position(list_t **front_ptr, void *elem,
    unsigned int position)
{
    list_t *temp = *front_ptr;
    list_t *node = NULL;

    if (front_ptr == NULL || position > list_get_size(*front_ptr)) {
        return false;
    }
    if (position == 0) {
        return list_add_elem_at_front(front_ptr, elem);
    }
    for (unsigned int i = 0; i < position - 1; ++i) {
        if (temp == NULL) {
            return false;
        }
        temp = temp->next;
    }
    node = malloc(sizeof(list_t));
    node->value = elem;
    node->next = temp->next;
    temp->next = node;
    return true;
}
