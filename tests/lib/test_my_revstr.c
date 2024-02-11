/*
** EPITECH PROJECT, 2019
** test_my_revstr.c
** File description:
** test the function
*/

#include "lib.h"
#include <criterion/criterion.h>

Test(my_revstr, test_with_null)
{
    char *str = NULL;

    cr_assert(my_revstr(str) == NULL);
}

Test(my_revstr, test_with_string)
{
    char *str = my_strdup("blablou");

    cr_assert_str_eq(my_revstr(str), "uolbalb");
    free(str);
}