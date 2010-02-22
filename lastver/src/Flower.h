// Flower.h
// By Monsieur_JaKy for hypermario project


#ifndef FLOWER_H
#define FLOWER_H

#include "Enemy.h"

class Flower : public Enemy
{
    public:
        Flower(Map* );
        virtual ~Flower();

        virtual void evolue(void);

    private:
};

#endif // FLOWER_H
