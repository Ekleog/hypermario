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
		 * It enumerates the possible sizes of Mario
		 */
		enum Size
		{
			Little,
			Medium,
			Giant
		};

		/**
		 * It enumerates the states of Mario
		 */
		enum State
		{
			Standing	= 0,
			Walking		= 1,
			Turning		= 4,
			Jumping		= 5
		};

	private:
		/**
		 * Is mario moving left, right, jumping, running or not ?
		 */
		bool myIsGoingLeft, myIsGoingRight, myIsJumping, myIsRunning;

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

		/**
		 * The actual animation state of Mario
		 */
		float myState;

	public:
		/**
		 * @param PosX the position of Mario on the X axis
		 * @param PosY the position of Mario on the Y axis
		 * @param map the map on which Mario is evoluting
		 */
		Mario(size_t PosX, size_t PosY, const Map &map)
			: sf::Sprite(ImageManager::Get("images/mario.png"))
			  , myIsGoingLeft(false), myIsGoingRight(false), myIsJumping(false)
			  , mySpeedY(0)
			  , myMap(&map)
			  , mySize(Medium)
			  , myState(Standing)
		{
			SetPosition(PosX * TILES_WIDTH, (PosY - 1) * TILES_HEIGHT);
			SetSubRect(sf::IntRect(0, 0, GetSubRect().GetWidth() / 6, GetSubRect().GetHeight()));
			ChangeSprite(myState);
		}

		/**
		 * @param Number the number of the sprite to use now in the spritesheet
		 */
		void ChangeSprite(float Number)
		{
			int I = Number < 0 ? 0 : static_cast<int>(Number);
			int Width = GetSubRect().GetWidth();
			int Height = GetSubRect().GetHeight();
			SetSubRect(sf::IntRect(I * Width, 0, (I + 1) * Width, Height));
		}
		/**
		 * Mario goes to the right
		 */
		void GoRight()
		{
			if(!myIsGoingRight)
			{
				myIsGoingRight = true;
				FlipX(false); myState = Walking;
			}
		}
		/**
		 * Mario goes to the left
		 */
		void GoLeft()
		{
			if(!myIsGoingLeft)
			{
				myIsGoingLeft = true;
				FlipX(true); myState = Walking;
			}
		}

		/**
		 * Mario stops going to the left
		 */
		void StopGoingLeft()
			{ myIsGoingLeft = false; myState = Standing; }
		/**
		 * Mario stops going to the right
		 */
		void StopGoingRight()
			{ myIsGoingRight = false; myState = Standing; }

		/**
		 * Makes Mario jumping
		 */
		void Jump()
		{
			if(myMap->BottomMax(*this, 1) == 0)
			{
				mySpeedY = -6.;
				myIsJumping = true;
				myState = Jumping;
			}
		}

		/**
		 * Mario starts running
		 */
		void Run()
			{ myIsRunning = true; }
		/**
		 * Mario stops running
		 */
		void StopRunning()
			{ myIsRunning = false; }

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

