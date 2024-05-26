/*
** EPITECH PROJECT, 2022
** bonus
** File description:
** bonus
*/

#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include "./include/my.h"
#include "./include/my_macros.h"

int init_win_sound(game_t *game_infos, char *win_sound_path)
{
    game_infos->win_sound = malloc(sizeof(game_sound_t));
    game_infos->win_sound->sound = NULL;
    game_infos->win_sound->sound = sfSound_create();
    game_infos->win_sound->sound_buffer = NULL;
    game_infos->win_sound->sound_buffer =
    sfSoundBuffer_createFromFile(win_sound_path);
    sfSound_setBuffer(game_infos->win_sound->sound,
    game_infos->win_sound->sound_buffer);
    return (0);
}

int won_game_check(game_t *game_infos, map_t *map)
{
    float music_seconds = 0.0;
    float animation_sleep = 0.125;

    sfSound_play(game_infos->win_sound->sound);
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++)
            mvprintw(i, j, "#");
        usleep(animation_sleep * 1000000);
        music_seconds += animation_sleep;
        refresh();
    }
    usleep((2 - music_seconds) * 1000000);
    return (0);
}

int won_game(int o, game_t *game_infos, map_t *map)
{
    int step_shift_nb = 3;

    if (o == WIN)
        won_game_check(game_infos, map);
    return (0);
}
