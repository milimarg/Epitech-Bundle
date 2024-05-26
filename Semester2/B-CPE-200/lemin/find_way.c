/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** lem_in
*/

#include "includes/lmin.h"

int file_way_condition(stlemin_t *stlemin, int *current_lign, int *j,
int *array_way_element)
{
    for (int i = 0; i < stlemin->room_nbr; i++) {
        if (stlemin->matrix[*current_lign][i] == -2) {
            stlemin->matrix[*current_lign][i] = -3;
            *array_way_element = *current_lign;
            *current_lign = i;
            (*j)++;
            return (1);
        }
    }
    return (0);
}

void find_and_file_way(stlemin_t *stlemin, int **array_way, int a)
{
    int current_lign = stlemin->start_room;
    int stop = 0;
    int index = 0;
    int j = 0;

    while (1) {
        index = 0;
        if (current_lign == stlemin->end_room) {
            stop = 1;
        }
        for (int i = 0; i < stlemin->room_nbr; i++)
            index += (stlemin->matrix[current_lign][i] == -2);
        if (index == 0)
            break;
        file_way_condition(stlemin, &current_lign, &j, &array_way[a][j]);
        if (stop == 1)
            break;
    }
}

void file_real_way(stlemin_t *stlemin, int **array_way, int i, int **real_way)
{
    for (int a = 0; a < stlemin->distance; a++) {
        if (a == stlemin->distance - 1) {
            real_way[i][a] = stlemin->end_room;
        } else {
            real_way[i][a] = array_way[i][a];
        }
    }
}

void create_clean_array_way(stlemin_t *stlemin, int **array_way)
{
    int nbr_real_way = count_real_way(stlemin, array_way);
    int **real_way = malloc(sizeof(int *) * (nbr_real_way + 1));
    for (int i = 0; i < nbr_real_way; i++) {
        real_way[i] = malloc(sizeof(int) * (stlemin->distance + 1));
        file_real_way(stlemin, array_way, i, real_way);
    }
    stlemin->array_way = real_way;
}

int find_way(stlemin_t *stlemin)
{
    int current_lign = 0;
    int **array_way = NULL;
    int i = 0;
    stlemin->start_room = stlemin->start_room - 1;
    stlemin->end_room = stlemin->end_room - 1;
    stlemin->distance = find_distance(stlemin);
    stlemin->nbr_way = 0;
    current_lign = stlemin->start_room;
    i = stlemin->distance;
    calculate_nbr_way(stlemin, current_lign, i);
    if (stlemin->nbr_way == 0)
        return (84);
    array_way = malloc(sizeof(int *) * (stlemin->nbr_way + 1));
    for (int a = 0; a < stlemin->nbr_way; a++)
        array_way[a] = malloc(sizeof(int) * (stlemin->distance - 1));
    file_way(stlemin, array_way);
    create_clean_array_way(stlemin, array_way);
    return (0);
}
