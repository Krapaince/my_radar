/*
** EPITECH PROJECT, 2019
** test_error_entities.c
** File description:
** test the function
*/

#include "lib.h"
#include "struct.h"
#include "script.h"
#include "error.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(len_nb, test_with_pos_number)
{
    int nb = 4038;

    cr_assert(len_nb(nb) == 4);
}

Test(check_aircraft_param, test_with_neg_x0)
{
    char *buffer = "A -1920 1080 30 30 5 0";
    int n = 0;
    int i = 1;

    cr_redirect_stderr();
    cr_assert(check_aircraft_param(buffer, &i, &n) == 84);
    cr_assert_stderr_eq_str(E_SCRIPT_PARAM);
}

Test(check_aircraft_param, test_with_over_x0)
{
    char *buffer = "A 1921 1080 30 30 5 0";
    int n = 0;
    int i = 1;

    cr_redirect_stderr();
    cr_assert(check_aircraft_param(buffer, &i, &n) == 84);
    cr_assert_stderr_eq_str(E_SCRIPT_PARAM);
}

Test(check_aircraft_param, test_with_neg_y0)
{
    char *buffer = "A 3 -1080 30 30 5 0";
    int n = 1;
    int i = 3;

    cr_redirect_stderr();
    cr_assert(check_aircraft_param(buffer, &i, &n) == 84);
    cr_assert_stderr_eq_str(E_SCRIPT_PARAM);
}

Test(check_aircraft_param, test_with_over_y0)
{
    char *buffer = "A 3 1081 30 30 5 0";
    int n = 1;
    int i = 3;

    cr_redirect_stderr();
    cr_assert(check_aircraft_param(buffer, &i, &n) == 84);
    cr_assert_stderr_eq_str(E_SCRIPT_PARAM);
}

Test(check_aircraft_param, test_with_neg_x1)
{
    char *buffer = "A 3 2 -1 5 0";
    int n = 2;
    int i = 5;

    cr_redirect_stderr();
    cr_assert(check_aircraft_param(buffer, &i, &n) == 84);
    cr_assert_stderr_eq_str(E_SCRIPT_PARAM);
}

Test(check_aircraft_param, test_with_over_x1)
{
    char *buffer = "A 3 2 1921 5 0";
    int n = 2;
    int i = 5;

    cr_redirect_stderr();
    cr_assert(check_aircraft_param(buffer, &i, &n) == 84);
    cr_assert_stderr_eq_str(E_SCRIPT_PARAM);
}

Test(check_aircraft_param, test_with_neg_y1)
{
    char *buffer = "A 3 2 4 -1 3 5";
    int n = 3;
    int i = 7;

    cr_redirect_stderr();
    cr_assert(check_aircraft_param(buffer, &i, &n) == 84);
    cr_assert_stderr_eq_str(E_SCRIPT_PARAM);
}

Test(check_aircraft_param, test_with_over_y1)
{
    char *buffer = "A 3 2 4 1081 3 5";
    int n = 3;
    int i = 7;

    cr_redirect_stderr();
    cr_assert(check_aircraft_param(buffer, &i, &n) == 84);
    cr_assert_stderr_eq_str(E_SCRIPT_PARAM);
}

Test(check_aircraft_param, test_with_neg_speed)
{
    char *buffer = "A 3 2 4 1 -1 3";
    int n = 4;
    int i = 9;

    cr_redirect_stderr();
    cr_assert(check_aircraft_param(buffer, &i, &n) == 84);
    cr_assert_stderr_eq_str(E_SCRIPT_PARAM);
}

Test(check_aircraft_param, test_with_neg_delta)
{
    char *buffer = "A 3 2 4 1 2 -1";
    int n = 5;
    int i = 11;

    cr_redirect_stderr();
    cr_assert(check_aircraft_param(buffer, &i, &n) == 84);
    cr_assert_stderr_eq_str(E_SCRIPT_PARAM);
}

Test(check_aircraft, test_with_good_param)
{
    char *buffer = "A 1920 1080 0 0 1 0";

    cr_assert(check_aircraft(buffer) == 0);
}

Test(check_aircraft, test_with_missing_info_len)
{
    char *buffer = "A 3 4 2";

    cr_redirect_stderr();
    cr_assert(check_aircraft(buffer) == 84);
    cr_assert_stderr_eq_str(E_SCRIPT_MISS);
}

Test(check_tower_param, test_with_neg_x)
{
    char *buffer = "T -3 4 2";
    int i = 1;
    int n = 0;

    cr_redirect_stderr();
    cr_assert(check_tower_param(buffer, &i, &n) == 84);
    cr_assert_stderr_eq_str(E_SCRIPT_PARAM);
}

Test(check_tower_param, test_with_over_x)
{
    char *buffer = "T 1921 4 2";
    int i = 1;
    int n = 0;

    cr_redirect_stderr();
    cr_assert(check_tower_param(buffer, &i, &n) == 84);
    cr_assert_stderr_eq_str(E_SCRIPT_PARAM);
}

Test(check_tower_param, test_with_neg_y)
{
    char *buffer = "T 3 -4 2";
    int i = 3;
    int n = 1;

    cr_redirect_stderr();
    cr_assert(check_tower_param(buffer, &i, &n) == 84);
    cr_assert_stderr_eq_str(E_SCRIPT_PARAM);
}

Test(check_tower_param, test_with_over_y)
{
    char *buffer = "T 3 1081 2";
    int i = 3;
    int n = 1;

    cr_redirect_stderr();
    cr_assert(check_tower_param(buffer, &i, &n) == 84);
    cr_assert_stderr_eq_str(E_SCRIPT_PARAM);
}

Test(check_tower_param, test_with_neg_radius)
{
    char *buffer = "T 3 2 -3";
    int i = 5;
    int n = 2;

    cr_redirect_stderr();
    cr_assert(check_tower_param(buffer, &i, &n) == 84);
    cr_assert_stderr_eq_str(E_SCRIPT_PARAM);
}

Test(check_tower_param, test_with_over_radius)
{
    char *buffer = "T 3 2 101";
    int i = 5;
    int n = 2;

    cr_redirect_stderr();
    cr_assert(check_tower_param(buffer, &i, &n) == 84);
    cr_assert_stderr_eq_str(E_SCRIPT_PARAM);
}

Test(check_tower, test_with_good_tower_param)
{
    char *buffer = "T 35 23 30";

    cr_assert(check_tower(buffer) == 0);
}

Test(check_tower, test_with_tower_miss_param)
{
    char *buffer = "T 54 23";

    cr_redirect_stderr();
    cr_assert(check_tower(buffer) == 84);
    cr_assert_stderr_eq_str(E_SCRIPT_MISS);
}