#include <criterion/criterion.h>

char *my_strncpy(char *dest, char const *src, int n);

Test(my_strncpy, hey)
{
    char *global = "Hello";
    char my_dest[15] = {0};
    char dest[15] = {0};

    my_strncpy(my_dest, global, 15);
    strncpy(dest, global, 15);
    cr_assert_str_eq(dest, my_dest);
}
