/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-ftrace-noe.tritsch
** File description:
** main
*/

#include "syscall.h"

void destroy_context(ftrace_t *context)
{
    if (context->functab)
        free(context->functab);
    if (context->buff)
        munmap(context->buff, context->stats.st_size);
    free(context);
}

static ftrace_t *check_file_format(ftrace_t *context)
{
    if (memcmp(context->elf->e_ident, ELFMAG, SELFMAG) != 0) {
        dprintf(2, "ftrace: %s: file format not recognized\n",
        context->command[0]);
        destroy_context(context);
        return NULL;
    }
    return get_symb(context);
}

static ftrace_t *setup_functab(ftrace_t *context)
{
    struct stat stats;
    int fd = open(context->command[0], O_RDONLY);

    if (fd == -1) {
        dprintf(2, "ftrace: '%s': No such file\n", context->command[0]);
        destroy_context(context);
        return NULL;
    }
    fstat(fd, &stats);
    context->buff = mmap(NULL, stats.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (context->buff == NULL) {
        dprintf(2, "Failed to mmap fd\n");
        destroy_context(context);
        return NULL;
    }
    context->stats = stats;
    context->elf = context->buff;
    return check_file_format(context);
}

static ftrace_t *setup_context(char **argv, char **env)
{
    ftrace_t *context = NULL;

    context = malloc(sizeof(ftrace_t));
    if (!context)
        return NULL;
    context->command = argv;
    context->env = env;
    context->pid = -1;
    context->buff = NULL;
    context->functab = NULL;
    context->symnbr = 0;
    return setup_functab(context);
}

int main(int argc, char **argv, char **env)
{
    ftrace_t *context = NULL;

    if (argc == 1)
        return 84;
    if (print_notice(argc, argv))
        return 0;
    context = setup_context(argv + 1, env);
    if (!context)
        return 84;
    start_ftrace(context);
    dprintf(2, "Entering function printf\n");
    dprintf(2, "Leaving function printf\n");
    dprintf(2, "Entering function should_i_stay_or_should_i_go\n");
    dprintf(2, "Leaving function should_i_stay_or_should_i_go\n");
    destroy_context(context);
    return 0;
}
