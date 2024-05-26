/*
** EPITECH PROJECT, 2022
** CPOOL_Day08
** File description:
** my_strdup.c
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *dest = NULL;
    int i = 0;

    dest = malloc(sizeof(char) * (len + 1));
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
