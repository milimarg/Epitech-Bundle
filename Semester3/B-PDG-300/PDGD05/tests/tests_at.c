/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD05-florent.guittre
** File description:
** tests_at.c
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(at, get_position_of_string)
{
    string_t s;
    char pos = 0;

    string_init(&s, "Hello World!");
    pos = s.at(&s, 8);
    cr_assert_eq(pos, 'r');
    string_destroy(&s);
}

Test(at, empty_struct)
{
    string_t *s = NULL;
    char pos = 0;

    string_init(s, "Hello World");
    pos = at(s, 8);
    cr_assert_eq(pos, -1);
    string_destroy(s);
}

Test(at, empty_string)
{
    string_t s;
    char pos = 0;

    string_init(&s, NULL);
    pos = s.at(&s, 8);
    cr_assert_eq(pos, -1);
    string_destroy(&s);
}

Test(at, pos_out_of_bounds)
{
    string_t s;
    char pos = 0;

    string_init(&s, "Hello World!");
    pos = s.at(&s, 20);
    cr_assert_eq(pos, -1);
    string_destroy(&s);
}
