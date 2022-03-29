/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** Utils to check integrity of passed argv's
*/

#include "my.h"
#include "bistromatic.h"
#include "utils.h"
#include <stdlib.h>

int contain_only_unique_chars(char *str)
{
    int times_found = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = i + 1; str[j] != '\0'; j++)
            times_found += str[i] == str[j];
        if (times_found > 0)
            return FALSE;
    }
    return TRUE;
}

int check_operators(char *operators)
{
    if (!contain_only_unique_chars(operators))
        return FALSE;
    if (my_strlen(operators) != 7)
        return FALSE;
    return TRUE;
}

int check_base(char *base)
{
    if (!contain_only_unique_chars(base))
        return FALSE;
    if (my_strlen(base) != 10)
        return FALSE;
    return TRUE;
}

int check_size_read(char *size)
{
    int i = 0;

    while (size[i] != '\0') {
        if (size[i] < '0' || size[i] > '9')
            return FALSE;
        i++;
    }
    return TRUE;
}

int check_lang_params_common_chars(char *base, char *operators)
{
    char *combined = malloc(my_strlen(base) + my_strlen(operators) + 1);

    my_strcat(combined, base);
    my_strcat(combined, operators);

    return contain_only_unique_chars(combined);
}
