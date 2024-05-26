/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-florent.guittre
** File description:
** user_input_utils.c
*/

#include <sys/types.h>
#include <stdlib.h>
#include "lib/my/libmy.h"
#include "../include/my.h"

int get_new_len(char *str, my_env *env_list, sh_infos *shell)
{
    char *temp = str;
    int has_found_variable = 0;
    int len = 0;
    int status = 0;

    while (*temp != '\0') {
        status = check_for_variable(&temp, env_list, &len, shell);
        if (status == 1)
            has_found_variable = 1;
        if (status == 84)
            return (-84);
        if (status == -2 || status == -3)
            return (status);
    }
    return ((has_found_variable) ? len : -1);
}

my_env *get_value(char *str, my_env *env_list)
{
    my_env *current = NULL;
    int variable_len = get_alphanum_len(str);

    current = get_value_of_variable(env_list, str, variable_len);
    return (current);
}

int replace_tilde_user(char **str, char **new_str, int *len, sh_infos *shell)
{
    int variable_len = get_alphanum_len(*str);

    if (variable_len == 0) {
        *len += my_strlen(shell->home_backup);
        *new_str = my_strcat(*new_str, shell->home_backup);
    } else {
        *new_str = my_strcat(*new_str, "/home/");
        *new_str = my_strncat(*new_str, *str, variable_len);
        *len += (6 + variable_len);
        *str += variable_len;
    }
    return (0);
}

int pre_handle_variables_in_new_str(char **temp, int *len, my_env *env_list,
sh_infos *shell)
{
    my_env *current = NULL;

    if (**temp == '$') {
        (*temp)++;
        current = get_value(*temp, env_list);
        if (current == NULL)
            return (84);
        *temp += current->key_len;
        *len += current->value_len;
        if (variable_exist_checker(current, *temp) == -2)
            return (-2);
    } else {
        (*temp)++;
        if (check_tilde_user(temp, len, shell) == -3)
            return (-3);
    }
    return (0);
}

int handle_error_variable_not_found(char *temp)
{
    int variable_len = get_alphanum_len(temp);
    char *variable_name = my_strndup(temp, variable_len);

    my_error(variable_name, 2);
    free(variable_name);
    return (0);
}
