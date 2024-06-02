/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-nmobjdump-florent.guittre
** File description:
** main.c
*/

#include <stdio.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include "../../include/prototypes.h"

static bool is_file_an_elf(data_t *data)
{
    get_file_format_64(data);
    if (data->file_format == ELFCLASS32) {
        return data->elf_header._32.e_ident[EI_MAG0] == ELFMAG0 &&
        data->elf_header._32.e_ident[EI_MAG1] == ELFMAG1 &&
        data->elf_header._32.e_ident[EI_MAG2] == ELFMAG2 &&
        data->elf_header._32.e_ident[EI_MAG3] == ELFMAG3;
    }
    if (data->file_format == ELFCLASS64) {
        return data->elf_header._64.e_ident[EI_MAG0] == ELFMAG0 &&
        data->elf_header._64.e_ident[EI_MAG1] == ELFMAG1 &&
        data->elf_header._64.e_ident[EI_MAG2] == ELFMAG2 &&
        data->elf_header._64.e_ident[EI_MAG3] == ELFMAG3;
    }
    return false;
}

static int display_data(data_t *data)
{
    if (data->file_format == ELFCLASS32) {
        display_header_32(data);
        display_sections_32(data);
        return 1;
    }
    if (data->file_format == ELFCLASS64) {
        if (display(data) == 84)
            return 84;
        return 0;
    }
    printf("objdump: %s: invalid elf class\n", data->bin_name);
    return 0;
}

static int error_handling_file_format(data_t *data)
{
    if (!is_file_an_elf(data)) {
        printf("objdump: %s: file format not recognized\n", data->bin_name);
        close(data->current_fd);
        data->return_value = 84;
        return 84;
    }
    return 0;
}

static int handle_file(char *filepath, data_t *data, int argc)
{
    data->bin_name = filepath;
    data->current_fd = open(data->bin_name, O_RDONLY);
    if (data->current_fd == -1) {
        printf("objdump: '%s': No such file\n",
        argc == 1 ? &filepath[2] : filepath);
        data->return_value = 84;
        return 84;
    }
    read(data->current_fd, &data->elf_header, sizeof(data->elf_header));
    if (error_handling_file_format(data) == 84)
        return 84;
    if (display_data(data) == 84)
        return 84;
    close(data->current_fd);
    return 0;
}

int main(int argc, char **argv)
{
    data_t data = {0};

    if (argc == 1)
        return handle_file("./a.out", &data, argc);
    for (int i = 1; i < argc; i++)
        if (handle_file(argv[i], &data, argc) == 84)
            continue;
    return data.return_value;
}
