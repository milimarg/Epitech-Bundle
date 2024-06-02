/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-ftrace-noe.tritsch
** File description:
** get_function_name
*/

#include "syscall.h"


static char *get_default_string(Elf64_Addr address)
{
    int size = snprintf(NULL, 0, "func_%ld@ftrace\n", address) + 1;
    char *str = malloc(sizeof(char) * (size));

    if (!str)
        return NULL;
    memset(str, 0, size);
    snprintf(str, size, "func_%ld@ftrace\n", address);
    return str;
}

char *get_function_name(ftrace_t *context, Elf64_Addr address)
{
    functab_t current;

    if (!context->functab)
        return get_default_string(address);
    for (int i = 0; i < context->symnbr; i++) {
        current = context->functab[i];
        if (address >= current.position &&
            address < current.position + current.size)
            return current.name;
    }
    return NULL;
}
