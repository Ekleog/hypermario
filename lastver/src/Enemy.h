// Enemy.h
// By Monsieur_JaKy for hypermario project

#ifndef Enemy_H
#define Enemy_H

#include "Mario.h"

 enum ENEMY
{
    GOOMBA, FLOWER, KOOPA
};

// Virtual abstract class

class Enemy : public sf::Sprite
{
    public:
        Enemy(Map* );

        virtual ~Enemy();

        virtual void evolue(void) = 0;
        ENEMY id(void) const;

        bool& draw(void);
        bool draw(void) const;

    protected:
        WHAT _status;
        sf::Clock _clock;
        sf::Image _img;
        Map* _map;
        ENEMY _id;

        // Draw the Enemy ?
        bool _draw;
};

#endif // Enemy_H
