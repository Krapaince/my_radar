/*
** EPITECH PROJECT, 2019
** aircraft.c
** File description:
** generate aircraft
*/

#include "lib.h"
#include "struct.h"
#include "script.h"

void generate_tower(FILE *script, int min, int max)
{
    char buffer[5] = {'\0'};

    fwrite("T ", sizeof(char), 2, script);
    my_revstr(nb_to_str(random_range(0, 1919), buffer, true));
    fwrite(buffer, sizeof(char), my_strlen(buffer), script);
    fwrite(" ", sizeof(char), 1, script);
    my_revstr(nb_to_str(random_range(0, 1079), buffer, true));
    fwrite(buffer, sizeof(char), my_strlen(buffer), script);
    fwrite(" ", sizeof(char), 1, script);
    my_revstr(nb_to_str(random_range(min, max), buffer, true));
    fwrite(buffer, sizeof(char), my_strlen(buffer), script);
}

void generate_aircraft(FILE *script)
{
    int i = 0;
    char buffer[5] = {'\0'};

    fwrite("A ", sizeof(char), 2, script);
    while (i < 2) {
        my_revstr(nb_to_str(random_range(0, 1919), buffer, true));
        fwrite(buffer, sizeof(char), my_strlen(buffer), script);
        fwrite(" ", sizeof(char), 1, script);
        my_revstr(nb_to_str(random_range(0, 1079), buffer, true));
        fwrite(buffer, sizeof(char), my_strlen(buffer), script);
        fwrite(" ", sizeof(char), 1, script);
        ++i;
    }
    my_revstr(nb_to_str(random_range(1, 100), buffer, true));
    fwrite(buffer, sizeof(char), my_strlen(buffer), script);
    fwrite(" ", sizeof(char), 1, script);
    my_revstr(nb_to_str(random_range(0, 10), buffer, true));
    fwrite(buffer, sizeof(char), my_strlen(buffer), script);
}