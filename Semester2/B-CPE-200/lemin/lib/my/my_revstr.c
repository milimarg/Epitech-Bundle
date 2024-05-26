/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** EZ
*/

int my_strlen(char const *str)
{
    int k = 0;

    while (str[k] != '\0') {
        k++;
    }
    return k;
}

char *my_revstr(char *str)
{
    int k = my_strlen(str);
    int kbis = my_strlen(str)-1;
    int i = 0;
    char j;

    for (i = 0; i < k / 2; i++) {
        j = str[kbis];
        str[kbis] = str[i];
        str[i] = j;
        kbis--;
    }
    return str;
}
