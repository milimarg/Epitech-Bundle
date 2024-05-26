/*
** EPITECH PROJECT, 2022
** strcat
** File description:
** Y a pas le goblin aujourdhui
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i;
    int j = my_strlen(dest);

    for (i = 0; src[i] != '\0'; i++) {
        dest[j] = src[i];
        j++;
    }
    dest[j] = '\0';
    return dest;
}
