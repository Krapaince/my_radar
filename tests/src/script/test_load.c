/*
** EPITECH PROJECT, 2019
** test_load.c
** File description:
** test the function
*/

#include "lib.h"
#include "struct.h"
#include "script.h"
#include "criterion/criterion.h"

Test(load, test_with_bad_filepath)
{
    aircraft_t *aircraft = NULL;
    tower_t *tower;
    int dt_max = 0;
    char *filepath = "blablou";

    cr_assert(load(&aircraft, &tower, &dt_max, filepath) == 84);
}