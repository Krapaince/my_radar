/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** give the length of a string
*/

#include "lib.h"

int my_strlen(char const *str)
{
    int i = 0;

    if (str) {
        while (str[i])
            i++;
    }
    return (i);
}