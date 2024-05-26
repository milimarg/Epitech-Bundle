/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** my_intlen.c
*/

long my_intlen(long nb)
{
    nb = (nb < 0) ? nb * (-1) : nb;
    if (nb >= 0 && nb <= 9)
        return 1;
    if (nb >= -4294967296 && nb <= 4294967296)
        return my_intlen(nb / 10) + 1;
    else
        return 0;
}
