/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** good prog
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    int i = 0;
    int a = 0;
    char *copy;
    while (src[i] != '\0') {
        i++;
    }
    copy = malloc(sizeof(char) * (i + 1));
    if (copy == NULL)
        return (NULL);
    while (src[a] != '\0') {
        copy[a] = src[a];
        a++;
    }
    copy[a] = '\0';
    return (copy);
}
