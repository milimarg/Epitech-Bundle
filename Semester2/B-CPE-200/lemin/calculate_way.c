/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-lemin-florent.guittre
** File description:
** calculate_way.c
*/

#include "includes/lmin.h"

void calculate_nbr_way(stlemin_t *stlemin, int current_lign, int i)
{
    for (int a = 0; a < stlemin->room_nbr; a++) {
        if (stlemin->matrix[current_lign][a] == 1) {
            stlemin->nbr_way++;
            return;
        }
        if (stlemin->matrix[current_lign][a] == i &&
        stlemin->matrix[a][current_lign] == i - 1) {
            calculate_nbr_way(stlemin, a, i - 1);
        }
    }
}

int nbr_way_start(int start, stlemin_t *stlemin)
{
    int result = 0;

    for (int i = 0; i < stlemin->room_nbr; i++) {
        if (stlemin->matrix[start][i] >= 0) {
            result++;
        }
    }
    return (result);
}

void recursive_find_way(stlemin_t *stlemin, int **array_way, int current_lign)
{
    for (int i = 0; i < stlemin->room_nbr; i++) {
        if (stlemin->matrix[current_lign][i] == 1) {
            stlemin->stop_recursive = 1;
        }
        if (stlemin->stop_recursive == 1) {
            return;
        }
        if (stlemin->matrix[current_lign][i] >= 2 &&
        stlemin->matrix[i][current_lign] ==
        stlemin->matrix[current_lign][i] - 1) {
            stlemin->matrix[current_lign][i] = -2;
            recursive_find_way(stlemin, array_way, i);
        }
    }
}

void file_way(stlemin_t *stlemin, int **array_way)
{
    int start = stlemin->start_room;
    int *way;
    int a = 0;
    stlemin->stop_recursive = 0;
    int value = 0;
    while (value = nbr_way_start(start, stlemin) > 0) {
        stlemin->stop_recursive = 0;
        recursive_find_way(stlemin, array_way, start);
        find_and_file_way(stlemin, array_way, a);
        a++;
        if (a == stlemin->nbr_way)
            break;
    }
}

int count_real_way(stlemin_t *stlemin, int **array_way)
{
    int start_room = stlemin->start_room;
    int nbr_real_way = 0;
    int index = 0;

    for (int a = 0; a < stlemin->nbr_way; a++) {
        index = 0;
        for (int i = 0; i < stlemin->distance - 1; i++) {
            index += (array_way[a][i] == start_room);
        }
        if (index == 1)
            nbr_real_way++;
    }
    return (nbr_real_way);
}
