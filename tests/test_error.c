#include <criterion/criterion.h>
#include "error.h"

Test(print_error, error_message)
{
    print_error();
}

Test(print_syntax_error, syntax_error_message)
{
    print_syntax_error();
}

Test(print_error, usage_message)
{
    print_usage();
}
