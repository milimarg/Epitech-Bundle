/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04am-florent.guittre
** File description:
** tests_1D_ARRAY_TO_2D_ARRAY.c
*/

#include <stdio.h>
#include <criterion/criterion.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res);
void array_2d_free(int **array, size_t height, size_t width);

Test(array_1d_to_2d_array, convert_array)
{
    int **array_2d = NULL;
    const int array_1d [42] = {
        0, 1, 2, 3, 4, 5,
        6, 7, 8, 9, 10, 11,
        12, 13, 14, 15, 16, 17,
        18, 19, 20, 21, 22, 23,
        24, 25, 26, 27, 28, 29,
        30, 31, 32, 33, 34, 35,
        36, 37, 38, 39, 40, 41
    };

    array_1d_to_2d(array_1d, 7, 6, &array_2d);
    cr_assert_eq(array_2d[0][0], 0);
    cr_assert_eq(array_2d[6][5], 41);
    cr_assert_eq(array_2d[4][4], 28);
    cr_assert_eq(array_2d[0][3], 3);
    cr_assert_eq(array_2d[3][0], 18);
    cr_assert_eq(array_2d[4][2], 26);
    array_2d_free ( array_2d , 7 , 6) ;
}

Test(array_1d_to_2d_array, empty_input)
{
    int **array_2d = NULL;

    array_1d_to_2d(NULL, 7, 6, &array_2d);
}

Test(array_1d_to_2d_array, empty_output)
{
    const int array_1d [42] = {
            0, 1, 2, 3, 4, 5,
            6, 7, 8, 9, 10, 11,
            12, 13, 14, 15, 16, 17,
            18, 19, 20, 21, 22, 23,
            24, 25, 26, 27, 28, 29,
            30, 31, 32, 33, 34, 35,
            36, 37, 38, 39, 40, 41
    };

    array_1d_to_2d(array_1d, 7, 6, NULL);
}
