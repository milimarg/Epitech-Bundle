/*
** EPITECH PROJECT, 2022
** CPOOL_CWorkshopLib
** File description:
** my_str_islower.c
*/

int my_str_islower(char const *str)
{
    int check = 0;

    for (int i = 0; str[i] != '\0'; i++)
        check = (str[i] >= 'a' && str[i] <= 'z') ? check + 1 : 0;
    return (check > 0);
}
