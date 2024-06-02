/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD05-florent.guittre
** File description:
** tests_append.c
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include "../string.h"

Test(append_c, concat_string)
{
    string_t s;

    string_init(&s, "Hello ");
    s.append_c(&s, "World!");
    cr_assert_str_eq(s.str, "Hello World!");
    string_destroy(&s);
}

Test(append_c, empty_struct)
{
    string_t *s = NULL;

    string_init(s, "Hello ");
    append_c(s, "World!");
    cr_assert_null(s);
    string_destroy(s);
}

Test(append_c, empty_input_string)
{
    string_t s;

    string_init(&s, NULL);
    s.append_c(&s, " World!");
    cr_assert_null(s.str);
    string_destroy(&s);
}

Test(append_c, empty_concat_string)
{
    string_t s;

    string_init(&s, "Hello ");
    s.append_c(&s, NULL);
    cr_assert_str_eq(s.str, "Hello ");
    string_destroy(&s);
}

Test(append_c, empty_args)
{
    string_t s;

    string_init(&s, NULL);
    s.append_c(&s, NULL);
    cr_assert_null(s.str);
    string_destroy(&s);
}

Test(append_c, all_is_empty)
{
    string_t *s = NULL;

    string_init(s, NULL);
    append_c(s, NULL);
    cr_assert_null(s);
    string_destroy(s);
}

Test(append_s, concat_strings)
{
    string_t s;
    string_t s2;

    string_init(&s, "Hello ");
    string_init(&s2, "World!");
    s.append_s(&s, &s2);
    cr_assert_str_eq(s.str, "Hello World!");
    string_destroy(&s);
    string_destroy(&s2);
}

Test(append_s, empty_concat_struct)
{
    string_t s;
    string_t s2;

    string_init(&s, "Hello ");
    string_init(&s2, "World!");
    s.append_s(&s, NULL);
    cr_assert_str_eq(s.str, "Hello ");
    string_destroy(&s);
    string_destroy(&s2);
}
