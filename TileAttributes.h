/*!
 * \file TileAttributes.h
 * \author Ekinox <ekinox1995@gmail.com>
 */

#ifndef TILE_ATTRIBUTES_INCLUDED
#define TILE_ATTRIBUTES_INCLUDED 1

#include <string>

/*!
 * \class TileAttributes
 * \brief Models the attributes of a tile
 *
 * It models the attributes of a tile :
 * <ul>
 * <li>File name of the image</li>
 * <li>Attributes (empty, breakable, push-able) as bit flags</li>
 * </ul>
 */
struct TileAttributes
{
        /*!
         * \enum AttributeFlags
         * \brief The bit flags of the attributes
         */
        enum AttributeFlags
        {
            NotEmpty = 0 << 0,
            Empty = 1 << 0,
            NotBreakable = 0 << 1,
            Breakable = 1 << 1,
            NotPushable = 0 << 2,
            Pushable = 1 << 2
        };

        std::string Filename; //!< The file name of the tile

        /*!
         * \brief The attributes of the tile
         *
         * It is a combination of AttributeFlags
         */
        unsigned char Attributes;

        TileAttributes() :
            Filename(), Attributes(Empty)
        {
        }

        /*!
         * \param File The file name
         * \param Attrs The attributes
         */
        TileAttributes(const std::string &File, unsigned char Attrs) :
            Filename(File), Attributes(Attrs)
        {
        }
};

#endif // TILE_ATTRIBUTES_INCLUDED
