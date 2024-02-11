/*
** EPITECH PROJECT, 2018
** my_putnbr
** File description:
** show a number store in an int
*/

#include "lib.h"

void my_putnbr(int nb, int std)
{
    if (nb < 0) {
        if (nb == -2147483648) {
            my_putchar('-', std);
            my_putchar('2', std);
            my_putnbr(147483648, std);
        } else {
            my_putchar('-', std);
            my_putnbr(-nb, std);
        }
    } else {
        if (nb > 9)
            my_putnbr(nb / 10, std);
        my_putchar(nb % 10 + 48, std);
    }
}