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
	std::ifstream file(File.c_str(), ios::in | ios::binary);
	std::ifstream table(Table.c_str(), ios::in | ios::binary);
	std::map<char, std::string> m;
	char c;
	std::string s;
	// Loading the correspondancy table <Tile id>/<Image file name>
	while(!table.eof())
	{
		table.get(c);
		getline(table, s, '\n');
		m.insert(c, s);
	}
	// Loading from the file
	size_t x = 0, y = 0;
	while(!file.eof())
	{
		file.get(c);
		if(c == '\n')
		{
			myMap.push_back(std::vector< Tile >());
			++y;
		}
		else
		{
			myMap.back().push_back(Tile(m[c], x, y));
			++x;
		}
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
void Map::Render(sf::RenderTarget &Target)
{
	for(std::vector< std::vector< Tile > >::iterator it = myMap.begin(); it != myMap.end(); ++it)
		for(std::vector< Tile >::iterator i = (*it).begin(); i != (*it).end(); ++i)
			Target.Draw(*i);
}

