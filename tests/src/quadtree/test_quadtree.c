/*
** EPITECH PROJECT, 2019
** test_quadtree.c
** File description:
** test the quadtree
*/

#include "lib.h"
#include "struct.h"
#include "script.h"
#include "quadtree.h"
#include "csfml.h"
#include <criterion/criterion.h>

Test(qtree_divide, test_with_to_divide)
{
    qtree_t *tree = qtree_create(0, 0, 1920, 1080);

    cr_assert(qtree_divide(tree) == true);
    cr_assert(tree->child[0]->x == 0);
    cr_assert(tree->child[0]->y == 0);
    cr_assert(tree->child[1]->x == WIDTH / 2);
    cr_assert(tree->child[1]->y == 0);
    cr_assert(tree->child[2]->x == 0);
    cr_assert(tree->child[2]->y == HEIGHT / 2);
    cr_assert(tree->child[3]->x == WIDTH / 2);
    cr_assert(tree->child[3]->y == HEIGHT / 2);
    qtree_destroy(tree);
    free(tree);
}

Test(qtree_aircraft_in_tree, test_inside)
{
    aircraft_t aircraft = {34, 51, 0, 0, 0, 0, 10, 10, 4,
    true, true, 0, 0, NULL, NULL};
    qtree_t *tree = qtree_create(0, 0, 100, 100);

    cr_assert(qtree_aircraft_in_tree(&aircraft, tree) == 1);
    cr_assert(tree != NULL);
    free(tree);
}

Test(qtree_aircraft_in_tree, test_x_on_edge)
{
    aircraft_t aircraft = {100, 51, 0, 0, 0, 0, 20, 20, 4, 1, 1, 0, 0, NULL,
    NULL};
    qtree_t *tree = qtree_create(0, 0, 100, 100);

    cr_assert(qtree_aircraft_in_tree(&aircraft, tree) == 1);
    cr_assert(tree != NULL);
    free(tree);
}

Test(qtree_aircraft_in_tree, test_x_out)
{
    aircraft_t aircraft = {101, 51, 0, 0, 0, 0, 20, 20, 4, 1, 1, 0, 0,
    NULL, NULL};
    qtree_t *tree = qtree_create(0, 0, 100, 100);

    cr_assert(qtree_aircraft_in_tree(&aircraft, tree) == 0);
    cr_assert(tree != NULL);
    free(tree);
}

Test(qtree_aircraft_in_tree, test_y_out)
{
    aircraft_t aircraft = {100, 101, 0, 0, 0, 0, 20, 20, 4, 1, 1, 0, 0,
    NULL, NULL};
    qtree_t *tree = qtree_create(0, 0, 100, 100);

    cr_assert(qtree_aircraft_in_tree(&aircraft, tree) == 0);
    cr_assert(tree != NULL);
    free(tree);
}

Test(qtree_aircraft_in_tree, test_y_x_out)
{
    aircraft_t aircraft = {101, 101, 0, 0, 0, 0, 20, 20, 4, 1, 1, 0, 0,
    NULL, NULL};
    qtree_t *tree = qtree_create(0, 0, 100, 100);

    cr_assert(qtree_aircraft_in_tree(&aircraft, tree) == 0);
    cr_assert(tree != NULL);
    free(tree);
}