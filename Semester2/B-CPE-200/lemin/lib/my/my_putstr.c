/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** dans 1h j'ai rdv avec le coatch
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int k = 0;

    while (str[k] != '\0') {
        my_putchar(str[k]);
        k++;
    }
    return 0;
}
