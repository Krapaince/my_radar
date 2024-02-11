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

bool error(generator_t *gen)
{
    if (gen->nb_air < 0 || gen->nb_tow < 0 || gen->dt_min < 0
    || gen->dt_max < gen->dt_min || gen->v_min <= 0 || gen->v_max < gen->v_min
    || gen->r_min < 0 || gen->r_max < gen->r_min) {
        my_putstr("Error in input param\n", STDERR_FILENO);
        return (false);
    }
    return (true);
}

bool get_param(generator_t *gen, char **ag)
{
    int *gen_init[] = {&gen->nb_air, &gen->dt_min, &gen->dt_max, &gen->v_min,
    &gen->v_max, &gen->nb_tow, &gen->r_min, &gen->r_max};
    int i = 0;

    while (i < 8) {
        *gen_init[i] = my_getnbr(ag[i + 2]);
        ++i;
    }
    return (error(gen));
}

void generate_script(FILE *script, generator_t *generator)
{
    int i = 0;
    char *end = "\n";

    while (i < generator->nb_air) {
        generate_aircraft(script, generator);
        fwrite(end, sizeof(char), 1, script);
        ++i;
    }
    i = 0;
    while (i < generator->nb_tow) {
        generate_tower(script, generator->r_min, generator->r_max);
        fwrite(end, sizeof(char), 1, script);
        ++i;
    }
}

int main(int ac, char **ag)
{
    FILE *script = NULL;
    generator_t generator = {0, 0, 0, 0, 0, 0, 0, 0};

    if (ac != 10 && ac != 2) {
        cat("resources/error.txt", STDERR_FILENO);
        return (84);
    } else if (ac == 2 && my_strcmp(ag[1], "-h") == 0)
        return (cat("resources/usage_generator.txt", STDOUT_FILENO));
    script = fopen(ag[1], "a");
    if (!script || !get_param(&generator, ag))
        return (84);
    srand(time(NULL));
    generate_script(script, &generator);
    fclose(script);
    return (0);
}