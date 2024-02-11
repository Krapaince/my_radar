/*
** EPITECH PROJECT, 2018
** create a window
** File description:
** create_window
*/

#include "csfml.h"

sfRenderWindow *create_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window = NULL;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "my_radar", 8, NULL);
    sfRenderWindow_setFramerateLimit(window, 30);
    return (window);
}