/*!
 * \file main.cpp
 * \author Ekinox <ekinox1995@gmail.com>
 */

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Map.h"
#include "Game.h"
#include "config.h"

/*!
 * \brief The main function of a program which just displays the game
 * \return 0 if success ; 1 otherwise
 */
int main(int, char**)
{
    sf::RenderWindow Window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                            "HyperMario");
    Map map("maps/1.map", "maps/correspondance.table");
    Game game(Window, map);
    game.Run();
    return 0;
}
