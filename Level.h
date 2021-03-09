#ifndef MAIN_Level_H
#define MAIN_Level_H

#include <string>
#include <fstream>
#include "GameObject.h"



struct Neighbour
{
    int up;
    int down;
    int left;
    int right;
};

struct Level
{
    Level(const std::string &file_name = " ", Neighbour levels = {.up = 0, .down = 0, .left = 0, .right = 0}, int index = 0, char type = 'N');

    ~Level();

    Level(const Level& other);

    int get_index() const;

    Neighbour get_neighbour() const;

    GameObject* get_objects () const;

    Level& operator= (const Level& other);

    char tile_type(int coord_x, int coord_y);

    int get_next(int side);

    GameObject* objects;
    Neighbour levels;
    int index;
    char type;
};

#endif //MAIN_Level_H