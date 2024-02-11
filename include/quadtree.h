/*
** EPITECH PROJECT, 2019
** quadtree.h
** File description:
** contain the quadtree prototype
*/

#ifndef QUADTREE_H_
    #define QUADTREE_H_
    #include <SFML/Graphics/RectangleShape.h>
    #define MAX_DEPTH 4
    #define PAD       1
    bool qtree(aircraft_t *aircraft, qtree_t *root);
    bool qtree_aircraft_in_tree(aircraft_t *aircraft, qtree_t *tree);
    qtree_t *qtree_create(float x, float y, float width, float height);
    bool qtree_divide(qtree_t *tree);
    void qtree_destroy(qtree_t *tree);
    bool qtree_insert_in_child(aircraft_t *aircraft, qtree_t *tree);
    bool qtree_insert(aircraft_t *aircraft, qtree_t *tree);
    void qtree_display(csfml_t *csfml, qtree_t *tree,
    sfRectangleShape *rect, sfVector2f *position);
#endif