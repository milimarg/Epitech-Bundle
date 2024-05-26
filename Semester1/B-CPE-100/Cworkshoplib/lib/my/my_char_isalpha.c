/*
** EPITECH PROJECT, 2022
** CPOOL_CWorkshopLib
** File description:
** my_char_isalpha.c
*/

int my_char_isalpha(char const c)
{
    int check = 0;

    if (c > 'a' && c < 'z')
        check++;
    if (c > 'A' && c < 'Z')
        check++;
    return (check >= 1);
}
