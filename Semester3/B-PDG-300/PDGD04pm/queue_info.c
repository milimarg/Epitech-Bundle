/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04pm-florent.guittre
** File description:
** queue_info.c
*/

#include "queue.h"

unsigned int queue_get_size(queue_t *queue)
{
    return list_get_size(queue);
}

bool queue_is_empty(queue_t *queue)
{
    return list_is_empty(queue);
}

void *queue_front(queue_t *queue)
{
    return list_get_elem_at_front(queue);
}
