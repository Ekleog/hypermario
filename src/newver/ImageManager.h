#ifndef IMAGE_MANAGER_INCLUDED
#define IMAGE_MANAGER_INCLUDED 1

#include <map>
#include <string>

#include <SFML/Graphics.hpp>

class ImageManager
{
	private:
		static std::map<std::string, sf::Image> ourMap;
	
	public:
		static sf::Image &Get(const std::string &Image);
};

#endif // IMAGE_MANAGER_INCLUDED

