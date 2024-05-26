/*
** EPITECH PROJECT, 2022
** putchar.c
** File description:
** wlh je l'avais pas deja
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
