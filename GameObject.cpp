#include "GameObject.h"


GameObject::GameObject(char type, Point coord )
{
    this->type = type;
    this->coord = coord;
};

char GameObject::getType() const
{
    return type;
}

Point GameObject::getCoord() const
{
    return coord;
}
