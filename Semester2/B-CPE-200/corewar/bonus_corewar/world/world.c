/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** world.c
*/

#include "../../corewar/srcs/vm.h"

void create_corewar_world(t_env *e)
{
    sfVector2u size = {16, 256};
    my_idt1_player player = {0, 0, 50, 0, 0};
    sfVideoMode mode = {0};

    e->world = create_world_from_memory(&size, &player);
    mode = (sfVideoMode){e->world->map.opengl_size.x, e->world->map.opengl_size.y, 32};
    e->window = sfRenderWindow_create(mode, "coreworld", sfDefaultStyle, NULL);
    set_ground_and_sky(e->window, e->world);
    e->world->joystick_connected = 0;
}

int world_handler(t_env *e)
{
    static sfEvent event = {0};

    sfRenderWindow_clear(e->window, sfBlack);
    while (sfRenderWindow_pollEvent(e->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(e->window);
            destroy_world(e->world);
            exit(0);
        }
    }
    move_player(e->world);
    display_world(e->world);
    sfRenderWindow_display(e->window);
    return (0);
}
