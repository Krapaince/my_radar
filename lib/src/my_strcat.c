/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** concat two string
*/

#include "lib.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i])
        i++;
    dest[i] = src[j];
    while (src[j])
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}