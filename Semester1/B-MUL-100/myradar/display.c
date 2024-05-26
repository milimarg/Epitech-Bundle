/*
** EPITECH PROJECT, 2022
** B-MUL-100-STG-1-1-myradar-florent.guittre
** File description:
** display
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "my_csfml/window/window.h"
#include "my_csfml/animation/animation.h"
#include "my_csfml/entity/entity.h"
#include "include/my_structs.h"

void display_airplane(game_t *game, my_window *window, airplane_t *airplane)
{
    if (game->display_sprites)
        display_entity(window, airplane->entity);
    if (game->display_hitboxes)
        sfRenderWindow_drawRectangleShape(window->renderer,
        airplane->hitbox_square, NULL);
}

void display_elements(my_window *window, game_t *game)
{
    airplane_t *head = game->airplane_list;

    for (; game->airplane_list != NULL; game->airplane_list =
    game->airplane_list->next) {
        if (game->airplane_list->is_flying)
            display_airplane(game, window, game->airplane_list);
    }
    for (int i = 0; i < game->tower_nb; i++) {
        if (game->display_sprites)
            display_entity(window, game->towers[i].entity);
        if (game->display_hitboxes)
            sfRenderWindow_drawCircleShape(window->renderer,
            game->towers[i].hitbox_circle, NULL);
    }
    game->airplane_list = head;
    sfRenderWindow_drawText(window->renderer, game->timer_object, NULL);
    sfRenderWindow_display(window->renderer);
}
