// Goomba.h
// By Monsieur_JaKy for hypermario project

#ifndef GOOMBA_H
#define GOOMBA_H

#include "Enemy.h"

class Goomba : public Enemy
{
    public:
        Goomba(Map* ) ;

        virtual ~Goomba() ;

        virtual void evolue(void) ;
        bool detectCollision(WHAT ) ;

    private:
        WHAT _direction;

} ;

#endif // GOOMBA_H
