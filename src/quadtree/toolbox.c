/*
** EPITECH PROJECT, 2019
** toolbox.c
** File description:
** toolbox for quadtree
*/

#include "lib.h"
#include "struct.h"
#include "quadtree.h"

void qtree_compare_aircraft_list(aircraft_t *aircraft, aircraft_t *list)
{
    while (list && aircraft) {
        collision_detection(aircraft, list);
        list = list ->qtree_next;
    }
}

void qtree_compare_list(aircraft_t *list)
{
    while (list && list->qtree_next) {
        qtree_compare_aircraft_list(list, list->qtree_next);
        list = list->qtree_next;
    }
}

void qtree_compare_aircraft_child(aircraft_t *aircraft, qtree_t *tree,
bool compare)
{
    if (tree->divided) {
        qtree_compare_aircraft_child(aircraft, tree->child[0], true);
        qtree_compare_aircraft_child(aircraft, tree->child[1], true);
        qtree_compare_aircraft_child(aircraft, tree->child[2], true);
        qtree_compare_aircraft_child(aircraft, tree->child[3], true);
    }
    if (compare)
        qtree_compare_aircraft_list(aircraft, tree->slot);
}