/*
** EPITECH PROJECT, 2022
** B-MUL-100-STG-1-1-myradar-florent.guittre
** File description:
** game
*/

#include <stdlib.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "my_csfml/window/window.h"
#include "my_csfml/animation/animation.h"
#include "my_csfml/entity/entity.h"
#include "include/my_structs.h"
#include "include/my.h"

int frees(char *timer, game_t *game, my_window *window)
{
    airplane_t *temp = NULL;

    for (; game->airplane_list != NULL; game->airplane_list = temp) {
        temp = game->airplane_list->next;
        free_airplane(game->airplane_list);
    }
    for (int i = 0; i < game->tower_nb; i++) {
        destroy_entity(game->towers[i].entity);
        sfCircleShape_destroy(game->towers[i].hitbox_circle);
    }
    free(game->towers);
    free(timer);
    sfText_destroy(game->timer_object);
    sfFont_destroy(game->time_font);
    sfRenderWindow_close(window->renderer);
    destroy_window(window);
    return (0);
}

int clock_restart_manager(game_t *game, my_window *window, int *seconds_temp)
{
    if ((game->time.microseconds / 1000) >= 16.66f) {
        move_entity_manager(game);
        restart_clock(window);
        (*seconds_temp)++;
    }
    return (0);
}

void key_display_manager(sfEvent *event, game_t *game)
{
    if (event->key.code == sfKeyL) {
        game->display_hitboxes = !game->display_hitboxes;
        event->key.code = -1;
    }
    if (event->key.code == sfKeyS) {
        game->display_sprites = !game->display_sprites;
        event->key.code = -1;
    }
    if (event->key.code == sfKeyR) {
        game->display_rainbow = !game->display_rainbow;
        event->key.code = -1;
    }
}

int run_game(my_window *window, game_t *game, char *timer)
{
    sfEvent event = {0};
    int seconds_temp = 0;

    init_entities(game);
    set_timer_object(game, timer, window);
    while (sfRenderWindow_isOpen(window->renderer)) {
        sfRenderWindow_clear(window->renderer, sfBlack);
        key_display_manager(&event, game);
        time_manager(&seconds_temp, timer, game);
        display_background(window, game->background);
        game->time = sfClock_getElapsedTime(window->clock);
        while (sfRenderWindow_pollEvent(window->renderer, &event));
        clock_restart_manager(game, window, &seconds_temp);
        if (game->airplane_list == NULL || event.type == sfEvtClosed ||
        event.key.code == sfKeyEscape)
            return (0);
        display_elements(window, game);
    }
    return (0);
}
