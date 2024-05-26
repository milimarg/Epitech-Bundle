/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** events.c
*/

#include "./my-csfml/csfml_structs.h"
#include "./include/myhunter_structs.h"
#include "./include/myhunter_protos.h"
#include "./my-csfml/csfml_protos.h"

int duck_killed(entity_t *entity, game_i_t *game_i)
{
    game_i->score += 1000;
    entity->speed += 0.1;
    set_score(game_i->max_score_len, game_i, game_i->score);
    if (!game_i->mute->is_sound_muted)
        sfSound_play(entity->sound);
    return (0);
}

int events_manager(window_t *window, mouse_t *mouse, game_i_t *game_i,
entity_t *entity)
{
    get_mouse(window, mouse);
    detect_click_on_entity(entity, window, mouse);
    if (mouse->left_clicked && entity->is_clicked) {
        duck_killed(entity, game_i);
        return (1);
    }
    return (0);
}

int events_loop(game_i_t *game_i, window_t *window, mouse_t *mouse,
entity_t *entities)
{
    for (int i = 0; i < game_i->entity_nb; i++) {
        if (!game_i->fly_sky[i]) {
            game_i->fly_sky[i] =
            (events_manager(window, mouse, game_i, &entities[i])) ?
            1 : game_i->fly_sky[i];
        }
        duck_fly_sky(i, entities, game_i, window);
    }
    return (0);
}
