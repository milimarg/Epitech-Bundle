/*
** EPITECH PROJECT, 2022
** B-CPE-110-STG-1-1-pushswap-florent.guittre
** File description:
** parts
*/

#include <unistd.h>

void pa_util(int *l_a, int *l_b, int *sizes)
{
    int i = 0;
    int temp = l_b[0];

    if (sizes[1] > 0) {
        for (; i < sizes[1] - 1; i++)
            l_b[i] = l_b[i + 1];
        l_b[sizes[1] - 1] = 0;
        sizes[0]++;
        sizes[1]--;
        for (i = sizes[0] - 1; i > 0; i--)
            l_a[i] = l_a[i - 1];
        l_a[0] = temp;
    }
    write(1, "pa", 2);
}

void pb_util(int *l_a, int *l_b, int *sizes)
{
    int i = sizes[1];

    if (sizes[0] > 0) {
        for (; i > 0; i--)
            l_b[i] = l_b[i - 1];
        sizes[0]--;
        sizes[1]++;
        l_b[0] = l_a[0];
        for (i = 0; i < sizes[0]; i++)
            l_a[i] = l_a[i + 1];
        for (; i < sizes[2]; i++)
            l_a[i] = 0;
    }
    write(1, "pb", 2);
}
