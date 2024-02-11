/*
** EPITECH PROJECT, 2018
** my_rev_str.c
** File description:
** swap each char of a string
*/

#include "lib.h"

char *my_revstr(char *str)
{
    int i = my_strlen(str) - 1;
    int p = 0;
    char temp = '\0';

    if (!str)
        return (str);
    while (p < i) {
        temp = str[p];
        str[p] = str[i];
        str[i] = temp;
        p++;
        i--;
    }
    return (str);
}