/*
** EPITECH PROJECT, 2018
** test_my_strcmp.c
** File description:
** test the function
*/

#include "lib.h"
#include <criterion/criterion.h>

Test(my_strcmp, test_with_empty_string)
{
    char *s1 = "";
    char *s2 = "tutu";

    cr_assert(my_strcmp(s1, s2) == -1);
}

Test(my_strcmp, test_with_two_empty_string)
{
    char *s1 = "";
    char *s2 = "";

    cr_assert(my_strcmp(s1, s2) == 0);
}

Test(my_strcmp, test_with_two_string_pos)
{
    char *s1 = "bobo";
    char *s2 = "bibi";

    cr_assert(my_strcmp(s1, s2) == 1);
}

Test(my_strcmp, test_with_two_string_neg)
{
    char *s1 = "bibo";
    char *s2 = "bobi";

    cr_assert(my_strcmp(s1, s2) == -1);
}