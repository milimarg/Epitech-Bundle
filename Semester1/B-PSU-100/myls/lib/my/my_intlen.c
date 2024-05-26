/*
** EPITECH PROJECT, 2022
** CPOOL_CWorkshopLib
** File description:
** my_intlen.c
*/

int my_intlen(int nb)
{
    nb = (nb < 0) ? nb * (-1) : nb;
    if (nb >= 0 && nb <= 9)
        return 1;
    if (nb >= -2147483647 && nb <= 2147483647)
        return my_intlen(nb / 10) + 1;
    else
        return 0;
}
