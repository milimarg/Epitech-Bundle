/*
** EPITECH PROJECT, 2022
** my_putnbr_base
** File description:
** put base
*/

#include "my.h"

int my_putnbr_base_unsigned(unsigned int nbr, char const *base)
{
    int len_base = my_strlen(base);
    int a = 0;
    int i = 0;

    char tpm[12];
    if (nbr == 0) {
        my_putchar(base[0]);
        return (1);
    }
    while (nbr > 0) {
        a = nbr % len_base;
        nbr /= len_base;
        tpm[i] = base[a];
        i++;
    } tpm[i] = '\0';
    my_revstr(tpm);
    my_putstr(tpm);
    return (i);
}
