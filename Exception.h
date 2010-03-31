/*!
 * \file Exception.h
 * \author Ekinox <ekinox1995@gmail.com>
 */

#ifndef EXCEPTION_INCLUDED
#define EXCEPTION_INCLUDED 1

#include <exception>

/*!
 * This class models an exception in Hypermario's project.
 */
class Exception : public std::exception
{
    private:
        const char *myMessage; //!< The message of the exception

    public:
        /*!
         * \param Message The message of the exception
         */
        Exception(const char *Message = "Unknown exception !") :
            myMessage(Message)
        {
        }

        /*!
         * \return The message of the exception
         */
        virtual const char *what() const throw ()
        {
            return myMessage;
        }
};

#endif // EXCEPTION_INCLUDED
