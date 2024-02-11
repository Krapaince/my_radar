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

bool qtree_divide(qtree_t *tree)
{
    int x = tree->x;
    int y = tree->y;
    int w = tree->width;
    int h = tree->height;
    int i = 0;

    tree->divided = true;
    tree->child[0] = qtree_create(x, y, w / 2 + PAD, h / 2 + PAD);
    tree->child[1] = qtree_create(x + w / 2, y, w / 2 + PAD, h / 2 + PAD);
    tree->child[2] = qtree_create(x, y + h / 2, w / 2 + PAD, h / 2 + PAD);
    tree->child[3] = qtree_create(x + w / 2, y + h / 2,
    w / 2 + PAD, h / 2 + PAD);
    while (i < 4) {
        if (!tree->child[i])
            return (false);
        tree->child[i]->parent = tree;
        tree->child[i]->depth = tree->depth + 1;
        ++i;
    }
    return (true);
}

bool qtree_aircraft_in_tree(aircraft_t *aircraft, qtree_t *tree)
{
    if (tree->x <= aircraft->x0 && aircraft->x0 <= tree->x + tree->width
    && tree->y <= aircraft->y0 && aircraft->y0 <= tree->y + tree->height)
        return (true);
    return (false);
}

bool qtree_insert_in_child(aircraft_t *aircraft, qtree_t *tree)
{
    int i = 0;

    while (i < 4) {
        if (qtree_insert(aircraft, tree->child[i]) == true)
            return (true);
        ++i;
    }
    my_putstr(E_QTREE_INSERT, STDERR_FILENO);
    return (false);
}

bool qtree_reinsert(aircraft_t *aircraft, qtree_t *tree)
{
    while (aircraft) {
        if (!qtree_insert_in_child(aircraft, tree))
            return (false);
        aircraft = aircraft->qtree_next;
    }
    tree->slot = NULL;
    return (true);
}

bool qtree_insert(aircraft_t *aircraft, qtree_t *tree)
{
    if (!qtree_aircraft_in_tree(aircraft, tree))
        return (false);
    if ((!tree->slot && !tree->divided && tree->nb_aircraft < 20)
    || MAX_DEPTH < tree->depth) {
        aircraft->qtree_next = tree->slot;
        tree->slot = aircraft;
        ++tree->nb_aircraft;
        return (true);
    }
    ++tree->nb_aircraft;
    if (!tree->divided) {
        if (!qtree_divide(tree))
            return (false);
    }
    if (!qtree_reinsert(tree->slot, tree))
        return (false);
    if (!qtree_insert_in_child(aircraft, tree))
        return (false);
    return (true);
}