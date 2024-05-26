/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** replace_env_variables
*/

#include <stdlib.h>
#include "lib/my/libmy.h"
#include "../include/my.h"

int set_env_variable_in_new_string(char **str, my_env *env_list, char **new_str,
int *len)
{
    my_env *current = get_value(++(*str), env_list);

    *new_str = my_strcat(*new_str, current->value);
    *str += current->key_len;
    *len += current->value_len;
    return (0);
}

char *create_new_string(char *str, my_env *env_list, int len, sh_infos *shell)
{
    char *new_str = malloc(sizeof(char) * (len + 1));

    new_str = my_char_memset(new_str, 0, len);
    len = 0;
    while (*str != '\0') {
        if (*str == '$')
            set_env_variable_in_new_string(&str, env_list, &new_str, &len);
        if (*str == '~') {
            str++;
            replace_tilde_user(&str, &new_str, &len, shell);
        }
        if (*str != '$' && *str != '~') {
            new_str[len++] = *str;
            str++;
        }
    }
    return (new_str);
}

char *replace_custom_variables(sh_infos *shell, my_env *env_list)
{
    char *str = shell->command_buffer;
    char *new_str = NULL;
    int len = 0;

    len = get_new_len(str, env_list, shell);
    if (len == -1)
        return (shell->command_buffer);
    if (len == -2 || len == -3 || len == -84)
        return (NULL);
    new_str = create_new_string(str, env_list, len, shell);
    free(shell->command_buffer);
    return (new_str);
}
