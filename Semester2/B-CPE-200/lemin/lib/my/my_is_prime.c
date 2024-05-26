/*
** EPITECH PROJECT, 2022
** my_is_prime.c
** File description:
** J'ai chaud
*/

int bouboucle(int nb)
{
    int i = 0;

    for (i = 2; i < nb - 1; i++) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}

int my_is_prime(int nb)
{
    if (nb < 0) {
        nb = nb * (-1);
    }
    if (nb == 0 || nb == 1) {
        return 0;
    } else {
        return bouboucle(nb);
    }
}
