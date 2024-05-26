/*
** EPITECH PROJECT, 2022
** flags3.c
** File description:
** ceci est une flag 3
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

int print_hexaxa(unsigned long int nb, int count)
{
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

int print_adress(va_list list_arg, int count)
{
    unsigned long int nb = va_arg(list_arg, unsigned long int);
    my_putstr("0x");
    count = print_hexaxa(nb, count);
    return count + 2;
}

int my_binary(va_list list_arg, int count)
{
    int nb = va_arg(list_arg, int);
    char binatableau[50];
    int i = 0;

    while (nb != 0) {
        binatableau[i] = (nb % 2);
        i++;
        nb = nb / 2;
    }
    for (int k = i - 1; k >= 0; k--) {
        my_put_nbr(binatableau[k]);
    }
    return count + i;
}

int my_put_float(int nb, int i, int nbbase)
{
    char floattab[50];
    int long x;

    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
        my_put_float(nb, i, nb);
    } else {
        if (nb / 10) {
            i = my_put_float(nb / 10, i, nbbase);
        }
        i++;
        if (i == my_nbrlen(nbbase) - 6) {
            my_putchar('.');
            i++;
        }
        floattab[i] = nb % 10;
        my_put_nbr(floattab[i]);
        return i;
    }
}

int print_float(va_list list_arg, int count)
{
    float fl = va_arg(list_arg, double);
    int nb = fl * 1000000;
    int k = 0;
    my_put_float(nb, -1, nb);
    return count + my_nbrlen(nb) + 1 + k;
}
