/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** Project's entrypoint
*/

#include "translator.h"
#include "eval_expr.h"
#include "my.h"
#include "bistromatic.h"
#include "check_args.h"
#include "error.h"
#include "utils.h"
#include "check_expression.h"
#include <stdlib.h>
#include <stdio.h>

int check_args(char *base, char *operators, char *size_read)
{
    if (!check_base(base)) {
        print_syntax_error();
        return FALSE;
    }
    if (!check_operators(operators)) {
        print_syntax_error();
        return FALSE;
    }
    if (!check_size_read(size_read)) {
        print_syntax_error();
        return FALSE;
    }
    if (!check_lang_params_common_chars(base, operators)) {
        print_syntax_error();
        return FALSE;
    }
    return TRUE;
}

int check_expr(char *expression, lang_t lang)
{
    if (!check_expression_parentheses(expression)) {
        print_syntax_error();
        return FALSE;
    }

    if (!check_expression_chars(expression, lang)) {
        print_syntax_error();
        return FALSE;
    }

    if (my_strlen(expression) == 0) {
        print_syntax_error();
        return FALSE;
    }

    return TRUE;
}

int handle_flag(char const *flag)
{
    if (flag[0] == '-' && flag[1] == 'h') {
        print_usage();
    } else {
        print_syntax_error();
        return 84;
    }
    return 0;
}

char *my_itoa(int number)
{
    int digits = get_digits(number);
    char *result = malloc(sizeof(char) * (digits + 2));
    int i = 0;
    int negative = number < 0;

    if (negative)
        number *= -1;
    while (i < digits) {
        result[i++] = DTOA(number % 10);
        number /= 10;
    }
    if (negative) {
        result[i++] = '-';
        result[i] = '\0';
    }
    else
        result[i] = '\0';
    my_revstr(result);
    return result;
}

int calc(int argc, char **argv, char *expr)
{
    lang_t lang;
    int inter;
    int divmod_by_zero = FALSE;

    if (argc == 4) {
        lang.base = argv[1];
        lang.operators = argv[2];
        if (!check_args(argv[1], argv[2], argv[3]) || !check_expr(expr, lang))
            return 84;
        inter = eval_expr(from_any_to_decimal(expr, lang), &divmod_by_zero);
        if (divmod_by_zero)
            return print_syntax_error();
        my_putstr(from_decimal_to_any(my_itoa(inter), lang));
    } else if (argc == 2)
        return handle_flag(argv[1]);
    else
        return print_syntax_error();
    return 0;
}
