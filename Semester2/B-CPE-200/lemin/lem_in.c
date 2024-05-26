/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** lem_in
*/

#include "includes/lmin.h"

int find_room_index(char *room_name, char **rooms)
{
    for (int i = 0; rooms[i] != NULL; i++)
        if (!my_strcmp(room_name, rooms[i]))
            return (i);
    return (-1);
}

void fill_links(stlemin_t *stlemin, int **links, int i)
{
    int idx = 0;

    for (; stlemin->rooms[idx + i] != NULL; idx++) {
        links[idx] = malloc(sizeof(int) * 2);
        links[idx][0] = find_room_index(stlemin->rooms[idx + i][0],
        stlemin->rooms_names);
        links[idx][1] = find_room_index(stlemin->rooms[idx + i][1],
        stlemin->rooms_names);
    }
    links[idx] = NULL;
}

void fill_rooms(int *i, stlemin_t *stlemin)
{
    for (*i = 1; *i < stlemin->room_nbr + 1; (*i)++) {
        stlemin->rooms_names[*i - 1] = malloc(sizeof(char) *
        my_strlen(stlemin->rooms[*i][0]));
        stlemin->rooms_names[*i - 1] = my_strcpy(stlemin->rooms_names[*i - 1],
        stlemin->rooms[*i][0]);
    }
    stlemin->rooms_names[stlemin->room_nbr] = NULL;
}

int subdivision_lem_in(stlemin_t *stlemin)
{
    int room_alone = direct_way(stlemin);
    if (room_alone != 0) {
        create_array_for_simple_way(stlemin, room_alone);
        move_ants(stlemin->array_way, stlemin);
        return (0);
    } else {
        if (find_way(stlemin) == 84)
            return (84);
        move_ants(stlemin->array_way, stlemin);
    }
    return (0);
}

int lem_in(stlemin_t *stlemin)
{
    int i = 0;
    int idx = 0;
    int **links = NULL;
    create_matrix(stlemin);
    for (; stlemin->rooms[idx][2][0] != '\0'; idx++);
    stlemin->rooms_names = malloc(sizeof(char *) * (stlemin->room_nbr + 1));
    fill_rooms(&i, stlemin);
    idx = 0;
    for (; stlemin->rooms[i + idx] != NULL; idx++);
    links = malloc(sizeof(int *) * (idx + 1));
    fill_links(stlemin, links, i);
    fill_matrix(stlemin, links);
    search_path(stlemin);
    return (subdivision_lem_in(stlemin));
}
