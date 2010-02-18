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
		 * The width and height of all the tiles.
		 *
		 * It is static as far as each tile should have the same width and height. It is used to calculate
		 * the coordinates of the tiles.
		 */
		static sf::Uint32 ourWidth, ourHeight;

		/**
		 * The attributes of the tile
		 */
		unsigned char myAttributes;

	public:
		/**
		 * This function is used to edit the dimensions of the tiles. <i>It should be called at the beginning
		 * of your program and never after.</i>
		 *
		 * @param Width the new width of the tiles
		 * @param Height the new height of the tiles
		 */
		static void SetTilesDimensions(sf::Uint32 Width, sf::Uint32 Height)
			{ ourWidth = Width; ourHeight = Height; }

		/**
		 * @return tiles' width
		 */
		static sf::Uint32 GetDimensionX()
			{ return ourWidth; }
		/**
		 * @return tiles' height
		 */
		static sf::Uint32 GetDimensionY()
			{ return ourHeight; }

		/**
		 * @param Image the tile's image's associated filename
		 * @param Attributes the tile's attributes
		 * @param PosX the position on the X axis of the tile
		 * @param PosY the position on the Y axis of the tile
		 */
		Tile(const std::string &Image, unsigned char Attributes, sf::Uint32 PosX, sf::Uint32 PosY)
			: sf::Sprite(ImageManager::Get(Image), sf::Vector2f(PosX * ourWidth, PosY * ourHeight))
			, myAttributes(Attributes)
		{}

		/**
		 * @param PosX the new position of the tile on the X axis
		 * @param PosY the new position of the tile on the Y axis
		 */
		void SetPosition(sf::Uint32 X, sf::Uint32 Y)
			{ sf::Drawable::SetPosition(X * ourWidth, Y * ourHeight); }

		/**
		 * @param X the new position of the tile on the X axis
		 */
		void SetX(sf::Uint32 X)
			{ sf::Drawable::SetX(X * ourWidth); }
		/**
		 * @param Y the new position of the tile on the Y axis
		 */
		void SetY(sf::Uint32 Y)
			{ sf::Drawable::SetY(Y * ourHeight); }

		/**
		 * @return the position on the X axis
		 */
		sf::Uint32 GetX() const
			{ return sf::Drawable::GetPosition().x / ourWidth; }
		/**
		 * @return the position on the Y axis
		 */
		sf::Uint32 GetY() const
			{ return sf::Drawable::GetPosition().y / ourHeight; }

		/**
		 * @return the attributes of the tile
		 */
		unsigned char GetAttributes() const
			{ return myAttributes; }
};

#endif // TILE_INCLUDED

