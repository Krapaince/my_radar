/*
** EPITECH PROJECT, 2019
** quadtree.c
** File description:
** quadtree main
*/

#include "lib.h"
#include "struct.h"
#include "csfml.h"
#include "quadtree.h"
#include "error.h"

void reset_root(qtree_t *root)
{
    root->slot = NULL;
    root->depth = 0;
    root->divided = false;
    root->nb_aircraft = 0;
}

bool qtree(aircraft_t *aircraft, qtree_t *root)
{
    int i = 0;

    if (!root) {
        my_putstr(E_MALLOC, STDERR_FILENO);
        return (false);
    }
    if (root->divided) {
        while (i < 4) {
            qtree_destroy(root->child[i]);
            ++i;
        }
    }
    reset_root(root);
    while (aircraft != NULL) {
        if (!qtree_insert(aircraft, root))
            return (false);
        aircraft = aircraft->next;
    }
    return (true);
}