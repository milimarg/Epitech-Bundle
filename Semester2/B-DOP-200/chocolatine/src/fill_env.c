/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** fill_env
*/

#include <stdlib.h>
#include "lib/my/libmy.h"
#include "../include/my.h"

static int save_key_and_value(my_env *element, char *env)
{
    char *env_value = env;

    element->str = env;
    for (; *env_value != '='; env_value++);
    element->key_len = env_value - env;
    element->key = my_strndup(env, element->key_len);
    for (env_value++; *env_value; env_value++);
    element->value_len = (env_value - env) - element->key_len - 1;
    element->value = my_strndup(env + element->key_len + 1, element->value_len);
    element->str_len = element->key_len + element->value_len + 1;
    return (0);
}

static int add_element_to_env_list(my_env **env_list, my_env *element)
{
    my_env *temp = NULL;

    if (*env_list == NULL) {
        *env_list = element;
    } else {
        temp = *env_list;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = element;
    }
    return (0);
}

int fill_env_list(my_env **env_list, char **env, sh_infos *shell)
{
    my_env *element = NULL;

    for (int i = 0; env[i] != NULL; i++) {
        shell->env_number++;
        element = malloc(sizeof(my_env));
        save_key_and_value(element, env[i]);
        element->is_custom = 0;
        element->next = NULL;
        add_element_to_env_list(env_list, element);
    }
    return (0);
}

int free_node_in_env(my_env *node_to_free)
{
    free(node_to_free->key);
    free(node_to_free->value);
    if (node_to_free->is_custom)
        free(node_to_free->str);
    free(node_to_free);
    return (0);
}

int destroy_env_list(my_env *env_list)
{
    my_env *temp = NULL;

    while (env_list != NULL) {
        temp = env_list;
        env_list = env_list->next;
        free_node_in_env(temp);
    }
    return (0);
}
