/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-strace-florent.guittre
** File description:
** format
*/

#include "../../include/strace.h"

static char *replace_backslash(char *str)
{
    char *tmp = malloc(sizeof(char) * strlen(str) * 2 + 1);
    char tab[7] = {'a', 'b', 't', 'n', 'v', 'f', 'r'};
    int i = 0;
    int j = 0;

    for (; str[i];) {
        if (str[i] >= 7 && str[i] <= 13) {
            tmp[j] = '\\';
            j++;
            tmp[j] = tab[str[i] - 7];
        } else
            tmp[j] = str[i];
        j++;
        i++;
    }
    tmp[j] = 0;
    return tmp;
}

static char *read_string_from_process(pid_t pid, long long addr)
{
    char *str = malloc(4096);
    int i = 0;
    long long data = 0;

    if (!str)
        return NULL;
    while (1) {
        errno = 0;
        data = ptrace(PTRACE_PEEKDATA, pid, addr + i, NULL);
        if (errno != 0) {
            str[i] = 0;
            break;
        }
        memcpy(str + i, &data, sizeof(char));
        if (memchr(&data, 0, sizeof(char)) != NULL)
            break;
        i += sizeof(char);
    }
    return str;
}

static char *get_string(pid_t pid, long long addr)
{
    char *str = read_string_from_process(pid, addr);
    char *res = NULL;

    if (!str)
        return NULL;
    res = replace_backslash(str);
    free(str);
    return res;
}

static char *get_format_and_value_argnb(strace_t *strace, long long addr,
    int argnb, long long *value)
{
    core_strace_t *core = &strace->core;
    char *format;

    if (core->args[argnb] == STRUCT_STAT_P)
        return handle_struct_stat_p(strace, addr, value);
    if (core->args[argnb] == STRING) {
        format = "\"%s\"";
        *value = (long long)get_string(strace->pid, addr);
    } else if (core->args[argnb] == NUM || core->args[argnb] == UNSIGNED) {
        format = "%lld";
        *value = addr;
    } else {
        format = "0x%llx";
        *value = addr;
    }
    return format;
}

static char *get_format_and_value_rdx(strace_t *strace, long long addr,
    long long *value)
{
    char *format;

    if (table[strace->rdx].ret_value == STRING) {
        format = "\"%s\"";
        *value = (long long)get_string(strace->pid, addr);
    } else if (table[strace->rdx].ret_value == NUM
        || table[strace->rdx].ret_value == UNSIGNED) {
        format = "%lld";
        *value = addr;
    } else {
        format = "0x%llx";
        *value = addr;
    }
    return format;
}

static char *get_format_and_value(strace_t *strace, long long addr, int argnb,
    long long *value)
{
    if (argnb >= 0)
        return get_format_and_value_argnb(strace, addr, argnb, value);
    else
        return get_format_and_value_rdx(strace, addr, value);
}

void store_display(strace_t *strace, int *offset, long long addr,
    int argnb)
{
    core_strace_t *core = &strace->core;
    long long value;
    char *format;

    if (!strace->flag_s)
        *offset += sprintf(core->buffer + *offset, "0x%llx", addr);
    else {
        format = get_format_and_value(strace, addr, argnb, &value);
        *offset += sprintf(core->buffer + *offset, format, value);
    }
}
