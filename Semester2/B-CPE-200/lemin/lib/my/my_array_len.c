/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-nahim.kandari
** File description:
** my_array_len
*/

#include "my.h"

int my_array_len(char **array)
{
    int i = 0;
    for (; array[i] != NULL; i++);
    return i;
}
