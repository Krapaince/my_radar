/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** contain the struct defenition
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    typedef struct error
    {
        FILE *script;
        char *buffer;
        size_t n;
        int atot;
        int line;
    } error_t;
    typedef struct aircraft
    {
        float x0;
        float y0;
        float x1;
        float y1;
        float v_x;
        float v_y;
        float width;
        float height;
        float delta_time;
        bool x;
        bool y;
        float angle;
        int destroy;
        struct aircraft *qtree_next;
        struct aircraft *next;
    } aircraft_t;
    typedef struct tower
    {
        int x;
        int y;
        int radius;
        struct tower *next;
    } tower_t;
    typedef struct
    {
        sfRenderWindow *window;
        sfText *text;
        sfFont *font;
        sfEvent *event;
        sfTexture *t_air;
        sfSprite *s_air;
        sfTexture *t_tow;
        sfSprite *s_tow;
        sfTexture *t_back;
        sfSprite *s_back;
        sfClock *timer;
        sfTime time;
        char *filepath;
        int hitbox;
        bool hitbox_active_switch;
        int sprite;
        bool sprite_active_switch;
        int dt;
        int dt_max;
        int sec;
        unsigned int widht;
        unsigned int height;
    } csfml_t;
    typedef struct qtree
    {
        struct qtree *child[4];
        struct qtree *parent;
        aircraft_t *slot;
        int nb_aircraft;
        int depth;
        float x;
        float y;
        float width;
        float height;
        bool divided;
    } qtree_t;
#endif