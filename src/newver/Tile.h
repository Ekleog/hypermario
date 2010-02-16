/**
 * @version 1.1
 *
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
 * @see sf::Sprite
 * @version 1.0
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
		 *
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		static sf::Uint32 ourWidth, ourHeight;

	public:
		/**
		 * This function is used to edit the dimensions of the tiles. <i>It should be called at the beginning
		 * of your program and never after.</i>
		 *
		 * @param Width the new width of the tiles
		 * @param Height the new height of the tiles
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		static void SetTilesDimensions(sf::Uint32 Width, sf::Uint32 Height)
			{ ourWidth = Width; ourHeight = Height; }

		/**
		 * The constructor for <i>Tile</i>.
		 *
		 * @param Image the tile's image's associated filename
		 * @param PosX the position on the X axis of the tile
		 * @param PosY the position on the Y axis of the tile
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		Tile(const std::string &Image, sf::Uint32 PosX, sf::Uint32 PosY)
			: sf::Sprite(ImageManager::Get(Image), sf::Vector2f(PosX * ourWidth, PosY * ourHeight))
		{}

		/**
		 * It changes the position of the tile.
		 *
		 * @param PosX the new position of the tile on the X axis
		 * @param PosY the new position of the tile on the Y axis
		 * @version 1.0
		 * 
		 * @author Lenoa
		 */
		void SetPosition(sf::Uint32 X, sf::Uint32 Y)
			{ sf::Drawable::SetPosition(X * ourWidth, Y * ourHeight); }

		/**
		 * It changes the X position of the tile
		 *
		 * @param X the new position of the tile on the X axis
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		void SetX(sf::Uint32 X)
			{ sf::Drawable::SetX(X * ourWidth); }
		/**
		 * It changes the Y position of the tile
		 *
		 * @param Y the new position of the tile on the Y axis
		 * @version 1.0
		 * 
		 * @author Lenoa
		 */
		void SetY(sf::Uint32 Y)
			{ sf::Drawable::SetY(Y * ourHeight); }

		/**
		 * It returns the actual position on the X axis.
		 *
		 * @return the position on the X axis
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		sf::Uint32 GetX() const
			{ return sf::Drawable::GetPosition().x / ourWidth; }
		/**
		 * It returns the actual position on the Y axis.
		 *
		 * @return the position on the Y axis
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		sf::Uint32 GetY() const
			{ return sf::Drawable::GetPosition().y / ourHeight; }
};

#endif // TILE_INCLUDED

