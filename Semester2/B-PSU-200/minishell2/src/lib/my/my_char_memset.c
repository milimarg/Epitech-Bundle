/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-florent.guittre
** File description:
** my_memset.c
*/

#include <stddef.h>

char *my_char_memset(char *s, int c, size_t n)
{
    for (size_t i = 0; i < n; i++)
        s[i] = c;
    return (s);
}
