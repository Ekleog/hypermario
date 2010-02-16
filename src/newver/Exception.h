/**
 * @version 1.0
 *
 * @author Lenoa
 */

#ifndef EXCEPTION_INCLUDED
#define EXCEPTION_INCLUDED 1

#include <exception>

/**
 * This class models an exception in Hypermario's project.
 *
 * It does nothing more than std::exception ; but it is a base for each exception of Hypermario.
 *
 * @version 1.0
 *
 * @author Lenoa
 */
class Exception : public std::exception
{
	private:
		/**
		 * The message of the exception.
		 *
		 * @version 1.0
		 * 
		 * @author Lenoa
		 */
		const char *myMessage;

	public:
		/**
		 * The default constructor.
		 *
		 * If no parameter, then the message will be set to a default message.
		 *
		 * @param Message the message of the exception
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		Exception(const char *Message = "Unknown exception !")
			: myMessage(Message) {}

		/**
		 * The reimplementation of the virtual function of std::exception.
		 *
		 * It just returns the message gived by the constructor.
		 *
		 * @return the message of the exception
		 * @version 1.0
		 *
		 * @author Lenoa
		 */
		virtual const char *what() const throw()
		{
			return myMessage;
		}
};

#endif // EXCEPTION_INCLUDED

