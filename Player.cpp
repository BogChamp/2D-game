#include "Player.h"


bool Player::Moved() const
{
  if(coords.x == old_coords.x && coords.y == old_coords.y)
    return false;
  else
    return true;
}

void Player::ProcessInput(MovementDir dir, Level level)
{
  int move_dist = move_speed * 1;
  switch(dir)
  {
    case (MovementDir::UP): 
      this->up += move_dist;    
      if ((level.tile_type(coords.x, coords.y + move_dist + tileSize - 1) != '#') && (level.tile_type(coords.x + tileSize - 1, coords.y + move_dist + tileSize - 1) != '#'))
      {
        if (coords.y + move_dist <= 512 - tileSize - 1)
        {
          old_coords.y = coords.y;
          coords.y += move_dist;
        }
             
        if ((level.tile_type(coords.x, coords.y + tileSize - 1) == 'Q') || (level.tile_type(coords.x, coords.y + tileSize - 1) == 'Q'))
          quit = true;

        if (coords.y >= 512 - tileSize - tileSize/2)
          exit = 1;
      }
      break;
    case (MovementDir::DOWN): 
      this->down += move_dist;
      if ((level.tile_type(coords.x, coords.y - move_dist) != '#') && (level.tile_type(coords.x + tileSize - 1, coords.y - move_dist) != '#'))
      {
        if (coords.y - move_dist >= 0)
        {
          old_coords.y = coords.y;
          coords.y -= move_dist;
        }

        if ((level.tile_type(coords.x, coords.y) == 'Q') || (level.tile_type(coords.x + tileSize - 1, coords.y) == 'Q'))
          quit = true;

        if (coords.y <= tileSize / 2)
        {
          exit = 3;
        }
      }
      break;
    case (MovementDir::LEFT):
      this->left += move_dist;
      if ((level.tile_type(coords.x - move_dist, coords.y) != '#') && (level.tile_type(coords.x - move_dist, coords.y + tileSize - 1) != '#'))
      {
        if (coords.x - move_dist >= 0)
        {
          old_coords.x = coords.x;
          coords.x -= move_dist;
        }

        if ((level.tile_type(coords.x, coords.y) == 'Q') || (level.tile_type(coords.x, coords.y + tileSize - 1) == 'Q'))
          quit = true;

        if (coords.x <= tileSize / 2)
          exit = 4;
      }
      break;
    case (MovementDir::RIGHT):
      this->right += move_dist;
      if ((level.tile_type(coords.x + move_dist + tileSize - 1, coords.y) != '#') && (level.tile_type(coords.x + move_dist + tileSize - 1, coords.y + tileSize - 1) != '#'))
      {
        if (coords.x + move_dist <= 1024 - tileSize - 1)
        {
          old_coords.x = coords.x;
          coords.x += move_dist;
        }

        if ((level.tile_type(coords.x + tileSize - 1, coords.y) == 'Q') || (level.tile_type(coords.x + tileSize - 1, coords.y + tileSize - 1) == 'Q'))
          quit = true;

        if (coords.x >= 1024 - tileSize - tileSize / 2)
          exit = 2;
      }
      break;
    default:
      break;
  }
}

void Player::Draw(Image &screen)
{
  if(Moved())
  {
    for(int y = old_coords.y; y < old_coords.y + tileSize; ++y)
    {
      for(int x = old_coords.x; x < old_coords.x + tileSize; ++x)
      {
        screen.PutPixel(x, y, screen.GetPixel(x,y));
      }
    }
    old_coords = coords;
  }

  for(int y = coords.y; y < coords.y + tileSize; ++y)
  {
    for(int x = coords.x; x < coords.x + tileSize; ++x)
    {
      screen.PutPixel(x, y, color);
    }
  }
}
