#include "Tile.h"

Tile::Tile()
{
    player_up1 = Image("./resources/up1.png").get_image();
    player_up2 = Image("./resources/up2.png").get_image();
    player_down1 = Image("./resources/down1.png").get_image();
    player_down2 = Image("./resources/down2.png").get_image();
    player_left1 = Image("./resources/left1.png").get_image();
    player_left2 = Image("./resources/left2.png").get_image();
    player_right1 = Image("./resources/right1.png").get_image();
    player_right2 = Image("./resources/right2.png").get_image();
    wall = Image("./resources/wall.png").get_image();
    door1 = Image("./resources/door1.png").get_image();
    door2 = Image("./resources/door2.png").get_image();
    door3 = Image("./resources/door3.png").get_image();
    door4 = Image("./resources/door4.png").get_image();
    under = Image("./resources/under.png").get_image();
    exit = Image("./resources/exit.png").get_image();
    trap1 = Image("./resources/trap1.png").get_image();
    trap2 = Image("./resources/trap2.png").get_image();
    trap3 = Image("./resources/trap3.png").get_image();
    empty1 = Image("./resources/empty1.png").get_image(); 
    empty2 = Image("./resources/empty2.png").get_image(); 
    empty3 = Image("./resources/empty3.png").get_image(); 
    enemydown1 = Image("./resources/enemydown1.png").get_image();
    enemydown2 = Image("./resources/enemydown2.png").get_image();
    enemydown3 = Image("./resources/enemydown3.png").get_image();
    enemyright1 = Image("./resources/enemyright1.png").get_image();
    enemyright2 = Image("./resources/enemyright2.png").get_image();
    enemyright3 = Image("./resources/enemyright3.png").get_image();
    enemyup1 = Image("./resources/enemyup1.png").get_image();
    enemyup2 = Image("./resources/enemyup2.png").get_image();
    enemyup3 = Image("./resources/enemyup3.png").get_image();
    enemyleft1 = Image("./resources/enemyleft1.png").get_image();
    enemyleft2 = Image("./resources/enemyleft2.png").get_image();
    enemyleft3 = Image("./resources/enemyleft3.png").get_image();

    player = player_left1;
    trap = trap1;
    empty = empty2;
    door = door1;
    enemy1 = enemyup1;
    enemy2 = enemyup3;

}

Tile::~Tile()
{
    if(player_down1)
        delete[] player_down1;
    if(player_down2)
        delete[] player_down2;
    if(player_left1)
        delete[] player_left1;
    if (player_left2)
        delete[] player_left2;
    if (player_up1)
        delete[] player_up1;
    if (player_up2)
        delete[] player_up2;
    if (wall)
        delete [] wall;
    if (door1)
        delete [] door1;
    if (door2)
        delete [] door2;
    if (door3)
        delete [] door3;
    if (door4)
        delete [] door4;
    if (under)
        delete [] under;
    if (exit)
        delete [] exit;
    if (trap1)
        delete [] trap1;
    if(trap2)
        delete [] trap2;
    if(trap3)
        delete [] trap3;
    if (empty1)
        delete [] empty1; 
    if (empty2)
        delete [] empty2; 
    if (empty3)
        delete [] empty3; 
    if (enemyup1) delete [] enemyup1; if (enemyup2) delete [] enemyup2; if (enemyup3) delete [] enemyup3; 
    if (enemyleft1) delete [] enemyleft1; if (enemyleft2) delete [] enemyleft2; if (enemyleft3) delete [] enemyleft3; 
    if (enemyright1) delete [] enemyright1; if (enemyright2) delete [] enemyright2; if (enemyright3) delete [] enemyright3; 
    if (enemydown1) delete [] enemydown1; if (enemydown2) delete [] enemydown2; if (enemyup3) delete [] enemydown3;
   

    trap = player_up1 = player_up2 = player_left1 = nullptr;
    player_left2 = player_down1 = player_down2 = player_right1 = nullptr;
    player_right2 = player = wall = door = under = exit = nullptr;
    trap1 = trap2 = trap3 = empty = empty1 = empty2 = empty3 = nullptr;   
    door1 = door2 = door3 = door4 = nullptr;
    enemyup1 =enemyup2 = enemyup3 = nullptr;
    enemyleft1 = enemyleft2 = enemyleft3 = nullptr;
    enemydown1 = enemydown2 = enemydown3 = nullptr;
    enemyright1 = enemyright2 = enemyright3 =nullptr;
    enemy1 = enemy2 = nullptr;

}

void Tile::load_back(Level& level, Image& screen)
{
    GameObject * object = level.get_objects();
    for (int i = 0; i < WINDOW_WIDTH_PIXEL * WINDOW_HEIGHT_PIXEL; ++i)
    {
        this->Draw(object[i].getType(), object[i].getCoord(), screen);
    }
    delete[] object;
}

void Tile::Draw(char type, Point coord, Image& screen)
{
    switch (type)
    {
    case '.':
        for(int y = coord.y; y < coord.y + tileSize; ++y)
        {
            for(int x = coord.x; x < coord.x + tileSize; ++x)
            {
                screen.PutPixelBack(x,y, under[(tileSize + coord.y - y - 1) * tileSize + x - coord.x]);
                screen.PutPixel(x,y,under[(tileSize + coord.y - y - 1) * tileSize + x - coord.x]);
            }
        }
        break;
    case '#':
        for(int y = coord.y; y < coord.y + tileSize; ++y)
        {
            for(int x = coord.x; x < coord.x + tileSize; ++x)
            {
                screen.PutPixelBack(x,y, wall[(tileSize + coord.y - y - 1) * tileSize + x - coord.x]);
                screen.PutPixel(x,y,wall[(tileSize + coord.y - y - 1) * tileSize + x - coord.x]);
            }
        }
        break;
    case 'x':
        for(int y = coord.y; y < coord.y + tileSize; ++y)
        {
            for(int x = coord.x; x < coord.x + tileSize; ++x)
            {
                screen.PutPixelBack(x,y, door[(tileSize + coord.y - y - 1) * tileSize + x - coord.x]);
                screen.PutPixel(x,y,door[(tileSize + coord.y - y - 1) * tileSize + x - coord.x]);
            }
        }
        break;
    case ' ':
        for(int y = coord.y; y < coord.y + tileSize; ++y)
        {
            for(int x = coord.x; x < coord.x + tileSize; ++x)
            {
                screen.PutPixelBack(x,y, empty[(tileSize + coord.y - y - 1) * tileSize + x - coord.x]);
                screen.PutPixel(x,y,empty[(tileSize + coord.y - y - 1) * tileSize + x - coord.x]);
            }
        }
        
        break;
    case 'Q':
        for(int y = coord.y; y < coord.y + tileSize; ++y)
        {
            for(int x = coord.x; x < coord.x + tileSize; ++x)
            {
                screen.PutPixelBack(x,y, exit[(tileSize + coord.y - y - 1) * tileSize + x - coord.x]);
                screen.PutPixel(x,y,exit[(tileSize + coord.y - y - 1) * tileSize + x - coord.x]);
            }
        }
        break;
    case 'T':
        for(int y = coord.y; y < coord.y + tileSize; ++y)
        {
            for(int x = coord.x; x < coord.x + tileSize; ++x)
            {
                screen.PutPixelBack(x,y, trap[(tileSize + coord.y - y - 1) * tileSize + x - coord.x]);
                screen.PutPixel(x,y, trap[(tileSize + coord.y - y - 1) * tileSize + x - coord.x]);
            }
        }
        break;
    
    default:
        break;
    }
}

void Tile::Draw_player(Point coords, Point old_coords, Image& screen)
{
    for(int y = old_coords.y; y <= old_coords.y + tileSize; ++y)
    {
      for(int x = old_coords.x; x <= old_coords.x + tileSize; ++x)
      {
        screen.PutPixel(x, y, screen.GetPixel(x,y));
      }
    }


   for(int y = coords.y; y < coords.y + tileSize; ++y)
    {
        for(int x = coords.x; x < coords.x + tileSize; ++x)
        {
            screen.PutPixel(x,y, player[(tileSize + coords.y - y - 1) * tileSize + x - coords.x]);
        }
    }
}

void Tile::Draw_enemy1(Point coords, Point old_coords, Image& screen)
{
    for(int y = old_coords.y; y <= old_coords.y + tileSize; ++y)
    {
      for(int x = old_coords.x; x <= old_coords.x + tileSize; ++x)
      {
        screen.PutPixel(x, y, screen.GetPixel(x,y));
      }
    }


   for(int y = coords.y; y < coords.y + tileSize; ++y)
    {
        for(int x = coords.x; x < coords.x + tileSize; ++x)
        {
            screen.PutPixel(x,y, enemy1[(tileSize + coords.y - y - 1) * tileSize + x - coords.x]);
        }
    }
}

void Tile::Draw_enemy2(Point coords, Point old_coords, Image& screen)
{
    for(int y = old_coords.y; y <= old_coords.y + tileSize; ++y)
    {
      for(int x = old_coords.x; x <= old_coords.x + tileSize; ++x)
      {
        screen.PutPixel(x, y, screen.GetPixel(x,y));
      }
    }


   for(int y = coords.y; y < coords.y + tileSize; ++y)
    {
        for(int x = coords.x; x < coords.x + tileSize; ++x)
        {
            screen.PutPixel(x,y, enemy2[(tileSize + coords.y - y - 1) * tileSize + x - coords.x]);
        }
    }
}

void Tile::player_pic(int side)
{
    switch (side)
    {
        case 1:
            if (up == false)
            {
                player = player_up2;
                up = true;
            }
            else
            {
                player = player_up1;
                up = false;
            }
            break;
        case 2:
            if (right == false)
            {
                player = player_right2;
                right = true;
            }
            else
            {
                player = player_right1;
                right = false;
            }
            break;
        case 3:
            if (down == false)
            {
                player = player_down2;
                down = true;
            }
            else
            {
                player = player_down1;
                down = false;
            }
            break;
        case 4:
            if (left == false)
            {
                player = player_left2;
                left = true;
            }
            else
            {
                player = player_left1;
                left = false;
            }
            break;
    }
}

void Tile::player_left()
{
    player = player_left1;
}

void Tile::player_right()
{
    player = player_right1;
}

void Tile::player_up()
{
    player = player_up1;
}

void Tile::player_down()
{
    player = player_down1;
}

void Tile::enemy_pic(int num, int side)
{
    switch (side)
    {
        case 1:
        if (num == 1)
        {
            if (animaup1 == 1)
            {
                enemy1 = enemyup2;
                animaup1 = 2;
            }
            else if (animaup1 == 2)
            {
                enemy1 = enemyup3;
                animaup1 = 3;
            }
            else
            {
                enemy1 = enemyup1;
                animaup1 = 1;
            }
        }
        else
        {
            if (animaup2 == 1)
            {
                enemy2 = enemyup2;
                animaup2 = 2;
            }
            else if (animaup2 == 2)
            {
                enemy2 = enemyup3;
                animaup2 = 3;
            }
            else
            {
                enemy2 = enemyup1;
                animaup2 = 1;
            }
        }
            break;
        case 2:
            if (num == 1)
        {
            if (animaright1 == 1)
            {
                enemy1 = enemyright2;
                animaright1 = 2;
            }
            else if (animaright1 == 2)
            {
                enemy1 = enemyright3;
                animaright1 = 3;
            }
            else
            {
                enemy1 = enemyright1;
                animaright1 = 1;
            }
        }
        else
        {
            if (animaright2 == 1)
            {
                enemy2 = enemyright2;
                animaright2 = 2;
            }
            else if (animaright2 == 2)
            {
                enemy2 = enemyright3;
                animaright2 = 3;
            }
            else
            {
                enemy2 = enemyright1;
                animaright2 = 1;
            }
        }
            break;
        case 3:
             if (num == 1)
        {
            if (animadown1 == 1)
            {
                enemy1 = enemydown2;
                animadown1 = 2;
            }
            else if (animadown1 == 2)
            {
                enemy1 = enemydown3;
                animadown1 = 3;
            }
            else
            {
                enemy1 = enemydown1;
                animadown1 = 1;
            }
        }
        else
        {
            if (animadown2 == 1)
            {
                enemy2 = enemydown2;
                animadown2 = 2;
            }
            else if (animadown2 == 2)
            {
                enemy2 = enemydown3;
                animadown2 = 3;
            }
            else
            {
                enemy2 = enemydown1;
                animadown2 = 1;
            }
        }
            break;
        case 4:
            if (num == 1)
        {
            if (animaleft1 == 1)
            {
                enemy1 = enemyleft2;
                animaleft1 = 2;
            }
            else if (animaleft1 == 2)
            {
                enemy1 = enemyleft3;
                animaleft1 = 3;
            }
            else
            {
                enemy1 = enemyleft1;
                animaleft1 = 1;
            }
        }
        else
        {
            if (animaleft2 == 1)
            {
                enemy2 = enemyleft2;
                animaleft2 = 2;
            }
            else if (animaleft2 == 2)
            {
                enemy2 = enemyleft3;
                animaleft2 = 3;
            }
            else
            {
                enemy2 = enemyleft1;
                animaleft2 = 1;
            }
        }
            break;
    }
}

void Tile::change_time()
{
    switch (change)
    {
        case 0:
            change++;
            trap = trap2;
            empty = empty3;
            break;
        case 1:
            change++;
            empty = empty2;
            trap = trap3;
            break;
        case 2:
            change++;
            empty = empty1;
            trap = trap2;
            break;
        case 3:
            change = 0;
            empty = empty2;
            trap = trap1;
            break;
        default:
            break;
    }
}

void Tile::open_doors()
{
    switch (door_num)
    {
        case 1:
            door = door2;
            door_num = 2;
            break;
        case 2:
            door = door3;
            door_num = 3;
            break;
        case 3:
            door = door4;
            door_num = 4;
            break;
        case 4:
            door = door1;
            door_num = 1;
            break;
    }
}
