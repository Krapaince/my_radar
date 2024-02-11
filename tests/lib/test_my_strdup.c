/*
** EPITECH PROJECT, 2018
** test_my_strdup.c
** File description:
** test the function
*/

#include <criterion/criterion.h>
#include "lib.h"

Test(my_strdup, test_with_null)
{
    char *str = NULL;
    char *res = my_strdup(str);

    cr_assert(res == NULL);
}

Test(my_strdup, test_with_string)
{
    char *str = "tutu";
    char *res = my_strdup(str);

    cr_assert(str != res);
    cr_assert_str_eq(res, str);
}