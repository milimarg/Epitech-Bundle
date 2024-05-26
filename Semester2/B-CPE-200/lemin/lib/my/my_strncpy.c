/*
** EPITECH PROJECT, 2022
** AOOOAOAOAOHHHH
** File description:
** Qui est le meilleur AER
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    if (src[i] == '\0') {
        dest[i] = '\0';
    }
    return dest;
}
