/*
** EPITECH PROJECT, 2019
** init.c
** File description:
** init the csfml
*/

#include "lib.h"
#include "struct.h"
#include "csfml.h"
#include "error.h"

void destroy_csfml(csfml_t *csfml)
{
    sfSprite_destroy(csfml->s_air);
    sfSprite_destroy(csfml->s_tow);
    sfSprite_destroy(csfml->s_back);
    free(csfml->event);
    sfRenderWindow_destroy(csfml->window);
    sfTexture_destroy(csfml->t_air);
    sfTexture_destroy(csfml->t_tow);
    sfTexture_destroy(csfml->t_back);
    sfText_destroy(csfml->text);
    sfFont_destroy(csfml->font);
    sfClock_destroy(csfml->timer);
    free(csfml);
}

int init_sprite(sfSprite **sprite, sfTexture **texture, char *filepath)
{
    *texture = sfTexture_createFromFile(filepath, NULL);
    *sprite = sfSprite_create();
    if (!*sprite || !*texture) {
        my_putstr(E_LOAD_SPRITE, STDOUT_FILENO);
        return (1);
    }
    sfSprite_setTexture(*sprite, *texture, sfTrue);
    return (0);
}

bool init_text(sfText **text, sfFont **font)
{
    *text = sfText_create();
    *font = sfFont_createFromFile("resources/roboto_black.ttf");
    sfVector2f position = {50, 50};

    if (!*text || !*font) {
        my_putstr(E_LOAD_TEXT, STDERR_FILENO);
        return (false);
    }
    sfText_setCharacterSize(*text, 80);
    sfText_setFont(*text, *font);
    sfText_setPosition(*text, position);
    sfText_setColor(*text, sfWhite);
    return (true);
}

int init_csfml(csfml_t *csfml)
{
    int r_value = init_sprite(&csfml->s_air, &csfml->t_air, AIRCRAFT_FILEPATH);

    r_value = init_sprite(&csfml->s_back, &csfml->t_back, BACKGROUND_FILEPATH);
    r_value = init_sprite(&csfml->s_tow, &csfml->t_tow, TOWER_FILEPATH);
    csfml->timer = sfClock_create();
    csfml->time.microseconds = 0;
    csfml->height = HEIGHT;
    csfml->widht = WIDTH;
    csfml->hitbox = 6;
    csfml->hitbox_active_switch = true;
    csfml->sprite = 3;
    csfml->sprite_active_switch = true;
    csfml->dt = 0;
    csfml->back = false;
    csfml->back_active_switch = true;
    csfml->sec = 0;
    return (r_value);
}

csfml_t *alloc_csfml(unsigned int width, unsigned int height)
{
    csfml_t *csfml = malloc(sizeof(csfml_t));

    if (!csfml) {
        my_putstr(E_LOAD_CSFML, STDOUT_FILENO);
        return (NULL);
    }
    csfml->event = malloc(sizeof(sfEvent));
    csfml->window = create_window(width, height);
    if (init_csfml(csfml) == 1 || !csfml->event || !csfml->window
    || !csfml->timer || !init_text(&csfml->text, &csfml->font)) {
        my_putstr(E_LOAD_CSFML, STDOUT_FILENO);
        return (NULL);
    }
    return (csfml);
}