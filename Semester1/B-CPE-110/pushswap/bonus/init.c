/*
** EPITECH PROJECT, 2022
** B-CPE-110-STG-1-1-pushswap-florent.guittre
** File description:
** init
*/

#include <stdlib.h>
#include "include/my_struct.h"
#include "include/my.h"
#include "include/my_struct.h"

int fill_arrays(int nb_arg, elements_t *elements, char **argv)
{
    for (int i = elements->start_pos; i < nb_arg + elements->start_pos; i++) {
        elements->l_a[i - elements->start_pos] = my_getnbr(argv[i + 1]);
        elements->l_b[i - elements->start_pos] = 0;
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
