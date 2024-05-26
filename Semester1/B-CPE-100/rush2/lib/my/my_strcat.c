/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** Glues two strings.
*/

char *my_strcat(char *dest, char const *src)
{
    int source_len = my_strlen(src);
    int destin_len = my_strlen(dest);

    for (int i = 0; i < source_len; i++) {
        dest[i + destin_len] = src[i];
    }
    dest[source_len + destin_len] = '\0';
    return dest;
}
