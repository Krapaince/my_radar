/*
** EPITECH PROJECT, 2019
** csfml.h
** File description:
** include for csfml
*/

#ifndef CSFML_H_
    #define CSFML_H_
    #define WIDTH  1920
    #define HEIGHT 1080
    #define MODE   7
    #define FPS    30
    #define AIRCRAFT_FILEPATH   "resources/aircraft.png"
    #define BACKGROUND_FILEPATH "resources/background.png"
    #define TOWER_FILEPATH      "resources/radar.png"
    //Alloc
    csfml_t *alloc_csfml(unsigned int width, unsigned int height);
    sfRenderWindow *create_window(unsigned int width, unsigned int height);
    //Init
    int init_sprite(sfSprite **sprite, sfTexture **texture, char *filepath);
    int init_csfml(csfml_t *csfml);
    bool init_text(sfText **text, sfFont **font);
    //Display
    void display_aircraft(csfml_t *csfml, aircraft_t *aircraft,
    sfRectangleShape *rect, sfVector2f *position);
    void display_tower(csfml_t *csfml, tower_t *tower, sfCircleShape *circle);
    bool create_hitbox_shape(sfRectangleShape **rect, sfCircleShape **circle);
    bool display(csfml_t *csfml, aircraft_t *aircraft, tower_t *tower,
    qtree_t *tree);
    //Event
    void event_check(csfml_t *csfml, sfEvent *event, aircraft_t *aircraft);
    bool time_update(csfml_t *csfml);
    //Destroy
    void destroy_csfml(csfml_t *csfml);
#endif