/*
** EPITECH PROJECT, 2022
** getnb.c
** File description:
** cestpasfaire
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = 1;
    long long result = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') {
            neg *= (-1);
        }
        i++;
    }
    for (int j = i; str[j] >= '0' && str[j] <= '9'; j++) {
        result *= 10;
        result += (str[j] - '0') * neg;
    }
    if (result > -2147483647 && result < 2147483648) {
        (int)result;
        return result;
    } else
        return 0;
}
