/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** env_array
*/

#include <stdlib.h>
#include "lib/my/libmy.h"
#include "../include/my.h"

static int build_env_array(sh_infos *shell, my_env *env_list)
{
    my_env *temp = env_list;

    shell->my_env_array = malloc(sizeof(char *) * (shell->env_number + 1));
    for (int i = 0; i < shell->env_number; i++) {
        if (temp == NULL)
            return (1);
        shell->my_env_array[i] = temp->str;
        temp = temp->next;
    }
    shell->my_env_array[shell->env_number] = NULL;
    return (0);
}

int env_array_manager(sh_infos *shell, my_env **env_list)
{
    shell->has_to_update_env_array = 0;
    free(shell->my_env_array);
    build_env_array(shell, *env_list);
    return (0);
}
