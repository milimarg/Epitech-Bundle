/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-nmobjdump-florent.guittre
** File description:
** display_sections.c
*/

#include "../../../include/prototypes.h"

void display_code_side_64(char *buffer, int *code_to_disp,
    int *highest_code_len, int *index)
{
    for (int i = 0; i < 16; i++) {
        if (*code_to_disp > 0) {
            printf("%02x", (unsigned char)buffer[*index]);
            (*code_to_disp)--;
            *highest_code_len += 2;
        }
        (*index)++;
        if (i > 0 && !((i + 1) % 4)) {
            printf(" ");
            (*highest_code_len)++;
        }
    }
}

void display_char_code_64(char *buffer, int *index, int *char_to_disp,
    int *highest_char_len)
{
    for (int i = 0; i < 16; i++) {
        if (*char_to_disp <= 0)
            continue;
        printf("%c", DISP_VISIBLE(buffer[*index]));
        (*char_to_disp)--;
        (*highest_char_len)++;
        (*index)++;
    }
}

void print_spaces_between_code_char_64(int code_to_disp, int highest_code_len)
{
    printf(" ");
    if (code_to_disp == 0)
        for (int i = 0; i < 36 - highest_code_len; i++)
            printf(" ");
}
