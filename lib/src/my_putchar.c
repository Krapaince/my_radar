/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** print a char
*/

#include "lib.h"

void my_putchar(char c, int std)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
    write(std, &c, 1);
#pragma GCC diagnostic pop
}