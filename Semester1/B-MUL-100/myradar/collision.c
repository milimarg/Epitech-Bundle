/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-florent.guittre
** File description:
** collision
*/

#include <math.h>
#include <SFML/Graphics.h>
#include "my_csfml/window/window.h"
#include "my_csfml/animation/animation.h"
#include "my_csfml/entity/entity.h"
#include "include/my_structs.h"
#include "include/my.h"
#include <stdio.h>

int collision_airplane(airplane_t *a1, airplane_t *a2)
{
    sfVector2f a1_pos = sfRectangleShape_getPosition(a1->hitbox_square);
    sfVector2f a2_pos = sfRectangleShape_getPosition(a2->hitbox_square);

    return (pow(a1_pos.x - a2_pos.x, 2) + pow(a1_pos.y - a2_pos.y, 2) <= 400);
}

int collision_tower(airplane_t *a1, game_t *game)
{
    sfVector2f a1_pos = sfRectangleShape_getPosition(a1->hitbox_square);
    sfVector2f tower_pos = {0};
    float tower_radius = 0;

    for (int i = 0; i < game->tower_nb; i++) {
        tower_pos = sfCircleShape_getPosition(game->towers[i].hitbox_circle);
        tower_radius = sfCircleShape_getRadius(game->towers[i].hitbox_circle);
        if (pow(a1_pos.x - tower_pos.x, 2) + pow(a1_pos.y - tower_pos.y, 2)
        <= pow(10.0 + tower_radius, 2)) {
            sfRectangleShape_setOutlineColor(a1->hitbox_square, sfBlack);
            return (1);
        } else {
            sfRectangleShape_setOutlineColor(a1->hitbox_square,
            (game->display_rainbow) ? a1->color : sfGreen);
        }
    }
    return (0);
}

int airplane_collision_manager(airplane_t *current_airplane,
airplane_t *checker, airplane_t **head)
{
    if (current_airplane != checker && checker->is_flying) {
        if (collision_airplane(current_airplane, checker)) {
            remove_node(head, current_airplane);
            remove_node(head, checker);
        }
    }
    return (0);
}

int check_airplane_collision(airplane_t *current_airplane, airplane_t *head,
game_t *game)
{
    if (collision_tower(current_airplane, game))
        return (0);
    for (airplane_t *checker = head; checker != NULL; checker = checker->next)
        airplane_collision_manager(current_airplane, checker, &head);
    return (0);
}
