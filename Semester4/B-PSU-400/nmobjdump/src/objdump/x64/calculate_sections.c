/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-nmobjdump-florent.guittre
** File description:
** display_sections.c
*/

#include "../../../include/prototypes.h"

bool check_section_is_valid(char *name)
{
    for (int i = 0; sections_skip[i] != NULL; i++)
        if (!strcmp(name, sections_skip[i]))
            return false;
    return true;
}

static void my_showmem(char *buffer, int size, Elf64_Addr address)
{
    int index = 0;
    int index2 = 0;
    int code_to_disp = size;
    int highest_code_len = 0;
    int highest_char_len = 0;

    for (int char_to_disp = size; char_to_disp > 0;) {
        highest_code_len = 0;
        highest_char_len = 0;
        printf(" %04lx ", (unsigned long)address);
        display_code_side(buffer, &code_to_disp, &highest_code_len, &index);
        index = index2;
        print_spaces_between_code_char(code_to_disp, highest_code_len);
        display_char_code(buffer, &index, &char_to_disp, &highest_char_len);
        for (int i = 0; i < 16 - highest_char_len; i++)
            printf(" ");
        printf("\n");
        address += 16;
        index2 = index;
    }
}

static void print_section_headers(void *map, Elf64_Ehdr *_64,
    Elf64_Shdr *section_headers, char *section_names)
{
    Elf64_Shdr section = {0};
    char *name = NULL;

    for (int i = 0; i < _64->e_shnum; i++) {
        section = section_headers[i];
        name = &section_names[section.sh_name];
        if (!check_section_is_valid(name))
            continue;
        printf("Contents of section %s:\n", name);
        my_showmem(map + section.sh_offset, section.sh_size, section.sh_addr);
    }
}

int display(data_t *data)
{
    struct stat file_stat = {0};
    Elf64_Ehdr *header = NULL;
    Elf64_Shdr *sections = NULL;
    char *section_names = NULL;

    fstat(data->current_fd, &file_stat);
    data->map = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE,
    data->current_fd, 0);
    if (display_truncated_objdump(data) == 84)
        return 84;
    display_header_64(data);
    header = (Elf64_Ehdr *)data->map;
    sections = (Elf64_Shdr *)(data->map + header->e_shoff);
    section_names = (char *)(data->map + sections[header->e_shstrndx].
    sh_offset);
    print_section_headers(data->map, header, sections, section_names);
    return 0;
}
