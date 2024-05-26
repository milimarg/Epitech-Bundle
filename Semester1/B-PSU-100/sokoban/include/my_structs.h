/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** my_structs.h
*/

#ifndef MY_STRUCTS_H_
    #define MY_STRUCTS_H_
typedef struct game_s {
    int player_position;
    int default_player_position;
    int box_containers_nb;
    int boxes_nb;
    int right_boxes;
    int blocked_boxes;
    int *box_containers;
    int shift;
} game_t;
typedef struct map_s {
    int is_valid;
    int width;
    int height;
    int filesize;
    char *buffer;
    char *original_buffer;
    int size;
} map_t;
#endif
