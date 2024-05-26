/*
** EPITECH PROJECT, 2022
** B-CPE-110-STG-1-1-pushswap-florent.guittre
** File description:
** parts
*/

#include <unistd.h>
#include "include/my_struct.h"

void pa_util(elements_t *elements)
{
    int i = 0;
    int temp = elements->l_b[0];

    if (elements->sizes[1] > 0) {
        for (; i < elements->sizes[1] - 1; i++)
            elements->l_b[i] = elements->l_b[i + 1];
        elements->l_b[elements->sizes[1] - 1] = 0;
        elements->sizes[0]++;
        elements->sizes[1]--;
        for (i = elements->sizes[0] - 1; i > 0; i--)
            elements->l_a[i] = elements->l_a[i - 1];
        elements->l_a[0] = temp;
    }
    write(1, "pa", 2);
}

void pb_util(elements_t *elements)
{
    int i = elements->sizes[1];

    if (elements->sizes[0] > 0) {
        for (; i > 0; i--)
            elements->l_b[i] = elements->l_b[i - 1];
        elements->sizes[0]--;
        elements->sizes[1]++;
        elements->l_b[0] = elements->l_a[0];
        for (i = 0; i < elements->sizes[0]; i++)
            elements->l_a[i] = elements->l_a[i + 1];
        for (; i < elements->sizes[2]; i++)
            elements->l_a[i] = 0;
    }
    write(1, "pb", 2);
}

void ra_util(elements_t *elements)
{
    int temp = elements->l_a[0];

    for (int i = 1; i < elements->sizes[0]; i++)
        elements->l_a[i - 1] = elements->l_a[i];
    elements->l_a[elements->sizes[0] - 1] = temp;
    write(1, "ra", 2);
}

void rra_util(elements_t *elements)
{
    int temp = elements->l_a[elements->sizes[0] - 1];

    for (int i = elements->sizes[0] - 1; i > 0; i--)
        if (i > 0)
            elements->l_a[i] = elements->l_a[i - 1];
    elements->l_a[0] = temp;
    write(1, "rra", 3);
}
