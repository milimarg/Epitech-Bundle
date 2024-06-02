/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD05-florent.guittre
** File description:
** tests_MY_STRING.c
*/

#include <stddef.h>
#include <criterion/criterion.h>
#include "../string.h"

Test(my_string, fulfill_struct)
{
    string_t s;

    string_init(&s, "Hello World!");
    cr_assert_str_eq(s.str, "Hello World!");
    string_destroy(&s);
    cr_assert_null(s.str);
}

Test(my_string, empty_struct)
{
    string_t *s = NULL;

    string_init(s, "Hello World!");
    cr_assert_null(s);
    string_destroy(s);
}

Test(my_string, empty_string)
{
    string_t s;
    char *input = NULL;

    string_init(&s, input);
    cr_assert_null(input);
    string_destroy(&s);
}
