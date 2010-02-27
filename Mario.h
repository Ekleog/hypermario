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
		 * The position to return when Mario dies
		 */
		float myReturnPosX, myReturnPosY;

		/**
		 * The actual size of Mario
		 */
		Size mySize;

		/**
		 * The number of lifes of Mario
		 */
		sf::Uint16 myLifes;

		/**
		 * Mario lost the game ?
		 */
		bool myLost;

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
		Mario(const size_t PosX, const size_t PosY, const Map &map, const sf::Uint16 Lifes)
			: sf::Sprite(ImageManager::Get("images/mario.png"))
			  , myIsGoingLeft(false), myIsGoingRight(false), myIsJumping(false), myIsRunning(false)
			  , mySpeedY(0)
			  , myMap(&map)
			  , myReturnPosX(PosX * TILES_WIDTH), myReturnPosY((PosY - 1) * TILES_HEIGHT)
			  , mySize(Medium)
			  , myLifes(Lifes)
			  , myLost(false)
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
			SetSubRect(sf::IntRect(I * Width, 0, (I + 1) * Width, GetSubRect().GetHeight()));
		}

		/**
		 * Sets the return position of Mario (if it dies).
		 */
		void SetReturnPos(float X, float Y)
			{ myReturnPosX = X; myReturnPosY = Y; }

		/**
		 * Mario dies
		 */
		void Die()
		{
			if(myLifes <= 1)
				myLost = true;
			else
			{
				--myLifes;
				SetPosition(myReturnPosX, myReturnPosY);
			}
		}

		/**
		 * Has Mario lost ?
		 */
		bool Lost() const
			{ return myLost; }

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

