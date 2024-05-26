/*
** EPITECH PROJECT, 2022
** my_strncmp
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int temp;
    while (s1[i] != s1[n] ) {
        if (s1[i] != s2[i]) {
            temp = s1[i] - s2[i];
            return (temp);
        }
        i++;
    }
    temp = 0;
    return (temp);
}
