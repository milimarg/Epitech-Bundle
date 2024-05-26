/*
** EPITECH PROJECT, 2023
** B-AIA-200-STG-2-1-n4s-florent.guittre
** File description:
** print_float_tab
*/

#include "../include/my.h"

void print_float_tab(float *tab, int lenght)
{
    for (int i = 0; i < lenght; i++) {
        dprintf(2, "[%.2f]", tab[i]);
        if (i < (lenght - 1)) {
            dprintf(2, " : ");
        } else
            dprintf(2 , "\n");
    }
}

void print_informations(float *left, float *front, float *right, float *all)
{
    dprintf(2, "left:\n");
    print_float_tab(left, 3);
    dprintf(2, "front:\n");
    print_float_tab(front, 3);
    dprintf(2, "right:\n");
    print_float_tab(right, 3);
}
