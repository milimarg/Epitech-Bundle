/*
** EPITECH PROJECT, 2022
** B-CPE-110-STG-1-1-pushswap-florent.guittre
** File description:
** basic
*/

#include "include/my.h"
#include "include/my_macros.h"

void find_highest_nb(int *l_a, int *l_b, int *sizes, int j)
{
    int pos = 0;
    int lowest_nb = l_a[0];

    for (j = 0; j < sizes[0]; j++)
        if (l_a[j] <= lowest_nb) {
            lowest_nb = l_a[j];
            pos = j;
        }
    if (pos > (sizes[0] / 2)) {
        j = pos;
        j = shift_numbers_to_left(j, sizes, l_a, l_b);
    } else {
        j = pos;
        j = shift_numbers_to_right(j, sizes, l_a, l_b);
    }
    PB;
    DELIM;
}

int pushswap_handler_basic(int *l_a, int *l_b, int *sizes)
{
    int j = 0;
    int cycles_nb = 3;
    int cycle_begin = 8;

    for (int i = 0; i < sizes[2]; i++) {
        find_highest_nb(l_a, l_b, sizes, j);
    }
    for (int i = 0; i < sizes[2]; i++) {
        PA;
        DELIM;
    }
    return (0);
}
