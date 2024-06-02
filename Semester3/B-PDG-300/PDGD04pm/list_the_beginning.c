/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04pm-florent.guittre
** File description:
** generic_list.c
*/

#include <stdlib.h>
#include "list.h"

bool list_add_elem_at_back(list_t **front_ptr, void *elem)
{
    list_t *node = malloc(sizeof(list_t));
    list_t *temp = NULL;

    if (front_ptr == NULL || node == NULL) {
        return false;
    }
    node->value = elem;
    node->next = NULL;
    if (*front_ptr == NULL) {
        node->next = *front_ptr;
        *front_ptr = node;
    } else {
        for (temp = *front_ptr; temp->next != NULL; temp = temp->next);
        temp->next = node;
    }
    return true;
}

void list_dump(list_t *list, value_displayer_t val_disp)
{
    for (; list != NULL; list = list->next) {
        val_disp(list->value);
    }
}

unsigned int list_get_size(list_t *list)
{
    unsigned int number = 0;

    for (; list != NULL; list = list->next) {
        number++;
    }
    return number;
}

bool list_is_empty(list_t *list)
{
    return list_get_size(list) == 0;
}

void list_clear(list_t **front_ptr)
{
    list_t *temp = NULL;

    if (front_ptr == NULL) {
        return;
    }
    while (*front_ptr != NULL) {
        temp = *front_ptr;
        *front_ptr = (*front_ptr)->next;
        free(temp);
    }
}
