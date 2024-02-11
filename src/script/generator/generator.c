/*
** EPITECH PROJECT, 2018
** map_generator.c
** File description:
** Generate a correct map
*/

#include "lib.h"
#include "struct.h"
#include "csfml.h"
#include "script.h"

bool get_param(int *nb_aircraft, int tower[], char **ag)
{
    *nb_aircraft = my_getnbr(ag[2]);
    tower[0] = my_getnbr(ag[3]);
    tower[1] = my_getnbr(ag[4]);
    tower[2] = my_getnbr(ag[5]);
    if (tower[0] < 0)
        tower[0] = 0;
    if (*nb_aircraft < 0)
        *nb_aircraft = 0;
    if (tower[1] > tower[2])
        return (false);
    return (true);
}

void generate_script(FILE *script, int nb_aircraft, int *tower)
{
    int i = 0;
    char *end = "\n";

    while (i < nb_aircraft) {
        generate_aircraft(script);
        fwrite(end, sizeof(char), 1, script);
        ++i;
    }
    i = 0;
    while (i < tower[0]) {
        generate_tower(script, tower[1], tower[2]);
        fwrite(end, sizeof(char), 1, script);
        ++i;
    }
}

int main(int ac, char **ag)
{
    FILE *script = NULL;
    int nb_aircraft = 0;
    int tower[3] = {0};

    if (ac != 6)
        return (0);
    script = fopen(ag[1], "a");
    if (!script || !get_param(&nb_aircraft, tower, ag))
        return (84);
    srand(time(NULL));
    generate_script(script, nb_aircraft, tower);
    fclose(script);
    return (0);
}