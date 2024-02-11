/*
** EPITECH PROJECT, 2019
** test_load_aircraft.c
** File description:
** test the function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lib.h"
#include "struct.h"
#include "proto.h"
#include "script.h"
#include "error.h"

Test(get_dt, test_with_aircraft_data)
{
    char *aircraft_data = "A 1 2 9 9 1 3";

    cr_assert(get_dt(aircraft_data) == 3);
}

Test(get_dt, test_with_aircraft_data_and_backslash_n)
{
    char *aircraft_data = "A 1 2 3 453 234 1000\n";

    cr_assert(get_dt(aircraft_data) == 1000);
}

Test(init_aircraft, test_init_aircraft)
{
    char *aircraft_info = "A 123 234 456 567 4 2";
    aircraft_t *new = malloc(sizeof(aircraft_t));

    cr_assert(new != NULL);
    init_aircraft(new, aircraft_info);
    cr_assert(new->x0 == 123);
    cr_assert(new->y0 == 234);
    cr_assert(new->x1 == 456);
    cr_assert(new->y1 == 567);
    cr_assert(new->delta_time);
    cr_assert(new->next == NULL);
    free(new);
}

Test(add_aircraft, test_with_a_good_dt)
{
    char *aircraft_info = "A 234 134 532 551 2 3";
    int dt = 3;
    aircraft_t *plane = NULL;

    cr_assert(add_aircraft(&plane, aircraft_info, dt, NULL) == 0);
    cr_assert(plane->x0 == 234);
    cr_assert(plane->y0 == 134);
    cr_assert(plane->x1 == 532);
    cr_assert(plane->y1 == 551);
    cr_assert(plane->delta_time == 3);
    cr_assert(plane->next == NULL);
    free(plane);
}

Test(add_aircraft, test_with_bad_dt)
{
    char *aircraft_info = "A 234 134 532 551 2 0";
    int dt = 2;
    aircraft_t *plane = NULL;

    cr_assert(add_aircraft(&plane, aircraft_info, dt, NULL) == 0);
    cr_assert(plane == NULL);
}

Test(load_aircraft, test_map_whithout_aircraft)
{
    char *filepath = "tests/map/map_without_aircraft";
    aircraft_t *plane = NULL;
    int dt = 0;

    cr_assert(load_aircraft(&plane, filepath, dt, NULL) == 0);
    cr_assert(plane == NULL);
}

Test(load_aircraft, test_map_with_aircraft)
{
    char *filepath = "tests/map/map_without_tower";
    aircraft_t *plane = NULL;
    int dt = 3;

    cr_assert(load_aircraft(&plane, filepath, dt, NULL) == 0);
    cr_assert(plane != NULL);
    cr_assert(plane->next == NULL);
    cr_assert(plane->x0 == 34);
    cr_assert(plane->y0 == 24);
    cr_assert(plane->x1 == 652);
    cr_assert(plane->y1 == 35);
    cr_assert(plane->delta_time == 3);
    free(plane);
}

Test(load_aircraft, test_map_with_multiple_aircraft)
{
    char *filepath = "tests/map/map_without_tower";
    aircraft_t *plane = NULL;
    int dt = 6;

    cr_assert(load_aircraft(&plane, filepath, dt, NULL) == 0);
    cr_assert(plane != NULL);
    cr_assert(plane->next != NULL);
    cr_assert(plane->next->next != NULL);
    cr_assert(plane->next->next->next == NULL);
    destroy_aircraft(plane);
}

Test(load_aircraft, test_with_unaccessible_map)
{
    char *filepath = "BLABLOU";
    aircraft_t *plane = NULL;
    int dt = 0;

    cr_redirect_stderr();
    cr_assert(load_aircraft(&plane, filepath, dt, NULL) == 84);
    cr_assert_stderr_eq_str(E_OPEN);
    cr_assert(plane == NULL);
}