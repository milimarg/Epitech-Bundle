/*
** EPITECH PROJECT, 2022
** flags4.c
** File description:
** flag4
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

int print_scien(va_list list_arg, int count)
{
    int k = 0;
    int j = 0;
    double nb = va_arg(list_arg, double);
    while (nb < 1) {
        nb = nb * 10;
        k++;
        j = 1;
    }
    while (nb > 9) {
        nb = nb / 10;
        k++;
    }
    my_printf("%f", nb);
    if (j == 0) {
        my_putstr("e+");
    } else {
        my_putstr("e-");
    }
    my_put_nbr(k);
    return count + k + 5;
}

int print_scienup(va_list list_arg, int count)
{
    int k = 0;
    int j = 0;
    double nb = va_arg(list_arg, double);
    while (nb < 1) {
        nb = nb * 10;
        k++;
        j = 1;
    }
    while (nb > 9) {
        nb = nb / 10;
        k++;
    }
    my_printf("%f", nb);
    if (j == 0) {
        my_putstr("E+");
    } else {
        my_putstr("E-");
    }
    my_put_nbr(k);
}

int print_space(const char *format, int i)
{
    while (format[i] == ' ') {
        i++;
    }
    return i;
}

int plus_flag(va_list list_arg, int count)
{
    va_list temp;
    va_copy(temp, list_arg);
    if (va_arg(temp, int) >= 0) {
        my_putchar('+');
        return count + 1;
    }
    return count;
}
