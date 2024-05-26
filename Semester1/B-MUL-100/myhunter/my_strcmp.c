/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** my_strcmp.c
*/

int my_strlen(char const *str);

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
