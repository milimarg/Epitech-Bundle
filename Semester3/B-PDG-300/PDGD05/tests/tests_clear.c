/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD05-florent.guittre
** File description:
** tests_clear.c
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(clear, clear_normal_string)
{
    string_t s;

    string_init(&s, "Hello World!");
    s.clear(&s);
    cr_assert_str_eq(s.str, "");
    string_destroy(&s);
}

Test(clear, empty_struct)
{
    string_t *s = NULL;

    string_init(s, "Hello World!");
    clear(s);
    cr_assert_null(s);
    string_destroy(s);
}
