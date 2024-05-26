/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** commands_checker
*/

#include <sys/stat.h>
#include <stdlib.h>
#include "lib/my/libmy.h"
#include "../include/my.h"
#include <stdio.h>

int custom_command_checker(custom_commands *commands_list, char *command_name,
sh_infos *shell, my_env **env_list)
{
    int status = 0;

    if (command_name == NULL) {
        set_return_code(shell, 1);
        return (1);
    }
    for (; commands_list != NULL; commands_list = commands_list->next) {
        if (!my_strcmp(command_name, commands_list->command))
            status = commands_list->func(shell, env_list);
        if (status != 0)
            return (status);
    }
    return (0);
}

int path_commands_checker(char *command_name, sh_infos *shell)
{
    char *shell_path = shell->path_backup;
    int path_len = 0;
    struct stat st = {0};

    shell->command_path = NULL;
    shell->path_array = my_str_to_word_array_sep(shell_path, ':');
    for (int i = 0; shell->path_array[i] != NULL; i++) {
        path_len = my_strlen(shell->path_array[i]);
        shell->command_path =
        malloc(sizeof(char) * (path_len + my_strlen(command_name) + 2));
        shell->command_path[0] = 0;
        shell->command_path = my_strcat(shell->command_path,
        shell->path_array[i]);
        shell->command_path = my_strcat(shell->command_path, "/");
        shell->command_path = my_strcat(shell->command_path, command_name);
        if (stat(shell->command_path, &st) == 0 && S_ISREG(st.st_mode))
            return (1);
        free(shell->command_path);
    }
    return (0);
}

int other_command_checker(char *command_name)
{
    struct stat st = {0};

    return ((stat(command_name, &st) == 0 && S_ISREG(st.st_mode)));
}
