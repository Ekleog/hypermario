/**
 * @version 1.1
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
 * @version 1.1
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
		 * It is the position of Mario at its begin place
		 *
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		unsigned long myMarioPosX, myMarioPosY;

		/**
		 * It is the maximum values of X and Y
		 *
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		unsigned long myMaxX, myMaxY;

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
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		Map(const std::string &File, const std::string &Table)
			{ Reload(File, Table); }

		/**
		 * It loads the file to the map
		 *
		 * @param File the file in which load the map
		 * @param Table the file in which load the correspondancy table of the tiles
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		void Reload(const std::string &File, const std::string &Table);

		/**
		 * It just returns Mario's place on the X axis in the file
		 *
		 * @return Mario's X coordinate in the file
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		unsigned long GetMarioPosX() const
			{ return myMarioPosX; }
		/**
		 * It just returns Mario's place on the Y axis in the file
		 *
		 * @return Mario's Y coordinate in the file
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		unsigned long GetMarioPosY() const
			{ return myMarioPosY; }

		/**
		 * This function returns the maximum on the X axis
		 *
		 * @return the maximum value on the X axis
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		unsigned long GetMaxX() const
			{ return myMaxX; }

		/**
		 * This function returns the maximum on the Y axis
		 *
		 * @return the maximum value on the Y axis
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		unsigned long GetMaxY() const
			{ return myMaxY; }

		/**
		 * This function returns the tile at a given place
		 *
		 * @param X the position of the tile on the X axis
		 * @param Y the position of the tile on the Y axis
		 * @return the tile at the position (X;Y)
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		Tile &TileAtPos(size_t X, size_t Y)
			{ return myMap[Y][X]; }
		/**
		 * This function returns the tile at a given place
		 *
		 * @param X the position of the tile on the X axis
		 * @param Y the position of the tile on the Y axis
		 * @return the tile at the position (X;Y)
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		const Tile &TileAtPos(size_t X, size_t Y) const
			{ return myMap[Y][X]; }
};

#endif // MAP_INCLUDED

