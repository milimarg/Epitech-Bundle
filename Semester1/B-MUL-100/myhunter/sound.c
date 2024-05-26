/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** sound.c
*/

#include "./include/myhunter_structs.h"
#include "./my-csfml/csfml_structs.h"

int switch_sound(game_i_t *game_i)
{
    if (sfKeyboard_isKeyPressed(sfKeyM))
        game_i->mute->is_sound_muted = !game_i->mute->is_sound_muted;
    return (0);
}

int add_mute_icon(game_i_t *game_i, char *filename, sfIntRect *rectangle,
window_t *window)
{
    sfVector2f mute_icon_pos = {0};
    sfVector2f mute_icon_scale = {0};
    int mute_icon_size = 2048;

    game_i->mute->sprite = sfSprite_create();
    game_i->mute->texture = sfTexture_createFromFile(filename, rectangle);
    sfSprite_setTexture(game_i->mute->sprite, game_i->mute->texture, sfTrue);
    mute_icon_scale.x = 0.05;
    mute_icon_scale.y = 0.05;
    mute_icon_pos.x = window->width -
    ((float)mute_icon_size * mute_icon_scale.x) -
    ((float)mute_icon_scale.x * 0.1);
    sfSprite_setPosition(game_i->mute->sprite, mute_icon_pos);
    sfSprite_setScale(game_i->mute->sprite, mute_icon_scale);
    return (0);
}
