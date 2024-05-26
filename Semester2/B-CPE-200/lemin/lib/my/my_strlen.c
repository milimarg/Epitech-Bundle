/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** c'est bientot ramadan
*/

int my_strlen(char const *str)
{
    int k = 0;

    while (str[k] != '\0') {
        k++;
    }
    return k;
}
