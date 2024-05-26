/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** env
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib/my/libmy.h"
#include "../include/my.h"

int custom_env(sh_infos *shell, my_env **env_list)
{
    my_env *temp = *env_list;

    if (shell->args[1] != NULL) {
        write(2, "env: ‘", 8);
        write(2, shell->args[1], my_strlen(shell->args[1]));
        write(2, "’: No such file or directory\n", 31);
        set_return_code(shell, 127);
        return (84);
    }
    while (temp != NULL) {
        write(1, temp->str, temp->str_len);
        write(1, "\n", 1);
        temp = temp->next;
    }
    return (1);
}

static int handle_home_path_backup(sh_infos *shell, char *key, char *value)
{
    if (!my_strcmp(key, "HOME")) {
        free(shell->home_backup);
        shell->home_backup = my_strdup(value);
    }
    if (!my_strcmp(key, "PATH")) {
        free(shell->path_backup);
        shell->path_backup = my_strdup(value);
    }
    return (0);
}

int custom_setenv(sh_infos *shell, my_env **env_list)
{
    char *key = NULL;
    char *value = NULL;

    if (shell->args_len == 1) {
        custom_env(shell, env_list);
        set_return_code(shell, 0);
        return (1);
    }
    if (shell->args_len > 3) {
        my_error("setenv", 5);
        set_return_code(shell, 1);
        return (1);
    }
    key = shell->args[1];
    value = (shell->args_len == 2) ? "" : shell->args[2];
    env_list_manager(shell, env_list, key, value);
    handle_home_path_backup(shell, key, value);
    return (1);
}

static int check_for_key_unsetenv(my_env *temp, sh_infos *shell, int i,
my_env **env_list)
{
    if (!my_strcmp(temp->key, shell->args[i]))
        delete_node_in_env(env_list, temp, shell);
    return (0);
}

int custom_unsetenv(sh_infos *shell, my_env **env_list)
{
    if (shell->args_len == 1) {
        my_error("unsetenv", 6);
        set_return_code(shell, 1);
        return (1);
    }
    for (int i = 1; i < shell->args_len; i++) {
        for (my_env *temp = *env_list; temp != NULL; temp = temp->next) {
            check_for_key_unsetenv(temp, shell, i, env_list);
        }
    }
    return (1);
}
