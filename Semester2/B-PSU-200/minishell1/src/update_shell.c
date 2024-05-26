/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** update_shell
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "lib/my/libmy.h"
#include "../include/my.h"

my_env *get_value_of_variable(my_env *env_list, char *variable_name,
int variable_len)
{
    for (; env_list != NULL; env_list = env_list->next) {
        if (!my_strncmp(env_list->key, variable_name, variable_len)
        && variable_len == env_list->key_len) {
            return (env_list);
        }
    }
    return (NULL);
}

int check_eligibility_of_string(sh_infos *shell, my_env **env_list)
{
    if (shell->has_to_update_env_array)
        env_array_manager(shell, env_list);
    return (check_if_buffer_is_alpha(shell));
}

int set_shell_variables(sh_infos *shell)
{
    shell->command_buffer = NULL;
    shell->return_code = 0;
    shell->is_return_code_an_error = 0;
    shell->env_number = 0;
    shell->command_path = NULL;
    shell->my_env_array = NULL;
    shell->has_to_update_env_array = 1;
    return (0);
}
