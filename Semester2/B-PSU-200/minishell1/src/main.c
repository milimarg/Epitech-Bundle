/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-florent.guittre
** File description:
** main.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "lib/my/libmy.h"
#include "../include/my.h"

static int shell_loop(sh_infos *shell, custom_commands *commands_list,
my_env **env_list)
{
    int status = 0;

    signal_handler();
    if (isatty(0))
        display_prompt(shell);
    if (read_user_input(shell) == 442) {
        free(shell->command_buffer);
        if (isatty(0))
            write(1, "exit\n", 5);
        return (442);
    }
    if (check_eligibility_of_string(shell, env_list))
        status = run_command(commands_list, shell, env_list);
    else
        free(shell->command_buffer);
    return (status);
}

static int init_shell(sh_infos *shell, custom_commands **commands_list,
char **env, my_env **env_list)
{
    my_env *temp_home = NULL;
    my_env *temp_path = NULL;

    set_shell_variables(shell);
    shell->old_pwd = malloc(sizeof(char) * 1000);
    shell->old_pwd = getcwd(shell->old_pwd, 1000);
    fill_env_list(env_list, env, shell);
    init_custom_commands(commands_list);
    temp_home = get_value_of_variable(*env_list, "HOME", 4);
    temp_path = get_value_of_variable(*env_list, "PATH", 4);
    shell->home_backup = (temp_home != NULL)
    ? my_strdup(temp_home->value) : my_strdup("/home");
    shell->path_backup = (temp_path != NULL)
    ? my_strdup(temp_path->value) : my_strdup("/bin");
    return (0);
}

static int shell_handler(char **env)
{
    sh_infos shell = {0};
    custom_commands *commands_list = NULL;
    my_env *env_list = NULL;

    if (check_if_malloc_is_null())
        return (84);
    init_shell(&shell, &commands_list, env, &env_list);
    while (shell_loop(&shell, commands_list, &env_list) != 442);
    free(shell.old_pwd);
    free(shell.my_env_array);
    destroy_env_list(env_list);
    destroy_custom_commands_list(commands_list);
    free(shell.home_backup);
    free(shell.path_backup);
    return (shell.return_code);
}

int main(int argc, char **argv, char **env)
{
    struct stat st = {0};

    if (argc == 1) {
        return (shell_handler(env));
    } else if (stat(argv[1], &st) != 0) {
        my_error(argv[1], 0);
        return (84);
    }
    return (0);
}
