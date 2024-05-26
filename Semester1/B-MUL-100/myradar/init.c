/*
** EPITECH PROJECT, 2022
** B-MUL-100-STG-1-1-myradar-florent.guittre
** File description:
** entity
*/

#include <stdlib.h>
#include <stddef.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "my_csfml/window/window.h"
#include "my_csfml/animation/animation.h"
#include "my_csfml/entity/entity.h"
#include "include/my_structs.h"
#include "include/my.h"
#include <stdio.h>

int add_hitbox_square(airplane_t *airplane, double angle)
{
    sfVector2f origin = {airplane->entity->animation->size.x / 2,
    airplane->entity->animation->size.y / 2};

    airplane->hitbox_square = sfRectangleShape_create();
    sfRectangleShape_setSize(airplane->hitbox_square,
    airplane->entity->animation->size);
    sfRectangleShape_setOutlineColor(airplane->hitbox_square, sfGreen);
    sfRectangleShape_setOutlineThickness(airplane->hitbox_square, 1);
    sfRectangleShape_setFillColor(airplane->hitbox_square, sfTransparent);
    sfRectangleShape_setPosition(airplane->hitbox_square, airplane->pos_start);
    sfRectangleShape_setRotation(airplane->hitbox_square, angle);
    sfRectangleShape_setOrigin(airplane->hitbox_square, origin);
    return (0);
}

int add_hitbox_circle(tower_t *tower)
{
    float thickness = 5.0;
    float radius = (tower->radius * 1920) / 100 / 10;
    sfVector2f origin = {radius, radius};

    tower->hitbox_circle = sfCircleShape_create();
    sfCircleShape_setRadius(tower->hitbox_circle, radius);
    sfCircleShape_setOutlineColor(tower->hitbox_circle, sfBlue);
    sfCircleShape_setOutlineThickness(tower->hitbox_circle, thickness);
    sfCircleShape_setFillColor(tower->hitbox_circle, sfTransparent);
    sfCircleShape_setPosition(tower->hitbox_circle, tower->pos);
    sfCircleShape_setOrigin(tower->hitbox_circle, origin);
    return (0);
}

void set_airplanes(airplane_t *airplane_list, my_sprites_list *sprites_list,
game_t *game)
{
    double angle = 0.0;
    airplane_t *head = airplane_list;
    sfVector2f origin = {0};

    for (; airplane_list != NULL; airplane_list = airplane_list->next) {
        airplane_list->entity = spawn_entity("airplane", sprites_list, 1);
        angle = get_direction_angle(airplane_list) - 180;
        sfSprite_setPosition(airplane_list->entity->animation->sprite,
        airplane_list->pos_start);
        airplane_list->entity->position = airplane_list->pos_start;
        sfSprite_setRotation(airplane_list->entity->animation->sprite, angle);
        origin.x = airplane_list->entity->animation->size.x / 2;
        origin.y = airplane_list->entity->animation->size.y / 2;
        sfSprite_setOrigin(airplane_list->entity->animation->sprite, origin);
        add_moves(airplane_list->entity);
        update_animation(airplane_list->entity);
        add_hitbox_square(airplane_list, angle);
        get_coeff_move_airplane(airplane_list);
    }
    game->airplane_list = head;
}

void set_towers(game_t *game, my_sprites_list *sprites_list)
{
    for (int i = 0; i < game->tower_nb; i++) {
        game->towers[i].entity = spawn_entity("tower", sprites_list, 1);
        sfSprite_setPosition(game->towers[i].entity->animation->sprite,
        game->towers[i].pos);
        sfSprite_setOrigin(game->towers[i].entity->animation->sprite,
        (sfVector2f){game->towers[i].entity->animation->size.x / 2,
        game->towers[i].entity->animation->size.y / 2});
        add_moves(game->towers[i].entity);
        update_animation(game->towers[i].entity);
        add_hitbox_circle(&game->towers[i]);
    }
}

int init_entities(game_t *game)
{
    my_sprites_list *sprites_list = init_sprites_list();
    sfVector2f airplane_size = {20, 20};
    sfVector2f tower_size = {48, 48};

    add_sprite(&sprites_list, "airplane", "./assets/plane.png", &airplane_size);
    add_sprite(&sprites_list, "tower", "./assets/tower.png", &tower_size);
    set_airplanes(game->airplane_list, sprites_list, game);
    set_towers(game, sprites_list);
    return (0);
}
