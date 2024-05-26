/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** structs
*/

#ifndef STRUCTS_H_
    #define STRUCTS_H_
typedef struct redirection {
    int type;
    char *command;
    char **commands_args_left;
    char **commands_args_right;
} redirection;
typedef struct pipe_s {
    int pipe_exists;
    int null_command;
    char *command_left;
    char **args1;
    char **args2;
} pipe_t;
typedef struct sh_infos {
    char *command_buffer;
    char *current_command;
    char **args;
    char *command_path;
    char **my_env_array;
    char *old_pwd;
    char **path_array;
    int return_code;
    int is_return_code_an_error;
    int env_number;
    int args_len;
    int has_to_update_env_array;
    char *home_backup;
    char *path_backup;
    redirection *red;
    pipe_t *pipe;
} sh_infos;
typedef struct my_env {
    char *key;
    int key_len;
    char *value;
    int value_len;
    char *str;
    int str_len;
    int is_custom;
    struct my_env *next;
} my_env;
typedef struct custom_commands {
    char *command;
    int (*func)(sh_infos *shell, my_env **env_list);
    struct custom_commands *next;
} custom_commands;
typedef enum chevron {
    STDOUT = 0,
    STDOUT_APPEND,
    STDIN,
    STDIN_APPEND,
} redirect_chevron;
#endif /* !STRUCTS_H_ */
