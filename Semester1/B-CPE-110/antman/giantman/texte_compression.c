/*
** EPITECH PROJECT, 2022
** giantman
** File description:
** giantman
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/giantman.h"

int pipe_checker(char *str, char *buffer, int *i, int *a)
{
    if (str[*i] != '|') {
        buffer[*a] = str[*i];
        (*a)++;
        (*i)++;
    } else {
        if (store_buffer(str, buffer, i, a) == 84)
            return (84);
    }
    return (0);
}

int texte_compression(int ac, char **av, char *str)
{
    int find_size_val = find_size(str);
    int size = find_size_val + my_strlen(str);
    char *buffer = malloc(sizeof(char) * (size + 1));
    int a = 0;
    int i = 0;
    int j = 0;
    int value = 0;
    int tmp = 0;

    if (find_size_val == -84 || buffer == NULL)
        return (84);
    while (str[i] != '\0') {
        if (pipe_checker(str, buffer, &i, &a) == 84)
            return (84);
    }
    buffer[a] = '\0';
    my_putstr(buffer);
    return (0);
}
