/*!
 * \file Map.cpp
 * \author Ekinox <ekinox1995@gmail.com>
 */

#include "Map.h"

#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

#include <SFML/Graphics.hpp>

#include "TileAttributes.h"
#include "Tile.h"
#include "config.h"
#include "Collision.h"

/*!
 * \param File The file in which load the map
 * \param Table The file in which load the correspondence table of the tiles
 */
Map::Map(const std::string &File, const std::string &Table)
{
    Reload(File, Table);
}

/*!
 * \param File The file in which load the map
 * \param Table The file in which load the correspondence table of the tiles
 */
void Map::Reload(const std::string &File, const std::string &Table)
{
    std::map < char, TileAttributes > m;
    std::string s;

    // Loading the correspondence table <Tile id>/<Tile informations>
    std::ifstream table(Table.c_str(), std::ios::in | std::ios::binary);
    while (std::getline(table, s, '\n'))
        if (s.length() > 2)
            m.insert(std::make_pair(s[0], TileAttributes(s.substr(2), s[1])));
    table.close();

    // Loading the map itself from the file
    size_t y = 0, x;
    std::ifstream file(File.c_str(), std::ios::in | std::ios::binary);
    while (std::getline(file, s))
    {
        x = 0;
        for (std::string::const_iterator i = s.begin() ; i != s.end() ; ++i)
        {
            if (*i == 'M')
            {
                myMarioPosX = x;
                myMarioPosY = y;
            }
            myTiles.push_back(Tile(m[*i].Filename, m[*i].Attributes, x
                    * TILES_WIDTH, y * TILES_HEIGHT));
            ++x;
        }
        ++y;
    }
    file.close();
    myMaxX = x - 1;
    myMaxY = y - 1;
}

/*!
 * \return Mario's X coordinate in the file
 */
size_t Map::GetMarioPosX() const
{
    return myMarioPosX;
}
/*!
 * \return Mario's Y coordinate in the file
 */
size_t Map::GetMarioPosY() const
{
    return myMarioPosY;
}

/*!
 * \return The maximum value on the X axis
 */
size_t Map::GetMaxX() const
{
    return myMaxX;
}
/*!
 * \return The maximum value on the Y axis
 */
size_t Map::GetMaxY() const
{
    return myMaxY;
}

/*!
 * \return A vector composed of all the tiles
 */
std::vector < Tile > &Map::Tiles()
{
    return myTiles;
}
/*!
 * \return A vector composed of all the tiles
 */
const std::vector < Tile > &Map::Tiles() const
{
    return myTiles;
}

/*!
 * \param Rect The bounding rectangle of the figure
 * \param Max The max going to the top
 * \return The maximum number of pixel the figure can go to the top
 */
float Map::TopMax(const sf::Sprite &Rect, float Max) const
{
    float NbPix = 0;
    sf::Sprite Copy(Rect);
    while (NbPix < Max)
    {
        ++NbPix;
        Copy.Move(0, -NbPix);
        for (std::vector < Tile >::const_iterator it(myTiles.begin()) ; it
                != myTiles.end() ; ++it)
            if (it->GetAttributes() != TileAttributes::Empty)
                if (Collision::BoundingBoxTest(Copy, *it))
                    return NbPix - 1;

        Copy.Move(0, NbPix);
    }
    return Max;
}
/**
 * \param Rect the bounding rectangle of the figure
 * \param Max the max going to the bottom
 * \return the maximum number of pixel the figure can go to the bottom
 */
float Map::BottomMax(const sf::Sprite &Rect, float Max) const
{
    float NbPix = 0;
    sf::Sprite Copy(Rect);
    while (NbPix < Max)
    {
        ++NbPix;
        Copy.Move(0, NbPix);
        for (std::vector < Tile >::const_iterator it(myTiles.begin()) ; it
                != myTiles.end() ; ++it)
            if (it->GetAttributes() != TileAttributes::Empty)
                if (Collision::BoundingBoxTest(Copy, *it))
                    return NbPix - 1;

        Copy.Move(0, -NbPix);
    }
    return Max;
}
/*!
 * \param Rect the bounding rectangle of the figure
 * \param Max the max going to the left
 * \return the maximum number of pixel the figure can go to the left
 */
float Map::LeftMax(const sf::Sprite &Rect, float Max) const
{
    float NbPix = 0;
    sf::Sprite Copy(Rect);
    while (NbPix < Max)
    {
        ++NbPix;
        Copy.Move(-NbPix, 0);
        for (std::vector < Tile >::const_iterator it(myTiles.begin()) ; it
                != myTiles.end() ; ++it)
            if (it->GetAttributes() != TileAttributes::Empty)
                if (Collision::BoundingBoxTest(Copy, *it))
                    return NbPix - 1;

        Copy.Move(NbPix, 0);
    }
    return Max;
}
/*!
 * \param Rect the bounding rectangle of the figure
 * \param Max the max going to the right
 * \return the maximum number of pixel the figure can go to the right
 */
float Map::RightMax(const sf::Sprite &Rect, float Max) const
{
    float NbPix = 0;
    sf::Sprite Copy(Rect);
    while (NbPix < Max)
    {
        ++NbPix;
        Copy.Move(NbPix, 0);
        for (std::vector < Tile >::const_iterator it(myTiles.begin()) ; it
                != myTiles.end() ; ++it)
            if (it->GetAttributes() != TileAttributes::Empty)
                if (Collision::BoundingBoxTest(Copy, *it))
                    return NbPix - 1;

        Copy.Move(-NbPix, 0);
    }
    return Max;
}

/**
 * \brief It renders the map to the target
 * \param Target The target on which render
 */
void Map::Render(sf::RenderTarget &Target) const
{
    for (std::vector < Tile >::const_iterator it = myTiles.begin() ; it
            != myTiles.end() ; ++it)
        Target.Draw(*it);
}

