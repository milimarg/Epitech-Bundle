/*
** EPITECH PROJECT, 2022
** CPOOL_Day04
** File description:
** my_evil_str.c
*/

int my_strlen(char const *str);

char *my_evil_str(char *str)
{
    int const LENGTH = my_strlen(str);
    char z;
    int j;

    for (j = 0; j < LENGTH / 2; j++) {
        z = str[j];
        str[j] = str[LENGTH - j - 1];
        str[LENGTH - j - 1] = z;
    }
    return str;
}

