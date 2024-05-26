/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** myhunter_protos.h
*/

#ifndef MYHUNTER_PROTOS_H_
    #define MYHUNTER_PROTOS_H_
int declare_backgrounds(background_t *backgrounds);
sprites_list_t *declare_entity_sprites(sprites_list_t *sprites_list,
sprites_list_t *element);
int random_spawnpoint_duck(entity_t *entity, window_t *window, int entity_index,
game_i_t *game_i);
int set_score(int max_score_len, game_i_t *game_i, int score);
int display_score(window_t *window, sfSprite *score_digits[],
int max_score_len);
int my_intlen(int nb);
int events_manager(window_t *window, mouse_t *mouse, game_i_t *game_i,
entity_t *entities);
game_i_t init_game_infos(void);
int move_display_things(entity_t *entities, game_i_t *game_i, window_t *window);
int move_duck(entity_t *entity, int entity_index, game_i_t *game_i,
window_t *window);
void display_target(window_t *window);
int set_game_elements(game_i_t *game_i, window_t *window,
background_t *backgrounds);
int background_animation_sound(game_i_t *game_i, window_t *window,
background_t *backgrounds, entity_t *entities);
int init_score_digits(game_i_t *game_i);
int duck_fly_sky(int entity_index, entity_t *entities, game_i_t *game_i,
window_t *window);
int get_scale_of_duck(sfVector2f *mirror_vertical, game_i_t *game_i,
int entity_index);
int events_loop(game_i_t *game_i, window_t *window, mouse_t *mouse,
entity_t *entities);
game_i_t init_game_infos(void);
int init_score_digits(game_i_t *game_i);
int run_game(window_t *window, game_i_t *game_i, entity_t *entities);
int destroy_digit_sprites(game_i_t *game_i);
int switch_sound(game_i_t *game_i);
int add_mute_icon(game_i_t *game_i, char *filename, sfIntRect *rectangle,
window_t *window);
#endif
