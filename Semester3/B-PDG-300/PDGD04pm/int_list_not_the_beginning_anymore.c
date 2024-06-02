/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04pm-florent.guittre
** File description:
** int_list_not_the_beginning_anymore.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "int_list.h"

bool int_list_add_elem_at_front(int_list_t **front_ptr, int elem)
{
    int_list_t *node = malloc(sizeof(int_list_t));

    if (front_ptr == NULL || node == NULL) {
        return false;
    }
    node->value = elem;
    node->next = *front_ptr;
    *front_ptr = node;
    return true;
}

bool int_list_add_elem_at_position(int_list_t **front_ptr, int elem,
    unsigned int position)
{
    int_list_t *temp = *front_ptr;
    int_list_t *node = NULL;

    if (front_ptr == NULL || position > int_list_get_size(*front_ptr) - 1) {
        return false;
    }
    if (position == 0) {
        return int_list_add_elem_at_front(front_ptr, elem);
    }
    for (unsigned int i = 0; i < position - 1; ++i) {
        if (*front_ptr == NULL) {
            return false;
        }
        temp = temp->next;
    }
    node = malloc(sizeof(int_list_t));
    node->value = elem;
    node->next = temp->next;
    temp->next = node;
    return true;
}
