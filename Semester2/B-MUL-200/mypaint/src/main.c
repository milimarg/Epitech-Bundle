/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** main.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include "../my_csfml/window/window.h"
#include "../my_csfml/button/button.h"
#include "../my_csfml/lib/lib.h"
#include "../include/structs.h"
#include "../include/my.h"

void game_free(my_paint *p)
{
    destroy_sounds(p);
    free(p->values);
    destroy_window(p->w);
    destroy_os_background(p);
    free(p);
}

static int display_help(void)
{
    char *help = "";
    int len = 1;

    write(1, help, len);
    return (0);
}

static int parse_argv(int argc, char **argv, my_paint *p)
{
    if (argc > 1) {
        if (argc > 2)
            return (84);
        if (!my_strcmp(argv[1], "--os")) {
            p->enable_os = 1;
            return (1);
        }
        if (!my_strcmp(argv[1], "-h")) {
            return (display_help());
        }
        return (84);
    }
    return (1);
}

static int init_struct(my_paint *p, int argc, char **argv, char **env)
{
    int parse_output = 0;

    p->is_paint_open = 0;
    p->enable_os = 0;
    parse_output = parse_argv(argc, argv, p);
    if (parse_output != 1)
        return (parse_output);
    p->env = env;
    p->values = malloc(sizeof(my_values));
    p->w = create_window("MyPaint", 800, 600);
    return (1);
}

int main(int argc, char **argv, char **env)
{
    sfEvent event = {0};
    int parse_output = 0;
    my_paint *p = malloc(sizeof(my_paint));

    parse_output = init_struct(p, argc, argv, env);
    if (parse_output != 1)
        return (parse_output);
    set_os_sounds(p);
    set_os_background(p);
    if (p->enable_os)
        sfSound_play(p->os_sounds[0]);
    while (sfRenderWindow_isOpen(p->w->renderer)) {
        if (p->is_paint_open || !p->enable_os)
            paint_handler(p->w, &event, p);
        if (!p->is_paint_open && p->enable_os)
            os_handler(p->w, &event, p);
    }
    if (p->enable_os)
        run_shutdown_sound(p);
    game_free(p);
}
