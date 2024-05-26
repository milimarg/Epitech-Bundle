/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-nahim.kandari
** File description:
** my_str_compare
*/

int my_str_compare(char *a, char *b)
{
    int i;
    for (i = 0; a[i] != '\0' && b[i] != '\0'; i++) {
        if (a[i] != b[i] || a[i] == '\0' || b[i] == '\0')
            return 0;
    }
    if ((a[i] == '\0' && b[i] != '\0') || (b[i] == '\0' && a[i] != '\0'))
        return 0;
    return 1;
}
