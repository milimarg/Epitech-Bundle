/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** node_utils_env
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../lib/my/libmy.h"
#include "../../include/my.h"

int edit_node_in_env(my_env *node_to_edit, char *key, char *value)
{
    node_to_edit->is_custom = 1;
    node_to_edit->key_len = my_strlen(key);
    node_to_edit->key = my_strndup(key, node_to_edit->key_len);
    node_to_edit->value_len = my_strlen(value);
    node_to_edit->value = my_strndup(value, node_to_edit->value_len);
    node_to_edit->str_len = node_to_edit->key_len + node_to_edit->value_len + 1;
    node_to_edit->str = malloc(sizeof(char) * (node_to_edit->str_len + 1));
    node_to_edit->str[0] = 0;
    node_to_edit->str = my_strcat(node_to_edit->str, node_to_edit->key);
    node_to_edit->str = my_strcat(node_to_edit->str, "=");
    node_to_edit->str = my_strcat(node_to_edit->str, node_to_edit->value);
    return (0);
}

int add_node_to_env_list(my_env **env_list, char *key, char *value)
{
    my_env *element = malloc(sizeof(my_env));
    my_env *temp = *env_list;

    edit_node_in_env(element, key, value);
    element->next = NULL;
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

int check_if_node_exist(my_env **env_list, char *key, char *value)
{
    for (my_env *temp = *env_list; temp != NULL; temp = temp->next) {
        if (!my_strcmp(key, temp->key)) {
            free(temp->key);
            free(temp->value);
            free((temp->is_custom) ? temp->str : NULL);
            temp->is_custom = 1;
            edit_node_in_env(temp, key, value);
            return (1);
        }
    }
    return (0);
}

int delete_node_in_env(my_env **head, my_env *node_to_delete, sh_infos *shell)
{
    my_env *temp = *head;

    if (*head == NULL || node_to_delete == NULL)
        return (1);
    if (node_to_delete == *head) {
        *head = (*head)->next;
    } else {
        while (temp->next != node_to_delete)
            temp = temp->next;
        temp->next = temp->next->next;
    }
    free_node_in_env(node_to_delete);
    shell->env_number--;
    shell->has_to_update_env_array = 1;
    return (0);
}

int env_list_manager(sh_infos *shell, my_env **env_list, char *key, char *value)
{
    if (!char_isalpha(key[0])) {
        my_error("setenv", 9);
        set_return_code(shell, 1);
        return (1);
    }
    for (int i = 0; key[i] != '\0'; i++) {
        if (!my_char_isvisiblenum(key[i])) {
            my_error("setenv", 7);
            set_return_code(shell, 1);
            return (1);
        }
    }
    shell->env_number++;
    if (!check_if_node_exist(env_list, key, value))
        add_node_to_env_list(env_list, key, value);
    set_return_code(shell, 0);
    shell->has_to_update_env_array = 1;
    return (0);
}
