#include "Fixed.hpp"

/* contruct */

Fixed::Fixed() : fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &other )
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPoint = other.getRawBits();
}

Fixed::Fixed( const int bits )
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = bits << fractionalBits;
}

Fixed::Fixed( const float bits )
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = (int)(roundf(bits * (1 << fractionalBits)));
}

/* destruct */

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/* operators */

Fixed& Fixed::operator= ( const Fixed &other )
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
		this->fixedPoint = other.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

/* member functions */

int Fixed::getRawBits( void ) const
{
	return (this->fixedPoint);
}

void Fixed::setRawBits( int const raw )
{
	this->fixedPoint = raw;
}

float Fixed::toFloat(void) const
{
	return (float)(fixedPoint) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return (fixedPoint >> fractionalBits);
}
