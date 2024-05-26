/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #include "my_structs.h"
int get_filesize(char *filename);
int game(map_t *map);
map_t fill_struct(char *filename, int filesize);
int get_map_rows(char *buffer, int filesize);
int get_map_columns(char *buffer);
int move_manager(int key, map_t *map, game_t *game_infos);
int get_boxes_nb(char *buffer, int filesize);
int get_box_containers_nb(char *buffer, int filesize);
int get_player_position(char *buffer, int map_size);
game_t init_game_infos(map_t *map);
int frees(map_t *map, game_t *game_infos);
int display_help_message(void);
int test(map_t *map, int index, int check_after[], int wall_nb);
int check_map_is_valid(map_t *map, int filesize, int wall_nb);
int is_box_on_container(char *map, game_t *game_infos, int next_moves[]);
int sokoban_handler(int argc, char **argv);
int check_if_box_blocked(game_t *game_infos, char *map, int next_moves[]);
int check_if_multiple_players(map_t *map, game_t *game_infos);
int player_box_container_handler(game_t *game_infos, char *map,
int next_moves[]);
void display_map(map_t *map, int x, int y);
char *my_strdup(char const *src);
int my_strlen(char const *str);
#endif
