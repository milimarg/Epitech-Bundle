/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** entity
*/

#ifndef ENTITY_H_
    #define ENTITY_H_
typedef struct my_entity {
    char *type;
    int is_clicked;
    int is_ready;
    my_animation *animation;
    sfVector2f position;
    float speed;
    float hp;
    int (*add_moves)(struct my_entity *);
    void (*update)(struct my_entity *);
    void (*display)(my_window *, struct my_entity *);
    int (*destroy)(struct my_entity *);
} my_entity;
int my_extra_strlen(char const *str);
int my_strcmp(const char *s1, const char *s2);
my_entity *spawn_entity(char *type, my_sprites_list *sprites_list,
int sprites_nb);
int set_spawnpoint(my_entity *entity, float x, float y, float angle);
int move_entity(my_entity *entity, float x, float y, float angle);
void update_animation(my_entity *entity);
void display_entity(my_window *window, my_entity *entity);
int ootb_x(int left_or_right, my_entity *entity, my_window *window);
int ootb_y(int up_or_down, my_entity *entity, my_window *window);
int add_moves(my_entity *entity);
int destroy_entity(my_entity *entity);
#endif /* !ENTITY_H_ */
