/*
** EPITECH PROJECT, 2018
** test_my_strcat.c
** File description:
** test the function
*/

#include "lib.h"
#include <criterion/criterion.h>

Test(my_strcat, test_with_two_string)
{
    char *dest = malloc(sizeof(char) * 10);
    char *src = "tutu";

    cr_assert(dest != NULL);
    dest = my_strcpy(dest, "tata");
    dest = my_strcat(dest, src);
    cr_assert_str_eq(dest, "tatatutu");
}

Test(my_strcat, test_with_first_empty_string)
{
    char *dest = malloc(sizeof(char) * 10);
    char *src = "";

    cr_assert(dest != NULL);
    dest = my_strcpy(dest, "tata");
    dest = my_strcat(dest, src);
    cr_assert_str_eq(dest, "tata");
}

Test(my_strcat, test_with_second_empty_string)
{
    char *dest = malloc(sizeof(char) * 10);
    char *src = "";

    cr_assert(dest != NULL);
    dest = my_strcpy(dest, "tata");
    dest = my_strcat(dest, src);
    cr_assert_str_eq(dest, "tata");
}

Test(my_strcat, test_with_two_empty_string)
{
    char *dest = malloc(sizeof(char) * 10);
    char *src = "";

    cr_assert(dest != NULL);
    dest = my_strcpy(dest, "");
    dest = my_strcat(dest, src);
    cr_assert_str_eq(dest, "");
}