/*
** EPITECH PROJECT, 2022
** B-MUL-100-STG-1-1-myradar-florent.guittre
** File description:
** move
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "my_csfml/window/window.h"
#include "my_csfml/animation/animation.h"
#include "my_csfml/entity/entity.h"
#include "include/my_structs.h"
#include "include/my.h"
#include <stdio.h>

int get_coeff_move_airplane(airplane_t *airplane)
{
    int shift = 0;

    airplane->coeff_move.x = airplane->pos_end.x - airplane->pos_start.x;
    airplane->coeff_move.y = airplane->pos_end.y - airplane->pos_start.y;
    shift = abs((int)(airplane->coeff_move.x) * (60 / airplane->speed)) / 100;
    airplane->coeff_move.x /= shift;
    airplane->coeff_move.y /= shift;
    airplane->cycles_nb = shift;
    airplane->is_flying = 0;
    airplane->color_int = 0;
    airplane->color = (sfColor){0, 0, 0, 255};
    return (0);
}

int move_airplane(airplane_t *current_airplane, airplane_t *head, game_t *game)
{
    current_airplane->cycles_nb--;
    sfSprite_move(current_airplane->entity->animation->sprite,
    current_airplane->coeff_move);
    sfRectangleShape_move(current_airplane->hitbox_square,
    current_airplane->coeff_move);
    if (game->display_rainbow)
        update_color(game->airplane_list);
    check_airplane_collision(current_airplane, head, game);
    return (0);
}

void move_entity_manager(game_t *game)
{
    airplane_t *head = game->airplane_list;

    for (; game->airplane_list != NULL; game->airplane_list =
    game->airplane_list->next) {
        if (game->seconds == game->airplane_list->seconds_to_go &&
        !game->airplane_list->is_flying)
            game->airplane_list->is_flying = 1;
        if (game->airplane_list->cycles_nb != 0 &&
        game->airplane_list->is_flying) {
            move_airplane(game->airplane_list, head, game);
        }
        if (!game->airplane_list->cycles_nb && game->airplane_list &&
        game->airplane_list->is_flying) {
            remove_node(&head, game->airplane_list);
        }
    }
    game->airplane_list = head;
}
