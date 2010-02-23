/**
 * @author Lenoa
 */

#include "Collision.h"

/**
 * @param Obj1 the first of the two objects to test if they are in collision
 * @param Obj2 the second of the two objects
 * @return true if the two sprites are in collision (via the method of the bounding boxes)
 * @author Lenoa
 */
bool Collision::BoundingBoxTest(const sf::Sprite &Obj1, const sf::Sprite &Obj2)
{
	return GetBoundingBox(Obj1).Intersects(GetBoundingBox(Obj2));
}
/**
 * @param Obj1 the first of the two objects to test if they are in collision
 * @param Obj2 the second of the two objects
 * @param AlphaLimit the limit of the alpha to consider if the pixel is or not a blocking pixel
 * @return true if the two sprites are in collision (via a pixel-perfect method)
 * @author Lenoa
 */
bool Collision::PixelTest(const sf::Sprite &Obj1, const sf::Sprite &Obj2, sf::Uint8 AlphaLimit)
{
	sf::IntRect Obj1BoundingBox(GetBoundingBox(Obj1));
	sf::IntRect Obj2BoundingBox(GetBoundingBox(Obj2));

	sf::IntRect Intersection;

	if(!Obj1BoundingBox.Intersects(Obj2BoundingBox, &Intersection))
		return false;

	if(AlphaLimit == 0)
		return true;

	for(int I = Intersection.Left; I <= Intersection.Right; ++I)
	{
		for(int J = Intersection.Top; J <= Intersection.Bottom; ++J)
		{
			sf::Vector2f Obj1Pix = Obj1.TransformToLocal(sf::Vector2f(I, J));
			sf::Vector2f Obj2Pix = Obj2.TransformToLocal(sf::Vector2f(I, J));

			if(Obj1Pix.x >= 0 && Obj1Pix.x < Obj1BoundingBox.GetWidth()
			&& Obj1Pix.y >= 0 && Obj1Pix.y < Obj1BoundingBox.GetHeight()
			&& Obj2Pix.x >= 0 && Obj2Pix.x < Obj2BoundingBox.GetWidth()
			&& Obj2Pix.y >= 0 && Obj2Pix.y < Obj2BoundingBox.GetHeight()
			&& Obj1.GetPixel(static_cast<int>(Obj1Pix.x), static_cast<int>(Obj1Pix.y)).a > AlphaLimit
			&& Obj2.GetPixel(static_cast<int>(Obj2Pix.x), static_cast<int>(Obj2Pix.y)).a > AlphaLimit)
				return true;
		}
	}

	return false;
}

/**
 * @param Obj the object
 * @return the bounding box of the object
 * @author Lenoa
 */
sf::IntRect Collision::GetBoundingBox(const sf::Sprite &Obj)
{
	sf::Vector2f Position = Obj.TransformToGlobal(sf::Vector2f(0, 0)); // Position of the top left corner
	sf::Vector2f Size     = Obj.GetSize(); // Size of the object
	
	return sf::IntRect(
			static_cast<int>(Position.x),
			static_cast<int>(Position.y),
			static_cast<int>(Position.x + Size.x),
			static_cast<int>(Position.y + Size.y)
	);
}

