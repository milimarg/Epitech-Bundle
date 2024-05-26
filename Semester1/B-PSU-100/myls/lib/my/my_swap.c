/*
** EPITECH PROJECT, 2022
** CPOOL_Day04
** File description:
** my_swap.c
*/

#include <stddef.h>

void my_swap(void *a, void *b)
{
    void *c = NULL;

    c = a;
    a = b;
    b = c;
}
