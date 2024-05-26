/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_char_isvisiblenum
*/

int my_char_isvisiblenum(char c)
{
    int check = 0;

    if (c >= 'a' && c <= 'z')
        check++;
    if (c >= 'A' && c <= 'Z')
        check++;
    if (c >= '0' && c <= '9')
        check++;
    if (c == '_')
        check++;
    return (check != 0);
}
