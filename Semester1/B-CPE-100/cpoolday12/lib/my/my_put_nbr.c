/*
** EPITECH PROJECT, 2022
** CPOOL_CWorkshopLib
** File description:
** my_put_nbr.c
*/

void my_putchar(char c);

int my_intlen(int nb);

int my_put_nbr(int nb)
{
    int LEN = my_intlen(nb);
    int temp[LEN];

    if (nb == 0)
        my_putchar('0');
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    for (int i = 0; i < LEN; i++) {
        temp[i] = nb % 10;
        nb /= 10;
    }
    for (int i = LEN - 1; i >= 0; i--) {
        my_putchar(temp[i] + '0');
    }
    return 0;
}
