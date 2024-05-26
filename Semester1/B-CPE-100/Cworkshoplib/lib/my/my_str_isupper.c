/*
** EPITECH PROJECT, 2022
** CPOOL_CWorkshopLib
** File description:
** my_str_isupper.c
*/

int my_str_isupper(char const *str)
{
    int check = 0;

    for (int i = 0; str[i] != '\0'; i++)
        check = (str[i] >= 'A' && str[i] <= 'Z') ? check + 1 : 0;
    return (check > 0);
}
