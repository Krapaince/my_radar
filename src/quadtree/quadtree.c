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

void reset_tree(qtree_t *tree)
{
    int i = 0;

    if (tree->depth < MAX_DEPTH) {
        while (i < 4) {
            reset_tree(tree->child[i]);
            ++i;
        }
    }
    tree->slot = NULL;
    tree->divided = false;
    tree->nb_aircraft = 0;
}

void crash_them_all(qtree_t *tree)
{
    qtree_compare_list(tree->slot);
    while (tree->slot) {
        qtree_compare_aircraft_child(tree->slot, tree, false);
        tree->slot = tree->slot->qtree_next;
    }
    if (tree->divided) {
        crash_them_all(tree->child[0]);
        crash_them_all(tree->child[1]);
        crash_them_all(tree->child[2]);
        crash_them_all(tree->child[3]);
    }
}

bool qtree(aircraft_t *aircraft, qtree_t *root, tower_t *tower)
{
    reset_tree(root);
    while (aircraft != NULL) {
        if (aircraft_in_tower_range(aircraft, tower))
            aircraft->depth = 6;
        else if (!qtree_insert(aircraft, root)) {
            aircraft->qtree_next = root->slot;
            aircraft->depth = root->depth;
            root->slot = aircraft;
        }
        aircraft = aircraft->next;
    }
    crash_them_all(root);
    return (true);
}