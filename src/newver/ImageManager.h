/**
 * @author Lenoa
 */

#ifndef IMAGE_MANAGER_INCLUDED
#define IMAGE_MANAGER_INCLUDED 1

#include <map>
#include <string>

#include <SFML/Graphics.hpp>

/**
 * <i>ImageManager</i> is a class which provides a way to avoid having twice the same image in memory.
 *
 * <b>ATTENTION !</b> It is not thread-safe, not even reentrant.
 *
 * @author Lenoa
 */
class ImageManager
{
	private:
		/**
		 * ourMap is a map std::string - sf::Image : It maps the file name of the image to the
		 * image itself.
		 */
		static std::map<std::string, sf::Image> ourMap;
	
	public:
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
		 * @return a reference to the image associated to the filename in memory
		 * @throws Exception_ImageNotLoaded if the image with the requested file name was not already opened and couldn't be opened
		 */
		static sf::Image &Get(const std::string &Image);
};

#endif // IMAGE_MANAGER_INCLUDED

