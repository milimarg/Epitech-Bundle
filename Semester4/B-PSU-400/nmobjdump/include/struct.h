/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-nmobjdump-florent.guittre
** File description:
** struct.h
*/

#ifndef B_PSU_400_STG_4_1_NMOBJDUMP_FLORENT_GUITTRE_STRUCT_H
    #define B_PSU_400_STG_4_1_NMOBJDUMP_FLORENT_GUITTRE_STRUCT_H
    #include "flags_please_work.h"
    #include <stdio.h>
    #include <elf.h>
    #include <stdbool.h>
    #include <sys/mman.h>
    #include <sys/stat.h>
    #include <string.h>

typedef struct {
    int return_value;
    union {
        Elf32_Ehdr _32;
        Elf64_Ehdr _64;
    } elf_header;
    char *bin_name;
    int current_fd;
    int file_format;
    void *map;
} data_t;

/* ARCHITECTURE */

typedef struct {
    uint16_t key;
    const char *str;
} architecture_t;

static architecture_t const architecture[] = {
    {EM_NONE, "None"},
    {EM_M32, "WE32100"},
    {EM_SPARC, "Sparc"},
    {EM_386, "i386"}, // "Intel 80386" instead of "i386"?
    {EM_68K, "MC68000"},
    {EM_88K, "MC88000"},
    {EM_860, "Intel 80860"},
    {EM_MIPS, "MIPS R3000"},
    {EM_PARISC, "HPPA"},
    {EM_SPARC32PLUS, "Sparc v8+"},
    {EM_PPC, "PowerPC"},
    {EM_PPC64, "PowerPC64"},
    {EM_S390, "IBM S/390"},
    {EM_ARM, "ARM"},
    {EM_SH, "Renesas / SuperH SH"},
    {EM_SPARCV9, "Sparc v9"},
    {EM_IA_64, "Intel IA-64"},
    {EM_X86_64, "i386:x86-64"},
    {0, NULL}
};

/* FLAGS */

typedef struct {
    int id;
    const char *value;
} flags_t;

static flags_t const flags[] = {
    {HAS_RELOC, "HAS_RELOC"},
    {EXEC_P, "EXEC_P"},
    {HAS_LINENO, "HAS_LINENO"},
    {HAS_DEBUG, "HAS_DEBUG"},
    {HAS_SYMS, "HAS_SYMS"},
    {HAS_LOCALS, "HAS_LOCALS"},
    {DYNAMIC, "DYNAMIC"},
    {WP_TEXT, "WP_TEXT"},
    {D_PAGED, "D_PAGED"},
    {BFD_IS_RELAXABLE, "BFD_IS_RELAXABLE"},
    {HAS_LOAD_PAGE, "HAS_LOAD_PAGE"},
    {0, NULL}
};

/* SECTIONS TO SKIP */

__attribute_maybe_unused__
static char const *sections_skip[] = {
    "",
    ".bss",
    ".shstrtab",
    ".symtab",
    ".strtab",
    ".rela.text",
    ".rela.debug_info",
    ".rela.debug_aranges",
    ".rela.debug_line",
    ".rela.eh_frame",
    ".tbss",
    "__libc_freeres_ptrs",
    NULL
};

#endif //B_PSU_400_STG_4_1_NMOBJDUMP_FLORENT_GUITTRE_STRUCT_H
