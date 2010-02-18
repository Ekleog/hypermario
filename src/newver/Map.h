/**
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
 * @author Lenoa
 */
class Map : public sf::Drawable
{
	private:
		/**
		 * It is the map : the double array of tiles.
		 */
		std::vector< std::vector< Tile > > myMap;

		/**
		 * It is the position of Mario at its begin place
		 */
		unsigned long myMarioPosX, myMarioPosY;

		/**
		 * It is the maximum values of X and Y
		 */
		unsigned long myMaxX, myMaxY;

		/**
		 * It renders the map to the target
		 *
		 * @param Target the target on which render
		 */
		void Render(sf::RenderTarget &Target) const;

	public:
		/**
		 * @param File the file in which load the map
		 * @param Table the file in which load the correspondancy table of the tiles
		 */
		Map(const std::string &File, const std::string &Table)
			{ Reload(File, Table); }

		/**
		 * @param File the file in which load the map
		 * @param Table the file in which load the correspondancy table of the tiles
		 */
		void Reload(const std::string &File, const std::string &Table);

		/**
		 * @return Mario's X coordinate in the file
		 */
		unsigned long GetMarioPosX() const
			{ return myMarioPosX; }
		/**
		 * @return Mario's Y coordinate in the file
		 */
		unsigned long GetMarioPosY() const
			{ return myMarioPosY; }

		/**
		 * @return the maximum value on the X axis
		 */
		unsigned long GetMaxX() const
			{ return myMaxX; }

		/**
		 * @return the maximum value on the Y axis
		 */
		unsigned long GetMaxY() const
			{ return myMaxY; }

		/**
		 * @param X the position of the tile on the X axis
		 * @param Y the position of the tile on the Y axis
		 * @return the tile at the position (X;Y)
		 */
		Tile &TileAtPos(size_t X, size_t Y)
			{ return myMap[Y][X]; }
		/**
		 * @param X the position of the tile on the X axis
		 * @param Y the position of the tile on the Y axis
		 * @return the tile at the position (X;Y)
		 */
		const Tile &TileAtPos(size_t X, size_t Y) const
			{ return myMap[Y][X]; }
};

#endif // MAP_INCLUDED

