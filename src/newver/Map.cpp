/**
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
	size_t y = 0, x;
	std::ifstream file(File.c_str(), std::ios::in | std::ios::binary);
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
	file.close();
	myMaxX = x - 1;
	myMaxY = y - 1;
}

/**
 * It renders the map to the target
 *
 * @param Target the target on which render
 * @author Lenoa
 */
void Map::Render(sf::RenderTarget &Target) const
{
	for(std::vector< std::vector< Tile > >::const_iterator it = myMap.begin(); it != myMap.end(); ++it)
		for(std::vector< Tile >::const_iterator i = (*it).begin(); i != (*it).end(); ++i)
			Target.Draw(*i);
}

