/**
 * @version 1.0
 *
 * @author Lenoa
 */

#include "Mario.h"

#include <SFML/Graphics.hpp>

#include "config.h"
#include "Tile.h"
#include "TileAttributes.h"

/**
 * It returns the best view englobing Mario.
 *
 * @return the view centered on Mario if possible
 * @version 1.0
 *
 * @author Lenoa
 */
sf::View Mario::GetView() const
{
	long
		l = mySprite.GetPosition().x + (mySprite.GetSize().x / 2) - (WINDOW_WIDTH / 2),
		r = l + WINDOW_WIDTH,
		t = mySprite.GetPosition().y + (mySprite.GetSize().y / 2) - (WINDOW_HEIGHT / 2),
		b = t + WINDOW_HEIGHT;
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
	if(static_cast<unsigned long>(r) > (myMap->GetMaxX() + 1) * Tile::GetDimensionX())
	{
		r = (myMap->GetMaxX() + 1) * Tile::GetDimensionX();
		l = r - WINDOW_WIDTH;
	}
	if(static_cast<unsigned long>(b) > (myMap->GetMaxY() + 1) * Tile::GetDimensionY())
	{
		b = (myMap->GetMaxY() + 1) * Tile::GetDimensionY();
		t = b - WINDOW_HEIGHT;
	}
	return sf::View(sf::FloatRect(l, t, r, b));
}

/**
 * It renders the mario to the target
 *
 * @param Target the target on which render
 * @version 1.0
 *
 * @author Lenoa
 */
void Mario::Render(sf::RenderTarget &Target) const
{
	Target.Draw(mySprite);
}

/**
 * Can Mario go to the left ?
 *
 * @return true if Mario can go to the left, false otherwise
 * @version 1.0
 *
 * @author Lenoa
 */
bool Mario::CanGoLeft() const
{
       	return (
		myPosX > 0 && (
			mySize == Little ? (myMap->TileAtPos(myPosX - 1, myPosY).GetAttributes() & TileAttributes::Empty) : (
				(myMap->TileAtPos(myPosX - 1, myPosY + 1).GetAttributes() & TileAttributes::Empty) &&
				(myMap->TileAtPos(myPosX - 1, myPosY    ).GetAttributes() & TileAttributes::Empty)
			)
		)
	);
}
/**
 * Can Mario go to the right ?
 *
 * @return true if Mario can go to the right, false otherwise
 * @version 1.0
 *
 * @author Lenoa
 */
bool Mario::CanGoRight() const
{
       	return (
		myPosX < myMap->GetMaxX() && (
			mySize == Little ? (myMap->TileAtPos(myPosX + 1, myPosY).GetAttributes() & TileAttributes::Empty) : (
				(myMap->TileAtPos(myPosX + 1, myPosY + 1).GetAttributes() & TileAttributes::Empty) &&
				(myMap->TileAtPos(myPosX + 1, myPosY    ).GetAttributes() & TileAttributes::Empty)
			)
		)
	);
}

