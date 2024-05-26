/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** good prog
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int temp;
    while (s1[i] != '\0' ) {
        if (s1[i] != s2[i]) {
            temp = s1[i] - s2[i];
            return (temp);
        }
        i++;
    }
    temp = 0;
    return (temp);
}
