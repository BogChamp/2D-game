#ifndef MAIN_PLAYER_H
#define MAIN_PLAYER_H

#include "Level.h"


enum class MovementDir
{
  UP,
  DOWN,
  LEFT,
  RIGHT
};

struct Player
{
  int exit = 0;
  int up = 0;
  int down = 0;
  int left = 0;
  int right = 0;

  explicit Player(Point pos = {.x = 10, .y = 10}) :
                 coords(pos), old_coords(coords) {};

  Point get_coords() { return coords;}
  Point get_old_coords() {return old_coords;}
  bool Moved() const;
  void ProcessInput(MovementDir dir, Level level);
  void Draw(Image &screen);
  bool finish() {return quit;}
  void set_pos(Point coords){this->coords.x = coords.x; this->coords.y = coords.y; this->old_coords.x = coords.x; this->old_coords.y = coords.y;}

  Point coords {.x = 10, .y = 10};
  Point old_coords {.x = 10, .y = 10};
  Pixel color {.r = 255, .g = 255, .b = 0, .a = 0};
  int move_speed = 1;
  int is_dead = 0;
  bool quit = false;
  char direction = 'a';
};

#endif //MAIN_PLAYER_H
