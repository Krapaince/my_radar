/*
** EPITECH PROJECT, 2018
** test_my_getnbr.c
** File description:
** test the function
*/

#include "lib.h"
#include <criterion/criterion.h>

Test(my_getnbr, test_with_pos)
{
    char *str = "45625";

    cr_assert(my_getnbr(str) == 45625);
}

Test(my_getnbr, test_with_neg)
{
    char *str = "---45352";

    cr_assert(my_getnbr(str) == -45352);
}

Test(my_getnbr, test_with_null_string)
{
    char *str = NULL;

    cr_assert(my_getnbr(str) == 0);
}

Test(my_getnbr, test_with_bad_string)
{
    char *str = "asdq-34";

    cr_assert(my_getnbr(str) == 0);
}

Test(my_getnbr, test_with_lim_pos)
{
    char *str = "2147483647";

    cr_assert(my_getnbr(str) == 2147483647);
}

Test(my_getnbr, test_with_lim_pos_plus_one)
{
    char *str = "2147483648";

    cr_assert(my_getnbr(str) == 0);
}

Test(my_getnbr, test_with_lim_neg)
{
    char *str = "-2147483648";

    cr_assert(my_getnbr(str) == -2147483648);
}