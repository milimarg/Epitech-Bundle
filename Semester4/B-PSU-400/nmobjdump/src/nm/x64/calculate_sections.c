/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-nmobjdump-florent.guittre
** File description:
** display_sections.c
*/

#include "../../../include/prototypes.h"

static void display_symtab(data_t *data, Elf64_Shdr *sections,
    Elf64_Shdr *symtab)
{
    Elf64_Sym *sym = NULL;
    char *name = NULL;
    char type = 0;

    for (Elf64_Xword i = 0; i < symtab->sh_size / symtab->sh_entsize; i++) {
        sym = (Elf64_Sym *)((char *)data->map + symtab->sh_offset) + i;
        name = (char *)(data->map + sections[symtab->sh_link].sh_offset +
        sym->st_name);
        if (sym->st_info == STT_FILE || !strcmp(name, ""))
            continue;
        type = get_type_64(sections, sym);
        if (ELF64_ST_BIND(sym->st_info) == STB_LOCAL && type != '?')
            type += 32;
        if (sym->st_value == 0 && sym->st_shndx == SHN_UNDEF)
            printf("%s %c %s\n", "                ", type, name);
        else
            printf("%016lx %c %s\n", sym->st_value, type, name);
    }
}

static void print_section_headers(data_t *data, Elf64_Ehdr *_64,
    Elf64_Shdr *section_headers, char *section_names)
{
    Elf64_Shdr section = {0};
    char *name = NULL;

    for (int i = 0; i < _64->e_shnum; i++) {
        section = section_headers[i];
        name = &section_names[section.sh_name];
        if (strcmp(name, ".symtab") != 0)
            continue;
        display_symtab(data, section_headers, &section);
    }
}

int display_64(data_t *data)
{
    struct stat file_stat = {0};
    Elf64_Ehdr *header = NULL;
    Elf64_Shdr *sections = NULL;
    char *section_names = NULL;

    fstat(data->current_fd, &file_stat);
    data->map = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE,
    data->current_fd, 0);
    header = (Elf64_Ehdr *)data->map;
    sections = (Elf64_Shdr *)(data->map + header->e_shoff);
    section_names = (char *)(data->map + sections[header->e_shstrndx].
    sh_offset);
    print_section_headers(data, header, sections, section_names);
    return 0;
}
