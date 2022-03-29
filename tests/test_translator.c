#include <criterion/criterion.h>
#include "translator.h"

Test(translator, to_decimal)
{
    lang_t lang = { .base = "abcdefghij", .operators = "()+-*/%"};
    cr_assert_str_eq(from_any_to_decimal("fj-bca+ji", lang), "59-120+98");
    lang = (lang_t) { .base = "abcdefghij", .operators = "Xp$o&8*"};
    cr_assert_str_eq(from_any_to_decimal("fjobca$ji", lang), "59-120+98");
    lang = (lang_t) { .base = "0123456789", .operators = "pr#*=!,"};
    cr_assert_str_eq(from_any_to_decimal("59*120#98a", lang), "59-120+98a");
}

Test(translator, to_any)
{
    lang_t lang = { .base = "abcdefghij", .operators = "()+-*/%"};
    cr_assert_str_eq(from_decimal_to_any("59-120+98", lang), "fj-bca+ji");
    lang = (lang_t) { .base = "abcdefghij", .operators = "Xp$o&8*"};
    cr_assert_str_eq(from_decimal_to_any("59-120+98", lang), "fjobca$ji");
    lang = (lang_t) { .base = "0123456789", .operators = "pr#*=!,"};
    cr_assert_str_eq(from_decimal_to_any("59-120+98", lang), "59*120#98");
}
