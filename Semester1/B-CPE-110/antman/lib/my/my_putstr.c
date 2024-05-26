/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** Good Prog
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
        my_putchar(str[i]);
        i++;
    } return (i);
}
