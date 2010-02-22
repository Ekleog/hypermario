// Map.cpp
// By Monsieur_JaKy for hypermario project

#include "Map.h"
#include "Game.h"

#include <iostream> // std::cout and std::endl

using std::cout;
using std::endl;

Map::Map()
{
    sf::Image map, tiles;

    map.LoadFromFile("media/map.bmp");
    _tiles.resize(map.GetWidth(), std::vector<s_Tiles>(map.GetHeight()));

    tiles.LoadFromFile("media/tiles.bmp");
    _img_tiles.resize(tiles.GetWidth() / 32 + 1);

    for (unsigned int i = 0; i < (_img_tiles.size() - 1); ++i)
    {
        _img_tiles[i].Create(32, 32);
        _img_tiles[i].Copy(tiles, 0, 0, sf::IntRect(i * 32, 0, (i + 1) * 32, 32));
        _img_tiles[i].CreateMaskFromColor(mask);
    }

    _img_tiles[_img_tiles.size() - 1].Create(32, 32, sf::Color(0, 0, 255));

    for (unsigned int i = 0; i < map.GetWidth(); ++i)
    {
        for (unsigned int j = 0; j < map.GetHeight(); ++j)
        {
            TYPE type;

            if (map.GetPixel(i, j) == sf::Color::Blue)
                type = SKY;

            else if (map.GetPixel(i, j) == sf::Color::Red)
                type = BOX;

            else if (map.GetPixel(i, j) == sf::Color::Magenta)
                type = WALL;

            else if (map.GetPixel(i, j) == sf::Color::Color(255, 102, 0))
                type = GROUND;

            else if (map.GetPixel(i, j) == sf::Color::Color(34, 255, 29))
                type = TUBE_HEADER1;

            else if (map.GetPixel(i, j) == sf::Color::Color(155, 255, 54))
                type = TUBE_HEADER2;

            else if (map.GetPixel(i, j) == sf::Color::Color(34, 231, 29))
                type = TUBE_BOTTOM1;

            else if (map.GetPixel(i, j) == sf::Color::Color(155, 231, 54))
                type = TUBE_BOTTOM2;

            else
                std::cerr << "Undefined type" << std::endl;

            _tiles[i][j].type = type;
            _tiles[i][j].spr.SetImage(_img_tiles[type]);

            _tiles[i][j].spr.SetX(static_cast<float>(i * 32));
            _tiles[i][j].spr.SetY(static_cast<float>(j * 32));
        }
    }

    _scroll.Left = 0.f;
    _scroll.Right = static_cast<float>(SCREEN_WIDHT);
    _scroll.Top = _tiles[0].size() * 32 - static_cast<float>(SCREEN_HEIGHT);
    _scroll.Bottom = _tiles[0].size() * 32;
}

void Map::refreshScrolling(const sf::Vector2f& pos)
{
        // Check if Mario isn't at the right side
    if ((_scroll.Right < _tiles.size() * 32
        && pos.x >= _scroll.Left + static_cast<int>(SCREEN_WIDHT * 0.5))

        // Or check if Mario isn't at the left side
        || (_scroll.Left > 0
        && pos.x <= _scroll.Left + static_cast<int>(SCREEN_WIDHT * 0.5)))
    {
        // Replace Mario
        _scroll.Left = pos.x - (SCREEN_WIDHT * 0.5);
    }

    _scroll.Right = _scroll.Left + static_cast<float>(SCREEN_WIDHT);

    /** Implémenter la même chose avec les ordonnées **/

}

void Map::drawMap(sf::RenderWindow& game)
{
    for (unsigned int i = 0; i < _tiles.size(); ++i)
    {
        for (unsigned int j = 0; j < _tiles[i].size(); ++j)
        {
            game.Draw(_tiles[i][j].spr);
        }
    }
}

int Map::size(void) const
{
    return _tiles.size() ;
}

sf::Rect<float> Map::getScrolling() const
{
    return _scroll;
}

s_Tiles& Map::getTiles(int x, int y)
{
    return _tiles[x][y];
}

