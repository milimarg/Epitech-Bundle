/*
** EPITECH PROJECT, 2022
** strncat
** File description:
** JULIEN M EMPECHE DE TRAVAIL
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int n)
{
    int i;
    int j = my_strlen(dest);

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[j] = src[i];
        j++;
    }
    if (src[i] == '\0') {
        dest[j] = '\0';
    }
    return dest;
}
