/*
** EPITECH PROJECT, 2019
** load_tower.c
** File description:
** load the tower in a structure
*/

#include "lib.h"
#include "struct.h"
#include "script.h"
#include "error.h"

char *get_next_tower(FILE *script)
{
    char *buffer = NULL;
    size_t n = 0;

    while (getline(&buffer, &n, script) != -1) {
        if (buffer[0] == 'T')
            return (buffer);
        free(buffer);
        buffer = NULL;
    }
    free(buffer);
    return (NULL);
}

void init_tower(tower_t *new, char *tower_info)
{
    int i = 2;
    int nb = 0;
    int n = 0;
    int *int_selector[] = {&new->x, &new->y, &new->radius};

    while (n < 3) {
        nb = my_getnbr(&tower_info[i]);
        *int_selector[n] = nb;
        i += 1 + len_nb(nb);
        ++n;
    }
    new->next = NULL;
}

int add_tower(tower_t **tower, char *tower_info)
{
    tower_t *new = malloc(sizeof(tower_t));

    if (!new) {
        my_putstr(E_MALLOC, STDERR_FILENO);
        return (84);
    }
    init_tower(new,tower_info);
    if (*tower)
        new->next = *tower;
    *tower = new;
    return (0);
}

int load_tower(tower_t **tower, char *filepath)
{
    FILE *script = fopen(filepath, "r");
    char *tower_info = NULL;

    if (!script) {
        my_putstr(E_OPEN, STDERR_FILENO);
        return (84);
    }
    tower_info = get_next_tower(script);
    while (tower_info) {
        if (add_tower(tower, tower_info) == 84) {
            my_putstr(E_LOAD_TOWER_ADD, STDERR_FILENO);
            return (84);
        }
        free(tower_info);
        tower_info = get_next_tower(script);
    }
    free(tower_info);
    fclose(script);
    return (0);
}