/**
 * @version 1.0
 *
 * @author Lenoa
 */

#ifndef GAME_INCLUDED
#define GAME_INCLUDED 1

#include <SFML/Graphics.hpp>

#include "Map.h"

/**
 * It models a game of Hypermario
 *
 * @see Map
 * @version 1.0
 *
 * @author Lenoa
 */
class Game
{
	private:
		/**
		 * The window in which render the game
		 *
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		sf::RenderWindow *myWindow;

		/**
		 * The map to play
		 *
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		Map *myMap;

	public:
		/**
		 * The default constructor
		 *
		 * <b>ATTENTION :</b> Do not delete the window/game map before the Game object, otherwise the Game object won't be valid !
		 *
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		Game(sf::RenderWindow &Window, Map &GameMap)
			: myWindow(&Window), myMap(&GameMap) {}

		/**
		 * The method to call to make the game play
		 *
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		void Run();
};

#endif // GAME_INCLUDED

