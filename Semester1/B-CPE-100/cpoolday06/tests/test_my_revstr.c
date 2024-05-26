#include <criterion/criterion.h>

char *my_revstr(char *str);

Test(my_revstr, hey)
{
    char my_dest[6] = "Hello";
    char dest[6] = "olleH";

    my_revstr(my_dest);
    cr_assert_str_eq(dest, my_dest);
}
