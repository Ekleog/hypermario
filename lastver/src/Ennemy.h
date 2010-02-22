#ifndef ENNEMY_H
#define ENNEMY_H

#include "Mario.h"

 enum ENNEMY
{
    GOOMBA, FLOWER, KOOPA
};

class Ennemy : public sf::Sprite
{
    public:
        Ennemy(Map* );

        virtual ~Ennemy();

        virtual void evolue(void) = 0;
        ENNEMY id(void) const;

        bool& draw(void);
        bool draw(void) const;

    protected:
        WHAT _status;
        sf::Clock _clock;
        sf::Image _img;
        Map* _map;
        ENNEMY _id;
        bool _draw;
};

#endif // ENNEMY_H
