/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-lemin-florent.guittre
** File description:
** dip_into_anthill.c
*/

#include "includes/lmin.h"

static void update_weight(int weight, int *index, stlemin_t *stlemin)
{
    if (stlemin->matrix[stlemin->i][stlemin->j] == weight) {
        for (int k = 0; k < stlemin->room_nbr; k++) {
            stlemin->matrix[stlemin->j][k] =
            (stlemin->matrix[stlemin->j][k] == 0) ?
            weight + 1 : stlemin->matrix[stlemin->j][k];
        }
        (*index)++;
    }
}

static void algo(stlemin_t *stlemin, int weight)
{
    int index = 0;

    for (stlemin->i = 0; stlemin->i < stlemin->room_nbr ; stlemin->i++)
        for (stlemin->j = 0; stlemin->j < stlemin->room_nbr ; stlemin->j++)
            update_weight(weight, &index, stlemin);
    if (index != 0)
        algo(stlemin, weight + 1);
}

void search_path(stlemin_t *stlemin)
{
    int current = stlemin->end_room - 1;
    int weight = 1;

    for (int i = 0; i < stlemin->room_nbr; i++)
        if (stlemin->matrix[current][i] == 0)
            stlemin->matrix[current][i] = weight;
    algo(stlemin, weight);
}
