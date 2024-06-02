/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-nmobjdump-florent.guittre
** File description:
** display_sections.c
*/

#include "../../../include/prototypes.h"

static void display_symtab(data_t *data, Elf32_Shdr *sections,
    Elf32_Shdr *symtab)
{
    Elf32_Sym *sym = NULL;
    char *name = NULL;
    char type = 0;

    for (Elf32_Xword i = 0; i < symtab->sh_size / symtab->sh_entsize; i++) {
        sym = (Elf32_Sym *)((char *)data->map + symtab->sh_offset) + i;
        name = (char *)(data->map + sections[symtab->sh_link].sh_offset +
        sym->st_name);
        if (sym->st_info == STT_FILE || !strcmp(name, ""))
            continue;
        type = get_type_32(sections, sym);
        if (ELF32_ST_BIND(sym->st_info) == STB_LOCAL && type != '?')
            type += 32;
        if (sym->st_value == 0 && sym->st_shndx == SHN_UNDEF)
            printf("%s %c %s\n", "        ", type, name);
        else
            printf("%08x %c %s\n", sym->st_value, type, name);
    }
}

static void print_section_headers(data_t *data, Elf32_Ehdr *_32,
    Elf32_Shdr *section_headers, char *section_names)
{
    Elf32_Shdr section = {0};
    char *name = NULL;

    for (int i = 0; i < _32->e_shnum; i++) {
        section = section_headers[i];
        name = &section_names[section.sh_name];
        if (strcmp(name, ".symtab") != 0)
            continue;
        display_symtab(data, section_headers, &section);
    }
}

int display_32(data_t *data)
{
    struct stat file_stat = {0};
    Elf32_Ehdr *header = NULL;
    Elf32_Shdr *sections = NULL;
    char *section_names = NULL;

    fstat(data->current_fd, &file_stat);
    data->map = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE,
    data->current_fd, 0);
    header = (Elf32_Ehdr *)data->map;
    sections = (Elf32_Shdr *)(data->map + header->e_shoff);
    section_names = (char *)(data->map + sections[header->e_shstrndx].
    sh_offset);
    print_section_headers(data, header, sections, section_names);
    return 0;
}
