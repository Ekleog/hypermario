/**
 * @author Lenoa
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

/**
 * @param File the file in which load the map
 * @param Table the file in which load the correspondancy table of the tiles
 * @author Lenoa
 */
void Map::Reload(const std::string &File, const std::string &Table)
{
	std::map<char, TileAttributes> m;
	std::string s;

	// Loading the correspondancy table <Tile id>/<Tile informations>
	std::ifstream table(Table.c_str(), std::ios::in | std::ios::binary);
	while(std::getline(table, s, '\n'))
		if(s.length() > 2)
			m.insert(std::pair<char, TileAttributes>(s[0], TileAttributes(s.substr(2), s[1])));
	table.close();

	// Loading the map itself from the file
	size_t y = 0, x = 0;
	std::ifstream file(File.c_str(), std::ios::in | std::ios::binary);
	while(std::getline(file, s))
	{
		x = 0;
		for(std::string::const_iterator i = s.begin(); i != s.end(); ++i)
		{
			if(*i == 'M')
			{
				myMarioPosX = x;
				myMarioPosY = y;
			}
			myTiles.push_back(Tile(m[*i].Filename, m[*i].Attributes, x * TILES_WIDTH, y * TILES_HEIGHT));
			++x;
		}
		++y;
	}
	file.close();
	myMaxX = x - 1;
	myMaxY = y - 1;
}
	
/**
 * @param Rect the bounding rect of the figure
 * @param Max the max going to the top
 * @return the maximm number of pixel Mario can go to the top
 */
float Map::TopMax(const sf::Sprite &Rect, float Max) const
{
	float NbPix = 0;
	sf::Sprite Copy(Rect);
	while(NbPix < Max)
	{
		++NbPix;
		Copy.Move(0, -NbPix);
		for(std::vector<Tile>::const_iterator it(myTiles.begin()); it != myTiles.end(); ++it)
			if(it->GetAttributes() != TileAttributes::Empty)
				if(Collision::PixelTest(Copy, *it))
					return NbPix - 1;

		Copy.Move(0, NbPix);
	}
	return Max;
}
/**
 * @param Rect the bounding rect of the figure
 * @param Max the max going to the bottom
 * @return the maximm number of pixel Mario can go to the bottom
 */
float Map::BottomMax(const sf::Sprite &Rect, float Max) const
{
	float NbPix = 0;
	sf::Sprite Copy(Rect);
	while(NbPix < Max)
	{
		++NbPix;
		Copy.Move(0, NbPix);
		for(std::vector<Tile>::const_iterator it(myTiles.begin()); it != myTiles.end(); ++it)
			if(it->GetAttributes() != TileAttributes::Empty)
				if(Collision::PixelTest(Copy, *it))
					return NbPix - 1;

		Copy.Move(0, -NbPix);
	}
	return Max;
}
/**
 * @param Rect the bounding rect of the figure
 * @param Max the max going to the left
 * @return the maximm number of pixel Mario can go to the left
 */
float Map::LeftMax(const sf::Sprite &Rect, float Max) const
{
	float NbPix = 0;
	sf::Sprite Copy(Rect);
	while(NbPix < Max)
	{
		++NbPix;
		Copy.Move(-NbPix, 0);
		for(std::vector<Tile>::const_iterator it(myTiles.begin()); it != myTiles.end(); ++it)
			if(it->GetAttributes() != TileAttributes::Empty)
				if(Collision::PixelTest(Copy, *it))
					return NbPix - 1;

		Copy.Move(NbPix, 0);
	}
	return Max;
}
/**
 * @param Rect the bounding rect of the figure
 * @param Max the max going to the right
 * @return the maximm number of pixel Mario can go to the right
 */
float Map::RightMax(const sf::Sprite &Rect, float Max) const
{
	float NbPix = 0;
	sf::Sprite Copy(Rect);
	while(NbPix < Max)
	{
		++NbPix;
		Copy.Move(NbPix, 0);
		for(std::vector<Tile>::const_iterator it(myTiles.begin()); it != myTiles.end(); ++it)
			if(it->GetAttributes() != TileAttributes::Empty)
				if(Collision::PixelTest(Copy, *it))
					return NbPix - 1;

		Copy.Move(-NbPix, 0);
	}
	return Max;
}

/**
 * It renders the map to the target
 *
 * @param Target the target on which render
 * @author Lenoa
 */
void Map::Render(sf::RenderTarget &Target) const
{
	for(std::vector<Tile>::const_iterator it = myTiles.begin(); it != myTiles.end(); ++it)
		Target.Draw(*it);
}

