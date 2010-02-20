/**
 * @author Lenoa
 */

#ifndef COLLISION_INCLUDED
#define COLLISION_INCLUDED 1

#include <SFML/Graphics.hpp>

/**
 * This class is used to test if two sprites are in collision.
 *
 * @author Lenoa
 */
class Collision
{
	private:
		/**
		 * Private constructor : not instanciable
		 */
		Collision();

	public:
		/**
		 * @param Obj1 the first of the two objects to test if they are in collision
		 * @param Obj2 the second of the two objects
		 * @return true if the two sprites are in collision (via the method of the bounding boxes)
		 */
		static bool BoundingBoxTest(const sf::Sprite &Obj1, const sf::Sprite &Obj2);
		/**
		 * @param Obj1 the first of the two objects to test if they are in collision
		 * @param Obj2 the second of the two objects
		 * @param AlphaLimit the limit of the alpha to consider if the pixel is or not a blocking pixel
		 * @return true if the two sprites are in collision (via a pixel-perfect method)
		 */
		static bool PixelTest(const sf::Sprite &Obj1, const sf::Sprite &Obj2, sf::Uint8 AlphaLimit = 127);

		/**
		 * @param Obj the object
		 * @return the bounding box of the object
		 */
		static sf::IntRect GetBoundingBox(const sf::Sprite &Obj);
};

#endif // COLLISION_INCLUDED

