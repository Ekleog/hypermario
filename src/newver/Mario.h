/**
 * @version 1.0
 *
 * @author Lenoa
 */

#ifndef MARIO_INCLUDED
#define MARIO_INCLUDED 1

#include <SFML/Graphics.hpp>

#include "Map.h"
#include "Tile.h"
#include "ImageManager.h"

/**
 * This class models a Mario, the hero of Hypermario.
 *
 * @version 1.0
 *
 * @author Lenoa
 */
class Mario : public sf::Drawable
{
	public:
		enum Size
		{
			Little,
			Medium,
			Giant
		};

	private:
		/**
		 * Those variables are the position of Mario on the X and Y axis.
		 *
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		unsigned long myPosX, myPosY;

		/**
		 * The map in which Mario is evoluting
		 *
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		const Map *myMap;

		/**
		 * The sprite to blit when we want to blit Mario
		 *
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		sf::Sprite mySprite;

		/**
		 * The actual size of Mario
		 *
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		Size mySize;

		/**
		 * It renders the mario to the target
		 *
		 * @param Target the target on which render
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		void Render(sf::RenderTarget &Target) const;

		/**
		 * It refreshes the sprite's position on the map
		 *
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		void RefreshSpritePosition()
			{ mySprite.SetPosition(myPosX * Tile::GetDimensionX(), myPosY * Tile::GetDimensionY()); }

	public:
		/**
		 * The constructor
		 *
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		Mario(unsigned long PosX, unsigned long PosY, const Map &map)
			: myPosX(PosX), myPosY(PosY - 1), myMap(&map), mySprite(ImageManager::Get("images/mario.png"))
			, mySize(Medium)
		{ RefreshSpritePosition(); }

		/**
		 * Can Mario go to the left ?
		 *
		 * @return true if Mario can go to the left, false otherwise
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		bool CanGoLeft() const;
		/**
		 * Can Mario go to the right ?
		 *
		 * @return true if Mario can go to the right, false otherwise
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		bool CanGoRight() const;

		/**
		 * Mario goes to the right
		 *
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		void GoRight()
			{ ++myPosX; RefreshSpritePosition(); }
		/**
		 * Mario goes to the left
		 *
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		void GoLeft()
			{ --myPosX; RefreshSpritePosition(); }

		/**
		 * It returns the best view englobing Mario.
		 *
		 * @return the view centered on Mario if possible
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		sf::View GetView() const;
};

#endif // MARIO_INCLUDED

