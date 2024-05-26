/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** Displays number.
*/

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
        my_put_nbr(nb);
    } else if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    } else {
        my_putchar(nb + '0');
    }
}
