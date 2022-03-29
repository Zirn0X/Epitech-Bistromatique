#include <criterion/criterion.h>
#include "bistromatic.h"
#include "translator.h"

Test(check_args, all)
{
    cr_assert(check_args("0123456789", "()+-*/%", "15"));

    cr_assert_not(check_args("0123456789a", "()+-*/%", "15"));
    cr_assert_not(check_args("9123456789", "()+-*/%", "15"));
    cr_assert_not(check_args("0123456789", "()+-*/%a", "15"));
    cr_assert_not(check_args("0123456789", "()++*/%", "15"));
    cr_assert_not(check_args("012345*789", "()+-*/%", "15"));
    cr_assert_not(check_args("0123456789", "()+-*/%", "adzjq15"));
}

Test(check_expr, all)
{
    lang_t lang;
    lang.base = "0123456789";
    lang.operators = "()+-*/%";

    cr_assert(check_expr("(5+5)*8/2%20-2", lang));

    cr_assert_not(check_expr("(5+5)*8/2%20-2)", lang));
    cr_assert_not(check_expr("(5+5)*8/2%20-2a", lang));
}

Test(my_itoa, all)
{
    cr_assert_str_eq(my_itoa(0), "0");
    cr_assert_str_eq(my_itoa(1), "1");
    cr_assert_str_eq(my_itoa(10), "10");
    cr_assert_str_eq(my_itoa(17), "17");
    cr_assert_str_eq(my_itoa(69), "69");
    cr_assert_str_eq(my_itoa(420), "420");
    cr_assert_str_eq(my_itoa(324568), "324568");
    cr_assert_str_eq(my_itoa(25863254), "25863254");
    cr_assert_str_eq(my_itoa(-2586324), "-2586324");
}

Test(calc, all)
{
    char *regular_args[] = {"./calc", "0123456789", "()+-*/%", "15"};
    char *usage[] = {"./calc", "-h"};
    char *not_enough_args[] = {"./calc"};
    char *bad_args[] = {"./calc", "0", "0", "15"};

    char *regular_expression = "(42+69)*5/2%4-8";
    char *unmatched_par_expression = "(45+89))";
    char *unrecognized_char = "45a+78";
    char *div_by_zero = "5/0";
    char *mod_by_zero = "15%0";

    cr_assert_eq(calc(4, regular_args, regular_expression), 0);
    cr_assert_eq(calc(2, usage, regular_expression), 0);
    cr_assert_eq(calc(1, not_enough_args, regular_expression), 84);
    cr_assert_eq(calc(1, bad_args, regular_expression), 84);

    cr_assert_eq(calc(4, regular_args, unmatched_par_expression), 84);
    cr_assert_eq(calc(4, regular_args, unrecognized_char), 84);
    cr_assert_eq(calc(4, regular_args, div_by_zero), 84);
    cr_assert_eq(calc(4, regular_args, mod_by_zero), 84);
}

Test(others, all)
{
    cr_assert_eq(handle_flag("-h"), 0);
    cr_assert_eq(handle_flag("test"), 84);
}