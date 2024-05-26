/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** csfml_protos.h
*/

#ifndef MY_H_
    #define MY_H_
    #include "csfml_structs.h"
window_t create_window(char *title);
sfTime update_clock(sfClock *clock);
void set_animation(animation_t *animation_infos, int sprite_nb,
sfVector2i *size, char *path);
int update_animation(animation_t *anim, int height_of_sprite, int order);
int set_background(background_t *background, sfVector2i *sizes,
sfVector2f *offset, char *path);
void display_background(window_t *window, background_t *background);
int get_mouse(window_t *window, mouse_t *mouse);
int is_quit(sfEvent *event, window_t *window);
int spawn_entity(entity_t *entity, char *type, sprites_list_t *sprites_list,
int sprites_nb);
int set_spawnpoint(entity_t *entity, float x, float y, float angle);
int move_entity(entity_t *entity, float x, float y, float angle);
int detect_click_on_entity(entity_t *entity, window_t *window, mouse_t *mouse);
sprites_list_t *add_sprite(sprites_list_t *sprites_list,
sprites_list_t *element, char **type_and_path, sfVector2i *sizes);
int ootb_x(int left_or_right, entity_t *entity, window_t *window);
int ootb_y(int up_or_down, entity_t *entity, window_t *window);
int add_target(window_t *window, char *target_path, sfIntRect *rectangle,
float scale);
void display_target(window_t *window);
int my_strcmp(const char *s1, const char *s2);
int destroy_entity_elements(sfTexture *texture, sfSprite *sprite,
sfSound *sound, sfSoundBuffer *sound_buffer);
int set_sound(entity_t *entity, char *filepath);
#endif
