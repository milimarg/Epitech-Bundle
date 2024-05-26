/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** window.c
*/

#include "csfml_structs.h"

window_t create_window(char *title)
{
    window_t window = {0};
    sfVideoMode mode = {0};

    window.width = 800;
    window.height = 600;
    window.bitsPerPixel = 32;
    mode.width = window.width;
    mode.height = window.height;
    mode.bitsPerPixel = window.bitsPerPixel;
    window.renderer = sfRenderWindow_create(mode, title, sfResize | sfClose,
    NULL);
    sfRenderWindow_setFramerateLimit(window.renderer, 60);
    sfRenderWindow_setMouseCursorVisible(window.renderer, sfFalse);
    window.clock = sfClock_create();
    return (window);
}

int set_background(background_t *background, sfVector2i *sizes,
sfVector2f *offset, char *path)
{
    sfIntRect rectangle = {0};

    background->width = sizes->x;
    background->height = sizes->y;
    background->x_offset = offset->x;
    background->y_offset = offset->y;
    background->path = path;
    rectangle.width = background->width;
    rectangle.height = background->height;
    rectangle.left = background->x_offset;
    rectangle.top = background->y_offset;
    background->texture =
    sfTexture_createFromFile(background->path, &rectangle);
    background->sprite = sfSprite_create();
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    return (0);
}

void display_background(window_t *window, background_t *background)
{
    sfVector2f scaling = {0};

    scaling.x = (float)window->width / (float)background->width;
    scaling.y = (float)window->height / (float)background->height;
    sfSprite_setScale(background->sprite, scaling);
    sfRenderWindow_drawSprite(window->renderer, background->sprite, NULL);
}

int add_target(window_t *window, char *target_path, sfIntRect *rectangle,
float scale)
{
    window->target->path = target_path;
    window->target->sprite = sfSprite_create();
    window->target->texture = sfTexture_createFromFile(window->target->path,
    rectangle);
    sfSprite_setTexture(window->target->sprite, window->target->texture,
    sfTrue);
    window->target->scale = scale;
    window->target->scale_vector.x = window->target->scale;
    window->target->scale_vector.y = window->target->scale;
    sfSprite_setScale(window->target->sprite, window->target->scale_vector);
    return (0);
}

void display_target(window_t *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window->renderer);
    sfVector2f sprite_pos = {0};

    sprite_pos.x = mouse_pos.x - (140 / 2 * window->target->scale);
    sprite_pos.y = mouse_pos.y - (140 / 2 * window->target->scale);
    sfSprite_setPosition(window->target->sprite, sprite_pos);
    sfRenderWindow_drawSprite(window->renderer, window->target->sprite, NULL);
}
