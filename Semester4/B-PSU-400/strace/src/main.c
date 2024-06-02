/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-strace-florent.guittre
** File description:
** main.c
*/

#include "../include/strace.h"

static void display_help(void)
{
    printf("USAGE: ./strace [-s] [-p <pid>|<command>]\n");
}

static char *error_handling(strace_t *s, char **env, char **argv)
{
    char *full_path = NULL;

    full_path = get_env_path(s->binary[0], env);
    if (!full_path && !s->flag_p) {
        dprintf(2, "%s: Can't stat '%s': No such file or directory\n", argv[0],
        s->binary[0]);
        return NULL;
    }
    return full_path;
}

static int run_strace(int argc, char **argv, strace_t *s, char **env)
{
    char *full_path = NULL;

    if (get_flags(argc, argv, s) == 84)
        return 84;
    full_path = error_handling(s, env, argv);
    if (full_path == NULL && !s->flag_p)
        return 84;
    s->abspath = full_path;
    s->envp = env;
    if (strace(s) == 84)
        return 84;
    free(full_path);
    return 0;
}

int main(int argc, char **argv, char **env)
{
    strace_t s = {.flag_p = false, .flag_s = false, .pid = -1, .binary = NULL,
        .flags = {.non = -1, .s = -1, .p = -1}, .abspath = NULL, .envp = NULL,
        .core = {.regs = {0}, .registers = {0}, .args = {0}, .status = 0,
        .buffer = NULL}, .rdx = 0
    };

    if (argc == 1) {
        dprintf(2, "strace: must have PROG [ARGS] or -p PID\n"
    "Try './strace -h' for more information.\n");
        return 84;
    }
    if (argc >= 2 && (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h"))) {
        display_help();
        return 0;
    }
    if (argc >= 2)
        if (run_strace(argc, argv, &s, env) == 84)
            return 84;
    return 0;
}
