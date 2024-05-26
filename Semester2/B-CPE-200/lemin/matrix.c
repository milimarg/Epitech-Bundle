/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-lemin-florent.guittre
** File description:
** matrix.c
*/

#include "includes/lmin.h"

void create_matrix(stlemin_t *stlemin)
{
    stlemin->matrix = malloc(sizeof(int *) * (stlemin->room_nbr + 1));

    for (int i = 0; i < stlemin->room_nbr; i++) {
        stlemin->matrix[i] = malloc(sizeof(int) * (stlemin->room_nbr));
        for (int a = 0; a < stlemin->room_nbr; a++)
            stlemin->matrix[i][a] = -1;
    }
    stlemin->matrix[stlemin->room_nbr] = NULL;
}

void fill_matrix(stlemin_t *stlemin, int **links)
{
    int x = 0;
    int y = 0;

    for (int i = 0; i < stlemin->link_nbr; i++) {
        x = links[i][0];
        y = links[i][1];
        stlemin->matrix[y][x] = 0;
        stlemin->matrix[x][y] = 0;
    }
}
