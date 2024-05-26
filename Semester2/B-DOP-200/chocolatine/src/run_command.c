/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-florent.guittre
** File description:
** run_command.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
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

int run_execve(int status, sh_infos *shell, char *command_string)
{
    pid_t forked_pid = 0;
    int pid_status = 0;
    char *command_name = (status == -1) ? shell->command_path : shell->args[0];

    if (check_for_file_permission(command_name, shell))
        return (1);
    if (status < 0) {
        forked_pid = fork();
        if (forked_pid == 0) {
            execve(command_name, shell->args, shell->my_env_array);
            check_if_file_is_executable(command_name);
        } else {
            waitpid(forked_pid, &pid_status, 0);
            pid_signal_handler(shell, pid_status);
        }
    }
    if (status == -1)
        free(shell->command_path);
    free(command_string);
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
    shell->args = my_str_to_word_array(command_string);
    shell->args_len = my_array_len(shell->args);
    command_status = commands_checker(shell, commands_list, env_list);
    if (command_status == 1) {
        destroy_my_str_to_word_array(shell->args);
        return (command_status);
    }
    if (run_execve(command_status, shell, command_string))
        return (1);
    if (command_status != 0)
        return (command_status);
    command_not_found(shell);
    return (0);
}
