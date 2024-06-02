/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04am-florent.guittre
** File description:
** tests_ARRAYS.c
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void sort_int_array(int *array, size_t nmemb);
size_t uniq_int_array(int *array, size_t nmemb);
void disp_int_array(const int *array, size_t nmemb);
void sort_array(void *array, size_t nmemb, size_t size,
                int(*compar)(const void *, const void *));
size_t uniq_array(void *array, size_t nmemb, size_t size,
                  int (*compar)(const void *, const void *));
void disp_array(const void *array, size_t nmemb, size_t size,
                void (*print)(const void *));

static int int_compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

static int compare_int(const void *a, const void *b)
{
    return (*(int *)a == *(int *)b);
}

static void print_int(const void *a)
{
    printf("%d\n", *(int *)a);
}

Test(sort_int_array, check_sorting)
{
    int len = 5;
    int array[] = {4, 5, 2, 3, 1};
    int sorted[] = {1, 2, 3, 4, 5};

    sort_int_array(array, len);

    for (int i = 0; i < len; i++) {
        cr_assert_eq(array[i], sorted[i]);
    }
}

Test(uniq_int_array, check_filtering)
{
    int array[] = {1, 1, 2, 2, 3};
    int result[] = {1, 2, 3};
    size_t a = uniq_int_array(array, 5);

    cr_assert_eq(a, 3);
    for (size_t i = 0; i < a; i++) {
        cr_assert_eq(array[i], result[i]);
    }
}

Test(uniq_int_array, input_len_is_zero)
{
    int array[] = {1, 1, 2, 2, 3};
    size_t a = uniq_int_array(array, 0);

    cr_assert_eq(a, 0);
}

Test(disp_int_array, check_display_array, .init = cr_redirect_stdout)
{
    int array[] = {1, 2, 3, 4, 5};
    disp_int_array(array, 5);

    fflush(stdout);
    cr_assert_stdout_eq_str("1\n2\n3\n4\n5\n");
}

Test(sort_array, check_sorting)
{
    int len = 5;
    int array[] = {4, 5, 2, 3, 1};
    int sorted[] = {1, 2, 3, 4, 5};

    sort_array(array, len, sizeof(int), int_compare);

    for (int i = 0; i < len; i++) {
    cr_assert_eq(array[i], sorted[i]);
    }
}

Test(uniq_array, check_filtering)
{
    int array[] = {1, 1, 2, 2, 3};
    int result[] = {1, 2, 3};
    size_t a = uniq_array(array, 5, sizeof(int), compare_int);

    cr_assert_eq(a, 3);
    for (size_t i = 0; i < a; i++) {
        cr_assert_eq(array[i], result[i]);
    }
}

Test(disp_array, check_display_array, .init = cr_redirect_stdout)
{
    int array[] = {1, 2, 3, 4, 5};
    disp_array(array, 5, sizeof(int), print_int);

    fflush(stdout);
    cr_assert_stdout_eq_str("1\n2\n3\n4\n5\n");
}
