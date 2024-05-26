/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** player.c
*/

#include "./my-csfml/csfml_structs.h"
#include "./include/myhunter_structs.h"

int my_intlen(int nb);

int convert_int_to_score(int digit, sfSprite *sprite, sfTexture *texture)
{
    sfIntRect rectangle;

    rectangle.width = 8;
    rectangle.height = 8;
    rectangle.left = 192;
    rectangle.top = 240;
    if (digit >= 5 && digit <= 9) {
        rectangle.top += rectangle.height;
        digit -= 5;
    }
    rectangle.left += (rectangle.width * digit);
    texture = sfTexture_createFromFile("./assets/backgrounds.png", &rectangle);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (0);
}

int set_score(int max_score_len, game_i_t *game_i, int score)
{
    int temp_score = score;

    game_i->score = score;
    if (game_i->score > game_i->max_score)
        game_i->score = game_i->max_score;
    for (int i = max_score_len - 1; i >= 0; i--) {
        game_i->score_digits_texture[i] = NULL;
        if (temp_score >= 1) {
            convert_int_to_score(temp_score % 10,
            game_i->score_digits[i], game_i->score_digits_texture[i]);
            temp_score /= 10;
        } else
            convert_int_to_score(0,
            game_i->score_digits[i], game_i->score_digits_texture[i]);
    }
    return (0);
}

int fill_number(window_t *window, sfSprite *sprite, sfVector2f *shift)
{
    sfSprite_setPosition(sprite, *shift);
    shift->x = 25.0 / 8.0;
    shift->y = 20.0 / 8.0;
    sfSprite_setScale(sprite, *shift);
    sfRenderWindow_drawSprite(window->renderer, sprite, NULL);
    return (0);
}

int display_score(window_t *window, sfSprite *score_digits[], int max_score_len)
{
    sfVector2f shift;

    for (int i = 0; i < max_score_len; i++) {
        shift.x = 600.0 + (i * 25);
        shift.y = 520.0;
        fill_number(window, score_digits[i], &shift);
    }
    return (0);
}
