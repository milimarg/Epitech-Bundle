/*
** EPITECH PROJECT, 2022
** my_compute_power_rec.c
** File description:
** OOF
*/

int my_compute_power_rec(int nb, int p)
{
    int x = 0;

    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return 1;
    }
    x = nb * my_compute_power_rec(nb, p - 1);
    return x;
}
