#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		void defaultMsg( void );

	public:
		Harl();
		~Harl();

		void complain( std::string level );
};

#endif
