/*
** EPITECH PROJECT, 2018
** color_smooth_random.c
** File description:
** make a smooth radiant random color
*/

#include "../include/lib.h"
#include "../include/struct.h"

int rand_range(int min, int max)
{
    int res = rand() % max + min;
    int sign = rand() % 2 + 1;

    if (min < 0 && sign == 1)
        return (-res);
    else
        return (res);
}

int set_sign(void)
{
    if (rand_range(1, 3) == 1)
        return (-1);
    else
        return (1);
}

sfUint8 *select_component_color(sfColor *color)
{
    int res = rand_range(1, 3);
    sfUint8 *choice = NULL;

    if (res == 1)
        choice = &color->r;
    else if (res == 2)
        choice = &color->g;
    else
        choice = &color->b;
    return (choice);
}

void set_color(smooth_t *s, sfColor *color)
{
    if (s->active == 1) {
        s->active = 0;
        s->sign = set_sign();
        s->color_choice = select_component_color(color);
        s->padding = 1;
        s->value_to_put = *s->color_choice;
        if (s->value_to_put == 0)
            s->value_to_put = 50;
        if ((*s->color_choice - s->value_to_put < 0 && s->sign == -1)
        || (255 < *s->color_choice + s->value_to_put && s->sign == 1))
            s->sign *= -1;
        s->res = *s->color_choice + s->value_to_put * s->sign;
        s->padding *= s->sign;
    } else
        *s->color_choice += s->padding;
    if (s->active == 0 && ((s->res <= *s->color_choice && s->sign == 1)
    || (*s->color_choice <= s->res && s->sign == -1)))
        s->active = 1;
}