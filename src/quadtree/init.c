/*
** EPITECH PROJECT, 2019
** quadtree.c
** File description:
** create quadtree
*/

#include "lib.h"
#include "struct.h"
#include "csfml.h"
#include "quadtree.h"
#include "error.h"

bool qtree_aircraft_in_tree(aircraft_t *aircraft, qtree_t *tree)
{
    if (tree->x + aircraft->width <= aircraft->x0
    && aircraft->x0 <= tree->x + tree->width - aircraft->width
    && tree->y + aircraft->height <= aircraft->y0
    && aircraft->y0 <= tree->y + tree->height - aircraft->height)
        return (true);
    return (false);
}

bool qtree_insert_in_child(aircraft_t *aircraft, qtree_t *tree)
{
    int i = 0;

    while (i < 4) {
        if (qtree_insert(aircraft, tree->child[i]))
            return (true);
        ++i;
    }
    return (false);
}

void qtree_reinsert(aircraft_t *aircraft, qtree_t *tree)
{
    aircraft_t *temp = NULL;
    aircraft_t *next = NULL;

    tree->nb_aircraft = 0;
    while (aircraft) {
        next = aircraft->qtree_next;
        if (!qtree_insert_in_child(aircraft, tree)) {
            aircraft->qtree_next = temp;
            temp = aircraft;
            aircraft->depth = tree->depth;
            ++tree->nb_aircraft;
        }
        aircraft = next;
    }
    tree->slot = temp;
}

bool qtree_insert(aircraft_t *aircraft, qtree_t *tree)
{
    if (!qtree_aircraft_in_tree(aircraft, tree))
        return (false);
    if ((!tree->divided && tree->nb_aircraft < MAX_SLOT)
    || tree->depth == MAX_DEPTH) {
        aircraft->qtree_next = tree->slot;
        tree->slot = aircraft;
        aircraft->depth = tree->depth;
        ++tree->nb_aircraft;
        return (true);
    }
    tree->divided = true;
    qtree_reinsert(tree->slot, tree);
    if (!qtree_insert_in_child(aircraft, tree)) {
        aircraft->qtree_next = tree->slot;
        tree->slot = aircraft;
        aircraft->depth = tree->depth;
    }
    return (true);
}