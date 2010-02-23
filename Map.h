/**
 * @author Lenoa
 */

#ifndef MAP_INCLUDED
#define MAP_INCLUDED 1

#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

#include "Tile.h"
#include "TileAttributes.h"

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
		std::vector<Tile> myTiles;

		/**
		 * It is the position of Mario at its begin place
		 */
		size_t myMarioPosX, myMarioPosY;

		/**
		 * It is the maximum values of X and Y
		 */
		size_t myMaxX, myMaxY;

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
		size_t GetMarioPosX() const
			{ return myMarioPosX; }
		/**
		 * @return Mario's Y coordinate in the file
		 */
		size_t GetMarioPosY() const
			{ return myMarioPosY; }

		/**
		 * @return the maximum value on the X axis
		 */
		size_t GetMaxX() const
			{ return myMaxX; }

		/**
		 * @return the maximum value on the Y axis
		 */
		size_t GetMaxY() const
			{ return myMaxY; }

		/**
		 * @return a vector of all the tiles
		 */
		std::vector<Tile> &Tiles()
			{ return myTiles; }
		/**
		 * @return a vector of all the tiles
		 */
		const std::vector<Tile> &Tiles() const
			{ return myTiles; }
	
		/**
		 * @param Rect the bounding rect of the figure
		 * @param Max the max going to the top
		 * @return the maximm number of pixel Mario can go to the top
		 */
		float TopMax(const sf::Sprite &Rect, float Max) const;
		/**
		 * @param Rect the bounding rect of the figure
		 * @param Max the max going to the bottom
		 * @return the maximm number of pixel Mario can go to the bottom
		 */
		float BottomMax(const sf::Sprite &Rect, float Max) const;
		/**
		 * @param Rect the bounding rect of the figure
		 * @param Max the max going to the left
		 * @return the maximm number of pixel Mario can go to the left
		 */
		float LeftMax(const sf::Sprite &Rect, float Max) const;
		/**
		 * @param Rect the bounding rect of the figure
		 * @param Max the max going to the right
		 * @return the maximm number of pixel Mario can go to the right
		 */
		float RightMax(const sf::Sprite &Rect, float Max) const;
};

#endif // MAP_INCLUDED

