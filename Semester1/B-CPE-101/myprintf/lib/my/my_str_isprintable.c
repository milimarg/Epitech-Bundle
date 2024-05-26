/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** my_str_isprintable.c
*/

int my_str_isprintable(char const *str)
{
    int check = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        check = ((str[i] >= 0 && str[i] <= 32) || str[i] == 127)
        ? check + 1 : 0;
    }
    return (check > 0);
}
