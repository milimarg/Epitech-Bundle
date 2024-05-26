/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** Displays strings in parameter.
*/

int    my_putstr(char const *str)
{
    int i;

    i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}
