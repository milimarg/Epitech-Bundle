/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Displays string's lenght in parameter.
*/

int my_strlen(char const *str)
{
    int k = 0;

    while (str[k] != '\0') {
        k++;
    }
    return k;
}
