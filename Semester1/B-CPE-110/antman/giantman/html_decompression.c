/*
** EPITECH PROJECT, 2022
** giantman
** File description:
** giantman
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/giantman.h"

int write_good_word(int i, char *str)
{
    if (str[i] == -1) {
        write(1, "html", 4);
        return (1);
    }
    if (str[i] == -2) {
        write(1, "function", 8);
        return (1);
    }
    if (str[i] == -3) {
        write(1, "link", 4);
        return (1);
    }
    if (str[i] == -4) {
        write(1, "script", 6);
        return (1);
    }
    return (0);
}

int html_compression (int ac, char **av, char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (write_good_word(i, str) == 0)
            my_putchar(str[i]);
        i++;
    }
}
