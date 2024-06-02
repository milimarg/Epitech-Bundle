/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGRUSH2-florent.guittre
** File description:
** tests_array.c
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include "../new.h"
#include "../array.h"
#include "../int.h"

Test(array, create_array)
{
    Object *array = new(Array, 10, Int, 0);
    Object *it = begin(array);
    Object *it_end = end(array);
    Object *item = NULL;
    Object *val = NULL;
    char *s2 = NULL;
    char *s = NULL;

    cr_assert_eq(len(array), 10);
    setitem(array, 5, 12);
    setitem(array, 6, 13);
    setval(it, 314159);
    val = getval(it);
    s = str(val);
    cr_assert_str_eq(s, "<Int (314159)>");
    cr_assert(gt(it_end, it));
    item = getitem(array, 5);
    s2 = str(item);
    cr_assert_str_eq(s2, "<Int (12)>");
    while (lt(it, it_end)) {
        incr(it);
    }
    cr_assert(eq(it, it_end));
    delete(it);
    delete(it_end);
    delete(array);
    free(s2);
    free(s);
}
