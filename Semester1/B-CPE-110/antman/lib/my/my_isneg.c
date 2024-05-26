/*
** EPITECH PROJECT, 2022
** my_isneg.c
** File description:
** Best Prog
*/

#include "my.h"

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else if (n < 0) {
        my_putchar('N');
    } else {
        my_putstr("Erreur");
    }
    return (0) ;
}
