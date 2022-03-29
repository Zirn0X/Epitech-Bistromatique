#include <criterion/criterion.h>
#include "numbers.h"
#include <stdlib.h>

Test(compare_numbers, all)
{
    cr_assert_eq(compare_numbers("1", "0"), 1);
    cr_assert_eq(compare_numbers("15", "0"), 1);
    cr_assert_eq(compare_numbers("199999", "099999"), 1);
    cr_assert_eq(compare_numbers("199999", "99999"), 1);

    cr_assert_eq(compare_numbers("123456789", "123456789"), 0, "out:%d\n", compare_numbers("123456789", "123456789"));
    
    cr_assert_eq(compare_numbers("0", "1"), -1);
    cr_assert_eq(compare_numbers("0", "15"), -1);
    cr_assert_eq(compare_numbers("199099", "199999"), -1);
    cr_assert_eq(compare_numbers("99999", "199999"), -1);
    cr_assert_eq(compare_numbers("67", "13"), 1);
    cr_assert_eq(compare_numbers("36","41"), -1);
}

Test(fill_with_zeros, all)
{
    char *number = malloc(sizeof(char) * 8);

    fill_with_zeros(number, 8);

    cr_assert_str_eq(number, "00000000");
}

Test(remove_trailling_zeros, all)
{
    cr_assert_str_eq(remove_trailing_zeros("154896"), "154896");
    cr_assert_str_eq(remove_trailing_zeros("000000000154896"), "154896");
    cr_assert_str_eq(remove_trailing_zeros("15489600"), "15489600");
    cr_assert_str_eq(remove_trailing_zeros("000000"), "0");
    cr_assert_str_eq(remove_trailing_zeros("0"), "0");
}