/*!
 * \file ImageManager.cpp
 * \author Ekinox <ekinox1995@gmail.com>
 */

#include "ImageManager.h"

#include <map>
#include <string>

#include <SFML/Graphics.hpp>

#include "Exception_ImageNotLoaded.h"

/*!
 * ourMap is a map std::string - sf::Image : It maps the file name of the image to the
 * image itself.
 */
std::map < std::string, sf::Image > ImageManager::ourMap;

/*!
 * \brief This function returns the image associated to the file name.
 * \param Image The file name of the image to get
 * \return A reference to the image in memory
 *
 * If the image is already in memory, a reference to it will be returned.
 * Otherwise, the image will be loaded and then you will get the reference.
 * Be careful not to edit the image, as if you edit the reference returned,
 * then it will be edited in the whole program. However, the return type of the
 * function is not constant, as far as you would be able for example to define
 * a color key of transparency for the whole program (however it is for only
 * one image).
 *
 * So <b>BE CAREFUL !</b>
 */
sf::Image &ImageManager::Get(const std::string &Image)
{
    // If we already have the image, return it
    std::map < std::string, sf::Image >::iterator it = ourMap.find(Image);
    if (it != ourMap.end())
        return (*it).second;

    // Otherwise, load it from the file
    sf::Image &I = ourMap[Image];
    if (!I.LoadFromFile(Image))
        throw Exception_ImageNotLoaded(Image); // On error, throw the exception

    // And return the image
    return I;
}

