#include <iostream>

#include <SFML/Graphics.hpp>

#include "Map.h"
#include "Game.h"
#include "config.h"

int main(int, char**)
{
	Tile::SetTilesDimensions(32, 32);

	sf::RenderWindow Window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Test of Tile");
	Map map("maps/1.map", "maps/correspondance.table");
	Game game(Window, map);
	game.Run();
	return 0;
}

