/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04pm-florent.guittre
** File description:
** stack_info.c
*/

#include "stack.h"

unsigned int stack_get_size(stack_t *stack)
{
    return list_get_size(stack);
}

bool stack_is_empty(stack_t *stack)
{
    return list_is_empty(stack);
}

void *stack_top(stack_t *stack)
{
    return list_get_elem_at_front(stack);
}
