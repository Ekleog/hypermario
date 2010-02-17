/**
 * @version 1.0
 *
 * @author Lenoa
 */

#include "Map.h"

#include <string>
#include <vector>
#include <fstream>
#include <map>

#include <SFML/Graphics.hpp>

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
	std::map<char, std::string> m;
	char c;
	std::string s;
	// Loading the correspondancy table <Tile id>/<Image file name>
	while(std::getline(table, s, '\n'))
	{
		c = s.at(0);
		s = s.substr(1);
		if(s.length() > 0)
			m.insert(std::pair<char, std::string>(c, s));
	}
	// Loading from the file
	size_t y = 0;
	while(std::getline(file, s))
	{
		myMap.push_back(std::vector<Tile>());
		size_t x = 0;
		for(std::string::const_iterator i = s.begin(); i != s.end(); ++i)
		{
			myMap.back().push_back(Tile(m[*i], x, y));
			++x;
		}
		++y;
	}
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

