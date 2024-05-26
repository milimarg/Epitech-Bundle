/*
** EPITECH PROJECT, 2022
** antman
** File description:
** antman
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/antman.h"

int seconde_recurent_word(int i, char *str)
{
    char c;
    if (str[i] == 'l' && str[i + 1] == 'i' && str[i + 2] == 'n' &&
    str[i + 3] == 'k') {
        c = -3;
        write(1, &c, 1);
        return (4);
    }
    if (str[i] == 's' && str[i + 1] == 'c' && str[i + 2] == 'r' &&
    str[i + 3] == 'i' && str[i + 4] == 'p' && str[i + 5] == 't') {
        c = -4;
        write(1, &c, 1);
        return (6);
    }
    return (0);
}

int recurent_word(int i, char *str)
{
    char c;
    if (str[i] == 'h' && str[i + 1] == 't' && str[i + 2] == 'm' &&
    str[i + 3] == 'l') {
        c = -1;
        write(1, &c, 1);
        return (4);
    }
    if (str[i] == 'f' && str[i + 1] == 'u' && str[i + 2] == 'n' &&
    str[i + 3] == 'c' && str[i + 4] == 't' && str[i + 5] == 'i' &&
    str[i + 6] == 'o' && str[i + 7] == 'n') {
        c = -2;
        write(1, &c, 1);
        return (8);
    }
    return (seconde_recurent_word(i, str));
}

int html_compression(int ac, char **av, char *str)
{
    int i = 0;
    int value = 0;

    while (str[i] != '\0') {
        value = recurent_word(i, str);
        if (value == 0) {
            write(1, &str[i], 1);
            i++;
        } else {
            i = i + value;
        }
    }
    return (0);
}
