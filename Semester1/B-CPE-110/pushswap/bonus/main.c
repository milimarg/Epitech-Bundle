/*
** EPITECH PROJECT, 2022
** Pushswap
** File description:
** main.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "include/my_struct.h"
#include "include/my.h"
#include "include/terminalcolors.h"

int check_is_list_sorted(elements_t *elements, int nb_arg)
{
    for (int i = 0; i < nb_arg; i++)
        if (elements->l_a[i] > elements->l_a[i + 1] && (i + 1) < nb_arg)
            return (0);
    return (1);
}

int frees(elements_t *elements)
{
    free(elements->l_a);
    free(elements->l_b);
    free(elements->sizes);
    free(elements->args);
    return (0);
}

void display_lists(elements_t *elements)
{
    static int step_nb = 1;

    write(1, CYAN, COLOR_LEN);
    write(1, "\nSTEP number ", 13);
    my_put_nbr(step_nb);
    write(1, RESET, RESET_LEN);
    write(1, "\nla = ", 6);
    for (int i = 0; i < elements->sizes[0]; i++) {
        my_put_nbr(elements->l_a[i]);
        write(1, (i == elements->sizes[0] - 1) ? "\n" : " ", 1);
    }
    write(1, "lb = ", 5);
    for (int i = 0; i < elements->sizes[1]; i++) {
        my_put_nbr(elements->l_b[i]);
        write(1, (i == elements->sizes[1] - 1) ? "\n" : " ", 1);
    }
    if (!elements->sizes[1])
        write(1, "\n", 1);
    write(1, "\n", 1);
    step_nb++;
}

void fill_elements_struct(elements_t *elements, int argc, char **argv)
{
    elements->args = get_args(argc, argv);
    for (int i = 0; i < 3; i++) {
        if (elements->args[i]) {
            argc--;
            elements->start_pos = 1;
        }
    }
    elements->l_a = malloc(sizeof(int) * argc);
    elements->l_b = malloc(sizeof(int) * argc);
    elements->sizes = init_sizes_array(argc);
}

int main(int argc, char **argv)
{
    elements_t elements = {0};

    if (argc == 1) {
        write(1, "\n", 1);
        return (0);
    }
    argc--;
    fill_elements_struct(&elements, argc, argv);
    fill_arrays(elements.sizes[2], &elements, argv);
    if (check_is_list_sorted(&elements, elements.sizes[2])) {
        write(1, "\n", 1);
        return (0);
    }
    pushswap_handler_basic(&elements);
    frees(&elements);
    return (0);
}
