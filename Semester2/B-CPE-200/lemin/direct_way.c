/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** lem_in
*/

#include "includes/lmin.h"

void create_array_for_simple_way(stlemin_t *stlemin, int room_alone)
{
    stlemin->array_way = malloc(sizeof(int *));
    stlemin->array_way[0] = malloc(sizeof(int) * 2);
    stlemin->array_way[0][0] = stlemin->start_room - 1;
    stlemin->array_way[0][1] = stlemin->end_room - 1;
    stlemin->distance = 2;
    return;
}

void print_char_triple(stlemin_t *stlemin)
{
    for (int i = 0; stlemin->rooms[i]; i++) {
        for (int j = 0; stlemin->rooms[i][j]; j++) {
            my_printf("%s\t", stlemin->rooms[i][j]);
        }
        my_putchar('\n');
    }
}

int calculate_size_array_char(char **array)
{
    int size = 0;
    while (array[size]) {
        size = size + 1;
    }
    return (size);
}

int find_simple_way(stlemin_t *stlemin, char **array)
{
    int value1 = my_getnbr(array[0]);
    int value2 = my_getnbr(array[1]);
    if (value1 == stlemin->start_room - 1 && value2 == stlemin->end_room - 1) {
        return (0);
    }
    if (value2 == stlemin->start_room - 1 && value1 == stlemin->end_room - 1) {
        return (0);
    }
    return (1);
}

int direct_way(stlemin_t *stlemin)
{
    int index;
    for (int i = 0; stlemin->rooms[i]; i++) {
        index = 1;
        if (calculate_size_array_char(stlemin->rooms[i]) == 4) {
            index = find_simple_way(stlemin, stlemin->rooms[i]);
        }
        if (index == 0) {
            return (i);
        }
    }
    return (0);
}
