/*
** EPITECH PROJECT, 2022
** CPOOL_Star
** File description:
** star.c
*/

void my_putchar(char c);

void my_putstr(char const *str);

int print_star_1(void);

void check_extremity_lines(int side, int size, int i, int length);

void check_line_lines(int i, int side, int length);

void check_body_lines(int length, int check_border);

void draw_top(int side, int size, int length)
{
    for (int i = 0; i < size; i++) {
        check_extremity_lines(side, size, i, length);
        my_putchar('\n');
    }
}

void draw_line(int side, int length)
{
    for (int i = 0; i < length; i++)
        check_line_lines(side, i, length);
    my_putchar('\n');
}

void draw_body(int size, int length)
{
    int check_border;

    check_border = 0;
    for (int i = 0; i < ((size - 1) * 2) + 1; i++) {
        check_body_lines(length, check_border);
        if (i >= 0 && i < size - 1)
            check_border++;
        else
            check_border--;
        my_putchar('\n');
    }
}

void draw_bottom(int side, int size, int length)
{
    for (int i = size - 1; i >= 0; i--) {
        check_extremity_lines(side, size, i, length);
        my_putchar('\n');
    }
}

void star(unsigned int size)
{
    int side;
    int middle;
    int length;

    side = (size * 2) + 1;
    middle = 1 + (size - 2) * 2;
    length = (side * 2) + middle;
    if (size == 1)
        print_star_1();
    if (size > 1 && size <= 2147483647) {
        draw_top(side, size, length);
        draw_line(side, length);
        draw_body(size, length);
        draw_line(side, length);
        draw_bottom(side, size, length);
    }
}
