/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** Utils to check the expression
*/

#include "utils.h"
#include "my.h"
#include "translator.h"
#include "check_args.h"

int check_expression_parentheses(char *expression)
{
    int parentheses = 0;
    int i = 0;

    while (expression[i] != '\0') {
        if (expression[i] == '(') {
            parentheses++;
        }
        if (expression[i] == ')') {
            parentheses--;
        }
        i++;
    }
    return (!parentheses);
}

int check_expression_chars(char *expression, lang_t lang)
{
    for (int i = 0; expression[i] != '\0'; i++) {
        if (get_index(lang.base, expression[i]) != -1)
            continue;
        if (get_index(lang.operators, expression[i]) != -1)
            continue;
        return FALSE;
    }

    return TRUE;
}
