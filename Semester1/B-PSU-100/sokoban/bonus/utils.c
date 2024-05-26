/*
** EPITECH PROJECT, 2022
** B-PSU-100-STG-1-1-sokoban-florent.guittre
** File description:
** utils
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "include/my.h"

int display_help_message(void)
{
    char *str = "USAGE\n"
                "     ./my_sokoban map\n"
                "DESCRIPTION\n"
                "     map   file representing the warehouse map, containing '#'"
                " for walls,\n     'P' for the player, 'X' for boxes and"
                " 'O' for storage locations.\n"
                "USER INPUT\n"
                "     [up-down-left-right] arrows: move.\n"
                "     f4: quit the game.\n";
    write(1, str, 260);
    return (0);
}

map_t fill_struct(char *filename, int filesize)
{
    map_t map = {0};
    int fd = open(filename, O_RDONLY);

    map.is_valid = 1;
    if (fd == -1)
        map.is_valid = 0;
    if (map.is_valid) {
        map.size = filesize;
        map.buffer = malloc(sizeof(void) * (map.size + 1));
        read(fd, map.buffer, map.size);
        map.buffer[map.size] = '\0';
        close(fd);
        map.original_buffer = my_strdup(map.buffer);
        map.width = get_map_columns(map.buffer);
        map.height = get_map_rows(map.buffer, map.size);
    }
    return (map);
}

int frees(map_t *map, game_t *game_infos)
{
    free(map->buffer);
    free(map->original_buffer);
    sfSoundBuffer_destroy(game_infos->win_sound->sound_buffer);
    sfSound_destroy(game_infos->win_sound->sound);
    free(game_infos->win_sound);
    return (0);
}
