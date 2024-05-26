/*
** EPITECH PROJECT, 2022
** flags2.c
** File description:
** ceci est une flag 2
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

int my_print_purcent(va_list list_arg, int count)
{
    my_putchar('%');
    return count + 1;
}

int print_octal(va_list list_arg, int count)
{
    int nb = va_arg(list_arg, int);
    int i = 0;
    int j = 0;
    int k = 1;

    while (nb != 0) {
        i = nb % 8;
        j = j + i * k;
        nb = nb / 8;
        k = k * 10;
    }
    my_put_nbr(j);
    return count + my_nbrlen(j);
}

int print_hexa_maj(va_list list_arg, int count)
{
    int nb = va_arg(list_arg, int);
    char hexatableau[50];
    int i = 0;

    while (nb != 0) {
        if (nb % 16 < 10) {
            hexatableau[i] = (48 + nb % 16);
            i++;
        } else {
            hexatableau[i] = (55 + nb % 16);
            i++;
        }
        nb = nb / 16;
    }
    for (int k = i - 1; k >= 0; k--) {
        my_putchar(hexatableau[k]);
    }
    return count + i;
}

int print_hexa_min(va_list list_arg, int count)
{
    int nb = va_arg(list_arg, int);
    char hexatableau[50];
    int i = 0;

    while (nb != 0) {
        if (nb % 16 < 10) {
            hexatableau[i] = (48 + nb % 16);
            i++;
        } else {
            hexatableau[i] = (87 + nb % 16);
            i++;
        }
        nb = nb / 16;
    }
    for (int k = i - 1; k >= 0; k--) {
        my_putchar(hexatableau[k]);
    }
    return count + i;
}

int printn(va_list list_arg, int count)
{
    *va_arg(list_arg, char*) = count;
    return count;
}
