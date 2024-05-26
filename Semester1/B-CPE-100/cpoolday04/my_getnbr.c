/*
** EPITECH PROJECT, 2022
** CPOOL_Day04
** File description:
** my_getnbr.c
*/

#include <stdio.h>
#include <string.h>

void my_putchar(char c);

int my_strlen(char const *str);

int convert_to_int(char const *str)
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

int my_getnbr(char const *str)
{
    int const LENGTH = strlen(str);
    int i;
    int j;
    int final;
    char c;
    char t[LENGTH];

    i = 0;
    j = 0;
    c = str[i];
    while (c != '\0') {
        if (c >= 48 && c <= 57) {
            if (str[i - 1] == '-') {
                t[j] = '-';
                j++;
            }
            t[j] = c;
            j++;
        }
        i++;
        c = str[i];
    }
    final = convert_to_int(t);
    printf("%d", final);
    return 0;
}

int main(void)
{
    my_getnbr(strdup(""));
    return 0;
}
