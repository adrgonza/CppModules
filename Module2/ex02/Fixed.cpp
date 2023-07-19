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
	this->fixedPoint = bits << this->fractionalBits;
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

Fixed&	Fixed::operator=( const Fixed &other )
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
		this->fixedPoint = other.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->toFloat() != other.toFloat());
}

Fixed	Fixed::operator+(const Fixed &other)
{
	return (this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other)
{
	return (this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other)
{
	return (this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other)
{
	if (other.fixedPoint == 0)
	{
		std::cout << "fatal: division by zero" << std::endl;
		return (*this);
	}
	return (this->toFloat() / other.toFloat());
}

Fixed	&Fixed::operator++(void)
{
	this->fixedPoint++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;

	this->fixedPoint++;
	return temp;
}

Fixed	&Fixed::operator--(void)
{
	fixedPoint--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;

	fixedPoint--;
	return temp;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

const Fixed &Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

/* member functions */

int	Fixed::getRawBits( void ) const
{
	return (this->fixedPoint);
}

void	Fixed::setRawBits( int const raw )
{
	this->fixedPoint = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)(fixedPoint) / (1 << fractionalBits);
}

int	Fixed::toInt(void) const
{
	return (this->fixedPoint >> this->fractionalBits);
}

Fixed &Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}
