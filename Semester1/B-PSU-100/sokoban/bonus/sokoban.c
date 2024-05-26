/*
** EPITECH PROJECT, 2022
** B-PSU-100-STG-1-1-sokoban-florent.guittre
** File description:
** sokoban
*/

#include "./include/my.h"
#include "./include/my_macros.h"

int sokoban_handler(int argc, char **argv)
{
    map_t map = {0};
    int o = 0;
    int filesize = 0;

    if (argc != 2)
        return (84);
    if (!my_strcmp(argv[1], "-h"))
        display_help_message();
    else {
        filesize = get_filesize(argv[1]);
        map = fill_struct(argv[1], filesize);
        if (filesize == -84 || !map.is_valid)
            return (84);
        o = game(&map);
        if (o == 84)
            return (84);
        return (o == FAIL);
    }
}
