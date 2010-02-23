/**
 * @author Lenoa
 */

#ifndef MARIO_INCLUDED
#define MARIO_INCLUDED 1

#include <SFML/Graphics.hpp>

#include "Map.h"
#include "Tile.h"
#include "ImageManager.h"
#include "config.h"

/**
 * This class models a Mario, the hero of Hypermario.
 *
 * @author Lenoa
 */
class Mario : public sf::Sprite
{
	public:
		/**
		 * IT enumerates the possible sizes of Mario
		 */
		enum Size
		{
			Little,
			Medium,
			Giant
		};

	private:
		/**
		 * Is mario moving left, right or not ?
		 */
		bool myIsGoingLeft, myIsGoingRight;

		/**
		 * The speed of Mario on the Y axis (inverted, as required by SFML)
		 */
		float mySpeedY;

		/**
		 * The map in which Mario is evoluting
		 */
		const Map *myMap;

		/**
		 * The actual size of Mario
		 */
		Size mySize;

	public:
		/**
		 * @param PosX the position of Mario on the X axis
		 * @param PosY the position of Mario on the Y axis
		 * @param map the map on which Mario is evoluting
		 */
		Mario(size_t PosX, size_t PosY, const Map &map)
			: sf::Sprite(ImageManager::Get("images/mario.png"))
			  , myIsGoingLeft(false), myIsGoingRight(false)
			  , mySpeedY(0)
			  , myMap(&map)
			  , mySize(Medium)
		{ SetPosition(PosX * TILES_WIDTH, (PosY - 1) * TILES_HEIGHT); }

		/**
		 * Mario goes to the right
		 */
		void GoRight()
			{ myIsGoingRight = true; }
		/**
		 * Mario goes to the left
		 */
		void GoLeft()
			{ myIsGoingLeft = true; }

		/**
		 * Mario stops going to the left
		 */
		void StopGoingLeft()
			{ myIsGoingLeft = false; }
		/**
		 * Mario stops going to the right
		 */
		void StopGoingRight()
			{ myIsGoingRight = false; }

		/**
		 * Makes Mario jumping
		 */
		void Jump()
			{ mySpeedY = -4.; }

		/**
		 * It updates the Mario
		 */
		void Update();

		/**
		 * @return the view centered on Mario if possible
		 */
		sf::View GetView() const;
};

#endif // MARIO_INCLUDED

