/*
** EPITECH PROJECT, 2022
** CPOOL_Day10_task02
** File description:
** my_find_char.c
*/

int my_find_char(char const *str, char to_find)
{
    int c;

    c = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == to_find)
            c++;
    return (c > 0);
}
