#include "ImageManager.h"

static std::map ImageManager::ourMap;

static sf::Image &ImageManager::Get(const std::string &Image)
{
	sf::Image &I = ourMap[Image];
	if(I.GetWidth() == 0 && I.GetHeight() == 0)
	{
		if(!I.LoadFromFile(Image))
		{
			// ERROR
		}
	}
	return I;
}

