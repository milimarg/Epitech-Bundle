/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-nmobjdump-florent.guittre
** File description:
** get_data_header.c
*/

#include "../../../include/prototypes.h"

const char *get_file_format_64(data_t *data)
{
    switch (data->elf_header._64.e_ident[EI_CLASS]) {
        case ELFCLASS32:
            data->file_format = ELFCLASS32;
            return "elf32-i386";
        case ELFCLASS64:
            data->file_format = ELFCLASS64;
            return "elf64-x86-64";
    }
    data->file_format = ELFCLASSNONE;
    return "Unknown Fileformat";
}

const char *get_architecture_64(data_t *data)
{
    for (int i = 0; architecture[i].str != NULL; i++)
        if (architecture[i].key == data->elf_header._64.e_machine)
            return architecture[i].str;
    return "Unknown Architecture";
}

unsigned long get_flags_per_type_64(data_t *data)
{
    switch (data->elf_header._64.e_type) {
        case ET_REL:
            return 17;
        case ET_EXEC:
            return 274;
        case ET_DYN:
            return 336;
    }
    return 0;
}

void display_used_flags_64(const unsigned long flags_number)
{
    int used_flags_number = 0;
    int index = 0;

    for (int i = 0; flags[i].value != NULL; i++)
        if (flags[i].id & flags_number)
            used_flags_number++;
    for (int i = 0; flags[i].value != NULL; i++) {
        if (!(flags[i].id & flags_number))
            continue;
        printf("%s", flags[i].value);
        index++;
        if (index != used_flags_number)
            printf(", ");
    }
    printf("\n");
}
