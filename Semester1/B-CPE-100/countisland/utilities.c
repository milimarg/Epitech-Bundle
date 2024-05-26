/*
** EPITECH PROJECT, 2022
** CPOOL_count_island
** File description:
** utilities.c
*/

#include <stddef.h>

int get_limits(char letter, char **world)
{
    int a = 0;

    if (letter == 'x')
        while (world[a] != NULL)
            a++;
    else
        while (world[1][a] != '\0')
            a++;
    return a;
}

int format_co(int value, char letter, char **world)
{
    int limit_x = get_limits('x', world);
    int limit_y = get_limits('y', world);

    if (letter == 'x') {
        value = (value >= 1) ? value : (value + 1);
        value = (value <= limit_x - 1) ? value : (value - 1);
    } else {
        value = (value >= 0) ? value : (value + 1);
        value = (value <= limit_y - 1) ? value : (value - 1);
    }
    return value;
}

char int_to_char(int nb)
{
    return ('0' + nb);
}
