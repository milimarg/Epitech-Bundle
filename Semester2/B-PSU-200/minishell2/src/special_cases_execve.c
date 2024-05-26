/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-florent.guittre
** File description:
** special_cases_execve.c
*/

#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include "../include/my.h"

void command_not_found(sh_infos *shell, int left_or_right)
{
    set_return_code(shell, 1);
    if (!left_or_right)
        my_error(shell->args[0], 1);
    else
        my_error(shell->pipe->args2[0], 1);
    destroy_my_str_to_word_array(shell->args);
}

int check_if_file_is_executable(char *command_name, sh_infos *shell)
{
    execve(command_name, shell->args, shell->my_env_array);
    if (errno == ENOEXEC) {
        my_error(command_name, 11);
        exit(1);
    }
    return (0);
}
