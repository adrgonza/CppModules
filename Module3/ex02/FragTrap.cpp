#include "FragTrap.hpp"

FragTrap::FragTrap()
:ClapTrap("unknown", 100, 100, 30)
{
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name)
:ClapTrap(name, 100, 100, 30)
{
	std::cout << "Name constructor called" << std::endl;
}

FragTrap::FragTrap( const FragTrap &other )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called" << std::endl;
}

FragTrap& FragTrap::operator= ( const FragTrap &other )
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
		*this = other;
	return (*this);
}

void FragTrap::guardGate()
{
	std::cout << "FragTrap is now in Gate keeper mode" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap wanna highfive!" << std::endl;
}
