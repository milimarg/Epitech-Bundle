#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_cat(char *file);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
}

Test(errors, exit_code, .init=redirect_all_stdout)
{
    char *dest = "Hello everybody\n";

    my_cat("test");
    cr_assert_stdout_eq_str(dest, "");
}
