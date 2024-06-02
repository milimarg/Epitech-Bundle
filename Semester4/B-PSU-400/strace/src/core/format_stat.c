/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-strace-florent.guittre
** File description:
** format_stat
*/

#include "../../include/strace.h"

static void buffer_stat(unsigned long long addr, pid_t child,
    size_t size, void *buffer)
{
    size_t data;
    unsigned long tmp;

    for (size_t i = 0; i < size; i += data) {
        tmp = ptrace(PTRACE_PEEKDATA, child, addr + i);
        data = ((size - i) / sizeof(tmp)) ? sizeof(tmp) : size % sizeof(tmp);
        memcpy(buffer + i, &tmp, data);
    }
}

static void append_matching_mode_string(char *str, int i)
{
    for (int j = 0; j < 7; j++)
        if (arg_stat[j].first == i) {
            strcat(str, arg_stat[j].second);
            break;
        }
}

static char *create_str(struct stat *s)
{
    char *str = malloc(4096 * sizeof(char));

    if (!str)
        return NULL;
    sprintf(str, "{st_mode=");
    for (int i = 0; i < 16; i++)
        if (s->st_mode & (1 << i))
            append_matching_mode_string(str, i);
    if (str[strlen(str) - 1] == '|')
        str[strlen(str) - 1] = '\0';
    return str;
}

static char *create_tmp(struct stat *s)
{
    char *tmp = malloc(4096 * sizeof(char));

    if (!tmp)
        return NULL;
    sprintf(tmp, ", st_size=%ld, ...}", s->st_size);
    return tmp;
}

char *handle_struct_stat_p(strace_t *strace, long long addr, long long *value)
{
    struct stat s;
    char *tmp = NULL;
    char *str = NULL;

    buffer_stat(addr, strace->pid, sizeof(struct stat), &s);
    str = create_str(&s);
    if (!str)
        exit(84);
    tmp = create_tmp(&s);
    if (!tmp) {
        free(str);
        exit(84);
    }
    strcat(str, tmp);
    *value = (long long)str;
    return "%s";
}
