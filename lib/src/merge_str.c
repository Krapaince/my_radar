/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** get the next line
*/

#include "lib.h"

int merge_str(char **s1, char *s2)
{
    char *temp = *s1;
    char *res = NULL;
    int len_s1 = my_strlen(*s1);
    int len_s2 = my_strlen(s2);

    if (!(*s1) && !s2)
        return (1);
    res = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
    if (!res)
        return (1);
    if (temp) {
        res = my_strcat(res, temp);
        free(temp);
    }
    if (s2)
        res = my_strcat(res, s2);
    *s1 = res;
    return (0);
}