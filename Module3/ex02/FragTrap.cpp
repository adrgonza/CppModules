#include "FragTrap.hpp"

FragTrap::FragTrap()
:ClapTrap("unknown", 100, 100, 30)
{
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name)
:ClapTrap(name, 100, 100, 30)
{
	std::cout << "Name FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap( const FragTrap &other )
{
	std::cout << "Copy FragTrap constructor called" << std::endl;
	*this = other;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor FragTrap called" << std::endl;
}

FragTrap& FragTrap::operator= ( const FragTrap &other )
{
	std::cout << "Assignation FragTrap operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->AttackDamage = other.AttackDamage;
		this->EnergyPoints = other.EnergyPoints;
		this->HitPoints = other.HitPoints;
	}
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
