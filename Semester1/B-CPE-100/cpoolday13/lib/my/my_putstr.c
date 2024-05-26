/*
** EPITECH PROJECT, 2022
** CPOOL_CWorkshopLib
** File description:
** my_putstr.c
*/

void my_putchar(char c);

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}
