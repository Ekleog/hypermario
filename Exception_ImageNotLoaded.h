/*!
 * \file Exception_ImageNotLoaded.h
 * \author Ekinox <ekinox1995@gmail.com>
 */

#ifndef EXCEPTION__IMAGE_NOT_LOADED_INCLUDED
#define EXCEPTION__IMAGE_NOT_LOADED_INCLUDED 1

#include <string>

#include "Exception.h"

/*!
 * \class Exception_ImageNotLoaded
 * \brief This class models an exception if an image file hadn't been loaded.
 *
 * This class models an exception which should be used when an image should
 * have been loaded but was not, in cause of an unknown error (which in the
 * case of the SFML will be printed via std::cerr)
 */
class Exception_ImageNotLoaded : public Exception
{
    private:
        const char *myFile; //!< The file name of the image not opened

    public:
        /*!
         * \param File The file name of the image you tried to open
         */
        Exception_ImageNotLoaded(const std::string &File) throw () :
                Exception(std::string("File " + File + " hadn't be loaded in "
                        + "memory as an error happened").c_str()),
                        myFile(File.c_str())
        {
        }

        /*!
         * \return The file name of the image you tried to open
         */
        const char *GetFile() const throw ()
        {
            return myFile;
        }
};

#endif // EXCEPTION__IMAGE_NOT_LOADED_INCLUDED
