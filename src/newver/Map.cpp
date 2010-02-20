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
 * @param Rect the bounding rect of the figure
 * @param Max the max going to the top
 * @return the maximm number of pixel Mario can go to the top
 */
sf::Uint32 Map::TopMax(const sf::IntRect &Rect, sf::Uint32 Max) const
{
	sf::Uint32 NbPix = 0;
	size_t Left  = Rect.Left  / Tile::GetDimensionX();
	size_t Right = Rect.Right / Tile::GetDimensionX();
	while(NbPix < Max)
	{
		++NbPix;
		size_t Top = (Rect.Top + NbPix) / Tile::GetDimensionY();
		for(size_t I = Left; I <= Right; ++I)
			if(Top + 1 > 0 && (TileAtPos(I, Top).GetAttributes() & TileAttributes::Empty) != TileAttributes::Empty)
				return NbPix - 1;
	}
	return Max;
}
/**
 * @param Rect the bounding rect of the figure
 * @param Max the max going to the bottom
 * @return the maximm number of pixel Mario can go to the bottom
 */
sf::Uint32 Map::BottomMax(const sf::IntRect &Rect, sf::Uint32 Max) const
{
	sf::Uint32 NbPix = 0;
	size_t Left  = Rect.Left  / Tile::GetDimensionX();
	size_t Right = Rect.Right / Tile::GetDimensionX();
	while(NbPix < Max)
	{
		++NbPix;
		size_t Bottom = (Rect.Bottom - NbPix) / Tile::GetDimensionY();
		for(size_t I = Left; I <= Right; ++I)
			if(Bottom <= myMaxY && (TileAtPos(I, Bottom).GetAttributes() & TileAttributes::Empty) != TileAttributes::Empty)
				return NbPix - 1;
	}
	return Max;
}
/**
 * @param Rect the bounding rect of the figure
 * @param Max the max going to the left
 * @return the maximm number of pixel Mario can go to the left
 */
sf::Uint32 Map::LeftMax(const sf::IntRect &Rect, sf::Uint32 Max) const
{
	sf::Uint32 NbPix = 0;
	size_t Top    = Rect.Top    / Tile::GetDimensionY();
	size_t Bottom = Rect.Bottom / Tile::GetDimensionY();
	while(NbPix < Max)
	{
		++NbPix;
		size_t Left = (Rect.Left - NbPix) / Tile::GetDimensionX();
		for(size_t I = Top; I <= Bottom; ++I)
			if(Left + 1 > 0 && (TileAtPos(I, Left).GetAttributes() & TileAttributes::Empty) != TileAttributes::Empty)
				return NbPix - 1;
	}
	return Max;
}
/**
 * @param Rect the bounding rect of the figure
 * @param Max the max going to the right
 * @return the maximm number of pixel Mario can go to the right
 */
sf::Uint32 Map::RightMax(const sf::IntRect &Rect, sf::Uint32 Max) const
{
	sf::Uint32 NbPix = 0;
	size_t Top    = Rect.Top    / Tile::GetDimensionY();
	size_t Bottom = Rect.Bottom / Tile::GetDimensionY();
	while(NbPix < Max)
	{
		++NbPix;
		size_t Right = (Rect.Right - NbPix) / Tile::GetDimensionX();
		for(size_t I = Top; I <= Bottom; ++I)
			if(Right <= myMaxX && (TileAtPos(I, Right).GetAttributes() & TileAttributes::Empty) != TileAttributes::Empty)
				return NbPix - 1;
	}
	return Max;
}

/**
 * @param Rect the rectangle of the entity
 * @return true if it could go at least 1 pixel to the top
 */
bool Map::CanGoTop(const sf::FloatRect &Rect) const
{
	return true;
	return
		Rect.Top > 0
		&& TopIsFree(Rect.Left  / Tile::GetDimensionX(), Rect.Top / Tile::GetDimensionY())
		&& TopIsFree(Rect.Right / Tile::GetDimensionX(), Rect.Top / Tile::GetDimensionY());
}
/**
 * @param Rect the rectangle of the entity
 * @return true if it could go at least 1 pixel to the bottom
 */
bool Map::CanGoBottom(const sf::FloatRect &Rect) const
{
	return true;
	return
		Rect.Bottom < myMaxY * Tile::GetDimensionY()
		&& BottomIsFree(Rect.Left  / Tile::GetDimensionX(), Rect.Top / Tile::GetDimensionY())
		&& BottomIsFree(Rect.Right / Tile::GetDimensionX(), Rect.Top / Tile::GetDimensionY());
}
/**
 * @param Rect the rectangle of the entity
 * @return true if it could go at least 1 pixel to the left
 */
bool Map::CanGoLeft(const sf::FloatRect &Rect) const
{
	return true;
	return
		Rect.Left > 0
		&& LeftIsFree(Rect.Left / Tile::GetDimensionX(),  Rect.Top                /  Tile::GetDimensionY()     )
		&& LeftIsFree(Rect.Left / Tile::GetDimensionX(), (Rect.Top + Rect.Bottom) / (Tile::GetDimensionY() * 2))
		&& LeftIsFree(Rect.Left / Tile::GetDimensionX(),             Rect.Bottom  /  Tile::GetDimensionY()     );
}
/**
 * @param Rect the rectangle of the entity
 * @return true if it could go at least 1 pixel to the right
 */
bool Map::CanGoRight(const sf::FloatRect &Rect) const
{
	return true;
	return
		Rect.Right < myMaxX * Tile::GetDimensionX()
		&& RightIsFree(Rect.Right / Tile::GetDimensionX(),  Rect.Top                /  Tile::GetDimensionY()     )
		&& RightIsFree(Rect.Right / Tile::GetDimensionX(), (Rect.Top + Rect.Bottom) / (Tile::GetDimensionY() * 2))
		&& RightIsFree(Rect.Right / Tile::GetDimensionX(),             Rect.Bottom  /  Tile::GetDimensionY()     );
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

