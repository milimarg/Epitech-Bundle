/*
** EPITECH PROJECT, 2022
** CPOOL_Star
** File description:
** loop_utilities.c
*/

void my_putchar(char c);

int check_extremity_conditions(int i, int j, int test, int shift);

int check_body_conditions(int j, int check_border, int shift, int length);

void check_extremity_lines(int side, int size, int i, int length)
{
    int shift;
    int test;

    shift = 0;
    test = side + (size - 2);
    for (int j = 0; j < length; j++)
        shift = check_extremity_conditions(i, j, test, shift);
}

void check_line_lines(int side, int i, int length)
{
    if (i < side || i > length - side - 1)
        my_putchar('*');
    else
        my_putchar(' ');
}

void check_body_lines(int length, int check_border)
{
    int shift;

    shift = 0;
    for (int j = 0; j < length; j++)
        shift = check_body_conditions(j, check_border, shift, length);
}
