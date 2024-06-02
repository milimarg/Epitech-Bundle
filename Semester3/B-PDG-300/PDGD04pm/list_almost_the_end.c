/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04pm-florent.guittre
** File description:
** list_almost_the_end.c
*/

#include <stdio.h>
#include "list.h"

void *list_get_elem_at_front(list_t *list)
{
    return list == NULL ? 0 : list->value;
}

void *list_get_elem_at_back(list_t *list)
{
    if (list == NULL) {
        return 0;
    }
    for (; list->next != NULL; list = list->next);
    return list->value;
}

void *list_get_elem_at_position(list_t *list, unsigned int position)
{
    list_t *temp = list;

    if (list == NULL) {
        return NULL;
    }
    for (unsigned int i = 0; i < position; i++) {
        if (temp == NULL) {
            return 0;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        return NULL;
    }
    return temp->value;
}
