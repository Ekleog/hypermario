/*!
 * \file ImageManager.h
 * \author Ekinox <ekinox1995@gmail.com>
 */

#ifndef IMAGE_MANAGER_INCLUDED
#define IMAGE_MANAGER_INCLUDED 1

#include <map>
#include <string>

#include <SFML/Graphics.hpp>

/**
 * \class ImageManager
 * \brief It is a class which provides a way to avoid having twice the
 *        same image in memory.
 *
 * <b>BE CAREFUL !</b> It is not thread-safe, not even reentrant.
 */
class ImageManager
{
    private:
        static std::map < std::string, sf::Image > ourMap;

    public:
        static sf::Image &Get(const std::string &Image);
};

#endif // IMAGE_MANAGER_INCLUDED
