/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-florent.guittre
** File description:
** dup_handler.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "lib/my/libmy.h"
#include "../include/my.h"

static int redirect_to_pipe(sh_infos *shell, int pipefd[2])
{
    int command_found = 0;
    pid_t a = 0;

    command_found = path_commands_checker(shell->pipe->args2[0], shell);
    if (!command_found)
        return (0);
    a = fork();
    if (a == 0) {
        dup2(pipefd[0], 0);
        execve(shell->command_path, shell->pipe->args2, shell->my_env_array);
    } else {
        waitpid(a, NULL, 0);
    }
    return (1);
}

int return_to_pipe_if_exists(sh_infos *shell, int pipefd[2])
{
    if (shell->pipe->pipe_exists) {
        close(pipefd[1]);
        if (!redirect_to_pipe(shell, pipefd))
            return (0);
    }
    return (1);
}

void init_dup(sh_infos *shell, int pipefd[2])
{
    int file_fd = 0;
    int o_flags = (shell->red->type == STDOUT) ? OUT_FLAGS : OUT_APPEND_FLAGS;

    if (shell->red->type == STDOUT || shell->red->type == STDOUT_APPEND) {
        file_fd = open(shell->red->commands_args_right[0], o_flags, 0644);
        dup2(file_fd, 1);
    }
    if (shell->red->type == STDIN) {
        file_fd = open(shell->red->commands_args_right[0], O_RDONLY);
        dup2(file_fd, 0);
    }
    if (shell->pipe->pipe_exists)
        dup2(pipefd[1], 1);
}
