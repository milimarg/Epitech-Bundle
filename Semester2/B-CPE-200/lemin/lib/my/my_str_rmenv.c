/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-nahim.kandari
** File description:
** my_str_compare
*/

int my_str_rmenv(char *inenv, char *src)
{
    int i = 0;
    for (; src[i] != '\0' && inenv[i] != '\0'; i++) {
        if (src[i] != inenv[i] || inenv[i] == '\0')
            return 0;
    } if (inenv[i] == '=') {
        return 1;
    }
    return 0;
}
