/*
** EPITECH PROJECT, 2022
** CPOOL_Personal
** File description:
** my_char_isalpha.c
*/

int my_char_isalpha(char c)
{
    int check;
    int o;

    check = 0;
    if (c >= 48 && c <= 57)
        check++;
    if (c >= 97 && c <= 122)
        check++;
    if (c >= 65 && c <= 90)
        check++;
    o = check >= 1;
    return o;
}
