/*
** EPITECH PROJECT, 2018
** test_merge_str.c
** File description:
** test the function
*/

#include "lib.h"
#include <criterion/criterion.h>

Test(merge_str, test_with_two_string)
{
    char *s1 = my_strdup("tutu");
    char *s2 = my_strdup("tata");

    cr_assert(merge_str(&s1, s2) == 0);
    cr_assert_str_eq(s2, "tata");
    cr_assert_str_eq(s1, "tututata");
    free(s1);
    free(s2);
}

Test(merge_str, test_with_first_null_string)
{
    char *s1 = NULL;
    char *s2 = my_strdup("tata");

    cr_assert(merge_str(&s1, s2) == 0);
    cr_assert_str_eq(s2, "tata");
    cr_assert_str_eq(s1, "tata");
    free(s2);
    free(s1);
}

Test(merge_str, test_with_second_null_string)
{
    char *s1 = my_strdup("titi");
    char *s2 = NULL;

    cr_assert(merge_str(&s1, s2) == 0);
    cr_assert(s2 == NULL);
    cr_assert_str_eq(s1, "titi");
    free(s1);
}

Test(merge_str, test_with_to_null_string)
{
    char *s1 = NULL;
    char *s2 = NULL;

    cr_assert(merge_str(&s1, s2) == 1);
    cr_assert(s2 == NULL);
    cr_assert(s1 == NULL);
}