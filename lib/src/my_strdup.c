/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** duplicate a string an alloaw to write on it
*/

#include "lib.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src) + 1;
    char *dest;

    if (!(dest = malloc(sizeof(*dest) * (len))))
        return (NULL);
    my_strcpy(dest, src);
    return (dest);
}