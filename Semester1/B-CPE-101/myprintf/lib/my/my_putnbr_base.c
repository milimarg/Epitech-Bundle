/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** my_putnbr_base.c
*/

void my_putchar(char c);

int my_strlen(char const *str);

int my_putnbr_base(long num, char const *base, int isdisplaying)
{
    char buffer[32];
    int base_nb = my_strlen(base);
    int i = 0;
    int len = 0;

    if (num == 0) {
        if (isdisplaying)
            my_putchar('0');
        return (1);
    }
    if (num < 0)
        num = 4294967296 + num;
    for (num; num > 0; num /= base_nb) {
        buffer[i++] = base[num % base_nb];
        len++;
    }
    for (int j = i - 1; j >= 0; j--)
        if (isdisplaying)
            my_putchar(buffer[j]);
    return (len);
}
