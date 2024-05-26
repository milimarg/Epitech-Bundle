/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** spawn.c
*/

#include <stdlib.h>
#include "./my-csfml/csfml_structs.h"
#include "./my-csfml/csfml_protos.h"
#include "./include/myhunter_structs.h"

int generate_y(int duck_pos_y)
{
    static int order = 0;
    static int isneg = 0;

    if (!isneg)
        order++;
    if (order > duck_pos_y)
        isneg = 1;
    if (isneg)
        order--;
    if (order <= 0) {
        order = 1;
        isneg = 0;
    }
    return (order);
}

int random_spawnpoint_duck(entity_t *entity, window_t *window, int entity_index,
game_i_t *game_i)
{
    int duck_y_order = 5;
    int duck_y = ((window->height - entity->animation->size.y) / duck_y_order)
    * ((rand() % 5) + 1);

    game_i->duck_pos[entity_index] = (rand() % 2) + 1;
    set_spawnpoint(entity, ootb_x((game_i->duck_pos[entity_index] == 2),
    entity, window), duck_y, -10);
    return (0);
}
