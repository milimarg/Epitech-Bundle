/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** God prog
*/

#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}
