/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-strace-florent.guittre
** File description:
** env.c
*/

#include "../include/strace.h"

static char *parse_env(char **envp)
{
    char *path = NULL;

    for (int i = 0; envp[i] != NULL; i++)
        if (!strncmp(envp[i], "PATH=", 5)) {
            path = envp[i] + 5;
            break;
        }
    return path;
}

static char *concat_path(char *path_env, char *binary_name)
{
    int path_len = strlen(path_env);
    char *abs_path = malloc(sizeof(char) * (path_len + strlen(binary_name) +
    2));

    abs_path[0] = 0;
    abs_path = strcat(abs_path, path_env);
    abs_path = strcat(abs_path, "/");
    return strcat(abs_path, binary_name);
}

char *get_env_path(char *binary_name, char **envp)
{
    char *shell_path = parse_env(envp);
    struct stat st = {0};
    char *abs_path = NULL;
    char *path_env = NULL;

    if (!shell_path || !binary_name)
        return NULL;
    path_env = strtok(shell_path, ":");
    for (; path_env != NULL; path_env = strtok(NULL, ":")) {
        abs_path = concat_path(path_env, binary_name);
        if (!stat(abs_path, &st) && S_ISREG(st.st_mode))
            return abs_path;
        free(abs_path);
    }
    if (!stat(binary_name, &st) && S_ISREG(st.st_mode))
        return strdup(binary_name);
    return NULL;
}
