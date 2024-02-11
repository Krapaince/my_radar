/*
** EPITECH PROJECT, 2018
** my_strcpy.c
** File description:
** copy string a to b
*/

#include "lib.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}