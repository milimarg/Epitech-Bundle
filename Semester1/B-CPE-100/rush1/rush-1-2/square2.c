/*
** EPITECH PROJECT, 2022
** CPOOL_Rush1
** File description:
** square2.c
*/

void my_putchar(char c);

void my_putstr(const char *str);

void print_square_char(int a, int b, int x, int y)
{
    if ((a == 0 && b == 0) || (a == y - 1 && b == x - 1))
        my_putchar('/');
    if ((a == 0 && b == x - 1) || (a == y - 1 && b == 0))
        my_putchar(92);
    if ((a > 0 && a < y - 1) && (b == 0 || b == x - 1))
        my_putchar('*');
    if ((a == 0 || a == y - 1) && (b > 0 && b < x - 1))
        my_putchar('*');
    if ((a > 0 && a < y - 1) && (b > 0 && b < x - 1))
        my_putchar(' ');
}

void looping_square(int x, int y)
{
    int a;
    int b;

    for (a = 0; a < y; a++) {
        for (b = 0; b < x; b++) {
            print_square_char(a, b, x, y);
        }
        my_putchar('\n');
    }
}

void put_one_case(int x, int y)
{
    int f;

    f = (x > 1 && y == 1) ? x : y;
    for (int i = 0; i < f; i++) {
        my_putchar('*');
        if (y > x)
            my_putchar('\n');
    }
    if (x >= y)
        my_putchar('\n');
}

void rush(int x, int y)
{
    if ((x <= 0 || y <= 0) || (x > 2147483647 || y > 2147483647))
        my_putstr("Invalid size\n");
    if (x > 1 && y > 1)
        looping_square(x, y);
    if ((x == 1 && y >= 1) || (x >= 1 && y == 1))
        put_one_case(x, y);

}
