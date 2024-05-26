/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** clock
*/

#include "window.h"

int get_time_clock(my_window *window)
{
    return (sfClock_getElapsedTime(window->clock).microseconds);
}

void restart_clock(my_window *window)
{
    sfClock_restart(window->clock);
}
