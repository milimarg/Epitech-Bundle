/*
** EPITECH PROJECT, 2022
** my_isneg
** File description:
** Prints if the input number is positive or negative.
*/

int    my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    my_putchar('\n');
    return 0;
}
