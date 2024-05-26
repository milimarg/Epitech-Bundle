/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-lemin-florent.guittre
** File description:
** display_moves.c
*/

#include "includes/lmin.h"

void subdivision_two(int a, int *ant_pos, int *index)
{
    if (ant_pos[a] == 0) {
        (*index)++;
    }
}

void space_placement(int a, int i, int j)
{
    if ((a != 0 && i != 0) || j != 0)
        write(1, " ", 1);
}

void move_ant_subdivision(stlemin_t *stlemin, int *ant_pos,
int **array_way, int i)
{
    int index = 0;
    int tmp = 0;
    int j = 0;
    for (int a = 0; a < stlemin->ant_nbr; a++) {
        tmp = same_room(ant_pos[a], i, array_way, stlemin);
        if (index == 0 && tmp != 84) {
            space_placement(a, i, j);
            my_printf("P%d-%s", a + 1, stlemin->rooms_names[tmp]);
            subdivision_two(a, ant_pos, &index);
            ant_pos[a] = tmp;
            j++;
        }
    }
}
