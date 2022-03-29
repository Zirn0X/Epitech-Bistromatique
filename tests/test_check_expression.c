#include <criterion/criterion.h>
#include "check_expression.h"
#include "translator.h"

Test(check_expression_parentheses, equals_parentheses)
{
    char expression[] = "(5+4)";
    cr_assert_eq(check_expression_parentheses(expression), 1);
}

Test(check_expression_parentheses, not_equals_parentheses)
{
    char expression[] = "((5+4)";
    cr_assert_eq(check_expression_parentheses(expression), 0);
}

Test(check_expression_parentheses, not_equals_parentheses1)
{
    char expression[] = "(5+4))";
    cr_assert_eq(check_expression_parentheses(expression), 0);
}

Test(check_expression_chars, regular)
{
    lang_t custom;
    
    custom.base = "apourity+_#";
    custom.operators = ")(=-*/%";
    
    cr_assert(check_expression_chars("a+=rity", custom));
    cr_assert_not(check_expression_chars("15+9", custom));
}
