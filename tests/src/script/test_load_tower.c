/*
** EPITECH PROJECT, 2019
** test_load_tower.c
** File description:
** test the function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lib.h"
#include "struct.h"
#include "script.h"

Test(get_next_tower, test_with_good_map)
{
    char *filepath = "tests/map/map_good";
    FILE *script = fopen(filepath, "r");
    char *tower = NULL;

    cr_assert(script != NULL);
    tower = get_next_tower(script);
    cr_assert(tower != NULL);
    cr_assert(tower[0] == 'T');
    free(tower);
}

Test(get_next_tower, test_without_tower)
{
    char *filepath = "tests/map/map_without_tower";
    FILE *script = fopen(filepath, "r");
    char *tower = NULL;

    cr_assert(script != NULL);
    tower = get_next_tower(script);
    cr_assert(tower == NULL);
}

Test(init_tower, test_no_tower)
{
    tower_t *new = malloc(sizeof(tower_t));
    char *tower_info = "T 34 24 20";

    cr_assert(new != NULL);
    init_tower(new, tower_info);
    cr_assert(new->x == 34);
    cr_assert(new->y == 24);
    cr_assert(new->next == NULL);
    free(new);
}

Test(add_tower, test_with_non_existing_tower)
{
    tower_t *tower = NULL;
    char *tower_info = "T 34 45 12";

    cr_assert(add_tower(&tower, tower_info) == 0);
    cr_assert(tower != NULL);
    cr_assert(tower->x == 34);
    cr_assert(tower->y == 45);
    cr_assert(tower->next == NULL);
    free(tower);
}

Test(add_tower, test_with_existing_tower)
{
    tower_t *tower = NULL;
    char *tower_info = "T 34 45 12";
    char *tower_info_2 = "T 35 14 13";
    tower_t *first = NULL;

    cr_assert(add_tower(&tower, tower_info) == 0);
    cr_assert(tower != NULL);
    cr_assert(tower->x == 34);
    cr_assert(tower->y == 45);
    first = tower;
    cr_assert(add_tower(&tower, tower_info_2) == 0);
    cr_assert(first == tower->next);
    cr_assert(tower != NULL);
    cr_assert(tower->y == 14);
    cr_assert(tower->x == 35);
    free(tower->next);
    free(tower);
}

Test(load_tower, test_without_tower)
{
    tower_t *tower = NULL;
    char *filepath = "tests/map/map_without_tower";

    cr_assert(load_tower(&tower, filepath) == 0);
    cr_assert(tower == NULL);
}

Test(load_tower, test_with_tower)
{
    tower_t *tower = NULL;
    char *filepath = "tests/map/map_good";

    cr_assert(load_tower(&tower, filepath) == 0);
    cr_assert(tower != NULL);
    cr_assert(tower->next != NULL);
    free(tower->next);
    free(tower);
}