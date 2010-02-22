// Game.h
// By Monsieur_JaKy for hypermario project

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

const sf::Color mask(208, 214, 226);

const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDHT = 640;

#include "Map.h"
#include "Mario.h"
#include "Enemy.h"

#include <list> // std::list<Enemy* >

class Game : public sf::RenderWindow
{
public:
    Game();

    virtual ~Game();

    void drawAll(void);

    void checkEvent(void);

    void evolue(void);

private:
    void loadEnemys(void);

    // Functions about Enemys (used with std::for_each)
    void _drawEnemy(const Enemy* ) ;
    void _deleteEnemy(Enemy* ) ;
    void _EnemyEvolue(Enemy* ) ;

    Map _map;
    Mario* _mario;

    sf::Clock _clock;

    std::list<Enemy* > _Enemys;
};

#endif // GAME_H
