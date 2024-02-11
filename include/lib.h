/*
** EPITECH PROJECT, 2018
** lib.h
** File description:
** contain the lib inclusion
*/

#ifndef LIB_H_
    #define LIB_H_
    #include <SFML/Graphics/CircleShape.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Config.h>
    #include <math.h>
    #include <time.h>
    #include <stdlib.h>
    #include <string.h>
    #include <limits.h>

    //lib's function prototype
    int merge_str(char **s1, char *s2);
    int my_getnbr(char const *str);
    char *my_strcat(char *dest, char const *src);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strcpy(char *dest, char const *src);
    char *my_strdup(char const *src);
    int my_strlen(char const *str);
#endif