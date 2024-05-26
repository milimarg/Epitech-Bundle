/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-lemin-florent.guittre
** File description:
** free_all_functions
*/

#include "../includes/lmin.h"

void free_all(stlemin_t stlemin)
{
    free(stlemin.input);
    for (int i = 0; stlemin.rooms[i] != NULL; i++) {
        for (int j = 0; stlemin.rooms[i][j] != NULL; j++)
            free(stlemin.rooms[i][j]);
        free(stlemin.rooms[i]);
    }
    free(stlemin.rooms);
}
