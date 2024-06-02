/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD05-florent.guittre
** File description:
** tests_compare.c
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(compare_c, compare_two_normal_strings)
{
    string_t s;
    int output = 0;

    string_init(&s, "Hello World");
    output = s.compare_c(&s, "Hello World");
    cr_assert_eq(output, 0);
    string_destroy(&s);
}

Test(compare_c, empty_struct)
{
    string_t *s = NULL;
    int output = 0;

    string_init(s, "Hello World");
    output = compare_c(NULL, "Hello World");
    cr_assert_eq(output, -1);
    string_destroy(s);
}

Test(compare_c, empty_string)
{
    string_t s;
    int output = 0;

    string_init(&s, NULL);
    output = compare_c(&s, "Hello World");
    cr_assert_eq(output, -1);
    string_destroy(&s);
}

Test(compare_s, compare_two_normal_strings)
{
    string_t s;
    string_t s2;
    int output = 0;

    string_init(&s, "Hello World");
    string_init(&s2, "Hello World");
    output = s.compare_s(&s, &s2);
    cr_assert_eq(output, 0);
    string_destroy(&s);
    string_destroy(&s2);
}

Test(compare_s, empty_string)
{
    string_t s;
    string_t s2;
    int output = 0;

    string_init(&s, "Hello World!");
    string_init(&s2, NULL);
    output = s.compare_s(&s, &s2);
    cr_assert_eq(output, -1);
    string_destroy(&s);
    string_destroy(&s2);
}

Test(compare_s, empty_second_struct)
{
    string_t s;
    int output = 0;

    string_init(&s, "Hello World!");
    output = s.compare_s(&s, NULL);
    cr_assert_eq(output, -1);
    string_destroy(&s);
}
