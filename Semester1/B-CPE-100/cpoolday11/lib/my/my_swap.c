/*
** EPITECH PROJECT, 2022
** CPOOL_Day04
** File description:
** my_swap.c
*/

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
