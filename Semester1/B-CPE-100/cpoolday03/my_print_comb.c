/*
** EPITECH PROJECT, 2022
** CPOOL_Day03
** File description:
** my_print_comb.c
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void handling_loop_end(char a, char b, char c)
{
    for (c = '2'; c <= '9'; ++c) {
        my_putchar(a);
        my_putchar(b);
        my_putchar(c);
        if (!(a == '7' && b == '8' && c == '9')) {
            my_putchar(',');
            my_putchar(' ');
        }
    }
}

int my_print_comb(void)
{
    char a;
    char b;
    char c;

    for (a = '0'; a <= '7'; ++a) {
            b = a + 1;
        for (b = '1'; b <= '8'; ++b) {
            c = b + 1;
            handling_loop_end(a, b, c);
        }
    }
    return 0;
}

int main(void)
{
    my_print_comb();
    return 0;
}
