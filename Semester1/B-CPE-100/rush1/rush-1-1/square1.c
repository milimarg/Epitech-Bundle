/*
** EPITECH PROJECT, 2022
** CPOOL_Rush1
** File description:
** square1.c
*/

void my_putchar(char c);

void my_putstr(const char *str);

void print_square_char(int a, int b, int x, int y)
{
    if ((a == 0 || a == y - 1) && (b == 0 || b == x - 1))
        my_putchar('o');
    if ((a > 0 && a < y - 1) && (b == 0 || b == x - 1))
        my_putchar('|');
    if ((a == 0 || a == y - 1) && (b > 0 && b < x - 1))
        my_putchar('-');
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

void rush(int x, int y)
{
    if ((x <= 0 || y <= 0) || (x > 2147483647 || y > 2147483647))
        my_putstr("Invalid size\n");
    else {
        looping_square(x, y);
    }
}

int main(void)
{
    rush(2147483647, 2147483647);
    return 0;
}
