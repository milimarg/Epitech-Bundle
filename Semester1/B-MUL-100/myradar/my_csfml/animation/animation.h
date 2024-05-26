/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** animations
*/

#ifndef ANIMATIONS_H_
    #define ANIMATIONS_H_
typedef struct my_animation {
    int i;
    int sprite_nb;
    sfVector2f size;
    char *path;
    int has_sprite_been_defined;
    sfTexture **textures;
    sfSprite *sprite;
} my_animation;
typedef struct my_sprites_list {
    char *type;
    char *path;
    int spriteFullWidth;
    int spriteFullHeight;
    struct my_sprites_list *next;
} my_sprites_list;
my_sprites_list *init_sprites_list(void);
void add_sprite(my_sprites_list **sprites_list, char *type, char *path,
sfVector2f *sizes);
int set_animation(my_animation *anim, int moves_nb, sfVector2f *size,
char *path);
int destroy_sprites_list(my_sprites_list *sprites_list);
int mirror_vertically(my_animation *animation);
int mirror_horizontally(my_animation *animation);
#endif /* !ANIMATIONS_H_ */
