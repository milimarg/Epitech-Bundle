/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** my_structs.h
*/

#ifndef MY_STRUCTS_H_
    #define MY_STRUCTS_H_
    #include <SFML/Audio.h>
typedef struct game_sound_s {
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
} game_sound_t;
typedef struct game_s {
    int player_position;
    int default_player_position;
    int box_containers_nb;
    int boxes_nb;
    int right_boxes;
    int blocked_boxes;
    int *box_containers;
    int shift;
    game_sound_t *win_sound;
} game_t;
typedef struct map_s {
    int is_valid;
    int width;
    int height;
    char *buffer;
    char *original_buffer;
    int size;
} map_t;
#endif
