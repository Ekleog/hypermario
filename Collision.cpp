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
#include <iostream>
bool Collision::PixelTest(const sf::Sprite &Obj1, const sf::Sprite &Obj2, sf::Uint8 AlphaLimit)
{
	sf::IntRect Obj1BoundingBox(GetBoundingBox(Obj1));
	sf::IntRect Obj2BoundingBox(GetBoundingBox(Obj2));
	std::cout << "Obj1BoundingBox = " << Obj1BoundingBox.Left << " ; " << Obj1BoundingBox.Top << " ; " << Obj1BoundingBox.Right << " ; " << Obj1BoundingBox.Bottom << std::endl;
	std::cout << "Obj2BoundingBox = " << Obj2BoundingBox.Left << " ; " << Obj2BoundingBox.Top << " ; " << Obj2BoundingBox.Right << " ; " << Obj2BoundingBox.Bottom << std::endl;

	sf::IntRect Intersection;

	if(!Obj1BoundingBox.Intersects(Obj2BoundingBox, &Intersection))
		return false;
	std::cout << "Intersection = " << Intersection.Left << " ; " << Intersection.Top << " ; " << Intersection.Right << " ; " << Intersection.Bottom << std::endl;

	if(AlphaLimit == 0)
		return true;

	for(int I = Intersection.Left; I <= Intersection.Right; ++I)
	{
		for(int J = Intersection.Top; J <= Intersection.Bottom; ++J)
		{
			sf::Vector2i Obj1Pix(I - Obj1BoundingBox.Left, J - Obj1BoundingBox.Top);
			sf::Vector2i Obj2Pix(I - Obj2BoundingBox.Left, J - Obj2BoundingBox.Top);

			if(Obj1Pix.x >= 0 && Obj1Pix.x < Obj1BoundingBox.GetWidth()
			&& Obj1Pix.y >= 0 && Obj1Pix.y < Obj1BoundingBox.GetHeight()
			&& Obj2Pix.x >= 0 && Obj2Pix.x < Obj2BoundingBox.GetWidth()
			&& Obj2Pix.y >= 0 && Obj2Pix.y < Obj2BoundingBox.GetHeight()
			&& Obj1.GetPixel(Obj1Pix.x, Obj1Pix.y).a > AlphaLimit
			&& Obj2.GetPixel(Obj2Pix.x, Obj2Pix.y).a > AlphaLimit)
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
	const sf::Vector2f &Position(Obj.GetPosition());
	const sf::IntRect  &SubRect(Obj.GetSubRect());
	return sf::IntRect(
			Position.x,
			Position.y,
			Position.x + SubRect.GetWidth(),
			Position.y + SubRect.GetHeight()
			);
}

