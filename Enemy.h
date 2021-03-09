#ifndef MAIN_ENEMY_H
#define MAIN_ENEMY_H

#include "Level.h"

struct Enemy
{

    explicit Enemy(Point pos = {.x = 10, .y = 10}) :
                 coords(pos), old_coords(coords) {};

    void move(Level level);
    void set_pos(Point coords){this->coords.x = coords.x; this->coords.y = coords.y; this->old_coords.x = coords.x; this->old_coords.y = coords.y;}

    Point coords {.x = 10, .y = 10};
    Point old_coords {.x = 10, .y = 10};
    int speed = 1;
    int distance = 0;
    int state = 1;
    int anima = 0;
    char direction = 'w';
};


#endif //MAIN_ENEMY_H