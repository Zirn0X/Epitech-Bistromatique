/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** Project's main file
*/

#include <bistromatic.h>
#include <input_reader.h>
#include <my.h>

int main(int argc, char **argv)
{
    char *expression;
    if (argc != 4 || my_getnbr(argv[3]) == 0 || my_getnbr(argv[3]) < 0)
        expression = "";
    else
        expression = read_input(my_getnbr(argv[3]));

    return calc(argc, argv, expression);
}
