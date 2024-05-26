/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** put number
*/
#include <stdarg.h>
#include "my.h"

static int my_put_nbr_len_next(int nb, int *lenght)
{
    int i = 0, temp = nb, result;
    if (nb < 0) {
        nb = -nb;
        *lenght = *lenght + 1;
    } if (nb > 0) {
        if (nb >= 10) {
            i = nb % 10;
            nb = nb / 10;
            *lenght = *lenght + 1;
            my_put_nbr_len_next(nb, lenght);
        } else {
            *lenght = *lenght + 1;
        }
    } if (nb == 0) {
        *lenght = *lenght + 1;
    } return (*lenght);
}

int len_nbr(int nb)
{
    int length = 0;
    int result = my_put_nbr_len_next(nb, &length);
    return (result);
}
