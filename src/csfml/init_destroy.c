/*
** EPITECH PROJECT, 2019
** init.c
** File description:
** init the csfml
*/

#include "lib.h"
#include "csfml.h"
#include "error.h"
#include "struct.h"

void destroy_csfml(csfml_t *csfml)
{
    sfSprite_destroy(csfml->aircraft);
    free(csfml->event);
    sfRenderWindow_destroy(csfml->window);
    sfTexture_destroy(csfml->texture);
    free(csfml);
}

void init_sprite(char *filepath, sfVector2f factors, csfml_t *csfml)
{
    csfml->texture = sfTexture_createFromFile(filepath, NULL);
    csfml->aircraft = sfSprite_create();
    if (!csfml->texture || !csfml->aircraft) {
        my_putstr(E_LOAD_SPRITE, STDOUT_FILENO);
        return;
    }
    sfSprite_setTexture(csfml->aircraft, csfml->texture, sfTrue);
    sfSprite_scale(csfml->aircraft, factors);
}

csfml_t *init_csfml(unsigned int width, unsigned int height)
{
    csfml_t *csfml = malloc(sizeof(csfml_t));
    sfVector2f scale = {0.0286, 0.0286};

    if (!csfml) {
        my_putstr(E_LOAD_CSFML, STDOUT_FILENO);
        return (NULL);
    }
    csfml->window = create_window(width, height);
    init_sprite("resources/aircraft_itbox.png", scale, csfml);
    csfml->event = malloc(sizeof(sfEvent));
    if (!csfml->window || !csfml->aircraft
    || !csfml->texture || !csfml->event) {
        my_putstr(E_LOAD_CSFML, STDOUT_FILENO);
        free(csfml);
        return (NULL);
    }
    csfml->height = height;
    csfml->widht = width;
    return(csfml);
}