/*
** EPITECH PROJECT, 2019
** display.c
** File description:
** launch the render of the entities
*/

#include "lib.h"
#include "struct.h"
#include "csfml.h"
#include "quadtree.h"

void qtree_display(csfml_t *csfml, qtree_t *tree,
sfRectangleShape *rect, sfVector2f *position)
{
    sfVector2f size = {tree->width, tree->height};
    sfColor color[5] = {sfGreen, sfCyan, sfBlue, sfMagenta,
    {255, 117, 26, 255}};
    int i = 0;

    if (csfml->hitbox == 2 || csfml->hitbox == 3 || csfml->hitbox == 6)
        return;
    if (tree->divided) {
        while (i < 4) {
            qtree_display(csfml, tree->child[i], rect, position);
            ++i;
        }
    }
    position->x = tree->x;
    position->y = tree->y;
    sfRectangleShape_setPosition(rect, *position);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setOutlineColor(rect, color[tree->depth]);
    sfRenderWindow_drawRectangleShape(csfml->window, rect, NULL);
}

bool create_hitbox_shape(sfRectangleShape **rect, sfCircleShape **circle)
{
    *rect = sfRectangleShape_create();
    *circle = sfCircleShape_create();
    if (!*rect || !*circle)
        return (false);
    sfCircleShape_setOutlineColor(*circle, sfRed);
    sfCircleShape_setFillColor(*circle, sfTransparent);
    sfRectangleShape_setFillColor(*rect, sfTransparent);
    sfRectangleShape_setOutlineThickness(*rect, 1);
    return (true);
}

bool display(csfml_t *csfml, aircraft_t *aircraft, tower_t *tower,
qtree_t *tree)
{
    sfRectangleShape *rect = NULL;
    sfCircleShape *circle = NULL;
    sfVector2f position = {0, 0};

    if (csfml->back)
        sfRenderWindow_drawSprite(csfml->window, csfml->s_back, NULL);
    else
        sfRenderWindow_clear(csfml->window, sfBlack);
    if (!create_hitbox_shape(&rect, &circle))
        return (false);
    qtree_display(csfml, tree, rect, &position);
    display_tower(csfml, tower, circle);
    display_aircraft(csfml, aircraft, rect, &position);
    if (!time_update(csfml))
        return (false);
    sfRenderWindow_display(csfml->window);
    sfCircleShape_destroy(circle);
    sfRectangleShape_destroy(rect);
    return (true);
}