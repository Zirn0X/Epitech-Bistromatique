/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** Translation utils
*/

#include "utils.h"
#include <stdio.h>
#include "my.h"

typedef struct lang {
    char *base;
    char *operators;
} lang_t;

const lang_t DECIMAL_LANG = {"0123456789", "()+-*/%"};

int get_index(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return i;
    }
    return -1;
}

char *translate(char *str, lang_t from, lang_t to)
{
    int operator_idx = -1;
    int base_id = -1;
    char *result = my_strdup(str);

    for (int i = 0; result[i] != '\0'; i++) {
        base_id = get_index(from.base, result[i]);
        if (base_id != -1) {
            result[i] = to.base[base_id];
            continue;
        }
        operator_idx = get_index(from.operators, result[i]);
        if (operator_idx != -1)
            result[i] = to.operators[operator_idx];
    }
    return result;
}

char *from_decimal_to_any(char *str, char *base, char *operators)
{
    lang_t to = {base, operators};

    return translate(str, DECIMAL_LANG, to);
}

char *from_any_to_decimal(char *str, char *base, char *operators)
{
    lang_t from = {base, operators};

    return translate(str, from, DECIMAL_LANG);
}
