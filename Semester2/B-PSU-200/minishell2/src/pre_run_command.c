/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-florent.guittre
** File description:
** pre_run_command.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "lib/my/libmy.h"
#include "../include/my.h"

int parse_redirectors(char *command_string, sh_infos *shell)
{
    char *used_command = NULL;
    int skip = 0;

    check_chevrons(command_string, shell);
    if (check_pipes(command_string, shell))
        return (1);
    if (shell->red->type != -1) {
        handle_chevrons(command_string, shell->red);
        used_command = shell->red->command;
    } else if (shell->pipe->pipe_exists) {
        skip = handle_pipes(command_string, shell->pipe);
        used_command = shell->pipe->command_left;
    } else
        used_command = command_string;
    if (skip)
        return (1);
    shell->args = my_str_to_word_array(used_command);
    shell->args_len = my_array_len(shell->args);
    return (0);
}

int check_for_file_permission(char *command_name, sh_infos *shell)
{
    struct stat st = {0};
    int stat_code = stat(command_name, &st);

    if ((stat_code == 0 && access(command_name, X_OK) != 0) ||
        (stat_code == 0 && S_ISDIR(st.st_mode))) {
        my_error(command_name, 8);
        set_return_code(shell, 1);
        return (1);
    }
    return (0);
}
