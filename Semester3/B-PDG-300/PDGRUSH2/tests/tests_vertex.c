/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGRUSH2-florent.guittre
** File description:
** tests_vertex.c
*/

#include <criterion/criterion.h>
#include "../new.h"
#include "../vertex.h"

Test(vertex, create_vertex)
{
    Object *vertex = new(Vertex, 0, 1, 2);
    Object *vertex2 = new(Vertex, 10, 11, 12);
    Object *add = addition(vertex, vertex2);
    Object *sub = subtraction(vertex, vertex2);
    char *str = str(vertex);
    char *str2 = str(add);
    char *str3 = str(sub);

    cr_assert_str_eq(str, "<Vertex (0, 1, 2)>");
    cr_assert_str_eq(str2, "<Vertex (10, 12, 14)>");
    cr_assert_str_eq(str3, "<Vertex (-10, -10, -10)>");

    delete(vertex);
    delete(vertex2);
    delete(add);
    delete(sub);
    free(str);
    free(str2);
    free(str3);
}
