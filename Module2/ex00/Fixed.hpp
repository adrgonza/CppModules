#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
	private:
		int fixedPoint;
		static const int fractionalBits = 8;

	public:
		Fixed();
		Fixed( const Fixed &other );

		~Fixed();

		Fixed& operator= ( const Fixed &other );

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
