/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** print a char
*/

#include "lib.h"

void my_putchar(char c, int std)
{
    write(std, &c, 1);
}