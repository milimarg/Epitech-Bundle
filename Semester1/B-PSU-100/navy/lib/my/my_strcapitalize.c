/*
** EPITECH PROJECT, 2023
** my_strcapitalize.c
** File description:
** capitalize str
*/

char my_is_down_case(char c)
{
    if (c >= 'a' && c <= 'z')
        return (' ');
    return (0);
}

char my_is_up_case(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (' ');
    return (0);
}

int my_strcapitalize_checker(char *str, int *i, int *startword)
{
    if (*startword) {
        str[*i] -= my_is_down_case(str[*i]);
        *startword = 0;
    } else if (str[*i] == ' ' || str[*i] == '-' || str[*i] == '+') {
        *startword = 1;
    } else {
        *startword = 0;
        str[*i] += my_is_up_case(str[*i]);
    }
    return (0);
}

char *my_strcapitalize(char *str)
{
    int i;
    int startword = 1;

    for (i = 0; str[i]; i++)
        my_strcapitalize_checker(str, &i, &startword);
    return (str);
}
