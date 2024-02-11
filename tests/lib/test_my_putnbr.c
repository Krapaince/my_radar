/*
** EPITECH PROJECT, 2018
** test_my_putnbr.c
** File description:
** test the function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lib.h"

Test(my_putnbr, test_with_lim_neg)
{
    cr_redirect_stdout();
    my_putnbr(-2147483648, STDOUT_FILENO);
    cr_assert_stdout_eq_str("-2147483648");
}

Test(my_putnbr, test_with_neg)
{
    cr_redirect_stdout();
    my_putnbr(-34, STDOUT_FILENO);
    cr_assert_stdout_eq_str("-34");
}

Test(my_putnbr, test_with_lim_pos)
{
    cr_redirect_stdout();
    my_putnbr(2147483647, STDOUT_FILENO);
    cr_assert_stdout_eq_str("2147483647");
}

Test(my_putnbr, test_with_random_nbr)
{
    cr_redirect_stdout();
    my_putnbr(24631, STDOUT_FILENO);
    cr_assert_stdout_eq_str("24631");
}