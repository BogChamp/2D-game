#ifndef MAIN_MAP_H
#define MAIN_MAP_H

#include "Level.h"

struct Map
{
    Map(const std::string &path = " ", int current = 14);

    ~Map();

    void set_current(int current);

    Level get_current() const;

    private:
        Level* map;
        int current;
};



#endif //MAIN_MAP_H