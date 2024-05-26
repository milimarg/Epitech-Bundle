/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** good prog
*/

char *my_revstr(char *str)
{
    int i = 0;
    int m = 0;
    int t = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    i--;
    while (m <= i) {
        t = str[m];
        str[m] = str[i];
        str[i] = t;
        m++;
        i--;
    }
    return (str);
}
