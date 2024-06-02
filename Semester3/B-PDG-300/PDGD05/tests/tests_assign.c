/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD05-florent.guittre
** File description:
** tests_assign.c
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(assign_c, fulfill_string)
{
    string_t s;

    string_init(&s, "");
    s.assign_c(&s, "Hello World!");
    cr_assert_str_eq(s.str, "Hello World!");
    string_destroy(&s);
}

Test(assign_c, null_struct)
{
    string_t *s = NULL;

    string_init(s, "");
    assign_c(s, "Hello World!");
    cr_assert_null(s);
    string_destroy(s);
}

Test(assign_s, fulfill_string)
{
    string_t s;
    string_t s2;

    string_init(&s, "");
    string_init(&s2, "Hello World!");
    s.assign_s(&s, &s2);
    cr_assert_str_eq(s.str, "Hello World!");
    string_destroy(&s);
    string_destroy(&s2);
}

Test(assign_s, empty_struct)
{
    string_t *s = NULL;
    string_t s2;

    string_init(s, "");
    string_init(&s2, "Hello World!");
    assign_s(s, &s2);
    cr_assert_null(s);
    string_destroy(s);
    string_destroy(&s2);
}
