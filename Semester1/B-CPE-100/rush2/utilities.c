/*
** EPITECH PROJECT, 2022
** rush2
** File description:
** utilities for rush2.
*/

void my_putchar(char c);

void my_putstr(char const *str);

int my_put_nbr(int nb);

int my_str_isalpha(char const *str);

char char_tolowcase(char letter)
{
    if (letter >= 'A' && letter <= 'Z')
        letter += 32;
    return letter;
}

char check_str(char *str)
{
    int alpha;

    alpha = my_str_isalpha(str);
    return ((alpha == 1) ? str[0] : '\0');
}

int check_char(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int strlen_alpha(char *str)
{
    int count;

    count = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (check_char(str[i]))
            count++;
    return count;
}
