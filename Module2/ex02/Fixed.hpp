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

		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other);
		bool operator>=(const Fixed &other);
		bool operator<=(const Fixed &other);
		bool operator==(const Fixed &other);
		bool operator!=(const Fixed &other);

		Fixed &operator+(const Fixed &other);
		Fixed &operator-(const Fixed &other);
		Fixed &operator*(const Fixed &other);
		Fixed &operator/(const Fixed &other);

		Fixed &operator++(int);
		Fixed &operator++(void);

		Fixed &operator--(int);
		Fixed &operator--(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		static Fixed &min(Fixed& a, Fixed& b);
		static Fixed &max(Fixed& a, Fixed& b);

		static Fixed &min(const Fixed& a, const Fixed& b);
		static Fixed &max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
