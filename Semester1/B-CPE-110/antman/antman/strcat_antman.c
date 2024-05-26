/*
** EPITECH PROJECT, 2022
** antman
** File description:
** antman
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/antman.h"

char *my_strcat_antman(char *dest, char *src, int size)
{
    int size_1 = 1;
    int size_2 = size;
    char *str = malloc(sizeof(char) * (size_1 + size_2 + 1));
    int i = 0;
    int a = 0;

    if (str == NULL)
        return (NULL);
    while (i < size_1 + size_2) {
        if (i < size_1)
            str[i] = dest[i];
        else {
            str[i] = src[a];
            a++;
        }
        i++;
    }
    str[i] = '\0';
    return (str);
}
