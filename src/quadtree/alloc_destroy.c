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
    if (tree->depth < MAX_DEPTH) {
        while (i < 4) {
            qtree_destroy(tree->child[i]);
            ++i;
        }
    }
    free(tree);
}

qtree_t *qtree_alloc(float x, float y, float width, float height)
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

bool qtree_create_child(qtree_t *parent)
{
    int x = parent->x;
    int y = parent->y;
    int w = parent->width;
    int h = parent->height;

    parent->child[0] = qtree_alloc(x, y, w / 2 + PAD, h / 2 + PAD);
    parent->child[1] = qtree_alloc(x + w / 2, y, w / 2 + PAD, h / 2 + PAD);
    parent->child[2] = qtree_alloc(x, y + h / 2, w / 2 + PAD, h / 2 + PAD);
    parent->child[3] = qtree_alloc(x + w / 2, y + h / 2,
    w / 2 + PAD, h / 2 + PAD);
    if (!parent->child[0] || !parent->child[1]
    || !parent->child[2] || !parent->child[3])
        return (false);
    return (true);
}

bool qtree_divide(qtree_t *parent)
{
    int i = 0;
    bool r_value = true;

    if (!qtree_create_child(parent))
        return (false);
    while (i < 4) {
        parent->child[i]->parent = parent;
        parent->child[i]->depth = parent->depth + 1;
        if (parent->child[i]->depth < MAX_DEPTH)
            r_value = qtree_divide(parent->child[i]);
        if (!r_value)
            return (false);
        ++i;
    }
    return (true);
}

qtree_t *qtree_create(void)
{
    qtree_t *root = qtree_alloc(0, 0, WIDTH, HEIGHT);

    if (!root || !qtree_divide(root)) {
        my_putstr(E_QTREE, STDERR_FILENO);
        return (NULL);
    }
    return (root);
}