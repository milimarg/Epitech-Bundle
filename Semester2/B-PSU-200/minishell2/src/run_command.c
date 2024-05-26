/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-florent.guittre
** File description:
** run_command.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "lib/my/libmy.h"
#include "../include/my.h"

int commands_checker(sh_infos *shell, custom_commands *commands_list,
my_env **env_list)
{
    int status = 0;
    char *command_name = shell->args[0];

    status = custom_command_checker(commands_list, command_name, shell,
    env_list);
    if (status != 0)
        return (1);
    status = path_commands_checker(command_name, shell);
    destroy_my_str_to_word_array(shell->path_array);
    if (status != 0)
        return (-1);
    status = other_command_checker(command_name);
    if (status != 0)
        return (-2);
    return (0);
}

int run_command_in_fork(sh_infos *shell, char *command_name)
{
    pid_t forked_pid = 0;
    int pid_status = 0;
    int pipefd[2] = {0};

    if (shell->pipe->pipe_exists)
        pipe(pipefd);
    forked_pid = fork();
    if (forked_pid == 0) {
        init_dup(shell, pipefd);
        check_if_file_is_executable(command_name, shell);
    } else {
        if (!return_to_pipe_if_exists(shell, pipefd)) {
            return (0);
        }
        if (!shell->pipe->pipe_exists)
            waitpid(forked_pid, &pid_status, 0);
        pid_signal_handler(shell, pid_status);
    }
    return (1);
}

static int run_execve(int status, sh_infos *shell)
{
    char *command_name = (status == -1) ? shell->command_path : shell->args[0];

    if (check_for_file_permission(command_name, shell))
        return (1);
    if (status < 0) {
        if (!run_command_in_fork(shell, command_name)) {
            command_not_found(shell, 1);
            return (1);
        }
    }
    if (status == -1)
        free(shell->command_path);
    return (0);
}

int run_command(custom_commands *commands_list, sh_infos *shell,
my_env **env_list)
{
    char *command_string = replace_custom_variables(shell, *env_list);
    int command_status = 0;

    if (command_string == NULL) {
        set_return_code(shell, 1);
        return (1);
    }
    if (parse_redirectors(command_string, shell))
        return (1);
    command_status = commands_checker(shell, commands_list, env_list);
    if (command_status == 1) {
        destroy_my_str_to_word_array(shell->args);
        return (command_status);
    }
    if (run_execve(command_status, shell))
        return (1);
    if (command_status != 0)
        return (command_status);
    command_not_found(shell, 0);
    return (0);
}

int run_multiple_commands(sh_infos *shell, my_env **env_list,
custom_commands *commands_list)
{
    int status = 0;
    char **commands = my_str_to_word_array_sep(shell->command_buffer, ';');

    free(shell->command_buffer);
    for (int i = 0; commands[i] != NULL; i++) {
        shell->current_command = commands[i];
        if (check_eligibility_of_string(shell, env_list))
            status = run_command(commands_list, shell, env_list);
    }
    destroy_my_str_to_word_array(commands);
    return (status);
}
