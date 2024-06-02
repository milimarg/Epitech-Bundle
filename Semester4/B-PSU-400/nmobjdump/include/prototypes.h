/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-nmobjdump-florent.guittre
** File description:
** prototypes.h
*/

#ifndef B_PSU_400_STG_4_1_NMOBJDUMP_FLORENT_GUITTRE_PROTOTYPES_H
    #define B_PSU_400_STG_4_1_NMOBJDUMP_FLORENT_GUITTRE_PROTOTYPES_H
    #define DISP_VISIBLE(c) c >= ' ' && c < 127 ? c : '.'
    #include "struct.h"

/* header */
const char *get_file_format_64(data_t *data);
const char *get_file_format_32(data_t *data);
const char *get_architecture_64(data_t *data);
const char *get_architecture_32(data_t *data);
unsigned long get_flags_per_type_64(data_t *data);
unsigned long get_flags_per_type_32(data_t *data);
void display_used_flags(const unsigned long flags_number);
void display_used_flags_32(const unsigned long flags_number);
void display_used_flags_64(const unsigned long flags_number);

/* misc */
void display_header_64(data_t *data);
void display_header_32(data_t *data);
int display(data_t *data);
int display_32(data_t *data);
int display_64(data_t *data);
void display_sections_32(data_t *data);
int display_truncated_nm(data_t *data);
int display_truncated_objdump(data_t *data);

/* sections */

bool check_section_is_valid(char *name);
void display_code_side(char *buffer, int *code_to_disp, int *highest_code_len,
    int *index);
void display_code_side_32(char *buffer, int *code_to_disp,
    int *highest_code_len, int *index);
void display_code_side_64(char *buffer, int *code_to_disp,
    int *highest_code_len, int *index);
void display_char_code(char *buffer, int *index, int *char_to_disp,
    int *highest_char_len);
void display_char_code_32(char *buffer, int *index, int *char_to_disp,
    int *highest_char_len);
void display_char_code_64(char *buffer, int *index, int *char_to_disp,
    int *highest_char_len);
void print_spaces_between_code_char(int code_to_disp, int highest_code_len);
void print_spaces_between_code_char_32(int code_to_disp, int highest_code_len);
void print_spaces_between_code_char_64(int code_to_disp, int highest_code_len);

/* symbols */
char get_type_64(Elf64_Shdr *sections, Elf64_Sym *sym);
char get_type_32(Elf32_Shdr *sections, Elf32_Sym *sym);

#endif //B_PSU_400_STG_4_1_NMOBJDUMP_FLORENT_GUITTRE_PROTOTYPES_H
