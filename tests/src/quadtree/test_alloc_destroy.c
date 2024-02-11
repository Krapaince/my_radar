/*
** EPITECH PROJECT, 2019
** test_quadtree.c
** File description:
** test the function
*/

#include "lib.h"
#include "struct.h"
#include "quadtree.h"
#include "csfml.h"
#include <criterion/criterion.h>

Test(qtree_create, test_to_create)
{
    qtree_t *new = qtree_create();

    cr_assert(new != NULL);
    cr_assert(new->divided == false);
    cr_assert(new->height = HEIGHT);
    cr_assert(new->width == WIDTH);
    cr_assert(new->child[0] != NULL);
    cr_assert(new->child[1] != NULL);
    cr_assert(new->child[2] != NULL);
    cr_assert(new->child[3] != NULL);
    cr_assert(new->parent == NULL);
    cr_assert(new->nb_aircraft == 0);
    cr_assert(new->slot == NULL);
    qtree_destroy(new);
}