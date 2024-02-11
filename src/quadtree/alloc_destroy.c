/*
** EPITECH PROJECT, 2019
** alloc_destroy.c
** File description:
** alloc and destroy the quadtree
*/

#include "lib.h"
#include "struct.h"
#include "csfml.h"
#include "quadtree.h"
#include "error.h"

void qtree_destroy(qtree_t *tree)
{
    int i = 0;

    if (!tree)
        return;
    if (tree->divided) {
        while (i < 4) {
            qtree_destroy(tree->child[i]);
            ++i;
        }
    }
    free(tree);
}

qtree_t *qtree_create(float x, float y, float width, float height)
{
    qtree_t *new = malloc(sizeof(qtree_t));

    if (!new) {
        my_putstr(E_MALLOC, STDERR_FILENO);
        return (NULL);
    }
    new->x = x;
    new->y = y;
    new->width = width;
    new->height = height;
    new->divided = false;
    new->nb_aircraft = 0;
    new->depth = 0;
    new->child[0] = NULL;
    new->child[1] = NULL;
    new->child[2] = NULL;
    new->child[3] = NULL;
    new->parent = NULL;
    new->slot = NULL;
    return (new);
}