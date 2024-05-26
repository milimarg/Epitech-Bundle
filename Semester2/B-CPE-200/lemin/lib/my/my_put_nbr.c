/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** il est 22h
*/

void my_putchar(char c);

void my_put_nbr(int nb)
{
    int long x;
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
        my_put_nbr(nb);
    } else {
        if (nb / 10) {
            my_put_nbr(nb / 10);
        }
    my_putchar('0' + nb % 10);
    }
}
