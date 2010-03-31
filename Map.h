/*!
 * \file Map.h
 * \author Ekinox <ekinox1995@gmail.com>
 */

#ifndef MAP_INCLUDED
#define MAP_INCLUDED 1

#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

#include "Tile.h"
#include "TileAttributes.h"

/*!
 * \class Map
 * \brief This class models a map of the game HyperMario : a double array of tiles.
 *
 * It should be drawed after the background and before the personages and monsters.
 */
class Map : public sf::Drawable
{
    private:
        std::vector < Tile > myTiles; //!< The map : the array of tiles
        size_t myMarioPosX, myMarioPosY; //!< The position of Mario at begin
        size_t myMaxX, myMaxY; //!< The maximum values of X and Y

        void Render(sf::RenderTarget &Target) const;

    public:
        Map(const std::string &File, const std::string &Table);

        void Reload(const std::string &File, const std::string &Table);

        size_t GetMarioPosX() const;
        size_t GetMarioPosY() const;

        size_t GetMaxX() const;
        size_t GetMaxY() const;

        std::vector < Tile > &Tiles();
        const std::vector < Tile > &Tiles() const;

        float TopMax(const sf::Sprite &Rect, float Max) const;
        float BottomMax(const sf::Sprite &Rect, float Max) const;
        float LeftMax(const sf::Sprite &Rect, float Max) const;
        float RightMax(const sf::Sprite &Rect, float Max) const;
};

#endif // MAP_INCLUDED
