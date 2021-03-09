#include "Enemy.h"

void Enemy::move(Level level)
{
    switch (state)
    {
        case 1:
            if ((level.tile_type(coords.x, coords.y + speed + tileSize - 1) != '#') && (level.tile_type(coords.x + tileSize - 1, coords.y + speed + tileSize - 1) != '#') && 
            (level.tile_type(coords.x, coords.y + speed + tileSize - 1) != 'T') && (level.tile_type(coords.x, coords.y + speed + tileSize - 1) != 'T') && 
            (level.tile_type(coords.x, coords.y + speed + tileSize - 1) != ' ') && (level.tile_type(coords.x, coords.y + speed + tileSize - 1) != ' ') && 
            (level.tile_type(coords.x, coords.y + speed + tileSize - 1) != 'x') && (level.tile_type(coords.x, coords.y + speed + tileSize - 1) != 'x') && (distance != 200))
            {
                old_coords = coords;
                coords.y += speed;
                distance += speed;
                anima += speed;
            }
            else
            {
                distance = 0;
                state = 2;
                anima = 0;
            }
            break;
        case 2:
            if ((level.tile_type(coords.x - speed, coords.y) != '#') && (level.tile_type(coords.x - speed, coords.y + tileSize - 1) != '#') && 
            (level.tile_type(coords.x - speed, coords.y) != 'T') && (level.tile_type(coords.x - speed, coords.y + tileSize - 1) != 'T') && 
            (level.tile_type(coords.x - speed, coords.y) != ' ') && (level.tile_type(coords.x - speed, coords.y + tileSize - 1) != ' ') && 
            (level.tile_type(coords.x - speed, coords.y) != 'x') && (level.tile_type(coords.x - speed, coords.y + tileSize - 1) != 'x') && (distance != 200))
            {
                old_coords = coords;
                coords.x -= speed;
                distance += speed;
                anima += speed;
            }
            else
            {
                distance = 0;
                state = 3;
                anima = 0;
            }
            break;
        case 3:
            if ((level.tile_type(coords.x, coords.y - speed) != '#') && (level.tile_type(coords.x + tileSize - 1, coords.y - speed) != '#') && 
            (level.tile_type(coords.x, coords.y - speed) != 'T') && (level.tile_type(coords.x + tileSize - 1, coords.y - speed) != 'T') && 
            (level.tile_type(coords.x, coords.y - speed) != ' ') && (level.tile_type(coords.x + tileSize - 1, coords.y - speed) != ' ') && 
            (level.tile_type(coords.x, coords.y - speed) != 'x') && (level.tile_type(coords.x + tileSize - 1, coords.y - speed) != 'x') &&(distance != 200))
            {
                old_coords = coords;
                coords.y -= speed;
                distance += speed;
                anima += speed;
            }
            else
            {
                distance = 0;
                state = 4;
                anima = 0;
            }
            break;
        case 4:
            if ((level.tile_type(coords.x - speed, coords.y) != '#') && (level.tile_type(coords.x - speed, coords.y + tileSize - 1) != '#') && 
            (level.tile_type(coords.x - speed, coords.y) != 'T') && (level.tile_type(coords.x - speed, coords.y + tileSize - 1) != 'T') && 
            (level.tile_type(coords.x - speed, coords.y) != ' ') && (level.tile_type(coords.x - speed, coords.y + tileSize - 1) != ' ') && 
            (level.tile_type(coords.x - speed, coords.y) != 'x') && (level.tile_type(coords.x - speed, coords.y + tileSize - 1) != 'x') &&(distance != 200))
            {
                old_coords = coords;
                coords.x -= speed;
                distance += speed;
                anima += speed;
            }
            else
            {
                distance = 0;
                state = 5;
                anima = 0;
            }
            break;
        case 5:
            if ((level.tile_type(coords.x, coords.y + speed + tileSize - 1) != '#') && (level.tile_type(coords.x + tileSize - 1, coords.y + speed + tileSize - 1) != '#') && 
            (level.tile_type(coords.x, coords.y + speed + tileSize - 1) != 'T') && (level.tile_type(coords.x, coords.y + speed + tileSize - 1) != 'T') && 
            (level.tile_type(coords.x, coords.y + speed + tileSize - 1) != ' ') && (level.tile_type(coords.x, coords.y + speed + tileSize - 1) != ' ') && 
            (level.tile_type(coords.x, coords.y + speed + tileSize - 1) != 'x') && (level.tile_type(coords.x, coords.y + speed + tileSize - 1) != 'x') &&(distance != 200))
            {
                old_coords = coords;
                coords.y += speed;
                distance += speed;
                anima += speed;
            }
            else
            {
                distance = 0;
                state = 6;
                 anima = 0;
            }
            break;
        case 6:
            if ((level.tile_type(coords.x + speed + tileSize - 1, coords.y) != '#') && (level.tile_type(coords.x + speed + tileSize - 1, coords.y + tileSize - 1) != '#') && 
            (level.tile_type(coords.x + speed + tileSize - 1, coords.y) != 'T') && (level.tile_type(coords.x + speed + tileSize - 1, coords.y + tileSize - 1) != 'T') && 
            (level.tile_type(coords.x + speed + tileSize - 1, coords.y) != ' ') && (level.tile_type(coords.x + speed + tileSize - 1, coords.y + tileSize - 1) != ' ') && 
            (level.tile_type(coords.x + speed + tileSize - 1, coords.y) != 'x') && (level.tile_type(coords.x + speed + tileSize - 1, coords.y + tileSize - 1) != 'x') && (distance != 200))
            {
                old_coords = coords;
                coords.x += speed;
                distance += speed;
                anima += speed;
            }
            else
            {
                distance = 0;
                state = 7;
                anima = 0;
            }
            break;
        case 7:
            if ((level.tile_type(coords.x, coords.y - speed) != '#') && (level.tile_type(coords.x + tileSize - 1, coords.y - speed) != '#') && 
            (level.tile_type(coords.x, coords.y - speed) != 'T') && (level.tile_type(coords.x + tileSize - 1, coords.y - speed) != 'T') && 
            (level.tile_type(coords.x, coords.y - speed) != ' ') && (level.tile_type(coords.x + tileSize - 1, coords.y - speed) != ' ') && 
            (level.tile_type(coords.x, coords.y - speed) != 'x') && (level.tile_type(coords.x + tileSize - 1, coords.y - speed) != 'x') && (distance != 200))
            {
                old_coords = coords;
                coords.y -= speed;
                distance += speed;
                anima += speed;
            }
            else
            {
                distance = 0;
                state = 8;
                anima = 0;
            }
            break;
        case 8:
            if ((level.tile_type(coords.x + speed + tileSize - 1, coords.y) != '#') && (level.tile_type(coords.x + speed + tileSize - 1, coords.y + tileSize - 1) != '#') && 
            (level.tile_type(coords.x + speed + tileSize - 1, coords.y) != 'T') && (level.tile_type(coords.x + speed + tileSize - 1, coords.y + tileSize - 1) != 'T') && 
            (level.tile_type(coords.x + speed + tileSize - 1, coords.y) != ' ') && (level.tile_type(coords.x + speed + tileSize - 1, coords.y + tileSize - 1) != ' ') && 
            (level.tile_type(coords.x + speed + tileSize - 1, coords.y) != 'x') && (level.tile_type(coords.x + speed + tileSize - 1, coords.y + tileSize - 1) != 'x') &&(distance != 200))
            {
                old_coords = coords;
                coords.x += speed;
                distance += speed;
                anima += speed;
            }
            else
            {
                distance = 0;
                state = 1;
                anima = 0;
            }
            break;
    }
}