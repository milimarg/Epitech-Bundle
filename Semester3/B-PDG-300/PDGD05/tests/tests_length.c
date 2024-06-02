/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD05-florent.guittre
** File description:
** tests_length.c
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(length, get_length_of_normal_string)
{
    string_t s;
    int len = 0;

    string_init(&s, "Hello World!");
    len = s.length(&s);
    cr_assert_eq(len, 12);
    string_destroy(&s);
}

Test(length, empty_struct)
{
    string_t *s = NULL;
    int len = 0;

    string_init(s, "Hello World!");
    len = length(s);
    cr_assert_eq(len, -1);
    string_destroy(s);
}

Test(length, empty_string)
{
    string_t s;
    int len = 0;

    string_init(&s, NULL);
    len = s.length(&s);
    cr_assert_eq(len, -1);
    string_destroy(&s);
}
