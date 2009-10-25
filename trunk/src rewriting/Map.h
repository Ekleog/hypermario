#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <vector>

enum TYPE
{
    BOX, GROUND, WALL, TUBE_HEADER1, TUBE_HEADER2, TUBE_BOTTOM1, TUBE_BOTTOM2, SKY
};

struct s_Tiles
{
    sf::Sprite spr;
    TYPE type;
};

class Map
{
public:
    Map();
    void drawMap(sf::RenderWindow&);

private:
    std::vector<std::vector<s_Tiles> > m_tiles;
    std::vector<sf::Image> m_img_tiles;
};

#endif // MAP_H