/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-strace-florent.guittre
** File description:
** parsing.c
*/

#include "../include/strace.h"

static int get_pid(const char *pid_value)
{
    int number = 0;

    if (!pid_value) {
        dprintf(2, "strace: option requires an argument -- 'p'\n"
    "Try './strace -h' for more information.\n");
        return 0;
    }
    number = atoi(pid_value);
    if (number == 0) {
        dprintf(2, "strace: Invalid process id: '%d'\n", number);
        return -1;
    }
    return number;
}

static void error_handling(int argc, char **argv, flags_t *flags)
{
    for (int rdx = 1; rdx < argc; rdx++) {
        if (argv[rdx][0] != '-') {
            flags->non = rdx;
            break;
        }
    }
    for (int rdx = 1; rdx < argc; rdx++) {
        if (!strcmp(argv[rdx], "-s")) {
            flags->s = rdx;
            break;
        }
    }
    for (int rdx = 1; rdx < argc; rdx++) {
        if (!strcmp(argv[rdx], "-p")) {
            flags->p = rdx;
            break;
        }
    }
}

static void parse_binary(int argc, char **argv, strace_t *s)
{
    int max = 0;

    error_handling(argc, argv, &s->flags);
    if ((s->flags.s < 0 || s->flags.non < s->flags.s) && (s->flags.p < 0 ||
    s->flags.non < s->flags.p)) {
        s->binary = &argv[1];
        return;
    }
    max = s->flags.s < s->flags.p ? s->flags.p : s->flags.s;
    s->binary = &argv[max + (s->flags.s < s->flags.p ? 2 : 1)];
}

static int check_p_flag(int i, strace_t *strace, char **argv)
{
    int number = 0;

    if (!strcmp(argv[i], "-p") && !strace->flag_p && (i == 1 ||
    (i == 2 && strace->flag_s))) {
        strace->flag_p = true;
        number = get_pid(argv[i + 1]);
        if (number > 0)
            strace->pid = number;
        else
            return 84;
    }
    return 0;
}

int get_flags(int argc, char **argv, strace_t *strace)
{
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-s") && !strace->flag_s &&
            (i == 1 || (i == 3 && strace->flag_p))) {
            strace->flag_s = true;
            continue;
        }
        if (check_p_flag(i, strace, argv) == 84)
            return 84;
    }
    parse_binary(argc, argv, strace);
    return 0;
}
