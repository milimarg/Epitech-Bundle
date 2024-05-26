/*
** EPITECH PROJECT, 2023
** B-AIA-200-STG-2-1-n4s-florent.guittre
** File description:
** get_between_idx
*/

#include "../include/my.h"

float *get_between_idx(char **args, int start, int end)
{
    float *tab = malloc(sizeof(float) * (end - start));
    int idx = 0;

    for (int i = start; i != end && args[i] != NULL; i++) {
        tab[idx] = atof(args[i]);
        idx++;
    }
    return (tab);
}
