/**
 * @author Lenoa
 */

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Map.h"
#include "Game.h"
#include "config.h"

/**
 * The main function of a program which just displays the game
 *
 * @return 0 if success ; 1 otherwise
 * @author Lenoa
 */
#include "Collision.h"
int main(int, char**)
{
	//*
	sf::Image A, B;
	A.LoadFromFile("images/mario.png");
	B.LoadFromFile("images/wall.bmp");
	sf::Sprite C(A), D(B);
	sf::IntRect SubRect(32, 0, 64, 64);
	C.SetSubRect(SubRect);
	std::cout << Collision::PixelTest(A, B) << std::endl;
	/*/
	sf::RenderWindow Window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "HyperMario");
	Map map("maps/1.map", "maps/correspondance.table");
	Game game(Window, map);
	game.Run();
	return 0;
	// */
}

