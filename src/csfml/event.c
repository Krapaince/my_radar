/*
** EPITECH PROJECT, 2019
** event.c
** File description:
** manage the event
*/

#include "csfml.h"

void event_check(csfml_t *csfml, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(csfml->window, event)) {
        if (event->type == sfEvtClosed || event->key.code == sfKeyEscape)
            sfRenderWindow_close(csfml->window);
    }
}