/*
** EPITECH PROJECT, 2018
** test_my_putchar.c
** File description:
** test the function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lib.h"

Test(my_putchar, test_with_num)
{
    char c = '0';

    cr_redirect_stdout();
    while (c < '9' + 1) {
        my_putchar(c, STDOUT_FILENO);
        ++c;
    }
    cr_assert_stdout_eq_str("0123456789");
}

Test(my_putchar, test_with_alpha)
{
    char c = 'a';

    cr_redirect_stdout();
    while (c < 'z' + 1) {
        my_putchar(c, STDOUT_FILENO);
        ++c;
    }
    cr_assert_stdout_eq_str("abcdefghijklmnopqrstuvwxyz");
}