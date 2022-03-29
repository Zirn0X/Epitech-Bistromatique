/*
** EPITECH PROJECT, 2021
** EvalExpr
** File description:
** Project's entrypoint
*/

#include "my.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

int eval_expr(char const *str, int *divmod_by_zero);

int eval_par_expr(char **str_ptr, int *divmod_by_zero)
{
    char *calc = malloc(sizeof(char) * (my_strlen(*str_ptr) + 1));
    int i = 0;

    for (int parentheses = 0; **str_ptr != '\0';) {
        if (**str_ptr == '(' && !parentheses) {
            parentheses++;
            (*str_ptr)++;
            continue;
        }
        if (**str_ptr == ')' && parentheses == 1) {
            (*str_ptr)++;
            break;
        }
        parentheses += (**str_ptr == '(') - (**str_ptr == ')');
        calc[i] = **str_ptr;
        (*str_ptr)++;
        i++;
    }
    calc[i] = '\0';
    return eval_expr(calc, divmod_by_zero);
}

int get_sign(int negative, char current)
{
    if (current == '-') {
        return !negative;
    } else if (current == '+') {
        return FALSE;
    } else {
        return negative;
    }
}

int number(char **str_ptr)
{
    int result = 0;
    int negative = FALSE;

    for (int found = FALSE; **str_ptr != '\0'; (*str_ptr)++) {
        if (**str_ptr == ' ')
            continue;
        if (**str_ptr >= '0' && **str_ptr <= '9') {
            result = (result * 10) + ATOD(**str_ptr);
            found = TRUE;
            continue;
        }
        if ((**str_ptr == '-' || **str_ptr == '+' || **str_ptr == '*' || \
             **str_ptr == '/' || **str_ptr == '%') && !found)
            negative = get_sign(negative, **str_ptr);
        else
            break;
    }
    return negative ? -result : result;
}

int operations(int result, int next_value, char operator, int *divmod_by_zero)
{
    if (next_value == 0 && (operator == '/' || operator == '%')) {
        *divmod_by_zero = TRUE;
        return 0;
    }
    if (operator == '+' || operator == '-')
        result += next_value;
    if (operator == '*')
        result *= next_value;
    if (operator == '/')
        result /= next_value;
    if (operator == '%')
        result %= next_value;
    if (operator != '+' && operator != '-' && operator != '*'\
        && operator != '/' && operator != '%')
        result = next_value;
    return result;
}

int eval_expr(char const *str, int *divmod_by_zero)
{
    char *calc = my_strdup(str);
    int result = number(&calc);
    int next_value;

    for (char operator; my_strlen(calc) > 0;) {
        operator = calc[0];
        if (operator == '(' || calc[1] == '(')
            next_value = eval_par_expr(&calc, divmod_by_zero);
        else
            next_value = number(&calc);
        result = operations(result, next_value, operator, divmod_by_zero);
        if (*divmod_by_zero)
            break;
    }
    return result;
}
