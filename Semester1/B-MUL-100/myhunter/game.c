/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** game.c
*/

#include <stdlib.h>
#include "./my-csfml/csfml_structs.h"
#include "./my-csfml/csfml_protos.h"
#include "./include/myhunter_structs.h"
#include "./include/myhunter_protos.h"

int free_elements(background_t *backgrounds, entity_t *entities,
sprites_list_t *sprites_list, game_i_t *game_i)
{
    for (int i = 0; i < game_i->bg_nb; i++)
        destroy_entity_elements(backgrounds[i].texture,
        backgrounds[i].sprite, NULL, NULL);
    for (int i = 0; i < game_i->entity_nb; i++) {
        destroy_entity_elements(entities[i].animation->texture,
        entities[i].animation->sprite, entities[i].sound,
        entities[i].sound_buffer);
        free(entities[i].animation);
    }
    destroy_entity_elements(game_i->mute->texture, game_i->mute->sprite, NULL,
    NULL);
    free(backgrounds);
    free(entities);
    free(game_i->mute);
    free(game_i->fly_sky);
    while (sprites_list) {
        sprites_list = sprites_list->next;
    }
    return (0);
}

int set_entities(game_i_t *game_i, sprites_list_t *sprites_list,
window_t *window, entity_t *entities)
{
    char *entity_names[] = {"duck", "duck2", "duck3", "duck4", "duck5"};
    int index = 0;
    int images_nb = 5;

    for (int i = 0; i < game_i->entity_nb; i++) {
        index = (rand() % images_nb);
        spawn_entity(&entities[i], entity_names[index], sprites_list, 3);
        entities[i].speed = 1.0;
        random_spawnpoint_duck(&entities[i], window, i, game_i);
        set_sound(&entities[i], "./assets/Dogma_angel_transform_end.ogg");
    }
    return (0);
}

int test(sfVector2f *mirror_vertical, game_i_t *game_i, entity_t *entities,
window_t *window)
{
    for (int i = 0; i < game_i->entity_nb; i++) {
        get_scale_of_duck(mirror_vertical, game_i, i);
        sfSprite_setScale(entities[i].animation->sprite, *mirror_vertical);
    }
    move_display_things(entities, game_i, window);
    return (0);
}

int run_game(window_t *window, game_i_t *game_i, entity_t *entities)
{
    sfEvent event;
    background_t *backgrounds = malloc(sizeof(background_t) * game_i->bg_nb);
    sprites_list_t *sprites_list = NULL;
    sprites_list_t *element = {0};
    mouse_t mouse = {0};
    sfVector2f mirror_vertical = {0};

    sprites_list = declare_entity_sprites(sprites_list, element);
    set_entities(game_i, sprites_list, window, entities);
    set_game_elements(game_i, window, backgrounds);
    while (sfRenderWindow_isOpen(window->renderer)) {
        is_quit(&event, window);
        background_animation_sound(game_i, window, backgrounds, entities);
        test(&mirror_vertical, game_i, entities, window);
        while (sfRenderWindow_pollEvent(window->renderer, &event))
            events_loop(game_i, window, &mouse, entities);
        sfRenderWindow_display(window->renderer);
    }
    free_elements(backgrounds, entities, sprites_list, game_i);
    return (0);
}
