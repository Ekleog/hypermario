#include <iostream>

#include <SFML/Graphics.hpp>

#include "Tile.h"
#include "Map.h"

int main(int, char**)
{
	Tile::SetTilesDimensions(32, 32);

	sf::RenderWindow Window(sf::VideoMode(320, 320), "Test of Tile");
	Map map("maps/1.map", "maps/correspondance.table");
	while(Window.IsOpened())
	{
		sf::Event Event;
		while(Window.GetEvent(Event))
		{
			if(Event.Type == sf::Event::Closed)
				Window.Close();
			else if(Event.Type == sf::Event::KeyPressed && Event.Key.Code == sf::Key::Escape)
				Window.Close();
		}
		Window.Clear();
		Window.Draw(map);
		Window.Display();
	}
	return 0;
}

