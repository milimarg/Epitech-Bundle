/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** animations
*/

#ifndef ANIMATIONS_H_
    #define ANIMATIONS_H_
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
typedef struct my_animation {
    int i;
    int sprite_nb;
    sfVector2f size;
    char *path;
    int has_sprite_been_defined;
    sfTexture **textures;
    sfSprite *sprite;
} my_animation;
typedef struct my_textures_list {
    char *name_tag;
    char *path;
    int width;
    int height;
    sfTexture *texture;
    struct my_textures_list *next;
} my_textures_list;
typedef struct sprite_sizes {
    int width;
    int height;
    sfIntRect *texture_rect;
} sprite_sizes;

// @brief Init a textures list.
// @return A NULL pointer to init the linked list.
my_textures_list *init_textures_list(void);

// @brief Link an image to a nametag, create a texture from the image and add it
// in the linked list.
// @param textures_list textures linked list
// @param name_tag nametag to check
// @param path path of image
// @param sfIntRect rectangle to apply
int add_texture(my_textures_list **textures_list, char *name_tag, char *path,
sfIntRect *rectangle);

// @brief Init animation.
// @param anim animation structure
// @param moves_nb number of sprites in image
// @param size full size of image
// @param path path of image
int set_animation(my_animation *anim, int moves_nb, sfVector2f *size,
char *path);

// @brief Update animation of one movement.
// @param anim animation structure
int destroy_textures_list(my_textures_list *textures_list);

#endif /* !ANIMATIONS_H_ */
