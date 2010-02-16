/**
 * @version 1.1
 *
 * @author Lenoa
 */

#include "ImageManager.h"

#include <map>
#include <string>

#include <SFML/Graphics.hpp>

#include "Exception_ImageNotLoaded.h"

/**
 * ourMap is a map std::string - sf::Image : It maps the file name of the image to the
 * image itself.
 *
 * @see std::map
 * @see std::string
 * @see sf::Image
 * @version 1.0
 *
 * @author Lenoa
 */
static std::map<std::string, sf::Image> ImageManager::ourMap;

/**
 * This function returns the image associated to the file name.
 *
 * If the image is already in memory, a reference to it will be returned. Otherwise, the image
 * will be loaded and then you will get the reference. Be careful not to edit the image, as if
 * you edit the reference returned, then it will be edited in the whole program. However, the
 * return type of the function is not constant, as far as you would be able for example to define
 * a color key of transparency for the whole program. So <b>BE CAREFUL !</b>
 *
 * @param Image the file name of the image to get
 * @throws Exception_ImageNotLoaded if the image with the requested file name was not already opened and couldn't be opened
 * @see sf::Image
 * @see std::string
 * @version 1.0
 *
 * @author Lenoa
 */
static sf::Image &ImageManager::Get(const std::string &Image)
{
	sf::Image &I = ourMap[Image];
	if(I.GetWidth() == 0 && I.GetHeight() == 0)
		if(!I.LoadFromFile(Image))
			throw Exception_ImageNotLoaded(Image);
	return I;
}

