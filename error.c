/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** Error's file
*/

#include "bistromatic.h"
#include "my.h"


int print_error(void)
{
    my_putstr(ERROR_MSG);

    return 84;
}

int print_syntax_error(void)
{
    my_putstr(SYNTAX_ERROR_MSG);

    return 84;
}

int print_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("./calc base operators size_read\n");
    my_putstr("\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("- base: all the symbols of the base\n");
    my_putstr("- operators: all the symbols for the");
    my_putstr("parentheses and the 5 operators\n");
    my_putstr("- size_read: number of characters to be read\n");
    return 0;
}
