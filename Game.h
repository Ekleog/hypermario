/*!
 * \file Game.h
 * \author Lenoa
 */

#ifndef GAME_INCLUDED
#define GAME_INCLUDED 1

#include <SFML/Graphics.hpp>

#include "Map.h"

/*!
 * \class Game
 * \brief It models a game of Hypermario
 */
class Game
{
    private:
        sf::RenderWindow *myWindow; //!< The window in which render the game
        Map *myMap; //!< The map to play

    public:
        static unsigned int const framerate = 40; //!< The frame rate limit

        Game(sf::RenderWindow &Window, Map &GameMap);
        void Run();
};

#endif // GAME_INCLUDED
