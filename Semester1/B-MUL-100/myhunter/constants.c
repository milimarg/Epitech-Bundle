/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** constants.c
*/

#include <stdlib.h>
#include "./my-csfml/csfml_protos.h"
#include "./include/myhunter_structs.h"
#include "./include/myhunter_protos.h"

int declare_backgrounds(background_t *backgrounds)
{
    sfVector2i sizes = {0};
    sfVector2f offset = {0};
    char *background_path = "./assets/backgrounds.png";

    sizes.x = 256;
    sizes.y = 240;
    offset.x = 0.0;
    offset.y = 0.0;
    for (int i = 0; i < 3; i++) {
        set_background(&backgrounds[i], &sizes, &offset, background_path);
        offset.x += 256.0;
    }
    return (0);
}

sprites_list_t *declare_entity_sprites(sprites_list_t *sprites_list,
sprites_list_t *element)
{
    sfVector2i duck_sizes = {0};
    char *type_path_1[] = {"duck", "./assets/ducks/1.png"};
    char *type_path_2[] = {"duck2", "./assets/ducks/2.png"};
    char *type_path_3[] = {"duck3", "./assets/ducks/3.png"};
    char *type_path_4[] = {"duck4", "./assets/ducks/4.png"};
    char *type_path_5[] = {"duck5", "./assets/ducks/5.png"};
    char **duck_elem[] = {type_path_1, type_path_2, type_path_3, type_path_4,
    type_path_5};
    int images_nb = 5;

    duck_sizes.x = 330;
    duck_sizes.y = 110;
    for (int i = 0; i < images_nb; i++) {
        sprites_list = add_sprite(sprites_list, element,
        duck_elem[i], &duck_sizes);
    }
    return (sprites_list);
}

game_i_t init_game_infos(void)
{
    game_i_t game_i = {0};

    game_i.score = 0;
    game_i.max_score = 999999;
    game_i.max_score_len = my_intlen(game_i.max_score);
    game_i.score_digits =
    malloc(sizeof(sfSprite *) * game_i.max_score_len);
    game_i.score_digits_texture =
    malloc(sizeof(sfTexture *) * game_i.max_score_len);
    game_i.bg_nb = 3;
    game_i.chosen_bg = 0;
    game_i.entity_nb = 2;
    game_i.fly_sky = malloc(sizeof(int) * game_i.entity_nb);
    game_i.duck_pos = malloc(sizeof(int) * game_i.entity_nb);
    for (int i = 0; i < game_i.entity_nb; i++) {
        game_i.fly_sky[i] = 0;
        game_i.duck_pos[i] = 1;
    }
    game_i.mute = malloc(sizeof(mute_t));
    return (game_i);
}

int init_score_digits(game_i_t *game_i)
{
    for (int i = 0; i < game_i->max_score_len; i++)
        game_i->score_digits[i] = sfSprite_create();
    return (0);
}

int set_game_elements(game_i_t *game_i, window_t *window,
background_t *backgrounds)
{
    declare_backgrounds(backgrounds);
    set_score(game_i->max_score_len, game_i, game_i->score);
    window->target = malloc(sizeof(target_t));
    add_target(window, "./assets/target.png", NULL, 0.5);
    add_mute_icon(game_i, "./assets/mute_icon.png", NULL, window);
    return (0);
}
