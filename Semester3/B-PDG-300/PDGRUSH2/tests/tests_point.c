/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGRUSH2-florent.guittre
** File description:
** tests_point.c
*/

#include <criterion/criterion.h>
#include "../new.h"
#include "../point.h"

Test(point, create_point)
{
    Object *point = new(Point, 42, -42);
    Object *point2 = new(Point, 10, -10);
    Object *add = addition(point, point2);
    Object *sub = subtraction(point, point2);
    char *str = str(point);
    char *str2 = str(add);
    char *str3 = str(sub);

    cr_assert_str_eq(str, "<Point (42, -42)>");
    cr_assert_str_eq(str2, "<Point (52, -52)>");
    cr_assert_str_eq(str3, "<Point (32, -32)>");

    delete(point);
    delete(point2);
    delete(add);
    delete(sub);
    free(str);
    free(str2);
    free(str3);
}
