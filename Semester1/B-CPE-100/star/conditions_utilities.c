/*
** EPITECH PROJECT, 2022
** CPOOL_Star
** File description:
** conditions_utilities.c
*/

void my_putchar(char c);

int check_extremity_conditions(int i, int j, int test, int shift)
{
    if (j - i == test || j + i == test) {
        my_putchar('*');
        shift++;
    } else {
        if (shift == 0 || (shift == 1 && i != 0))
            my_putchar(' ');
    }
    return shift;
}

int check_body_conditions(int j, int check_border, int shift, int length)
{
    if (j - 1 == check_border || length - j - 2 == check_border) {
        my_putchar('*');
        shift++;
    } else {
        if (shift == 0 || shift == 1)
            my_putchar(' ');
    }
    return shift;
}
