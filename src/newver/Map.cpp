/**
 * @version 1.0
 *
 * @author Lenoa
 */

#include "Map.h"

#include <string>
#include <fstream>
#include <map>
#include <vector>

#include <SFML/Graphics.hpp>

#include "TileAttributes.h"
#include "Tile.h"

/**
 * It loads the file to the map
 *
 * @param File the file in which load the map
 * @param Table the file in which load the correspondancy table of the tiles
 */
void Map::Reload(const std::string &File, const std::string &Table)
{
	std::ifstream file(File.c_str(), std::ios::in | std::ios::binary);
	std::ifstream table(Table.c_str(), std::ios::in | std::ios::binary);
	std::map<char, TileAttributes> m;
	std::string s;
	// Loading the correspondancy table <Tile id>/<Image file name>
	while(std::getline(table, s, '\n'))
	{
		if(s.length() > 2)
			m.insert(std::pair<char, TileAttributes>(s[0], TileAttributes(s.substr(2), s[1])));
	}
	// Loading from the file
	size_t y = 0, x;
	myMaxX = 0;
	while(std::getline(file, s))
	{
		myMap.push_back(std::vector<Tile>());
		x = 0;
		for(std::string::const_iterator i = s.begin(); i != s.end(); ++i)
		{
			if(*i == 'M')
			{
				myMarioPosX = x;
				myMarioPosY = y;
			}
			myMap.back().push_back(Tile(m[*i].Filename, m[*i].Attributes, x, y));
			++x;
		}
		++y;
	}
	myMaxX = x - 1;
	myMaxY = y - 1;
}

/**
 * It renders the map to the target
 *
 * @param Target the target on which render
 * @version 1.0
 * 
 * @author Lenoa
 */
void Map::Render(sf::RenderTarget &Target) const
{
	for(std::vector< std::vector< Tile > >::const_iterator it = myMap.begin(); it != myMap.end(); ++it)
		for(std::vector< Tile >::const_iterator i = (*it).begin(); i != (*it).end(); ++i)
			Target.Draw(*i);
}

