#ifndef TILE_INCLUDED
#define TILE_INCLUDED 1

#include <string>

#include <SFML/Graphics.hpp>

#include "ImageManager.h"

class Tile : public sf::Sprite
{
	private:
		static sf::Uint32 ourWidth, ourHeight;

	public:
		static void SetTilesDimensions(sf::Uint32 Width, sf::Uint32 Height);

		Tile(const std::string &Image, sf::Uint32 PosX, sf::Uint32 PosY)
			: sf::Sprite(ImageManager::Get(Image), sf::Vector2f(PosX * ourWidth, PosY * ourHeight))
		{}

		void SetPosition(sf::Uint32 X, sf::Uint32 Y)
			{ sf::Drawable::SetPosition(X * ourWidth, Y * ourHeight); }

		void SetX(sf::Uint32 X)
			{ sf::Drawable::SetX(X * ourWidth); }
		void SetY(sf::Uint32 Y)
			{ sf::Drawable::SetY(Y * ourHeight); }

		sf::Uint32 GetX() const
			{ return sf::Drawable::GetPosition().x / ourWidth; }
		sf::Uint32 GetY() const
			{ return sf::Drawable::GetPosition().y / ourHeight; }

		void GoRight()
			{ SetX(GetX() + 1); }
		void GoLeft()
			{ SetX(GetX() - 1); }
		void GoUp()
			{ SetY(GetY() - 1); }
		void GoDown()
			{ SetY(GetY() + 1); }
};

#endif // TILE_INCLUDED

