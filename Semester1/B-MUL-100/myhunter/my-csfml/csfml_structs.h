/*
** EPITECH PROJECT, 2022
** Bootstrap_MyHunter
** File description:
** csfml_structs.h
*/

#ifndef MY_STRUCTS_H_
    #define MY_STRUCTS_H_
    #include <SFML/Graphics.h>
    #include <SFML/Config.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
typedef struct background_s {
    int width;
    int height;
    char *path;
    float x_offset;
    float y_offset;
    sfTexture *texture;
    sfSprite *sprite;
} background_t;
typedef struct target_s {
    sfTexture *texture;
    sfSprite *sprite;
    float scale;
    sfVector2f scale_vector;
    char *path;
} target_t;
typedef struct window_s {
    int width;
    int height;
    int bitsPerPixel;
    char *title;
    sfRenderWindow *renderer;
    target_t *target;
    sfClock *clock;
} window_t;
typedef struct animation_s {
    int i;
    int sprite_nb;
    sfVector2i size;
    char *path;
    int has_sprite_been_defined;
    sfTexture *texture;
    sfSprite *sprite;
} animation_t;
typedef struct mouse_s {
    sfVector2i coor;
    sfBool left_clicked;
    sfBool right_clicked;
} mouse_t;
typedef struct entity_s {
    char *type;
    int is_clicked;
    int x;
    int y;
    animation_t *animation;
    sfVector2f position;
    float speed;
    float hp;
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
} entity_t;
typedef struct sprites_list_s {
    char *type;
    char *path;
    int spriteFullWidth;
    int spriteFullHeight;
    struct sprites_list_s *next;
} sprites_list_t;
#endif
