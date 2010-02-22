// Enemy.cpp
// By Monsieur_JaKy for hypermario project

#include "Enemy.h"

Enemy::Enemy(Map* map) : sf::Sprite()
{
    _map = map;
    _status = ON_THE_GROUND;
    _draw = true;
}

Enemy::~Enemy()
{

}

ENEMY Enemy::id(void) const
{
    return _id;
}

bool& Enemy::draw(void)
{
    return _draw;
}

bool Enemy::draw(void) const
{
    return _draw;
}


