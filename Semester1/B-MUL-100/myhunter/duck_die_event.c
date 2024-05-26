/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** duck_die_event.c
*/

#include "./my-csfml/csfml_protos.h"
#include "./include/myhunter_structs.h"
#include "./include/myhunter_protos.h"

int duck_fly_sky(int entity_index, entity_t *entities, game_i_t *game_i,
window_t *window)
{
    sfVector2f test = {0};

    test = sfSprite_getPosition(entities[entity_index].animation->sprite);
    if ((test.y - entities[entity_index].animation->size.y) < -150 &&
    game_i->fly_sky[entity_index]) {
        game_i->fly_sky[entity_index] = 0;
        entities[entity_index].is_clicked = 0;
        random_spawnpoint_duck(&entities[entity_index], window, entity_index,
        game_i);
    }
    return (0);
}
