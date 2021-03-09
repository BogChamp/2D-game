#ifndef MAIN_TILE_H
#define MAIN_TILE_H

#include "Level.h"

struct Tile
{
    Tile();

    ~Tile();

    void load_back(Level& level, Image& screen);

    void Draw(char type, Point coord, Image& screen);

    void Draw_player(Point coords, Point old_coords, Image& screen);
    void Draw_enemy1(Point coords, Point old_coords, Image& screen);
    void Draw_enemy2(Point coords, Point old_coords, Image& screen);

    void player_pic(int side);
    void enemy_pic(int num, int side);

    void change_time();

    void open_doors();

    void player_left();
    void player_right();
    void player_up();
    void player_down();

    Pixel* player; 
    Pixel* player_up1; Pixel* player_up2;
    Pixel* player_down1; Pixel* player_down2;
    Pixel* player_left1; Pixel* player_left2;
    Pixel* player_right1; Pixel* player_right2;
    Pixel* wall;
    Pixel* door; Pixel* door1;
    Pixel* door2; Pixel* door3; Pixel* door4;
    Pixel* under;
    Pixel* exit;
    Pixel* trap; Pixel* trap1; 
    Pixel* trap2;
    Pixel* trap3;
    Pixel* empty; Pixel* empty1; Pixel* empty2; Pixel* empty3;
    Pixel* enemy1; Pixel* enemy2;
    Pixel* enemyup1; Pixel* enemyup2;
    Pixel* enemyup3; Pixel* enemyright1;
    Pixel* enemyright2; Pixel* enemyright3;
    Pixel* enemydown1; Pixel* enemydown2;
    Pixel* enemydown3; Pixel* enemyleft1;
    Pixel* enemyleft2; Pixel* enemyleft3;
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    int change = 0;
    int door_num = 1;
    int animaup1 = 1;
    int animaup2 = 1;
    int animadown1 = 1;
    int animadown2 = 1;
    int animaright1 = 1;
    int animaright2 = 1;
    int animaleft1 = 1;
    int animaleft2 = 1;
};


#endif //MAIN_TILE_H