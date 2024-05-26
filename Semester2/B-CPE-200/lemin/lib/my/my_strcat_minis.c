/*
** EPITECH PROJECT, 2022
** strcat
** File description:
** Y a pas le goblin aujourdhui
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat_minis(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *newstr = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src)
                            + 1));

    for (; dest[i] != '\0'; i++ & j++)
        newstr[j] = dest[i];
    for (i = 0; src[i] != '\0' && src[i] != '\n'; i++ & j++)
        newstr[j] = src[i];
    newstr[j] = '\0';
    free(dest);
    return newstr;
}
