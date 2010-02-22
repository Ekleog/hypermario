// Map.h
// By Monsieur_JaKy for hypermario project

#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp> // sf::RenderWindow, sf::Sprite, sf::Vector2f, etc...
#include <vector> // _tiles and _img_tiles

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
    s_Tiles& getTiles(int, int);

    void refreshScrolling(const sf::Vector2f& ) ;
    sf::Rect<float> getScrolling(void) const;
    int size(void) const;

private:
    std::vector<std::vector<s_Tiles> > _tiles;
    std::vector<sf::Image> _img_tiles;

     sf::Rect<float> _scroll;
};

#endif // MAP_H
