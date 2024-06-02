/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04pm-florent.guittre
** File description:
** stack_modify.c
*/

#include <stdio.h>
#include "stack.h"

bool stack_push(stack_t **stack_ptr, void *elem)
{
    return list_add_elem_at_front(stack_ptr, elem);
}

bool stack_pop(stack_t **stack_ptr)
{
    return list_del_elem_at_front(stack_ptr);
}

void stack_clear(stack_t **stack_ptr)
{
    list_clear(stack_ptr);
}
