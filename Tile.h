/*!
 * \file Tile.h
 * \author Ekinox <ekinox1995@gmail.com>
 */

#ifndef TILE_INCLUDED
#define TILE_INCLUDED 1

#include <string>

#include <SFML/Graphics.hpp>

#include "ImageManager.h"

/*!
 * \class Tile
 * This class models a tile, which is a sprite which isn't animated and
 * doesn't move.
 */
class Tile : public sf::Sprite
{
    private:
        unsigned char myAttributes; //!< The attributes of the tile

    public:
        /*!
         * \param Image The tile's image's associated filename
         * \param Attributes The tile's attributes
         * \param PosX The position on the X axis of the tile
         * \param PosY The position on the Y axis of the tile
         */
        Tile(const std::string &Image, unsigned char Attributes, float PosX,
             float PosY) :
            sf::Sprite(ImageManager::Get(Image), sf::Vector2f(PosX, PosY)),
                    myAttributes(Attributes)
        {
        }

        /*!
         * \return The attributes of the tile
         */
        unsigned char GetAttributes() const
        {
            return myAttributes;
        }
        /*!
         * \param Attributes The new attributes of the tile
         */
        void SetAttributes(unsigned char Attributes)
        {
            myAttributes = Attributes;
        }
};

#endif // TILE_INCLUDED
