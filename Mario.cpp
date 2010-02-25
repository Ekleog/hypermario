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
 * @author Lenoa
 */
void Mario::Update()
{
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
	if(myIsGoingLeft && !myIsGoingRight)
		Move(-myMap->LeftMax(*this, 2), 0);
	else if(myIsGoingRight && !myIsGoingLeft)
		Move(+myMap->RightMax(*this, 2), 0);

	// Compute state
	if(myIsJumping)
	{
		myState = Jumping;
	}
	else if(myIsGoingLeft || myIsGoingRight)
	{
		if((myState += 0.3) > Walking + 2)
			myState = Walking;
	}
	else
	{
		myState = Standing;
	}
	ChangeSprite(myState);
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

	// Re-centrate (if out of the limits of the map)
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

