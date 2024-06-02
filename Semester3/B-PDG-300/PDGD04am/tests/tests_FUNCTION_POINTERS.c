/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04am-florent.guittre
** File description:
** tests_FUNCTIONS_POINTERS.c
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../ex04/print.h"

void print_normal(const char *str);
void print_reverse(const char *str);
void print_upper(const char *str);
void print_42(const char *str);
void do_action(action_t action, const char *str);

Test(function_pointers_normal, main_test, .init = cr_redirect_stdout)
{
    const char *str = "So long, and thanks for all the fish.";

    do_action(PRINT_NORMAL, str);
    fflush(stdout);
    cr_assert_stdout_eq_str("So long, and thanks for all the fish.\n");
}

Test(function_pointers_reverse, main_test, .init = cr_redirect_stdout)
{
    const char *str = "So long, and thanks for all the fish.";

    do_action(PRINT_REVERSE, str);
    fflush(stdout);
    cr_assert_stdout_eq_str(".hsif eht lla rof sknaht dna ,gnol oS\n");
}

Test(function_pointers_upper, main_test, .init = cr_redirect_stdout)
{
    const char *str = "So long, and thanks for all the fish.";

    do_action(PRINT_UPPER, str);
    fflush(stdout);
    cr_assert_stdout_eq_str("SO LONG, AND THANKS FOR ALL THE FISH.\n");
}

Test(function_pointers_42, main_test, .init = cr_redirect_stdout)
{
    const char *str = "So long, and thanks for all the fish.";

    do_action(PRINT_42, str);
    fflush(stdout);
    cr_assert_stdout_eq_str("42\n");
}
