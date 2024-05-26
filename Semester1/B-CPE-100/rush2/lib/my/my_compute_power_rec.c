/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** Displays power of the number in parameter (recursive version).
*/

int    my_compute_power_rec(int nb, int p)
{
    int k = nb;

    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    k = nb * my_compute_power_rec(nb, p - 1);
    return (k);
}
