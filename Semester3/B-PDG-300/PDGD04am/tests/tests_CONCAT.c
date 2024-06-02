/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04am-florent.guittre
** File description:
** tests_CONCAT.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <criterion/criterion.h>
#include "../ex02/concat.h"

void concat_strings(const char *str1, const char *str2, char **res);
void concat_struct(concat_t *str);

Test(test_concat_string, main_test)
{
    char str1 [] = "I find your lack of faith...";
    char str2 [] = " disturbing.";
    char *res = NULL;
    concat_strings(str1, str2, &res);
    cr_assert_str_eq(res, "I find your lack of faith... disturbing.");
    free(res);
}

Test(test_concat_string, null_str1)
{
    char str2 [] = " disturbing.";
    char *res = NULL;

    concat_strings(NULL, str2, NULL);
    cr_assert_null(res);
}

Test(test_concat_string, null_str2)
{
    char str1 [] = "I find your lack of faith...";
    char *res = NULL;

    concat_strings(str1, NULL, NULL);
    cr_assert_null(res);
}

Test(test_concat_struct, main_test)
{
    char str1 [] = "These aren't the Droids";
    char str2 [] = " you're looking for.";
    concat_t str = {
            .str1 = str1 ,
            .str2 = str2 ,
            .res = NULL
    };
    concat_struct(&str);
    cr_assert_str_eq(str.res, "These aren't the Droids you're looking for.");
    free(str.res);
}

Test(test_concat_struct, null_str1)
{
    char str2 [] = " disturbing.";
    concat_t str = {NULL, str2, NULL};

    concat_struct(&str);
    cr_assert_null(str.res);
}

Test(test_concat_struct, null_str2)
{
    char str1 [] = "These aren't the Droids";
    concat_t str = {str1, NULL, NULL};

    concat_struct(&str);
    cr_assert_null(str.res);
}
