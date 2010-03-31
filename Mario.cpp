/*!
 * \file Mario.cpp
 * \author Ekinox <ekinox1995@gmail.com>
 */

#include "Mario.h"

#include <SFML/Graphics.hpp>

#include "config.h"
#include "Collision.h"
#include "Map.h"
#include "Tile.h"
#include "TileAttributes.h"

/*!
 * \param PosX The position of Mario on the X axis
 * \param PosY The position of Mario on the Y axis
 * \param map The map on which Mario is evolving
 */
Mario::Mario(const size_t PosX, const size_t PosY, const Map &map,
             const sf::Uint16 Lifes) :
    AnimatedSprite(std::string("images/mario.png\n"
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
        "fire.unknown 8")), myIsGoingLeft(false), myIsGoingRight(false),
            myIsJumping(false), myIsRunning(false), mySpeedY(0), myMap(&map),
            myReturnPosX(PosX * TILES_WIDTH), myReturnPosY((PosY - 1)
                    * TILES_HEIGHT), mySize("small"), myLifes(Lifes),
            myLost(false), myState("stand")
{
    SetPosition(PosX * TILES_WIDTH, (PosY - 1) * TILES_HEIGHT);
}

/*!
 * \brief Sets the return position of Mario (if it dies).
 */
void Mario::SetReturnPos(float X, float Y)
{
    myReturnPosX = X;
    myReturnPosY = Y;
}

/*!
 * \brief Mario dies
 */
void Mario::Die()
{
    if (myLifes <= 1)
        myLost = true;
    else
    {
        --myLifes;
        SetPosition(myReturnPosX, myReturnPosY);
    }
}

/*!
 * \brief Has Mario lost ?
 */
bool Mario::Lost() const
{
    return myLost;
}

/*!
 * \brief Mario goes to the right
 */
void Mario::GoRight()
{
    if (!myIsGoingRight)
    {
        myIsGoingRight = true;
        FlipX(false);
        myState = "walk";
    }
}
/*!
 * \brief Mario goes to the left
 */
void Mario::GoLeft()
{
    if (!myIsGoingLeft)
    {
        myIsGoingLeft = true;
        FlipX(true);
        myState = "walk";
    }
}

/*!
 * \brief Mario stops going to the left
 */
void Mario::StopGoingLeft()
{
    myIsGoingLeft = false;
    myState = "stand";
}
/*!
 * \brief Mario stops going to the right
 */
void Mario::StopGoingRight()
{
    myIsGoingRight = false;
    myState = "stand";
}

/*!
 * \brief Makes Mario jumping
 */
void Mario::Jump()
{
    if (myMap->BottomMax(*this, 1) == 0)
    {
        mySpeedY = -6.;
        myIsJumping = true;
        myState = "jump";
    }
}

/*!
 * \brief Mario starts running
 */
void Mario::Run()
{
    myIsRunning = true;
}
/*!
 * \brief Mario stops running
 */
void Mario::StopRunning()
{
    myIsRunning = false;
}

/*!
 * \brief It updates the Mario
 *
 * \author Ekinox <ekinox1995@gmail.com>, iSma
 */
void Mario::Update()
{
    AnimatedSprite::Update();
    // Test if Mario is died
    if (GetPosition().y > (myMap->GetMaxY() + 1) * TILES_HEIGHT)
        Die();
    // Compute Y move
    mySpeedY += GRAVITATION;
    if (mySpeedY < 0)
    {
        float i = myMap->TopMax(*this, -mySpeedY);
        if (i == 0)
            mySpeedY = 0;
        else
            Move(0, -i);
    }
    else if (mySpeedY > 0)
    {
        float i = myMap->BottomMax(*this, mySpeedY);
        if (i == 0)
        {
            mySpeedY = 0;
            myIsJumping = false;
        }
        else
            Move(0, i);
    }
    // Compute X move
    if (myIsRunning)
    {
        if (myIsGoingLeft && !myIsGoingRight)
            Move(-myMap->LeftMax(*this, 4), 0);
        else if (myIsGoingRight && !myIsGoingLeft)
            Move(+myMap->RightMax(*this, 4), 0);
    }
    else
    {
        if (myIsGoingLeft && !myIsGoingRight)
            Move(-myMap->LeftMax(*this, 1.7), 0);
        else if (myIsGoingRight && !myIsGoingLeft)
            Move(+myMap->RightMax(*this, 1.7), 0);
    }
    // Compute state
    if (myIsJumping)
    {
        myState = "jump";
    }
    else if (myIsGoingLeft || myIsGoingRight)
    {
        myState = "walk";
        if (myIsRunning)
            framesPerSecond = 12;
        else
            framesPerSecond = 6;
    }
    else
    {
        myState = "stand";
    }
    std::string newAnim = mySize + "." + myState;
    if (newAnim != currentAnimation->name)
        SetAnimation(newAnim);
}

/*!
 * \return The view centered on Mario if possible
 */
sf::View Mario::GetView() const
{
    // Compute the view centered on Mario
    float l = GetPosition().x + (GetSize().x / 2) - (WINDOW_WIDTH / 2), r = l
            + WINDOW_WIDTH, t = GetPosition().y + (GetSize().y / 2)
            - (WINDOW_HEIGHT / 2), b = t + WINDOW_HEIGHT;

    // Re-center (if out of the limits of the map)
    if (l < 0)
    {
        l = 0;
        r = WINDOW_WIDTH;
    }
    if (t < 0)
    {
        t = 0;
        b = WINDOW_HEIGHT;
    }
    if (r > (myMap->GetMaxX() + 1) * TILES_WIDTH)
    {
        r = (myMap->GetMaxX() + 1) * TILES_HEIGHT;
        l = r - WINDOW_WIDTH;
    }
    if (b > (myMap->GetMaxY() + 1) * TILES_HEIGHT)
    {
        b = (myMap->GetMaxY() + 1) * TILES_HEIGHT;
        t = b - WINDOW_HEIGHT;
    }

    // Return the view
    return sf::View(sf::FloatRect(l, t, r, b));
}
