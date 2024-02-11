/*
** EPITECH PROJECT, 2018
** create a window
** File description:
** create_window
*/

#include "lib.h"
#include "struct.h"
#include "csfml.h"

sfRenderWindow *create_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window = NULL;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "my_radar", MODE, NULL);
    sfRenderWindow_setFramerateLimit(window, FPS);
    return (window);
}