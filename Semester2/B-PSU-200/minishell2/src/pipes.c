/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-florent.guittre
** File description:
** pipes.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib/my/libmy.h"
#include "../include/my.h"

int check_pipes(const char *command_string, sh_infos *shell)
{
    for (int i = 0; command_string[i] != '\0'; i++) {
        if (command_string[i] == '|' && command_string[i + 1] != '\n') {
            shell->pipe->pipe_exists = 1;
            return (0);
        }
        if (command_string[i] == '|' && command_string[i + 1] == '\n') {
            set_return_code(shell, 1);
            write(2, "Invalid null command.\n", 22);
            return (1);
        }
    }
    shell->pipe->pipe_exists = 0;
    return ((shell->red->type != -1 && shell->pipe->pipe_exists));
}

int handle_pipes(char *command_string, pipe_t *pipe)
{
    int i = 0;

    for (; command_string[i] != '|'; i++);
    pipe->command_left = malloc(sizeof(char) * (i + 1));
    pipe->command_left[i] = 0;
    pipe->command_left = my_strncpy(pipe->command_left, command_string, i);

    pipe->args1 = my_str_to_word_array(pipe->command_left);
    i++;
    pipe->args2 = my_str_to_word_array(&command_string[i]);
    for (int j = 0; pipe->args2[0][j] != '\0'; j++) {
        if (pipe->args2[0][j] == '.') {
            return (1);
        }
    }
    return (0);
}
