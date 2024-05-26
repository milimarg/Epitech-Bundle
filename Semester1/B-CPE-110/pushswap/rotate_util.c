/*
** EPITECH PROJECT, 2022
** B-CPE-110-STG-1-1-pushswap-florent.guittre
** File description:
** rotate_util
*/

#include <unistd.h>

void ra_util(int *l_a, int *l_b, int *sizes)
{
    int temp = l_a[0];

    for (int i = 1; i < sizes[0]; i++)
        l_a[i - 1] = l_a[i];
    l_a[sizes[0] - 1] = temp;
    write(1, "ra", 2);
}

void rb_util(int *l_a, int *l_b, int *sizes)
{
    int temp = l_b[0];

    for (int i = 1; i < sizes[1]; i++)
        l_b[i - 1] = l_b[i];
    l_b[sizes[1] - 1] = temp;
    write(1, "rb", 2);
}

void rr_util(int *l_a, int *l_b, int *size)
{
    ra_util(l_a, l_b, size);
    rb_util(l_a, l_b, size);
}
