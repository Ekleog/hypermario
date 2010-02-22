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
	sf::IntRect Rect(Collision::GetBoundingBox(mySprite));

	// Compute Y move
	mySpeedY += GRAVITATION;
	if(mySpeedY < 0)
		mySprite.Move(0, -myMap->   TopMax(Rect, -mySpeedY));
	else if(mySpeedY > 0)
	{
		float i = myMap->BottomMax(Rect, mySpeedY);
		if(i == 0)
			mySpeedY = 0;
		else
			mySprite.Move(0,  myMap->BottomMax(Rect,  mySpeedY));
	}

	// Re-compute rect
	Rect = Collision::GetBoundingBox(mySprite);

	// Compute X move
	if(myIsGoingLeft && !myIsGoingRight)
		mySprite.Move(-myMap->LeftMax(Rect, 2), 0);
	else if(myIsGoingRight && !myIsGoingLeft)
		mySprite.Move(+myMap->RightMax(Rect, 2), 0);
}

/**
 * @return the view centered on Mario if possible
 * @author Lenoa
 */
sf::View Mario::GetView() const
{
	// Compute the view centered on Mario
	float
		l = mySprite.GetPosition().x + (mySprite.GetSize().x / 2) - (WINDOW_WIDTH / 2),
		r = l + WINDOW_WIDTH,
		t = mySprite.GetPosition().y + (mySprite.GetSize().y / 2) - (WINDOW_HEIGHT / 2),
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
	if(r > (myMap->GetMaxX() + 1) * Tile::GetDimensionX())
	{
		r = (myMap->GetMaxX() + 1) * Tile::GetDimensionX();
		l = r - WINDOW_WIDTH;
	}
	if(b > (myMap->GetMaxY() + 1) * Tile::GetDimensionY())
	{
		b = (myMap->GetMaxY() + 1) * Tile::GetDimensionY();
		t = b - WINDOW_HEIGHT;
	}

	// Return the view
	return sf::View(sf::FloatRect(l, t, r, b));
}

/**
 * It renders the mario to the target
 *
 * @param Target the target on which render
 * @author Lenoa
 */
void Mario::Render(sf::RenderTarget &Target) const
{
	Target.Draw(mySprite);
}

/**
 * @return true if Mario can go to the left, false otherwise
 * @author Lenoa
 */
bool Mario::CanGoLeft() const
{
	return true;
}
/**
 * @return true if Mario can go to the right, false otherwise
 * @author Lenoa
 */
bool Mario::CanGoRight() const
{
	return true;
}

