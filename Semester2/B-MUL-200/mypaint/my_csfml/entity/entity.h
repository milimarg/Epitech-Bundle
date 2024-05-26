/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** entity
*/

#ifndef ENTITY_H_
    #define ENTITY_H_
    #include <SFML/Graphics.h>
    #include "../window/window.h"
    #include "../animation/animation.h"
typedef struct my_entity {
    char *type;
    int is_clicked;
    int is_ready;
    my_animation *animation;
    sfVector2f position;
    float speed;
    float hp;
} my_entity;

// @brief Init an entity.
// @param entity entity structure
// @param name_tag name_tag to match
// @param textures_list textures linked list
// @param sprites_nb number of sprites in image
my_entity *spawn_entity(char *name_tag, my_textures_list *textures_list,
int sprites_nb);

// @brief Init first position of entity.
// @param x x axis of position
// @param y y axis of position
// @param angle of position
int set_spawnpoint(my_entity *entity, float x, float y, float angle);

// @brief Move position of entity.
// @param entity entity structure
// @param x x offset of move
// @param y y offset of move
// @param angle angle offset of move
int move_entity(my_entity *entity, float x, float y, float angle);

// ...
int ootb_x(int left_or_right, my_entity *entity, my_window *window);

// ...
int ootb_y(int up_or_down, my_entity *entity, my_window *window);

// ...
int add_moves(my_entity *entity);

// ...
int destroy_entity(my_entity *entity);
#endif /* !ENTITY_H_ */
