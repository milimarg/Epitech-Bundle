/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-florent.guittre
** File description:
** special_cases_execve.c
*/

#include <stdlib.h>
#include <errno.h>
#include "../include/my.h"

void command_not_found(sh_infos *shell)
{
    set_return_code(shell, 1);
    my_error(shell->args[0], 1);
    destroy_my_str_to_word_array(shell->args);
}

int check_if_file_is_executable(char *command_name)
{
    if (errno == ENOEXEC) {
        my_error(command_name, 11);
        exit(1);
    }
    return (0);
}
