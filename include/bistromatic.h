/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** Project's utils file
*/

#include "translator.h"

#ifndef BISTROMATIC_H
    #define BISTROMATIC_H

    #define SYNTAX_ERROR_MSG "syntax error"
    #define ERROR_MSG        "error"

int calc(int argc, char **argv, char *expression);
int check_args(char *base, char *operators, char *size_read);
int check_expression(char *expression, lang_t lang);
int handle_flag(char const *flag);
char *my_itoa(int number);

#endif
