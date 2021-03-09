#include "Map.h"

Map::Map(const std::string &path, int current)
{
    if (path != " ")
    {
        std::ifstream file(path);

        if (!file.is_open())
            throw 'M';

        char labirint[20][20]{};
        int indexes[20][20]{};
        int index = 1;
        char type;

        int i = 0, j = 0;


        while (!file.eof())
        {
            file.get(type);
            if (type == '\n')
            {
                labirint[i][j] = type;
                i++;
                j = 0;
            }
            else 
            {
                labirint[i][j] = type;
                if (type != ' ')
                {
                    indexes[i][j] = index;
                    index++; 
                }
                j++;
            }
        }
        file.close();

        map = new Level[index - 1];

        for (int k = 0; k < 20; k++)
            for(j = 0; j < 20; j++)
            {
            if (labirint[k][j] == '\n')
                break;
            if (labirint[k][j] == ' ')
                continue;
        
            Neighbour neigbor = {0, 0, 0, 0};
            if (j != 0)
                neigbor.left = indexes[k][j - 1];
            if (j != 19)
                neigbor.right = indexes[k][j + 1];
            if (k != 0)
                neigbor.up = indexes[k - 1][j];
            if (k != 19)
                neigbor.down = indexes[k + 1][j];
            
            switch(labirint[k][j])
            {
                case 'A':
                    map[indexes[k][j] - 1] = Level("./resources/A", neigbor, indexes[k][j], labirint[k][j]);
                    break;
                case 'B':
                    map[indexes[k][j] - 1] = Level("./resources/B", neigbor, indexes[k][j], labirint[k][j]);
                    break;
                case 'C':
                    map[indexes[k][j] - 1] = Level("./resources/C", neigbor, indexes[k][j], labirint[k][j]);
                    break;
                case 'D':
                    map[indexes[k][j] - 1] = Level("./resources/D", neigbor, indexes[k][j], labirint[k][j]);  
                    break;
            }
            }
    }
    else
        map = nullptr;
    
    this->current = current;

};

Map::~Map()
{
    if (map)
    {
        delete[] map;
        map = nullptr;
    }
}

void Map::set_current(int current)
{
    this->current = current;
}

Level Map::get_current() const
{
    return map[current - 1];
}