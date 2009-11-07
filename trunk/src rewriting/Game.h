#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

const sf::Color mask(208, 214, 226);

const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDHT = 640;

#include "Map.h"
#include "Mario.h"

class Game : public sf::RenderWindow
{
public:
    Game();

    virtual ~Game();

    void drawAll(void);

    void checkEvent(void);

    void evolue(void);

private:
    Map _map;
    Mario* _mario;
};

#endif // GAME_H