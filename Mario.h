/**
 * @author Lenoa
 */

#ifndef MARIO_INCLUDED
#define MARIO_INCLUDED 1

#include "AnimatedSprite.h"
#include "Map.h"
#include "Tile.h"
#include "ImageManager.h"
#include "config.h"

/**
 * This class models a Mario, the hero of Hypermario.
 *
 * @author Lenoa
 */
class Mario : public AnimatedSprite
{
	public:

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
		std::string mySize;

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
		std::string myState;

	public:
		/**
		 * @param PosX the position of Mario on the X axis
		 * @param PosY the position of Mario on the Y axis
		 * @param map the map on which Mario is evoluting
		 */
		Mario(const size_t PosX, const size_t PosY, const Map &map, const sf::Uint16 Lifes)
			: myIsGoingLeft(false), myIsGoingRight(false), myIsJumping(false), myIsRunning(false)
			  , mySpeedY(0)
			  , myMap(&map)
			  , myReturnPosX(PosX * TILES_WIDTH), myReturnPosY((PosY - 1) * TILES_HEIGHT)
			  , mySize("small")
			  , myLifes(Lifes)
			  , myLost(false)
			  , myState("stand")
			, AnimatedSprite(std::string("images/mario!.png\n"
					"default 1\n"
					"small.stand 1\n"
					"small.walk 3\n"
					"small.turn 1\n"
					"small.jump 1\n"
					"small.swim 4\n"
					"tall.stand 1\n"
					"tall.walk 3\n"
					"tall.turn 1\n"
					"tall.jump 1\n"
					"tall.crouch 1\n"
					"tall.swim 6\n"
					"tall.unknown 8\n"
					"fire.stand 1\n"
					"fire.walk 3\n"
					"fire.fire 1\n"
					"fire.turn 1\n"
					"fire.jump 1\n"
					"fire.crouch 1\n"
					"fire.swim 6\n"
					"fire.unknown 8"))
		{
			SetPosition(PosX * TILES_WIDTH, (PosY - 1) * TILES_HEIGHT);
			mySize = "fire";
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
				FlipX(false); myState = "walk";
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
				FlipX(true); myState = "walk";
			}
		}

		/**
		 * Mario stops going to the left
		 */
		void StopGoingLeft()
			{ myIsGoingLeft = false; myState = "stand"; }
		/**
		 * Mario stops going to the right
		 */
		void StopGoingRight()
			{ myIsGoingRight = false; myState = "stand"; }

		/**
		 * Makes Mario jumping
		 */
		void Jump()
		{
			if(myMap->BottomMax(*this, 1) == 0)
			{
				mySpeedY = -6.;
				myIsJumping = true;
				myState = "jump";
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

