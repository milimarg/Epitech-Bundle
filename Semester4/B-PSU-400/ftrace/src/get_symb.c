/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-ftrace-noe.tritsch
** File description:
** get_symb
*/

#include "syscall.h"

static ftrace_t *check_truncated(ftrace_t *context)
{
    long unsigned int size = 0;

    size = context->stats.st_size;
    if (size < context->elf->e_shoff
    + (context->elf->e_shnum * context->elf->e_shentsize)) {
        dprintf(2, "ftrace: %s: file format not recognized\n",
        context->command[0]);
        destroy_context(context);
        return NULL;
    }
    return (context);
}

void fill_tab64(ftrace_t *context, Elf64_Shdr *sym,
    Elf64_Shdr *sections_header)
{
    char *current = NULL;
    Elf64_Sym *symbols = (Elf64_Sym *)(context->buff + sym->sh_offset);

    for (int i = 0; i < sym->sh_size / sym->sh_entsize; i++) {
        current = (char *)context->buff +
        sections_header[sym->sh_link].sh_offset + symbols->st_name;
        if (ELF64_ST_TYPE(symbols->st_info) == STT_FUNC
        || ELF64_ST_TYPE(symbols->st_info) == STT_NOTYPE) {
            context->functab = realloc(context->functab,
            (context->symnbr + 1) * (sizeof(functab_t)));
            context->functab[context->symnbr].name = strdup(current);
            context->functab[context->symnbr].position = symbols->st_value;
            context->functab[context->symnbr].size = symbols->st_size;
            context->symnbr++;
        }
        symbols++;
    }
}

ftrace_t *get_symb(ftrace_t *context)
{
    int counter = 0;
    Elf64_Shdr *sections_header = (context->buff + context->elf->e_shoff);

    if (check_truncated(context) == NULL)
        return NULL;
    while (counter < context->elf->e_shnum) {
        if (sections_header[counter].sh_type == SHT_SYMTAB)
            fill_tab64(context, &sections_header[counter], sections_header);
        if (sections_header[counter].sh_type == SHT_DYNSYM)
            fill_tab64(context, &sections_header[counter], sections_header);
        counter++;
    }
    return context;
}
