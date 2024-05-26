/*
** EPITECH PROJECT, 2022
** B-PSU-100-STG-1-1-sokoban-florent.guittre
** File description:
** items
*/

#include "./include/my.h"
#include "./include/my_macros.h"

int player_box_container_handler(game_t *game_infos, char *map,
int next_moves[])
{
    for (int i = 0; i < game_infos->box_containers_nb; i++) {
        if (game_infos->player_position == game_infos->box_containers[i]) {
            map[game_infos->player_position] = BOX_CONTAINER;
            map[next_moves[1]] = (map[next_moves[0]] == BOX)
            ? BOX : map[next_moves[1]];
            map[next_moves[0]] = PLAYER;
            game_infos->player_position = next_moves[0];
        }
        if (next_moves[0] == game_infos->box_containers[i] &&
        map[next_moves[0]] == BOX && map[next_moves[1]] != WALL) {
            map[game_infos->player_position] = FREE;
            map[next_moves[0]] = PLAYER;
            map[next_moves[1]] = BOX;
            game_infos->player_position = next_moves[0];
            game_infos->right_boxes--;
        }
    }
    return (0);
}

int is_box_on_container(char *map, game_t *game_infos, int next_moves[])
{
    if (map[next_moves[0]] == BOX &&
    map[next_moves[1]] == BOX_CONTAINER) {
        map[game_infos->player_position] = FREE;
        map[next_moves[0]] = PLAYER;
        map[next_moves[1]] = BOX;
        game_infos->player_position = next_moves[0];
        game_infos->right_boxes++;
    }
    return (0);
}

int check_if_multiple_players(map_t *map, game_t *game_infos)
{
    int players = 0;
    int box_and_walls_condition = 0;
    int player_and_free_conditions = 0;
    int shift_box_container = 0;

    for (int i = 0; i < map->size; i++) {
        box_and_walls_condition = (map->buffer[i] != WALL &&
        map->buffer[i] != BOX && map->buffer[i] != BOX_CONTAINER);
        player_and_free_conditions = (map->buffer[i] != PLAYER &&
        map->buffer[i] != FREE && map->buffer[i] != '\n');
        if (box_and_walls_condition && player_and_free_conditions)
            return (84);
        if (map->buffer[i] == PLAYER)
            players++;
        if (map->buffer[i] == BOX_CONTAINER)
            game_infos->box_containers[shift_box_container++] = i;
    }
    if (players != 1)
        return (84);
    return (0);
}

int check_if_box_blocked(game_t *game_infos, char *map, int next_moves[])
{
    if (map[next_moves[0]] == BOX && map[next_moves[1]] == FREE &&
    (map[next_moves[2]] == WALL || map[next_moves[2]] == BOX)) {
        if ((map[next_moves[1] - 1] == WALL || map[next_moves[1] + 1] == WALL)
        || (map[next_moves[1] - 1] == BOX || map[next_moves[1] + 1] == BOX))
            game_infos->blocked_boxes++;
    }
    return (0);
}
