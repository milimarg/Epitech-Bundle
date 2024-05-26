/*
** EPITECH PROJECT, 2022
** CPOOL_CWorkshopLib
** File description:
** my_str_isnum.c
*/

int my_str_isnum(char const *str)
{
    int check = 0;

    for (int i = 0; str[i] != '\0'; i++)
        check = (str[i] >= '0' && str[i] <= '9') ? check + 1 : 0;
    return (check > 0);
}
