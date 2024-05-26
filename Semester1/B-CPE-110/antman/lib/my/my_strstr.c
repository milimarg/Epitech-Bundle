/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** wonderfull mouli
*/

#include "my.h"

static char ever(char *str, char const *to_find, int t, int i)
{
    int y = 0;
    while (str[t] == to_find[y]) {
        t++;
        y++;
        if (to_find[y] == '\0') {
            my_putchar(str[t - i]);
            return (str[t - i]);
        }
    }
    return 0;
    y = 0;
}

char *my_strstr (char *str, char const *to_find)
{
    int i = 0;
    int t = 0;
    int g;
    char temp;
    while (to_find[i] != '\0') {
        i++;
    }
    while (str[t] != '\0') {
        if (str[t] != to_find[0]) {
            t++;
            continue;
        }
        g = t;
        temp = ever(str, to_find, t ,i);
        if (temp != 0) {
            return (&str[t]);
        }
        t = g;
        t++;
    }
}
