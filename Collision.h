/*!
 * \file Collision.h
 * \author Ekinox <ekinox1995@gmail.com>
 */

#ifndef COLLISION_INCLUDED
#define COLLISION_INCLUDED 1

#include <SFML/Graphics.hpp>

/*!
 * \class Collision
 * \brief This class is used to test if two sprite(s) are in collision.
 */
class Collision
{
    private:
        Collision(); //!< Private constructor, as far as it is a static class

    public:
        static bool BoundingBoxTest(const sf::Sprite &Obj1,
                                    const sf::Sprite &Obj2);
        static bool PixelTest(const sf::Sprite &Obj1, const sf::Sprite &Obj2,
                              sf::Uint8 AlphaLimit = 127);

        static sf::IntRect GetBoundingBox(const sf::Sprite &Obj);
};

#endif // COLLISION_INCLUDED
