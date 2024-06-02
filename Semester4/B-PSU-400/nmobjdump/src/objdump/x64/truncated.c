/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-nmobjdump-florent.guittre
** File description:
** truncated.c
*/

#include "../../../include/prototypes.h"

// TODO: missing x86 truncated file check

static bool check_if_truncated(data_t *data)
{
    struct stat s;
    long unsigned int size = 0;

    stat(data->bin_name, &s);
    size = s.st_size;
    if (data->file_format == ELFCLASS64 && size < data->elf_header._64.e_shoff
    + (data->elf_header._64.e_shnum * data->elf_header._64.e_shentsize))
        return true;
    return false;
}

int display_truncated_objdump(data_t *data)
{
    if (check_if_truncated(data)) {
        printf("objdump: warning: %s has a section extending past %s\n",
        data->bin_name, "end of file");
        printf("objdump: %s: file format not recognized\n", data->bin_name);
        return 84;
    }
    return 0;
}
