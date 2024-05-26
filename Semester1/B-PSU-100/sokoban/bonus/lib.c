/*
** EPITECH PROJECT, 2022
** bonus
** File description:
** lib
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

int my_strcmp(const char *s1, const char *s2)
{
    int s1_len = my_strlen(s1);
    int s2_len = my_strlen(s2);
    int o = 0;

    if (s1_len != s2_len)
        return (1);
    for (int i = 0; i < s1_len; i++)
        if (s1[i] != s2[i])
            o = 1;
    return (o);
}

char *my_strdup(char const *src)
{
    int len = 0;
    char *dest = "";
    int i = 0;

    len = my_strlen(src);
    dest = malloc(sizeof(char) * (len + 1));
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = 1;
    int nb = 0;

    while (str[i] == '-' || str[i] == '+') {
        neg *= (str[i] == '-') ? (-1) : 1;
        i++;
    }
    for (i; str[i] >= '0' && str[i] <= '9'; i++) {
        nb *= 10;
        nb += (str[i] - '0');
    }
    nb *= neg;
    return nb;
}
