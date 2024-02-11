/*
** EPITECH PROJECT, 2019
** error.h
** File description:
** define the error message
*/

#ifndef ERROR_H_
    #define ERROR_H_
    #define E_MALLOC             "Malloc failled his mission\n"
    #define E_OPEN               "Can't open file\n"
    #define E_LOAD               "Encounter problem when loadind the script\n"
    #define E_LOAD_TOWER         "Encounter problem when loading the tower\n"
    #define E_LOAD_TOWER_ADD     "Encounter problem when adding tower\n"
    #define E_LOAD_AIRCRAFT      "Encounter problem when loading aircraft\n"
    #define E_LOAD_AIRCRAFT_ADD  "Encounter problem when adding aircraft\n"
    #define E_LOAD_SPRITE        "Error when loading sprite\n"
    #define E_LOAD_TEXT          "Error when loading text\n"
    #define E_LOAD_CSFML         "Encounter problem when loading CSFML\n"
    #define E_UPDATE_AIRCRAFT    "Problem when updating aircraft list"
    #define E_SIMU               "Encounter problem during the simulation\n"
    #define E_SCRIPT             "Encounter problem in the script\n"
    #define E_SCRIPT_EMPTY       "The script is empty\nDo I really have to work\
 in this condition?!\n"
    #define E_SCRIPT_TOWER       "Wrong tower description\n"
    #define E_SCRIPT_AIRCRAFT    "Wrong aircraft description\n"
    #define E_SCRIPT_MISS        "Missing information\n"
    #define E_SCRIPT_MISS_S      "Missing space\n"
    #define E_SCRIPT_PARAM       "Wrong parameter\n"
    #define E_SCRIPT_TYPE        "The type must be aircraft(A) or tower(T)\n"
    #define E_SCRIPT_ATA         "Aircraft description after tower\n"
    #define E_LINE               ": error at this line of the script\n"
    #define E_QTREE              "Error quadtree\n"
#endif