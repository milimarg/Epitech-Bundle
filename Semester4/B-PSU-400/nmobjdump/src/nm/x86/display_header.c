/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-nmobjdump-florent.guittre
** File description:
** display_header_32.c
*/

#include "../../../include/prototypes.h"

void display_header_32(data_t *data)
{
    const char *fileformat = get_file_format_32(data);
    const char *architecture = get_architecture_32(data);
    const unsigned long flags = get_flags_per_type_32(data);

    printf("\n%s:     file format %s\n", data->bin_name,
    fileformat);
    printf("architecture: %s, flags 0x%08lx:\n", architecture, flags);
    display_used_flags(flags);
    printf("start address 0x%08x\n\n", data->elf_header._32.e_entry);
}
