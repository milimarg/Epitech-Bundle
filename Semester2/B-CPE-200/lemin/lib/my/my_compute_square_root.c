/*
** EPITECH PROJECT, 2022
** my_compute_square_root.c
** File description:
** Nathannael est un BDG
*/

int my_compute_square_root(int nb)
{
    int i = 0;

    while (i * i < nb)
        i++;
    if (i * i == nb)
        return i;
    return 0;
}
