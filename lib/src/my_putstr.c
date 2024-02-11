/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** display a string
*/

#include "lib.h"

void my_putstr(char const *str, int std)
{
    int i = 0;

    if (str) {
        while (str[i]) {
            my_putchar(str[i], std);
            i++;
        }
    }
}