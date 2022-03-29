/*
** EPITECH PROJECT, 2021
** tests
** File description:
** testing functions
*/

#include "my.h"
#include <criterion/criterion.h>
#include "check_args.h"

Test(check_base, test1)
{
    cr_assert_eq(check_base("0123456789"), 1);
}

Test(check_base, test2)
{
    cr_assert_eq(check_base("01345678956789"), 0);
}

Test(check_base, test3)
{
    cr_assert_eq(check_base("12"), 0);
}

Test(check_operators, test1)
{
    cr_assert_eq(check_operators("*+/-%()"), 1);
}

Test(check_operators, test2)
{
    cr_assert_eq(check_operators("--/%*()234"), 0);
}

Test(check_operators, test3)
{
    cr_assert_eq(check_operators("+-"), 0);
}

Test(check_size_read, test1)
{
    cr_assert_eq(check_size_read("+-==è('"), 0);
}

Test(check_size_read, test2)
{
    cr_assert_eq(check_size_read("12345"), 1);
}

Test(check_size_read, test3)
{
    cr_assert_eq(check_size_read("989"), 1);
}

Test(check_size_read, test4)
{
    cr_assert_not(check_size_read(":ajdzojd964121."));
}

Test(check_lang_params_common_chars, test1)
{
    cr_assert(check_lang_params_common_chars("0123456789", "()+-*/%"));
}

Test(check_lang_params_common_chars, test2)
{
    cr_assert_not(check_lang_params_common_chars("0123456789", "()1-*/%"));
}
