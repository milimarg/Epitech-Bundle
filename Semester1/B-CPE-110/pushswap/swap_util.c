/*
** EPITECH PROJECT, 2022
** B-CPE-110-STG-1-1-pushswap-florent.guittre
** File description:
** swap_util
*/

#include <unistd.h>

void swap_elem(int *array, int index1, int index2);

void sa_util(int *l_a, int *l_b, int *sizes)
{
    if (sizes[0] >= 2)
        swap_elem(l_a, 0, 1);
    write(1, "sa ", 4);
}

void sb_util(int *l_a, int *l_b, int *sizes)
{
    if (sizes[1] >= 2)
        swap_elem(l_b, 0, 1);
}

void sc_util(int *l_a, int *l_b, int *sizes)
{
    sa_util(l_a, l_b, sizes);
    sb_util(l_a, l_b, sizes);
}
