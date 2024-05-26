/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** move.c
*/

#include "./my-csfml/csfml_structs.h"
#include "./include/myhunter_structs.h"
#include "./include/myhunter_protos.h"

int move_entity(entity_t *entity, float x, float y, float angle);

int move_duck(entity_t *entity, int entity_index, game_i_t *game_i,
window_t *window)
{
    float x = 0.0;
    float y = 0.0;
    float angle = 0.0;
    sfVector2f entity_pos = {0};

    x = (game_i->duck_pos[entity_index] == 1) ? 2 : -2;
    y = -1;
    angle = 0.05;
    move_entity(entity, (x * entity->speed), (y * entity->speed), angle);
    entity_pos = sfSprite_getPosition(entity->animation->sprite);
    entity_pos.x -= entity->animation->size.x;
    entity_pos.y += entity->animation->size.y;
    if (game_i->duck_pos[entity_index] == 1 &&
    (entity_pos.y < 0 || entity_pos.x > window->width))
        random_spawnpoint_duck(entity, window, entity_index, game_i);
    if (game_i->duck_pos[entity_index] == 2 &&
    (entity_pos.y < 0 || entity_pos.x < (0 - entity->animation->size.x /
    entity->animation->sprite_nb)))
        random_spawnpoint_duck(entity, window, entity_index, game_i);
    return (0);
}

int get_scale_of_duck(sfVector2f *mirror_vertical, game_i_t *game_i,
int entity_index)
{
    mirror_vertical->x = (game_i->duck_pos[entity_index] == 1) ? 1 : -1;
    mirror_vertical->y = 1;
    return (0);
}
