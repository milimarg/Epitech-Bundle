/*
** EPITECH PROJECT, 2022
** CPOOL_CWorkshopLib
** File description:
** my_isneg.c
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    return 0;
}
