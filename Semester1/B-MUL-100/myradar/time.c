/*
** EPITECH PROJECT, 2022
** B-MUL-100-STG-1-1-myradar-florent.guittre
** File description:
** time
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "my_csfml/window/window.h"
#include "my_csfml/animation/animation.h"
#include "my_csfml/entity/entity.h"
#include "include/my_structs.h"
#include "include/my.h"

void timer_update(char timer[])
{
    if (timer[4] > '9') {
        timer[4] = '0';
        timer[3]++;
    }
    if (timer[3] > '5') {
        timer[3] = '0';
        timer[1]++;
    }
    if (timer[1] > '9') {
        timer[1] = '0';
        timer[0]++;
    }
    if (timer[0] > '5') {
        timer[0] = '0';
        timer[1] = '0';
        timer[3] = '0';
        timer[4] = '0';
    }
}

int set_timer_object(game_t *game, char *timer_str, my_window *window)
{
    game->time_font = sfFont_createFromFile("./assets/Roboto-Regular.ttf");
    sfVector2f position = {window->width - 150, 0};

    timer_str[0] = '0';
    timer_str[1] = '0';
    timer_str[2] = ':';
    timer_str[3] = '0';
    timer_str[4] = '0';
    timer_str[5] = '\0';
    game->timer_object = sfText_create();
    sfText_setString(game->timer_object, timer_str);
    sfText_setFont(game->timer_object, game->time_font);
    sfText_setOutlineThickness(game->timer_object, 1.0);
    sfText_setFillColor(game->timer_object, sfBlack);
    sfText_setCharacterSize(game->timer_object, 50);
    sfText_setPosition(game->timer_object, position);
    return (0);
}

void time_manager(int *seconds_temp, char *timer, game_t *game)
{
    if (*seconds_temp >= 60) {
        *seconds_temp = 0;
        game->seconds++;
        timer[4]++;
        timer_update(timer);
        sfText_setString(game->timer_object, timer);
    }
}
