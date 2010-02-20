/**
 * @author Lenoa
 */

#ifndef EXCEPTION__IMAGE_NOT_LOADED_INCLUDED
#define EXCEPTION__IMAGE_NOT_LOADED_INCLUDED 1

#include <string>

#include "Exception.h"

/**
 * This class models an exception which should be used when an image should have been loaded but was not, in cause
 * of an unknown error (which in the case of the SFML will be printed via std::cerr)
 * 
 * @author Lenoa
 */
class Exception_ImageNotLoaded : public Exception
{
	private:
		/**
		 * The file name of the image which you tried to open
		 */
		const char *myFile;

	public:
		/**
		 * @param File the file name of the image you tried to open
		 */
		Exception_ImageNotLoaded(const std::string &File) throw()
			: Exception(("File " + File + " hadn't be loaded in memory as en error happened").c_str())
			, myFile(File.c_str())
		{}

		/**
		 * @return the file name of the image you tried to open
		 */
		const char *GetFile() const throw()
			{ return myFile; }
};

#endif // EXCEPTION__IMAGE_NOT_LOADED_INCLUDED

