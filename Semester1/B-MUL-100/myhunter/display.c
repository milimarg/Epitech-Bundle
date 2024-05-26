/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** display.c
*/

#include "./my-csfml/csfml_structs.h"
#include "./include/myhunter_structs.h"
#include "./include/myhunter_protos.h"

void display_background(window_t *window, background_t *background);
int update_animation(animation_t *anim, int height_of_sprite, int order);

int move_display_things(entity_t *entities, game_i_t *game_i, window_t *window)
{
    for (int i = 0; i < game_i->entity_nb; i++) {
        sfRenderWindow_drawSprite(window->renderer,
        entities[i].animation->sprite, NULL);
    if (!game_i->fly_sky[i])
        move_duck(&entities[i], i, game_i, window);
    }
    display_score(window, game_i->score_digits, game_i->max_score_len);
    display_target(window);
    return (0);
}

int switch_background(game_i_t *game_i)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum1) && game_i->chosen_bg != 0)
        game_i->chosen_bg = 0;
    if (sfKeyboard_isKeyPressed(sfKeyNum2) && game_i->chosen_bg != 1)
        game_i->chosen_bg = 1;
    if (sfKeyboard_isKeyPressed(sfKeyNum3) && game_i->chosen_bg != 2)
        game_i->chosen_bg = 2;
    return (0);
}

int background_animation_sound(game_i_t *game_i, window_t *window,
background_t *backgrounds, entity_t *entities)
{
    float seconds =
    sfClock_getElapsedTime(window->clock).microseconds / 1000000.0;
    sfVector2f offset = {0, -5};

    sfRenderWindow_clear(window->renderer, sfBlack);
    switch_background(game_i);
    display_background(window, &backgrounds[game_i->chosen_bg]);
    for (int i = 0; i < game_i->entity_nb; i++) {
        if (game_i->fly_sky[i])
            sfSprite_move(entities[i].animation->sprite, offset);
    }
    if (seconds > 0.25) {
        for (int i = 0; i < game_i->entity_nb; i++)
            update_animation(entities[i].animation, 110, 0);
        switch_sound(game_i);
        sfClock_restart(window->clock);
    }
    if (game_i->mute->is_sound_muted)
        sfRenderWindow_drawSprite(window->renderer, game_i->mute->sprite, NULL);
    return (0);
}
