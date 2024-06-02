/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-nmobjdump-florent.guittre
** File description:
** get_type.c
*/

#include "../../../include/prototypes.h"

static bool check_some_other_flags(unsigned int type)
{
    static const unsigned int types[] = {SHT_PROGBITS, SHT_NOTE,
    SHT_FINI_ARRAY, SHT_INIT_ARRAY};

    for (int i = 0; i < 4; i++) {
        if (type == types[i])
            return true;
    }
    return false;
}

static char brute_force_checks(Elf64_Sym *sym)
{
    if (ELF64_ST_BIND(sym->st_info) == STB_GNU_UNIQUE)
        return 'u';
    if (ELF64_ST_BIND(sym->st_info) == STB_WEAK)
        return sym->st_shndx == SHN_UNDEF ? 'w' : 'W';
    if (ELF64_ST_BIND(sym->st_info) == STB_WEAK && ELF64_ST_TYPE(sym->st_info)
    == STT_OBJECT)
        return sym->st_shndx == SHN_UNDEF ? 'v' : 'V';
    if (sym->st_shndx == SHN_UNDEF)
        return 'U';
    if (sym->st_shndx == SHN_ABS)
        return 'A';
    if (sym->st_shndx == SHN_COMMON)
        return 'C';
    return 0;
}

char get_type_64(Elf64_Shdr *sections, Elf64_Sym *sym)
{
    char type = brute_force_checks(sym);

    if (type != 0)
        return type;
    if (sections[sym->st_shndx].sh_type == SHT_NOBITS &&
    sections[sym->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        return 'B';
    if (check_some_other_flags(sections[sym->st_shndx].sh_type)) {
        switch (sections[sym->st_shndx].sh_flags) {
            case SHF_ALLOC:
                return 'R';
            case (SHF_ALLOC | SHF_WRITE):
                return 'D';
            case (SHF_ALLOC | SHF_EXECINSTR):
                return 'T';
        }
    }
    if (sections[sym->st_shndx].sh_type == SHT_DYNAMIC)
        return 'D';
    return '?';
}
