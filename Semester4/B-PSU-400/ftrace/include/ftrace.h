/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-ftrace-noe.tritsch
** File description:
** ftrace
*/

#ifndef FTRACE_H_
    #define FTRACE_H_
    #include <stdbool.h>
    #include <string.h>
    #include <stdio.h>
    #include <sys/ptrace.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <sys/user.h>
    #include <errno.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <libelf.h>
    #include <gelf.h>

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/ptrace.h>
    #include <sys/wait.h>
    #include <sys/user.h>
    #include <string.h>
    #include <fcntl.h>
    #include <elf.h>
    #include <libelf.h>
    #include <gelf.h>

    #include <stdlib.h>
    #include <string.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <sys/mman.h>
    #include <elf.h>
    #include <ar.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <ctype.h>


typedef struct syscall_s {
    int index;
    char *mnemo;
    int arg_count;
    int return_type;
    int params[6];
} syscall_t;

typedef struct {
    char *name;
    Elf64_Addr position;
    Elf64_Xword size;
}functab_t;

typedef struct ftrace_s {
    pid_t pid;
    char **command;
    char **env;
    // FUNCTAB
    Elf64_Ehdr *elf;
    void *buff;
    functab_t *functab;
    size_t symnbr;
    struct stat stats;
} ftrace_t;

typedef struct user_regs_struct regs_t;

typedef Elf elf_t;

bool print_notice(int argc, char **argv);
void start_ftrace(ftrace_t *context);
char *get_function_name(ftrace_t *context, Elf64_Addr address);
char *get_name_loop(elf_t *elf, Elf_Scn *scn, Elf64_Shdr *shdr,
    Elf64_Addr address);
ftrace_t *get_symb(ftrace_t *context);
void destroy_context(ftrace_t *context);

#endif /* !FTRACE_H_ */
