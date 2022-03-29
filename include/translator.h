/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** Translation utils header file
*/

#ifndef TRANSLATION_H
    #define TRANSLATION_H

typedef struct lang {
    char *base;
    char *operators;
} lang_t;

char *from_decimal_to_any(char *str, lang_t lang);
char *from_any_to_decimal(char *str, lang_t lang);
int get_index(char *str, char c);

#endif
