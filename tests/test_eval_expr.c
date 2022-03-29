#include <criterion/criterion.h>
#include "eval_expr.h"
#include "utils.h"

int divmod;

Test(eval_expr, fifteen)
{
    char calc[] = "15";
    cr_assert_eq(eval_expr(&calc, &divmod), 15);
}

Test(eval_expr, ninety_nine_plus_one)
{
    char calc[] = "99+1";
    cr_assert_eq(eval_expr(&calc, &divmod), 100);
}

Test(eval_expr, forty_two_minus_twenty)
{
    char calc[] = "42-20";
    cr_assert_eq(eval_expr(&calc, &divmod), 22);
}

Test(eval_expr, minus_eighty_for_minus_one_hundred)
{
    char calc[] = "-84-100";
    cr_assert_eq(eval_expr(&calc, &divmod), -184);
}

Test(eval_expr, one_hundred_times_one_hundred)
{
    char calc[] = "100*100";
    cr_assert_eq(eval_expr(&calc, &divmod), 10000);
}

Test(eval_expr, sixty_nine_times_zero)
{
    char calc[] = "69 * 0";
    cr_assert_eq(eval_expr(&calc, &divmod), 0);
}

Test(eval_expr, one_hundred_divided_by_ten)
{
    char calc[] = "100/10";
    cr_assert_eq(eval_expr(&calc, &divmod), 10);
}

Test(eval_expr, sixty_six_modulo_two)
{
    char calc[] = "66%2";
    cr_assert_eq(eval_expr(&calc, &divmod), 0);
}

Test(eval_expr, multi_operator_one)
{
    char calc[] = "42*84/4-56+12";
    cr_assert_eq(eval_expr(&calc, &divmod), 838);
}

Test(eval_expr, multi_operator_two)
{
    char calc[] = "44+56*2/-1";
    char calc1[] = "44+56*2/-1";
    cr_assert_eq(eval_expr(&calc, &divmod), -200);
    cr_assert_neq(eval_expr(&calc1, &divmod), -209329);
}

Test(eval_expr, parentheses_one)
{
    char calc[] = "(5+6)*10";
    cr_assert_eq(eval_expr(&calc, &divmod), 110);
}
Test(eval_expr, parentheses_two)
{
    char calc[] = "(42+69)*32/(9-6)";
    cr_assert_eq(eval_expr(&calc, &divmod), 1184);
}

Test(eval_expr, parentheses_three)
{
    char calc[] = "(69*(1--1))-(69*2)+1";
    cr_assert_eq(eval_expr(&calc, &divmod), 1);
}
