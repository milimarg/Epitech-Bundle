/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04pm-florent.guittre
** File description:
** queue_modify.c
*/

#include "queue.h"

bool queue_push(queue_t **queue_ptr, void *elem)
{
    return list_add_elem_at_back(queue_ptr, elem);
}

bool queue_pop(queue_t **queue_str)
{
    return list_del_elem_at_front(queue_str);
}

void queue_clear(queue_t **queue_ptr)
{
    list_clear(queue_ptr);
}
