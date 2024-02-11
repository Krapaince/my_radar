/*
** EPITECH PROJECT, 2018
** test_my_strcpy.c
** File description:
** test the function
*/

#include "lib.h"
#include <criterion/criterion.h>

Test(my_strcpy, test_with_two_string)
{
    char *s1 = malloc(sizeof(char) * 8);
    char *s2 = "tutu";

    cr_assert(s1 != NULL);
    s1 = my_strcpy(s1, s2);
    cr_assert_str_eq(s1, "tutu");
    free(s1);
}

Test(my_strcpy, test_with_two_empty_string)
{
    char *s1 = malloc(sizeof(char) * 8);
    char *s2 = "";

    cr_assert(s1 != NULL);
    s1 = my_strcpy(s1, s2);
    cr_assert_str_eq(s1, "");
    free(s1);
}