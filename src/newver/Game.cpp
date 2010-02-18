/**
 * @author Lenoa
 */

#include "Game.h"

#include <SFML/Graphics.hpp>

#include "Mario.h"

/**
 * The method to call to make the game play
 *
 * @author Lenoa
 */
void Game::Run()
{
	// Set the frame rate
	myWindow->SetFramerateLimit(26);

	// Initialise the Mario
	Mario mario = Mario(myMap->GetMarioPosX(), myMap->GetMarioPosY(), *myMap);

	// Main loop
	bool Stop = false;
	while(!Stop)
	{
		// Event managing
		sf::Event Event;
		while(myWindow->GetEvent(Event))
		{
			switch(Event.Type)
			{
				case sf::Event::Closed:
					return;

				case sf::Event::KeyPressed:
					switch(Event.Key.Code)
					{
						case sf::Key::Escape:
							return;
						
						case sf::Key::Left:
							if(mario.CanGoLeft())
								mario.GoLeft();
							break;

						case sf::Key::Right:
							if(mario.CanGoRight())
								mario.GoRight();

						default:
							break;
					}
					break;
		
				default:
					break;
			}
		}

		// Update the map and all which is on it
		mario.Update();

		// Update the view
		myWindow->SetView(mario.GetView());
		
		// Redraw the screen
		myWindow->Clear();
		myWindow->Draw(*myMap);
		myWindow->Draw(mario);
		myWindow->Display();
	}
}

