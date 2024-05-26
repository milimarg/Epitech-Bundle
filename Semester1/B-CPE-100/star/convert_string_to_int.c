/*
** EPITECH PROJECT, 2022
** CPOOL_Day03
** File description:
** convert_string_to_int.c
*/

int convert_string_to_int(char const *str)
{
    int z;
    int s;

    z = 0;
    s = 0;
    while (str[z] != '\0') {
        if (str[z] != '-')
            s = s * 10 + (str[z] - 48);
        z++;
    }
    if (str[0] == '-')
        s = s * (-1);
    return s;
}
