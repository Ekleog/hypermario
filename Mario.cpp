/**
 * @author Lenoa
 */

#include "Mario.h"

#include <SFML/Graphics.hpp>

#include "config.h"
#include "Collision.h"
#include "Map.h"
#include "Tile.h"
#include "TileAttributes.h"

/**
 * It updates the Mario
 *
 * @author Lenoa, iSma
 */
void Mario::Update()
{
	AnimatedSprite::Update();
	// Test if Mario is died
	if(GetPosition().y > (myMap->GetMaxY() + 1) * TILES_HEIGHT)
		Die();
	// Compute Y move
	mySpeedY += GRAVITATION;
	if(mySpeedY < 0)
	{
		float i = myMap->TopMax(*this, -mySpeedY);
		if(i == 0)
			mySpeedY = 0;
		else
			Move(0, -i);
	}
	else if(mySpeedY > 0)
	{
		float i = myMap->BottomMax(*this, mySpeedY);
		if(i == 0)
		{
			mySpeedY = 0;
			myIsJumping = false;
		}
		else
			Move(0, i);
	}
	// Compute X move
	if(myIsRunning)
	{
		if(myIsGoingLeft && !myIsGoingRight)
			Move(-myMap->LeftMax(*this, 4), 0);
		else if(myIsGoingRight && !myIsGoingLeft)
			Move(+myMap->RightMax(*this, 4), 0);
	}
	else
	{
		if(myIsGoingLeft && !myIsGoingRight)
			Move(-myMap->LeftMax(*this, 1.7), 0);
		else if(myIsGoingRight && !myIsGoingLeft)
			Move(+myMap->RightMax(*this, 1.7), 0);
	}
	// Compute state
	if(myIsJumping)
	{
		myState = "jump";
	}
	else if(myIsGoingLeft || myIsGoingRight)
	{
		myState = "walk";
		if(myIsRunning)
			framesPerSecond = 12;
		else
			framesPerSecond = 6;
	}
	else
	{
		myState = "stand";
	}
	std::string newAnim = mySize + "." + myState;
	if(newAnim != currentAnimation->name)
		SetAnimation(newAnim);
}

/**
 * @return the view centered on Mario if possible
 * @author Lenoa
 */
sf::View Mario::GetView() const
{
	// Compute the view centered on Mario
	float
		l = GetPosition().x + (GetSize().x / 2) - (WINDOW_WIDTH / 2),
		r = l + WINDOW_WIDTH,
		t = GetPosition().y + (GetSize().y / 2) - (WINDOW_HEIGHT / 2),
		b = t + WINDOW_HEIGHT;

	// Re-center (if out of the limits of the map)
	if(l < 0)
	{
		l = 0;
		r = WINDOW_WIDTH;
	}
	if(t < 0)
	{
		t = 0;
		b = WINDOW_HEIGHT;
	}
	if(r > (myMap->GetMaxX() + 1) * TILES_WIDTH)
	{
		r = (myMap->GetMaxX() + 1) * TILES_HEIGHT;
		l = r - WINDOW_WIDTH;
	}
	if(b > (myMap->GetMaxY() + 1) * TILES_HEIGHT)
	{
		b = (myMap->GetMaxY() + 1) * TILES_HEIGHT;
		t = b - WINDOW_HEIGHT;
	}

	// Return the view
	return sf::View(sf::FloatRect(l, t, r, b));
}

