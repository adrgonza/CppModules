#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
:ClapTrap("unknown", 100, 50, 20)
{
	std::cout << "Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name)
:ClapTrap(name, 100, 50, 20)
{
	std::cout << "Name constructor called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &other )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator= ( const ScavTrap &other )
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
		*this = other;
	return (*this);
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
