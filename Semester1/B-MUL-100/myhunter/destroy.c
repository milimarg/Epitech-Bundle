/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** destroy.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "./include/myhunter_structs.h"

int destroy_digit_sprites(game_i_t *game_i)
{
    for (int i = 0; i < game_i->max_score_len; i++) {
        sfTexture_destroy(game_i->score_digits_texture[i]);
        sfSprite_destroy(game_i->score_digits[i]);
    }
    free(game_i->score_digits);
    free(game_i->score_digits_texture);
    return (0);
}
