/**
 * @version 1.0
 *
 * @author Lenoa
 */

#ifndef MAP_INCLUDED
#define MAP_INCLUDED 1

#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

#include "Tile.h"

/**
 * This class models a map of the game HyperMario : a double array of tiles.
 *
 * It should be drawed after the background and before the personnages and monsters.
 *
 * @version 1.0
 *
 * @author Lenoa
 */
class Map : public sf::Drawable
{
	private:
		/**
		 * It is the map : the double array of tiles.
		 *
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		std::vector< std::vector< Tile > > myMap;
		/**
		 * It renders the map to the target
		 *
		 * @param Target the target on which render
		 * @version 1.0
		 * 
		 * @author Lenoa
		 */
		void Render(sf::RenderTarget &Target) const;

	public:
		/**
		 * The constructor.
		 *
		 * @param File the file in which load the map
		 * @param Table the file in which load the correspondancy table of the tiles
		 */
		Map(const std::string &File, const std::string &Table)
			{ Reload(File, Table); }

		/**
		 * It loads the file to the map
		 *
		 * @param File the file in which load the map
		 * @param Table the file in which load the correspondancy table of the tiles
		 */
		void Reload(const std::string &File, const std::string &Table);
};

#endif // MAP_INCLUDED

