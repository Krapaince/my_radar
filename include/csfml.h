/*
** EPITECH PROJECT, 2019
** csfml.h
** File description:
** include for csfml
*/

#ifndef CSFML_H_
    #define CSFML_H_
    #define WIDTH  1920
    #define HEIGHT 1080
    #include <SFML/Graphics.h>
    #include <SFML/System/Clock.h>
    typedef struct
    {
        sfRenderWindow *window;
        sfEvent *event;
        sfTexture *texture;
        sfSprite *aircraft;
        unsigned int widht;
        unsigned int height;
    } csfml_t;
    sfRenderWindow *create_window(unsigned int width, unsigned int height);
    void init_sprite(char *filepath, sfVector2f factors, csfml_t *csfml);
    csfml_t *init_csfml(unsigned int width, unsigned int height);
    void event_check(csfml_t *csfml, sfEvent *event);
    void destroy_csfml(csfml_t *csfml);
#endif