/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** myhunter_structs.h
*/

#ifndef MYHUNTER_STRUCTS_H_
    #define MYHUNTER_STRUCTS_H_
    #include <SFML/Graphics.h>
typedef struct mute_s {
    int is_sound_muted;
    sfTexture *texture;
    sfSprite *sprite;
} mute_t;
typedef struct game_i_s {
    int *duck_pos;
    int score;
    int max_score;
    int max_score_len;
    sfSprite **score_digits;
    sfTexture **score_digits_texture;
    int entity_nb;
    int bg_nb;
    int chosen_bg;
    int *fly_sky;
    mute_t *mute;
} game_i_t;
#endif
