/*
** EPITECH PROJECT, 2022
** CPOOL_Personal
** File description:
** my_char_isalpha.c
*/

int my_char_isalpha(char const c)
{
    int check;
    int o;

    check = 0;
    if (c > 0 && c < 9)
        check++;
    if (c > 'a' && c < 'z')
        check++;
    if (c > 'A' && c < 'Z')
        check++;
    o = check >= 1;
    return o;
}
