/*
** EPITECH PROJECT, 2022
** my_compare.c
** File description:
** Compare two strings
*/

int my_strlen(char const *str);

int compareword(char *w1, char *w2)
{
    for (int i = 0; i < my_strlen(w1); i++) {
        if (w1[i] != w2[i])
            return 0;
    }
    return 1;
}
