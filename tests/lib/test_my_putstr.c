/*
** EPITECH PROJECT, 2018
** test_my_putstr.c
** File description:
** test the function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lib.h"

Test(my_putstr, test_with_empty_string)
{
    cr_redirect_stdout();
    my_putstr("", STDOUT_FILENO);
    cr_assert_stdout_eq_str("");
}

Test(my_putstr, test_with_string)
{
    cr_redirect_stdout();
    my_putstr("vroumtutu", STDOUT_FILENO);
    cr_assert_stdout_eq_str("vroumtutu");
}