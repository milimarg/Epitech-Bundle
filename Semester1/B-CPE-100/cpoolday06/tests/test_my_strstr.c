#include </home/florentguittre/Criterion/include/criterion/criterion.h>

char *my_strstr(char *str, char const *to_find);

Test(my_strstr, hey)
{
    char *global = "Hello";
    char my_dest[15] = {0};
    char dest[15] = {0};

    my_strncpy(my_dest, global, 15);
    strncpy(dest, global, 15);
    cr_assert_str_eq(dest, my_dest);
}
