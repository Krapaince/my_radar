/*
** EPITECH PROJECT, 2019
** test_destroy_entities.c
** File description:
** test the function
*/

#include "lib.h"
#include "struct.h"
#include "proto.h"
#include "criterion/criterion.h"
#include "script.h"

Test(destroy, test_with_map_load)
{
    char *filepath = "tests/map/map_good";
    aircraft_t *plane = NULL;
    tower_t *tower = NULL;

    cr_assert(load(&plane, &tower, 0, filepath) == 0);
    destroy(plane, tower);
}