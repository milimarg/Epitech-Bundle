/*
** EPITECH PROJECT, 2022
** CPOOL_CWorkshopLib
** File description:
** my_str_isalpha.c
*/

int my_char_isalpha(char c);

int my_str_isalpha(char const *str)
{
    int check = 0;

    for (int i = 0; str[i] != '\0'; i++)
        check = (my_char_isalpha(str[i])) ? check + 1 : 0;
    return (check > 0);
}
