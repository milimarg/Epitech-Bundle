/*
** EPITECH PROJECT, 2022
** Pushswap
** File description:
** main.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"

int check_is_list_sorted(int *l_a, int *l_b, int nb_arg)
{
    for (int i = 0; i < nb_arg; i++) {
        if (l_a[i] > l_a[i + 1] && (i + 1) < nb_arg) {
            return (0);
        }
    }
    return (1);
}

int frees(int *l_a, int *l_b, int *sizes)
{
    free(l_a);
    free(l_b);
    free(sizes);
    return (0);
}

int main(int argc, char **argv)
{
    int nb_arg = argc - 1;
    int *l_a = {0};
    int *l_b = {0};
    int *sizes = {0};

    if (argc == 1) {
        write(1, "\n", 1);
        return (0);
    }
    l_a = malloc(sizeof(int) * nb_arg);
    l_b = malloc(sizeof(int) * nb_arg);
    sizes = init_sizes_array(nb_arg);
    fill_arrays(sizes[2], l_a, l_b, argv);
    if (check_is_list_sorted(l_a, l_b, sizes[2])) {
        write(1, "\n", 1);
        return (0);
    }
    pushswap_handler_basic(l_a, l_b, sizes);
    frees(l_a, l_b, sizes);
    return (0);
}
