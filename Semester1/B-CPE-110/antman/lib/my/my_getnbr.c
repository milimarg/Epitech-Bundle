/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** Vraiment pas mal ce programme
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int stop = 0;
    int result = 0;
    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57) {
            result = result * 10 + str[i] - 48;
            stop++;
        } if (str[i] < 48 && str[i] > 57 && stop > 0)
            break;
        i++;
    }
    return (result);
}
