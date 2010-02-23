/**
 * @author Lenoa
 */

#ifndef TILE_INCLUDED
#define TILE_INCLUDED 1

#include <string>

#include <SFML/Graphics.hpp>

#include "ImageManager.h"

/**
 * This class models a tile, which is a sprite which isn't animated and doesn't move.
 *
 * @author Lenoa
 */
class Tile : public sf::Sprite
{
	private:
		/**
		 * The attributes of the tile
		 */
		unsigned char myAttributes;

	public:
		/**
		 * @param Image the tile's image's associated filename
		 * @param Attributes the tile's attributes
		 * @param PosX the position on the X axis of the tile
		 * @param PosY the position on the Y axis of the tile
		 */
		Tile(const std::string &Image, unsigned char Attributes, float PosX, float PosY)
			: sf::Sprite(ImageManager::Get(Image), sf::Vector2f(PosX, PosY))
			, myAttributes(Attributes)
		{}

		/**
		 * @return the attributes of the tile
		 */
		unsigned char GetAttributes() const
			{ return myAttributes; }
		/**
		 * @param Attributes the new attributes of the tile
		 */
		void SetAttributes(unsigned char Attributes)
			{ myAttributes = Attributes; }
};

#endif // TILE_INCLUDED

