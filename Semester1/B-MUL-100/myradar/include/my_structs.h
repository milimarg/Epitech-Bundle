/*
** EPITECH PROJECT, 2022
** B-MUL-100-STG-1-1-myradar-florent.guittre
** File description:
** my_structs
*/

#ifndef MY_STRUCTS_H
    #define MY_STRUCTS_H
typedef struct airplane_s {
    my_entity *entity;
    sfVector2f pos_start;
    sfVector2f pos_end;
    int speed;
    int seconds_to_go;
    sfRectangleShape *hitbox_square;
    sfVector2f coeff_move;
    int cycles_nb;
    int is_flying;
    int color_int;
    sfColor color;
    struct airplane_s *next;
    struct airplane_s *prev;
} airplane_t;
typedef struct tower_s {
    my_entity *entity;
    sfVector2f pos;
    int radius;
    sfCircleShape *hitbox_circle;
} tower_t;
typedef struct game_s {
    my_background *background;
    int tower_nb;
    airplane_t *airplane_list;
    tower_t *towers;
    sfFont *time_font;
    sfText *timer_object;
    int seconds;
    sfTime time;
    int display_hitboxes;
    int display_sprites;
    int display_rainbow;
} game_t;
#endif /* !MY_STRUCTS_H_ */
