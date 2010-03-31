/*!
 * \file Collision.cpp
 * \author Ekinox <ekinox1995@gmail.com>
 */

#include "Collision.h"

/*!
 * \brief Tests whether the sprite Obj1 collides with the sprite Obj2
 * \param Obj1 The first of the two objects to test if they are in collision
 * \param Obj2 The second of the two objects
 * \return Are the two objects are colliding (via the bounding boxes method) ?
 */
bool Collision::BoundingBoxTest(const sf::Sprite &Obj1, const sf::Sprite &Obj2)
{
    return GetBoundingBox(Obj1).Intersects(GetBoundingBox(Obj2));
}
/*!
 * \brief Tests whether the sprite Obj1 collides with the sprite Obj2
 * \param Obj1 The first of the two objects
 * \param Obj2 The second of the two objects
 * \param AlphaLimit The limit of the alpha value
 * \return Are the two objects are in collision (via a pixel-perfect method) ?
 *
 * It tests using a pixel-perfect condition, with AlphaLimit to test whether
 * the pixels are colliding.
 */
bool Collision::PixelTest(const sf::Sprite &Obj1, const sf::Sprite &Obj2,
                          sf::Uint8 AlphaLimit)
{
    sf::IntRect Obj1BoundingBox(GetBoundingBox(Obj1));
    sf::IntRect Obj2BoundingBox(GetBoundingBox(Obj2));

    sf::IntRect Intersection;

    if (!Obj1BoundingBox.Intersects(Obj2BoundingBox, &Intersection))
        return false;

    if (AlphaLimit == 0)
        return true;

    for (int I = Intersection.Left ; I <= Intersection.Right ; ++I)
    {
        for (int J = Intersection.Top ; J <= Intersection.Bottom ; ++J)
        {
            sf::Vector2i Obj1Pix(I - Obj1BoundingBox.Left, J
                    - Obj1BoundingBox.Top);
            sf::Vector2i Obj2Pix(I - Obj2BoundingBox.Left, J
                    - Obj2BoundingBox.Top);

            if (Obj1Pix.x >= 0 && Obj1Pix.x < Obj1BoundingBox.GetWidth()
                    && Obj1Pix.y >= 0 && Obj1Pix.y
                    < Obj1BoundingBox.GetHeight() && Obj2Pix.x >= 0
                    && Obj2Pix.x < Obj2BoundingBox.GetWidth() && Obj2Pix.y >= 0
                    && Obj2Pix.y < Obj2BoundingBox.GetHeight()
                    && Obj1.GetPixel(Obj1Pix.x, Obj1Pix.y).a > AlphaLimit
                    && Obj2.GetPixel(Obj2Pix.x, Obj2Pix.y).a > AlphaLimit)
                return true;
        }
    }

    return false;
}

/*!
 * \param Obj The object
 * \return The bounding box of the object
 */
sf::IntRect Collision::GetBoundingBox(const sf::Sprite &Obj)
{
    const sf::Vector2f &Position(Obj.GetPosition());
    const sf::IntRect &SubRect(Obj.GetSubRect());
    return sf::IntRect(Position.x, Position.y, Position.x + SubRect.GetWidth(),
                       Position.y + SubRect.GetHeight());
}

