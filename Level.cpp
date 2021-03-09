#include "Level.h"


Level::Level(const std::string &file_name, Neighbour levels, int index, char type)
{
    
    if (file_name != " ")
    {
        std::ifstream file(file_name);

        if (!file.is_open())
            throw 'L';
    
            
        char type;
        int i = WINDOW_HEIGHT_PIXEL - 1, j = -1;

        objects = new GameObject[WINDOW_WIDTH_PIXEL * WINDOW_HEIGHT_PIXEL];

        while(!file.eof())
        {
            file.get(type);
            j++;
        
            if (type == '\n')
            {
                i--;
                j = -1;
                continue;
            }

            if ((j == WINDOW_WIDTH_PIXEL / 2 - 1) || (j == WINDOW_WIDTH_PIXEL / 2))
            {
                if ((i == WINDOW_HEIGHT_PIXEL - 1) && (levels.up != 0))
                    type = 'x';
                else if ((i == 0) && (levels.down != 0))
                    type = 'x';
            }
        
            if ((i == WINDOW_HEIGHT_PIXEL / 2 - 1) || (i == WINDOW_HEIGHT_PIXEL / 2))
            {
                if ((j == 0) && (levels.left != 0))
                    type = 'x';
                else if ((j == WINDOW_WIDTH_PIXEL - 1) && (levels.right != 0))
                    type = 'x';
            }

            if (index == 20)
            {
                if((i == 0) && ((j == WINDOW_WIDTH_PIXEL / 2) || (j == WINDOW_WIDTH_PIXEL / 2 - 1)))
                    type = 'Q';
            }
        
            objects[i*WINDOW_WIDTH_PIXEL + j] = GameObject(type,{.x = j * tileSize, .y = i *  tileSize});
        }
        file.close();
    }
    else
        objects = nullptr;
    this->levels = levels;
    this->index = index;
    this->type = type;

};

Level::~Level()
{
    if (objects != nullptr)
    {
        delete[] objects;
        objects = nullptr;
    }
}

int Level::get_index() const
{
    return index;
}

Neighbour Level::get_neighbour() const
{
    return levels;
}

GameObject* Level::get_objects() const
{
    GameObject* copy = new GameObject[WINDOW_HEIGHT_PIXEL * WINDOW_WIDTH_PIXEL];
    for(int i = 0; i < WINDOW_WIDTH_PIXEL * WINDOW_HEIGHT_PIXEL; ++i)
        copy[i] = objects[i];
    return copy;
}

Level& Level::operator= (const Level& other)
{
    if (index != other.get_index())
    {
        index = other.get_index();
        levels = other.get_neighbour();
        if (objects)
            delete[] objects;
        objects = other.get_objects();
    }

    return *this;
}

char Level::tile_type(int coord_x, int coord_y)
{
    return objects[(coord_y / tileSize) * WINDOW_WIDTH_PIXEL + (coord_x / tileSize)].getType();
}

Level::Level(const Level& other)
{
    index = other.get_index();
    levels = other.get_neighbour();
    objects = other.get_objects();
}

int Level::get_next(int side)
{
    switch (side)
    {
        case 1:
            return levels.up;
            break;
        case 2:
            return levels.right;
            break;
        case 3:
            return levels.down;
            break;
        case 4:
            return levels.left;
            break;
    }
    return 0;
}