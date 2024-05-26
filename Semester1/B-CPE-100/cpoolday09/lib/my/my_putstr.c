/*
** EPITECH PROJECT, 2022
** CPOOL_Day04
** File description:
** my_putstr.c
*/

void my_putchar(char c);

void my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
