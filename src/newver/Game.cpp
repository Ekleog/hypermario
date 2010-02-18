#include "Game.h"

#include <SFML/Graphics.hpp>

#include "Mario.h"

/**
 * The method to call to make the game play
 *
 * @version 1.0
 *
 * @author Lenoa
 */
void Game::Run()
{
	Mario mario = Mario(myMap->GetMarioPosX(), myMap->GetMarioPosY(), *myMap);
	bool Stop = false;
	while(!Stop)
	{
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
		myWindow->SetView(mario.GetView());
		myWindow->Clear();
		myWindow->Draw(*myMap);
		myWindow->Draw(mario);
		myWindow->Display();
	}
}

