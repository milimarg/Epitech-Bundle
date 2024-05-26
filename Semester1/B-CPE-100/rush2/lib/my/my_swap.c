/*
** EPITECH PROJECT, 2022
** my_swap
** File description:
** Swaps two integers.
*/

void    my_swap(int *a, int *b)
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
}
