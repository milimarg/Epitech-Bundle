/*
** EPITECH PROJECT, 2022
** CPOOL_Day05
** File description:
** my_compute_factorial_it.c
*/

int my_compute_factorial_it(int nb)
{
    int s;

    s = 0;
    if (nb >= 0 && nb <= 12) {
        s = 1;
        for (int i = 0; i < nb; i++)
            s = s * (i + 1);
    }
    return s;
}
