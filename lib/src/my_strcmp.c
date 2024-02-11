/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** compare the char of two string
*/

#include "lib.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && (s1[i] || s2[i]))
        i++;
    if (s1[i] - s2[i] > 0)
        return (1);
    else if (s1[i] - s2[i] < 0)
        return (-1);
    return (0);
}