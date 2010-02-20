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
	
		/**
		 * @param Rect the bounding rect of the figure
		 * @param Max the max going to the top
		 * @return the maximm number of pixel Mario can go to the top
		 */
		sf::Uint32 TopMax(const sf::IntRect &Rect, sf::Uint32 Max) const;
		/**
		 * @param Rect the bounding rect of the figure
		 * @param Max the max going to the bottom
		 * @return the maximm number of pixel Mario can go to the bottom
		 */
		sf::Uint32 BottomMax(const sf::IntRect &Rect, sf::Uint32 Max) const;
		/**
		 * @param Rect the bounding rect of the figure
		 * @param Max the max going to the left
		 * @return the maximm number of pixel Mario can go to the left
		 */
		sf::Uint32 LeftMax(const sf::IntRect &Rect, sf::Uint32 Max) const;
		/**
		 * @param Rect the bounding rect of the figure
		 * @param Max the max going to the right
		 * @return the maximm number of pixel Mario can go to the right
		 */
		sf::Uint32 RightMax(const sf::IntRect &Rect, sf::Uint32 Max) const;

		/**
		 * @param X the X position of the tile to test
		 * @param Y the Y position of the tile to test
		 * @return true if the tile is empty
		 */
		bool IsFree(size_t X, size_t Y) const
			{ return (TileAtPos(X, Y).GetAttributes() & TileAttributes::Empty) == TileAttributes::Empty; }

		/**
		 * @param X the X coordinate of the tile to know if the tile on its top it is free
		 * @param Y the Y coordinate of the tile to know if the tile on its top it is free
		 * @return true if the tile on its top is free
		 */
		bool TopIsFree(size_t X, size_t Y) const
			{ return Y > 0 && IsFree(X, Y - 1); }
		/**
		 * @param X the X coordinate of the tile to know if the tile on its bottom it is free
		 * @param Y the Y coordinate of the tile to know if the tile on its bottom it is free
		 * @return true if the tile on its bottom is free
		 */
		bool BottomIsFree(size_t X, size_t Y) const
			{ return Y < myMaxY && IsFree(X, Y + 1); }
		/**
		 * @param X the X coordinate of the tile to know if the tile on its left it is free
		 * @param Y the Y coordinate of the tile to know if the tile on its left it is free
		 * @return true if the tile on its left is free
		 */
		bool LeftIsFree(size_t X, size_t Y) const
			{ return X > 0 && IsFree(X - 1, Y); }
		/**
		 * @param X the X coordinate of the tile to know if the tile on its right it is free
		 * @param Y the Y coordinate of the tile to know if the tile on its right it is free
		 * @return true if the tile on its right is free
		 */
		bool RightIsFree(size_t X, size_t Y) const
			{ return X < myMaxX && IsFree(X + 1, Y); }

		/**
		 * @param Rect the rectangle of the entity
		 * @return true if it could go at least 1 pixel to the top
		 */
		bool CanGoTop(const sf::FloatRect &Rect) const;
		/**
		 * @param Rect the rectangle of the entity
		 * @return true if it could go at least 1 pixel to the bottom
		 */
		bool CanGoBottom(const sf::FloatRect &Rect) const;
		/**
		 * @param Rect the rectangle of the entity
		 * @return true if it could go at least 1 pixel to the left
		 */
		bool CanGoLeft(const sf::FloatRect &Rect) const;
		/**
		 * @param Rect the rectangle of the entity
		 * @return true if it could go at least 1 pixel to the right
		 */
		bool CanGoRight(const sf::FloatRect &Rect) const;
};

#endif // MAP_INCLUDED

