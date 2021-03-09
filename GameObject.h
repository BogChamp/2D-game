#ifndef MAIN_GameObject_H
#define MAIN_GameObject_H

#include "Image.h"
constexpr int WINDOW_WIDTH_PIXEL = 32, WINDOW_HEIGHT_PIXEL = 16;

struct Point
{
  int x;
  int y;

  bool operator== (const Point& other)
  {
    if ((x == other.x) && (y == other.y))
      return true;
    else  
      return false;
  }
};

struct GameObject
{
    GameObject(char type = 'N', Point coord = {.x = 0, .y = 0});

    char getType() const ;

    Point getCoord() const;

    private:
    char type;
    Point coord;
};


#endif //MAIN_GameObject_H