/*
** EPITECH PROJECT, 2022
** CPOOL_Day05
** File description:
** my_compute_square_root.c
*/

int my_compute_square_root(int nb)
{
    int a;
    int r;
    int final;

    a = 1;
    r = 1;
    if (nb == 0 || nb == 1)
        final = nb;
    while (r < nb) {
        a++;
        r = a * a;
        if (nb == r)
            final = a;
        else
            final = 0;
    }
    return final;
}
