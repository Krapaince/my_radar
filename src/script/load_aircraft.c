/*
** EPITECH PROJECT, 2019
** load_aircraft.c
** File description:
** load the aircraft
*/

#include "lib.h"
#include "struct.h"
#include "script.h"
#include "csfml.h"
#include "error.h"

int get_dt(char *buffer)
{
    int i = my_strlen(buffer);
    int dt = 0;

    if (buffer[i - 1] == '\n')
        --i;
    while (0 <= i - 1 && '0' <= buffer[i - 1] && buffer[i - 1] <= '9')
        --i;
    dt = my_getnbr(&buffer[i]);
    return (dt);
}

void set_rotation_and_speed(aircraft_t *new, float *angle)
{
    float delta_x = new->x1 - new->x0;
    float delta_y = new->y1 - new->y0;
    float hypo = sqrt(pow(delta_x, 2) + pow(delta_y, 2));

    *angle = atan2(delta_y, delta_x) * 180 / M_PI + 90;
    if (hypo != 0) {
        new->v_y = (fabs(delta_y / hypo) * new->v_x) / FPS;
        new->v_x = (fabs(delta_x / hypo) * new->v_x) / FPS;
    } else {
        new->v_x = 0;
        new->v_y = 0;
    }
    if (new->x1 < new->x0) {
        new->x = 1;
        new->v_x *= -1;
    }
    if (new->y1 < new->y0) {
        new->y = 1;
        new->v_y *= -1;
    }
}

void init_aircraft(aircraft_t *new, char *aircraft_info)
{
    int i = 2;
    int nb = 0;
    int n = 0;
    float *int_selector[] = {
    &new->x0, &new->y0, &new->x1, &new->y1, &new->v_x, &new->delta_time};

    while (n < 6) {
        nb = my_getnbr(&aircraft_info[i]);
        *int_selector[n] = nb;
        i += 1 + len_nb(nb);
        ++n;
    }
    new->width = 20;
    new->height = 20;
    new->destroy = 0;
    new->next = NULL;
    new->qtree_next = NULL;
    new->depth = 0;
    set_rotation_and_speed(new, &new->angle);
    new->angle = 0;
}

int add_aircraft(aircraft_t **plane, char *aircraft_info, int dt, int *dt_max)
{
    aircraft_t *new = NULL;
    int dt_current = get_dt(aircraft_info);

    if (dt_max && *dt_max < dt_current)
        *dt_max = dt_current;
    if (dt == dt_current) {
        new = malloc(sizeof(aircraft_t));
        if (!new) {
            my_putstr(E_MALLOC, STDERR_FILENO);
            return (84);
        }
        new->x = 0;
        new->y = 0;
        init_aircraft(new, aircraft_info);
        if (*plane)
            new->next = *plane;
        *plane = new;
        }
    return (0);
}

int load_aircraft(aircraft_t **plane, char *filepath, int dt, int *dt_max)
{
    FILE *script = fopen(filepath, "r");
    char *aircraft_info = NULL;
    int r_getline = 0;
    size_t n = 0;

    if (!script) {
        my_putstr(E_OPEN, STDERR_FILENO);
        return (84);
    }
    r_getline = getline(&aircraft_info, &n, script);
    while (r_getline != -1 && aircraft_info[0] == 'A') {
        if (add_aircraft(plane, aircraft_info, dt, dt_max) == 84) {
            my_putstr(E_LOAD_AIRCRAFT_ADD, STDERR_FILENO);
            return (84);
        }
        r_getline = getline(&aircraft_info, &n, script);
    }
    free(aircraft_info);
    fclose(script);
    return (0);
}