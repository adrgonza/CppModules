#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
:ClapTrap("unknown", 100, 50, 20)
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name)
:ClapTrap(name, 100, 50, 20)
{
	std::cout << "Name ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &other )
{
	std::cout << "Copy ScavTrap constructor called" << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor ScavTrap called" << std::endl;
}

ScavTrap& ScavTrap::operator= ( const ScavTrap &other )
{
	std::cout << "Assignation ScavTrap operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->AttackDamage = other.AttackDamage;
		this->EnergyPoints = other.EnergyPoints;
		this->HitPoints = other.HitPoints;
	}
	return (*this);
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
