/*
** EPITECH PROJECT, 2023
** my_strlowcase.c
** File description:
** uncapitalize str
*/

char *my_strlowcase(char *str)
{
    int i = 0;
    for (; str[i]; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += ' ';
    return (str);
}
