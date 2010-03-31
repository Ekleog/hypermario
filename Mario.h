/*!
 * \file Mario.h
 * \author Ekinox <ekinox1995@gmail.com>
 */

#ifndef MARIO_INCLUDED
#define MARIO_INCLUDED 1

#include "AnimatedSprite.h"
#include "Map.h"
#include "Tile.h"
#include "ImageManager.h"
#include "config.h"

/*!
 * \class Mario
 * \brief This class models a Mario, the hero of Hypermario.
 */
class Mario : public AnimatedSprite
{
    public:

    private:
        /*!
         * \brief Is mario moving left, right, jumping, running or not ?
         */
        bool myIsGoingLeft, myIsGoingRight, myIsJumping, myIsRunning;

        float mySpeedY; //!< The speed of Mario on the Y axis
        const Map *myMap; //!< The map in which Mario is evolving
        float myReturnPosX, myReturnPosY; //!< Mario's return position
        std::string mySize; //!< Mario's current size
        sf::Uint16 myLifes; //!< Mario's number of lifes
        bool myLost; //!< Has Mario lost the game ?
        std::string myState; //!< The actual animation state of Mario

    public:
        Mario(const size_t PosX, const size_t PosY, const Map &map,
              const sf::Uint16 Lifes);

        void SetReturnPos(float X, float Y);
        void Die();
        bool Lost() const;

        void GoRight();
        void GoLeft();
        void StopGoingLeft();
        void StopGoingRight();

        void Jump();

        void Run();
        void StopRunning();

        void Update();

        sf::View GetView() const;
};

#endif // MARIO_INCLUDED
