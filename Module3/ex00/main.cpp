#include "ClapTrap.hpp"

int main()
{
	ClapTrap a;
	ClapTrap b("Adrgonza");
	ClapTrap c(b);

	a.attack("Hakahmed");
	b.attack("Alepinto");
	c.attack("Amejia");
	a.takeDamage(10);
	a.beRepaired(10);
	b.takeDamage(5);
	b.beRepaired(10);
	c.takeDamage(10);
	c.beRepaired(10);
}
