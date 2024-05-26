/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** Reverses string.
*/

char *my_revstr(char *str)
{
    char t;
    int j = my_strlen(str) - 1;

    for (int i = 0; i < j; i++) {
        t = str[i];
        str[i] = str[j];
        str[j] = t;
        j--;
    }
    return str;
}
