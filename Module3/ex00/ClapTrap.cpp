#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	name = "unknown";
	HitPoints = 10;
	EnergyPoints = 10;
	AttackDamage = 0;
}

ClapTrap::ClapTrap( const std::string name )
{
	std::cout << "Name constructor called" << std::endl;
	this->name = name;
	HitPoints = 10;
	EnergyPoints = 10;
	AttackDamage = 0;
}

ClapTrap::ClapTrap( const ClapTrap &other )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (HitPoints < 1 || EnergyPoints < 1)
		return ;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << AttackDamage << "points of damage!" << std::endl;
	EnergyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	HitPoints -= AttackDamage;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (HitPoints < 1 || EnergyPoints < 1)
		return ;
	HitPoints += amount;
	EnergyPoints--;
}
