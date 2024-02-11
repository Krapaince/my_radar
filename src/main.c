/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main for bootstrap_my_radar
*/

#include "../include/lib.h"
#include "../include/struct.h"
#include "../include/proto.h"

int circle_interseting(sfCircleShape *c1, sfCircleShape *c2)
{
    sfVector2f pos_c1 = sfCircleShape_getPosition(c1);
    sfVector2f pos_c2 = sfCircleShape_getPosition(c2);
    float radius_c1 = sfCircleShape_getRadius(c1);
    float radius_c2 = sfCircleShape_getRadius(c2);

    pos_c1.x +=radius_c1;
    pos_c2.x +=radius_c2;
    pos_c1.y +=radius_c1;
    pos_c2.y +=radius_c2;
    if (pow(pos_c1.x - pos_c2.x, 2) + pow(pos_c1.y - pos_c2.y, 2) <= pow(radius_c1 + radius_c2, 2))
        return (1);
    return (0);
}

void check_colision(circle_t *circle)
{
    int i = 0;
    int j = 0;

    while (circle[i].c != NULL) {
        j = i + 1;
        while (circle[j].c != NULL) {
            if (circle_interseting(circle[i].c, circle[j].c) == 1) {
                set_color(circle[i].s, &circle[i].s->color);
                sfCircleShape_setFillColor(circle[i].c, circle[i].s->color);
                set_color(circle[i].s, &circle[j].s->color);
                sfCircleShape_setFillColor(circle[j].c, circle[i].s->color);
            }
            ++j;
        }
        ++i;
    }
}

void draw_circle(circle_t *circle, sfRenderWindow *window)
{
    int i = 0;

    while (circle[i].c) {
        sfRenderWindow_drawCircleShape(window, circle[i].c, NULL);
        ++i;
    }
}

void update_pos(circle_t *circle)
{
    int i = 0;
    sfVector2f pos;
    float radius;

    while (circle[i].c) {
        pos = sfCircleShape_getPosition(circle[i].c);
        radius = sfCircleShape_getRadius(circle[i].c);
        pos.x += circle[i].vx;
        pos.y += circle[i].vy;
        if (pos.x <= 0 || 1920 <= pos.x + radius * 2)
            circle[i].vx *= -1;
        if (pos.y <= 0 || 1080 <= pos.y + 2 * radius)
            circle[i].vy *= -1;
        sfCircleShape_setPosition(circle[i].c, pos);
        sfCircleShape_setFillColor(circle[i].c, sfBlack);
        ++i;
    }
}

int main(void)
{
    sfRenderWindow *window = create_my_window(1920, 1080);
    circle_t *circle = init_circle_tab(200);

    srand(time(NULL));
    if (circle == NULL)
        return (84);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        update_pos(circle);
        check_colision(circle);
        draw_circle(circle, window);
        sfRenderWindow_display(window);
    }
}