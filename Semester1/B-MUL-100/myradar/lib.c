/*
** EPITECH PROJECT, 2022
** B-MUL-100-STG-1-1-myradar-florent.guittre
** File description:
** lib
*/

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
