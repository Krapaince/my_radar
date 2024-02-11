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
    #define MAX_SLOT  4
    #define PAD       0
    bool qtree(aircraft_t *aircraft, qtree_t *root, tower_t *tower);
    bool qtree_aircraft_in_tree(aircraft_t *aircraft, qtree_t *tree);
    qtree_t *qtree_alloc(float x, float y, float width, float height);
    bool qtree_create_child(qtree_t *parent);
    qtree_t *qtree_create(void);
    bool qtree_divide(qtree_t *parent);
    void qtree_destroy(qtree_t *tree);
    bool qtree_insert_in_child(aircraft_t *aircraft, qtree_t *tree);
    bool qtree_insert(aircraft_t *aircraft, qtree_t *tree);
    void qtree_display(csfml_t *csfml, qtree_t *tree,
    sfRectangleShape *rect, sfVector2f *position);
    bool aircraft_in_tower_range(aircraft_t *aircraft, tower_t *tower);
    void collision_detection(aircraft_t *one, aircraft_t *two);
    void qtree_compare_aircraft_list(aircraft_t *aircraft, aircraft_t *list);
    void qtree_compare_list(aircraft_t *list);
    void qtree_compare_aircraft_child(aircraft_t *aircraft, qtree_t *tree,
    bool compare);
#endif