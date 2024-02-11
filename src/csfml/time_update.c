/*
** EPITECH PROJECT, 2019
** time_update.c
** File description:
** manage the clock
*/

#include "lib.h"
#include "struct.h"
#include "csfml.h"
#include "error.h"
#include "script.h"

char *int_to_str(int nb)
{
    char *res = malloc(sizeof(char) * (len_nb(nb) + 1));

    if (!res) {
        my_putstr(E_MALLOC, STDERR_FILENO);
        return (NULL);
    }
    res = my_revstr(nb_to_str(nb, res, true));
    return (res);
}

void reset_switch(csfml_t *csfml)
{
    csfml->hitbox_active_switch = true;
    csfml->sprite_active_switch = true;
    csfml->back_active_switch = true;
}

bool time_update(csfml_t *csfml)
{
    char *buffer_time = NULL;

    csfml->time = sfClock_getElapsedTime(csfml->timer);
    if (1000000 <= csfml->time.microseconds) {
        ++csfml->dt;
        sfClock_restart(csfml->timer);
        reset_switch(csfml);
        csfml->sec = 1;
    } else
        csfml->sec = 0;
    buffer_time = int_to_str(csfml->dt);
    if (!buffer_time) {
        my_putstr(E_MALLOC, STDERR_FILENO);
        return (false);
    }
    sfText_setString(csfml->text, buffer_time);
    sfRenderWindow_drawText(csfml->window, csfml->text, NULL);
    free(buffer_time);
    return (true);
}