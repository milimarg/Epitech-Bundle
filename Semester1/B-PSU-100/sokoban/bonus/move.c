/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** move.c
*/

#include "./include/my.h"
#include "./include/my_macros.h"

int move_player_inside_map(char *map, game_t *game_infos, int next_moves[])
{
    player_box_container_handler(game_infos, map, next_moves);
    if (map[next_moves[0]] == BOX && map[next_moves[1]] == FREE) {
        map[game_infos->player_position] = FREE;
        map[next_moves[0]] = PLAYER;
        map[next_moves[1]] = BOX;
        game_infos->player_position = next_moves[0];
    }
    if (map[next_moves[0]] == FREE || map[next_moves[0]] == BOX_CONTAINER) {
        map[game_infos->player_position] = FREE;
        map[next_moves[0]] = PLAYER;
        game_infos->player_position = next_moves[0];
    }
    return (0);
}

int move_player(char *map, game_t *game_infos, int next_moves[])
{
    if (map[next_moves[0]] != WALL) {
        check_if_box_blocked(game_infos, map, next_moves);
        move_player_inside_map(map, game_infos, next_moves);
        is_box_on_container(map, game_infos, next_moves);
    }
    return (0);
}

int move_manager(int key, map_t *map, game_t *game_infos)
{
    int next_moves[] = {0, 0, 0};

    if (key == UP_ARROW || key == LEFT_ARROW) {
        game_infos->shift =
        (key == UP_ARROW) ? map->width + 1 : 1;
        next_moves[0] = game_infos->player_position - game_infos->shift;
        next_moves[1] = next_moves[0] - game_infos->shift;
        next_moves[2] = next_moves[1] - game_infos->shift;
    }
    if (key == DOWN_ARROW || key == RIGHT_ARROW) {
        game_infos->shift =
        (key == DOWN_ARROW) ? map->width + 1 : 1;
        next_moves[0] = game_infos->player_position + game_infos->shift;
        next_moves[1] = next_moves[0] + game_infos->shift;
        next_moves[2] = next_moves[1] + game_infos->shift;
    }
    move_player(map->buffer, game_infos, next_moves);
    if (game_infos->right_boxes == game_infos->boxes_nb)
        return (WIN);
    if (game_infos->blocked_boxes == game_infos->boxes_nb)
        return (FAIL);
    return (0);
}
