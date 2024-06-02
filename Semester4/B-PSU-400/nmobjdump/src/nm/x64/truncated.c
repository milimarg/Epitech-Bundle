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

int display_truncated_nm(data_t *data)
{
    if (check_if_truncated(data)) {
        printf("bfd plugin: %s: file too short\n", data->bin_name);
        printf("nm: warning: %s has a section extending %s\n",
        data->bin_name, "past end of file");
        printf("nm: %s: file format not recognized\n", data->bin_name);
        return 84;
    }
    return 0;
}
