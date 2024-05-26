/*
** EPITECH PROJECT, 2022
** B-CPE-110-STG-1-1-pushswap-florent.guittre
** File description:
** init
*/

#include <stdlib.h>
#include "include/my.h"

int fill_arrays(int nb_arg, int *l_a, int *l_b, char **argv)
{
    for (int i = 0; i < nb_arg; i++) {
        l_a[i] = my_getnbr(argv[i + 1]);
        l_b[i] = 0;
    }
    return (0);
}

int *init_sizes_array(int nb_arg)
{
    int *sizes = malloc(sizeof(int) * 3);

    sizes[0] = nb_arg;
    sizes[1] = 0;
    sizes[2] = nb_arg;
    return (sizes);
}
