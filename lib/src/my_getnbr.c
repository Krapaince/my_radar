/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** Like atoi but the file is name my_getnbr
*/

#include "lib.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int sign = 1;
    long check = 0;

    if (!str)
        return (0);
    while (str[i] == '-' || str[i]  == '+') {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while ('0' <= str[i] && str[i] <= '9') {
        check = check * 10 + str[i] - 48;
        if (check * sign < INT_MIN || INT_MAX < check * sign)
            return (0);
        nb = (int)check;
        i++;
    }
    return (nb * sign);
}