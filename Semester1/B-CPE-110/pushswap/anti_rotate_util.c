/*
** EPITECH PROJECT, 2022
** B-CPE-110-STG-1-1-pushswap-florent.guittre
** File description:
** double_rotate_util
*/

#include <unistd.h>

void rra_util(int *l_a, int *l_b, int *sizes)
{
    int temp = l_a[sizes[0] - 1];

    for (int i = sizes[0] - 1; i > 0; i--)
        l_a[i] = l_a[i - 1];
    l_a[0] = temp;
    write(1, "rra", 3);
}

void rrb_util(int *l_a, int *l_b, int *sizes)
{
    int temp = l_b[sizes[1] - 1];

    for (int i = sizes[1] - 1; i >= 0; i--)
        l_b[i] = l_b[i - 1];
    l_b[1] = temp;
    write(1, "rrb", 3);
}

void rrr_util(int *l_a, int *l_b, int *sizes)
{
    rra_util(l_a, l_b, sizes);
    rrb_util(l_a, l_b, sizes);
}
