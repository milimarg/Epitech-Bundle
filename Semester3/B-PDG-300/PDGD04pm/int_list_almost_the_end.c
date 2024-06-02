/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04pm-florent.guittre
** File description:
** int_list_almost_the_end.c
*/

#include <stdio.h>
#include "int_list.h"

int int_list_get_elem_at_front(int_list_t *list)
{
    return list == NULL ? 0 : list->value;
}

int int_list_get_elem_at_back(int_list_t *list)
{
    if (list == NULL) {
        return 0;
    }
    for (; list->next != NULL; list = list->next);
    return list->value;
}

int int_list_get_elem_at_position(int_list_t *list, unsigned int position)
{
    int_list_t *temp = list;

    if (list == NULL) {
        return 0;
    }
    for (unsigned int i = 0; i < position; i++) {
        if (temp == NULL) {
            return 0;
        }
        temp = temp->next;
    }
    return temp->value;
}
