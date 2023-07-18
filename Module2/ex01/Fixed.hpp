#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>

class Fixed
{
	private:
		int fixedPoint;
		static const int fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int bits);
		Fixed(const float bits);

		~Fixed();

		Fixed &operator=(const Fixed &other);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
