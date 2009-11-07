#include "Map.h"
#include "Game.h"

Map::Map()
{
    sf::Image map, tiles;

    map.LoadFromFile("media/map.bmp");
    _tiles.resize(map.GetWidth(), std::vector<s_Tiles>(map.GetHeight()));

    tiles.LoadFromFile("media/tiles.bmp");
    _img_tiles.resize(tiles.GetWidth() / 32 + 1);

    const sf::Color mask(208, 214, 226);

    for (int i = 0; i < (_img_tiles.size() - 1); ++i)
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

            _tiles[i][j].type = type;
            _tiles[i][j].spr.SetImage(_img_tiles[type]);

            _tiles[i][j].spr.SetX(static_cast<float>(i * 32));
            _tiles[i][j].spr.SetY(static_cast<float>(j * 32));
        }
    }

    _scroll.Left = 0.f;
    _scroll.Right = static_cast<float>(SCREEN_WIDHT);
    _scroll.Top = 0.f;
    _scroll.Bottom = static_cast<float>(SCREEN_HEIGHT);
}

void Map::refreshScrolling(const sf::Vector2f& pos)
{
    if (_scroll.Right < _tiles.size() * 32
        && pos.x >= _scroll.Left + (_scroll.Right * 0.6))
    {
        ++_scroll.Left;
        ++_scroll.Right;
    }
    else if (_scroll.Left > 0
             && pos.x <= _scroll.Left + (_scroll.Right * 0.3))
    {
        --_scroll.Left;
        --_scroll.Right;
    }

}

void Map::drawMap(sf::RenderWindow& game)
{
    for (int i = 0; i < _tiles.size(); ++i)
    {
        for (int j = 0; j < _tiles[i].size(); ++j)
        {
            game.Draw(_tiles[i][j].spr);
        }
    }
}

sf::Rect<float> Map::getScrolling() const
{
    return _scroll;
}

s_Tiles& Map::getTiles(int x, int y)
{
    return _tiles[x][y];
}
