#include "Ennemy.h"
#include <iostream>

Ennemy::Ennemy(Map* map) : sf::Sprite()
{
    _map = map;
    _status = ON_THE_GROUND;
    _draw = true;
}

Ennemy::~Ennemy()
{

}

ENNEMY Ennemy::id(void) const
{
    return _id;
}

bool& Ennemy::draw(void)
{
    return _draw;
}

bool Ennemy::draw(void) const
{
    return _draw;
}


