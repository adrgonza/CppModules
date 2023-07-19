#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap a;
	FragTrap b("Adrgonza");
	FragTrap c(b);
	FragTrap d;

	a.attack("Hakahmed");
	b.attack("Alepinto");
	c.attack("Amejia");
	a.takeDamage(10);
	a.beRepaired(10);
	b.takeDamage(5);
	b.beRepaired(10);
	c.takeDamage(10);
	c.beRepaired(10);
	c.guardGate();
	c.highFivesGuys();
}

