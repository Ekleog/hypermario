/**
 * @author Lenoa
 */

#ifndef GAME_INCLUDED
#define GAME_INCLUDED 1

#include <SFML/Graphics.hpp>

#include "Map.h"

/**
 * It models a game of Hypermario
 *
 * @author Lenoa
 */
class Game
{
	private:
		/**
		 * The window in which render the game
		 */
		sf::RenderWindow *myWindow;

		/**
		 * The map to play
		 */
		Map *myMap;

	public:
		/**
		 * The default constructor
		 *
		 * <b>ATTENTION :</b> Do not delete the window/game map before the Game object, otherwise the Game object won't be valid !
		 *
		 * @param Window the window on which render the game
		 * @param GameMap the map to play
		 */
		Game(sf::RenderWindow &Window, Map &GameMap)
			: myWindow(&Window), myMap(&GameMap) {}

		/**
		 * The method to call to make the game play
		 */
		void Run();
};

#endif // GAME_INCLUDED

