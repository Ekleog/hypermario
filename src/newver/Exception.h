/**
 * @author Lenoa
 */

#ifndef EXCEPTION_INCLUDED
#define EXCEPTION_INCLUDED 1

#include <exception>

/**
 * This class models an exception in Hypermario's project.
 *
 * @author Lenoa
 */
class Exception : public std::exception
{
	private:
		/**
		 * The message of the exception.
		 */
		const char *myMessage;

	public:
		/**
		 * @param Message the message of the exception
		 */
		Exception(const char *Message = "Unknown exception !")
			: myMessage(Message) {}

		/**
		 * @return the message of the exception
		 */
		virtual const char *what() const throw()
		{
			return myMessage;
		}
};

#endif // EXCEPTION_INCLUDED

