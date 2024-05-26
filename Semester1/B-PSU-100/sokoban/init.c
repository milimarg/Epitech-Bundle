/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** init.c
*/

#include <stdlib.h>
#include "./include/my.h"

game_t init_game_infos(map_t *map)
{
    game_t game_infos = {0};

    game_infos.boxes_nb = get_boxes_nb(map->buffer, map->size);
    game_infos.box_containers_nb =
    get_box_containers_nb(map->buffer, map->size);
    game_infos.player_position =
    get_player_position(map->buffer, map->size);
    game_infos.right_boxes = 0;
    game_infos.blocked_boxes = 0;
    game_infos.box_containers = malloc(sizeof(int) *
    game_infos.box_containers_nb);
    game_infos.default_player_position = game_infos.player_position;
    game_infos.shift = 0;
    return (game_infos);
}
