/*
** EPITECH PROJECT, 2018
** lib.h
** File description:
** contain the lib inclusion
*/

#ifndef LIB_H_
    #define LIB_H_
    #include <math.h>
    #include <time.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <string.h>
    #include <limits.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <SFML/Graphics.h>
    #include <SFML/System/Clock.h>

    //lib's function prototype
    int cat(char *filepath, int std);
    int merge_str(char **s1, char *s2);
    int my_getnbr(char const *str);
    void my_putchar(char c, int std);
    void my_putnbr(int nb, int std);
    void my_putstr(char const *str, int std);
    char *my_revstr(char *str);
    char *my_strcat(char *dest, char const *src);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strcpy(char *dest, char const *src);
    char *my_strdup(char const *src);
    int my_strlen(char const *str);
#endif