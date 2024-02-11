/*
** EPITECH PROJECT, 2019
** event.c
** File description:
** manage the event
*/

#include "lib.h"
#include "struct.h"
#include "csfml.h"

void switch_value(int *nb, int max)
{
    if (*nb < max)
        ++*nb;
    else
        *nb = 0;
}

void event_check(csfml_t *csfml, sfEvent *event, aircraft_t *aircraft)
{
    if (csfml->dt > csfml->dt_max && !aircraft)
        sfRenderWindow_close(csfml->window);
    while (sfRenderWindow_pollEvent(csfml->window, event)) {
        if (event->type == sfEvtClosed || event->key.code == sfKeyEscape)
            sfRenderWindow_close(csfml->window);
        if (event->key.code == sfKeyL && csfml->hitbox_active_switch) {
            switch_value(&csfml->hitbox, 7);
            csfml->hitbox_active_switch = false;
        }
        if (event->key.code == sfKeyS && csfml->sprite_active_switch) {
            switch_value(&csfml->sprite, 3);
            csfml->sprite_active_switch = false;
        }
    }
}