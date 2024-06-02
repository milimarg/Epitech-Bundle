/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04pm-florent.guittre
** File description:
** int_list.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "int_list.h"

bool int_list_add_elem_at_back(int_list_t **front_ptr, int elem)
{
    int_list_t *node = malloc(sizeof(int_list_t));
    int_list_t *temp = NULL;

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

void int_list_dump(int_list_t *list)
{
    for (; list != NULL; list = list->next) {
        printf("%d\n", list->value);
    }
}

unsigned int int_list_get_size(int_list_t *list)
{
    unsigned int number = 0;

    for (; list != NULL; list = list->next) {
        number++;
    }
    return number;
}

bool int_list_is_empty(int_list_t *list)
{
    return int_list_get_size(list) == 0;
}

void int_list_clear(int_list_t **front_ptr)
{
    int_list_t *temp = NULL;

    if (front_ptr == NULL) {
        return;
    }
    while (*front_ptr != NULL) {
        temp = *front_ptr;
        *front_ptr = (*front_ptr)->next;
        free(temp);
    }
}
