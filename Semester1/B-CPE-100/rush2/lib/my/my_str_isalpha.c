/*
** EPITECH PROJECT, 2022
** my_str_isalpha
** File description:
** Verifies if string is made of alphanumeric characters.
*/

int my_str_isalpha(char const *str)
{
    int test = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= 'a' && str[i] <= 'z') ||
        (str[i] >= 'A' && str[i] <= 'Z'))) {
            test = 84;
        }
    }
    return test;
}
