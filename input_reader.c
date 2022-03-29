/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** Input reader file
*/

#include <stdlib.h>
#include <unistd.h>

char *read_input(int read_size)
{
    char *buffer = malloc(sizeof(char) * (read_size + 1));

    read(0, buffer, read_size);
    buffer[read_size] = '\0';

    return buffer;
}
