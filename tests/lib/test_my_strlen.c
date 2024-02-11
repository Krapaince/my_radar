/*
** EPITECH PROJECT, 2018
** test_my_strlen.c
** File description:
** test the function
*/

#include "lib.h"
#include <criterion/criterion.h>

Test(my_strlen, test_with_string)
{
    char *str = "tututu";

    cr_assert(my_strlen(str) == 6);
}

Test(my_strlen, test_with_empty_string)
{
    char *str = "";

    cr_assert(my_strlen(str) == 0);
}

Test(my_strlen, test_with_null_string)
{
    char *str = NULL;

    cr_assert(my_strlen(str) == 0);
}