#include "Fixed.hpp"

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
	this->fixedPoint = static_cast<int>(bits * (1 << fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator= ( const Fixed &other )
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
		this->fixedPoint = other.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    fixed.printAsFloat(os);
    return os;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPoint);
}

void Fixed::setRawBits( int const raw )
{
	this->fixedPoint = raw;
}

float Fixed::toFloat(void) const
{
	float result = 0;

	return (result);
}

int Fixed::toInt(void) const
{
	return fixedPoint >> fractionalBits;
}

void Fixed::printAsFloat(std::ostream& os) const
{
    // Convierte el valor de punto fijo a punto flotante dividiéndolo por 2^(fractionalBits)
    float floatValue = static_cast<float>(fixedPoint) / (1 << fractionalBits);

    // Imprime el valor de punto flotante en el stream de salida
    os << floatValue;
}