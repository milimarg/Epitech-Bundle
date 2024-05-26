/*
** EPITECH PROJECT, 2022
** CPOOL_Day05
** File description:
** my_compute_power_it.c
*/

int my_compute_power_it(int nb, int p)
{
    int r;

    r = 0;
    if (p >= 0) {
        r = 1;
        for (int s = 0; s < p; s++) {
            r = r * nb;
        }
    }
    return r;
}
