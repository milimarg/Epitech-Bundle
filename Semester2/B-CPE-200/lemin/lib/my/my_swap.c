/*
** EPITECH PROJECT, 2022
** my_swap.c
** File description:
** askip c ez
*/

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
