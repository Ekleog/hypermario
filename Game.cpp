/*!
 * \file Game.cpp
 * \author Ekinox <ekinox1995@gmail.com>
 */

#include "Game.h"

#include <SFML/Graphics.hpp>

#include "Mario.h"
#include "config.h"

/*!
 * \param Window the window on which render the game
 * \param GameMap the map to play
 * \brief The default constructor
 *
 * <b>BE CAREFUL :</b> Do not delete the window/game map before the
 * Game object, otherwise the Game object won't be valid !
 */
Game::Game(sf::RenderWindow &Window, Map &GameMap) :
    myWindow(&Window), myMap(&GameMap)
{
}

/*!
 * \brief The method to call to make the game play
 */
void Game::Run()
{
    // Set the frame rate
    myWindow->SetFramerateLimit(framerate);

    // Initialize Mario
    Mario mario =
            Mario(myMap->GetMarioPosX(), myMap->GetMarioPosY(), *myMap, 3);

    // Main loop
    bool Stop = false;
    while (!Stop)
    {
        // Event managing
        sf::Event Event;
        while (myWindow->GetEvent(Event))
        {
            switch (Event.Type)
            {
                case sf::Event::Closed:
                    return;

                case sf::Event::KeyPressed:
                    switch (Event.Key.Code)
                    {
                        case sf::Key::Escape:
                            return;

                        case sf::Key::Left:
                            mario.GoLeft();
                            break;

                        case sf::Key::Right:
                            mario.GoRight();
                            break;

                        case sf::Key::Up:
                            mario.Jump();
                            break;

                        case sf::Key::R:
                            mario.Run();
                            break;

                        default:
                            break;
                    }
                    break;

                case sf::Event::KeyReleased:
                    switch (Event.Key.Code)
                    {
                        case sf::Key::Left:
                            mario.StopGoingLeft();
                            break;

                        case sf::Key::Right:
                            mario.StopGoingRight();
                            break;

                        case sf::Key::R:
                            mario.StopRunning();
                            break;

                        default:
                            break;
                    }

                default:
                    break;
            }
        }

        // Update the map and all which is on it
        mario.Update();

        // If Mario lost, close
        if (mario.Lost())
            return;

        // Update the view
        myWindow->SetView(mario.GetView());

        // Redraw the screen
        myWindow->Clear(BACKGROUND_COLOR);
        myWindow->Draw(*myMap);
        myWindow->Draw(mario);
        myWindow->Display();
    }
}

