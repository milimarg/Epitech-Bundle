/*
** EPITECH PROJECT, 2022
** flags
** File description:
** les flags
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

int print_str(va_list list_arg, int count)
{
    char* str = va_arg(list_arg, char*);
    my_putstr(str);
    return count + my_strlen(str);
}

int print_unsi(va_list list_arg, int count)
{
    long nb = va_arg(list_arg, long);
    my_put_unnbr(nb);
    return count + my_nbrlen(nb);
}

int print_char(va_list list_arg, int count)
{
    char b = va_arg(list_arg, int);
    my_putchar(b);
    return count + 1;
}

int print_int(va_list list_arg, int count)
{
    int nb = va_arg(list_arg, int);
    my_put_nbr(nb);
    return count + my_nbrlen(nb);
}
