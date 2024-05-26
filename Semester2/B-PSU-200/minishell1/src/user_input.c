/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** user_input
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "lib/my/libmy.h"
#include "../include/my.h"

int read_user_input(sh_infos *shell)
{
    size_t n = 0;
    ssize_t state = getline(&shell->command_buffer, &n, stdin);

    return ((state == -1) ? 442 : 0);
}

int variable_exist_checker(my_env *current, char *str)
{
    int variable_len = 0;
    char *variable = NULL;

    if (current == NULL) {
        variable_len = get_alphanum_len(str);
        variable = my_strndup(str, variable_len);
        my_error(variable, 2);
        free(variable);
        return (-2);
    }
    return (0);
}

int tilde_username_handler(int variable_len, char **temp, int *len)
{
    char *path_user = malloc(sizeof(char) * (7 + variable_len));
    struct stat st = {0};
    int is_user_found = 0;

    path_user[0] = 0;
    path_user = my_strcat(path_user, "/home/");
    path_user = my_strncat(path_user, *temp, variable_len);
    if (stat(path_user, &st) == 0) {
        is_user_found = 1;
        *temp += variable_len;
        *len += my_strlen(path_user);
    } else {
        write(2, "Unknown user: ", 14);
        write(2, *temp, variable_len);
        write(2, ".\n", 2);
    }
    free(path_user);
    return (is_user_found);
}

int check_tilde_user(char **temp, int *len, sh_infos *shell)
{
    int variable_len = get_alphanum_len(*temp);
    int is_user_found = 0;

    if (variable_len == 0) {
        is_user_found = 1;
        *len += my_strlen(shell->home_backup);
    } else
        is_user_found = tilde_username_handler(variable_len, temp, len);
    return ((is_user_found) ? 0 : -3);
}

int check_for_variable(char **temp, my_env *env_list, int *len, sh_infos *shell)
{
    int has_found_variable = 0;
    int error = 0;

    if (**temp == '$' || **temp == '~') {
        has_found_variable = 1;
        error = pre_handle_variables_in_new_str(temp, len, env_list, shell);
        if (error == -3)
            return (84);
        if (error == 84) {
            handle_error_variable_not_found(*temp);
            return (84);
        }
    } else {
        (*len)++;
        (*temp)++;
    }
    return (has_found_variable);
}
