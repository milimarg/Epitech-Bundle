/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** game.c
*/

#include <ncurses.h>
#include <SFML/Audio.h>
#include <unistd.h>
#include "./include/my.h"
#include "./include/my_macros.h"

int reset_game(map_t *map, game_t *game_infos, int key)
{
    if (key == SPACE_KEY) {
        for (int i = 0; i < map->size; i++)
            map->buffer[i] = map->original_buffer[i];
        game_infos->player_position = game_infos->default_player_position;
        game_infos->right_boxes = 0;
        game_infos->blocked_boxes = 0;
    }
    return (0);
}

int game_manager(map_t *map, game_t *game_infos, int key, int x_y[])
{
    int o = 0;

    if (map->height <= x_y[1] && map->width <= x_y[0]) {
        reset_game(map, game_infos, key);
        o = move_manager(key, map, game_infos);
        if (o == WIN || o == FAIL) {
            won_game(o, game_infos, map);
            endwin();
            return (o);
        }
    }
    return (0);
}

int game_loop(map_t *map, game_t *game_infos)
{
    int key = 0;
    int x_y[] = {0, 0};
    int o = 0;

    initscr();
    noecho();
    do {
        getmaxyx(stdscr, x_y[1], x_y[0]);
        clear();
        display_map(map, x_y[0], x_y[1]);
        key = getch();
        o = game_manager(map, game_infos, key, x_y);
        if (o == WIN || o == FAIL)
            return (o);
        refresh();
    } while (key != QUIT_KEY);
    endwin();
    return (0);
}

int game(map_t *map)
{
    int o = 0;
    int key = 0;
    int shift = 0;
    game_t game_infos = init_game_infos(map);

    if (check_if_multiple_players(map, &game_infos) == 84 ||
    game_infos.player_position == -84 ||
    game_infos.boxes_nb != game_infos.box_containers_nb)
        return (84);
    init_win_sound(&game_infos, "./assets/win.ogg");
    o = game_loop(map, &game_infos);
    frees(map, &game_infos);
    return (o);
}
