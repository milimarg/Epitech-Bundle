/*
** EPITECH PROJECT, 2022
** CPOOL_Day05
** File description:
** my_compute_factorial_rec.c
*/

int my_compute_factorial_rec(int nb)
{
    if (nb == 0 || nb == 1) {
        return 1;
    } else if (nb < 0 || nb > 12) {
        return 0;
    } else {
        return nb * my_compute_factorial_rec(nb - 1);
    }
}
