/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** my_putstr_full.c
*/

void my_putchar(char c);

int my_char_isprintable(char c);

int my_intlen(int nb);

int my_put_nbr(int nb);

int my_putnbr_base(long num, char const *base, int isdisplaying);

void my_putstr_full_display(int nb, int isdisplaying)
{
    int nb_len = my_putnbr_base(nb, "01234567", 0);

    if (isdisplaying) {
        my_putchar('\\');
        for (int j = 0; j < (3 - nb_len); j++)
            my_put_nbr(0);
        my_putnbr_base(nb, "01234567", 1);
    }
}

int my_putstr_full(char const *str, int isdisplaying, int len)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_isprintable(str[i])) {
            my_putchar(str[i]);
            len++;
        } else {
            my_putstr_full_display(str[i], isdisplaying);
            len += 4;
        }
    }
    return (len);
}
