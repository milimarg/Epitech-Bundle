/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-lemin-florent.guittre
** File description:
** display_moves.c
*/

#include "includes/lmin.h"

int calculate_size_array(int **array_way)
{
    int nbr_way = 0;
    for (int i = 0; array_way[i]; i++) {
        nbr_way++;
    }
    return (nbr_way);
}

int *file_the_ant_pos(int **array_way, stlemin_t *stlemin)
{
    int *ant_pos = malloc(sizeof(int) * (stlemin->ant_nbr));
    for (int i = 0; i < stlemin->ant_nbr; i++) {
        ant_pos[i] = array_way[0][0];
    }
    return (ant_pos);
}

int same_room(int actual_ant, int way, int **array_way, stlemin_t *stlemin)
{
    for (int i = 0; i < stlemin->distance; i++) {
        if (i + 1 != stlemin->distance && actual_ant == array_way[way][i]) {
            return (array_way[way][i + 1]);
        }
    }
    return (84);
}

void move_ants(int **array_way, stlemin_t *stlemin)
{
    int nbr_way = calculate_size_array(array_way);
    int *ant_pos = file_the_ant_pos(array_way, stlemin);
    write(1, "#moves\n", 7);
    while (ant_pos[stlemin->ant_nbr - 1] !=
    array_way[nbr_way - 1][stlemin->distance - 1]) {
        for (int i = 0; i < nbr_way; i++) {
            move_ant_subdivision(stlemin, ant_pos, array_way, i);
        }
        write(1, "\n", 1);
    }
}
