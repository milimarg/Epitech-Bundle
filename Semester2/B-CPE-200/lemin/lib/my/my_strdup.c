/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-nahim.kandari
** File description:
** my_strdup
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char *string)
{
    int i = 0;
    char *newstr = malloc(sizeof(char) * my_strlen(string) + 1);
    for (; string[i] != '\0'; i++)
        newstr[i] = string[i];
    newstr[i] = '\0';
    return newstr;
}
