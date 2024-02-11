/*
** EPITECH PROJECT, 2019
** test_error.c
** File description:
** test the function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "struct.h"
#include "script.h"
#include "lib.h"
#include "error.h"

Test(aircraft_after_tower, test_with_aircraft_after_tower)
{
    char *buffer = "A";
    int atot = 1;

    cr_redirect_stderr();
    cr_assert(aircraft_after_tower(buffer, &atot) == 84);
    cr_assert_stderr_eq_str(E_SCRIPT_ATA);
}

Test(aircraft_after_tower, test_when_go_to_tower)
{
    char *buffer = "T";
    int atot = 0;

    cr_assert(aircraft_after_tower(buffer, &atot) == 0);
    cr_assert(atot == 1);
}

Test(aircraft_after_tower, test_with_airplne_phase)
{
    char *buffer = "A";
    int atot = 0;

    cr_assert(aircraft_after_tower(buffer, &atot) == 0);
    cr_assert(atot == 0);
}

Test(check_line, test_with_good_aircraft)
{
    char *buffer = "A 3 2 5 2 4 5";
    int atot = 0;

    cr_assert(check_line(buffer, &atot) == 0);
}

Test(check_line, test_with_bad_aircraft)
{
    char *buffer = "A 3 4 5 2 5 -2";
    int atot = 0;

    cr_redirect_stderr();
    cr_assert(check_line(buffer, &atot) == 84);
}

Test(check_line, test_with_good_tower)
{
    char *buffer = "T 45 23 90";
    int atot = 1;

    cr_assert(check_line(buffer, &atot) == 0);
}

Test(check_line, test_with_bad_tower)
{
    char *buffer = "T 43 15 -13";
    int atot = 1;

    cr_redirect_stderr();
    cr_assert(check_line(buffer, &atot) == 84);
}

Test(check_line, test_with_unknow_type)
{
    char *buffer = "E 34 53 2";
    int atot = 0;

    cr_redirect_stderr();
    cr_assert(check_line(buffer, &atot) == 84);
    cr_assert_stderr_eq_str(E_SCRIPT_TYPE);
}

Test(check_line, test_with_a_after_tower)
{
    char *buffer = "A 45 24 100 355 23 5";
    int atot = 1;

    cr_redirect_stderr();
    cr_assert(check_line(buffer, &atot) == 84);
}

Test(error_script, test_with_good_map)
{
    char *filepath = "tests/map/map_good";

    cr_assert(error_script(filepath) == 0);
}

Test(error_script, test_with_empty_map)
{
    char *filepath = "tests/map/map_empty";

    cr_redirect_stderr();
    cr_assert(error_script(filepath) == 84);
    cr_assert_stderr_eq_str(E_SCRIPT_EMPTY);
}

Test(error_script, test_with_no_file)
{
    char *filepath = "tutuvroum";

    cr_redirect_stderr();
    cr_assert(error_script(filepath) == 84);
    cr_assert_stderr_eq_str(E_OPEN);
}

Test(error_script, test_with_aircraft_after_tower)
{
    char *filepath = "tests/map/map_aircraft_after_tower";

    cr_redirect_stderr();
    cr_assert(error_script(filepath) == 84);
}