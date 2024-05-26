/*
** EPITECH PROJECT, 2022
** B-CPE-110-STG-1-1-pushswap-florent.guittre
** File description:
** basic
*/

#include "include/my_struct.h"
#include "include/my.h"

void find_highest_nb(elements_t *elements)
{
    int lowest_nb = elements->l_a[0];
    int pos = 0;
    int j = 0;

    for (j = 0; j < elements->sizes[0]; j++) {
        if (elements->l_a[j] <= lowest_nb) {
            lowest_nb = elements->l_a[j];
            pos = j;
        }
    }
    if (pos > (elements->sizes[0] / 2))
        shift_numbers_to_left(pos, elements);
    else
        shift_numbers_to_right(pos, elements);
    pb_util(elements);
    display_delimiter(elements, j);
    if (elements->args[0])
        display_lists(elements);
}

int pushswap_handler_basic(elements_t *elements)
{
    int j = 0;

    for (int i = 0; i < elements->sizes[2]; i++)
        find_highest_nb(elements);
    for (int i = 0; i < elements->sizes[2]; i++) {
        pa_util(elements);
        display_delimiter(elements, j);
        if (elements->args[0])
            display_lists(elements);
    }
    return (0);
}
