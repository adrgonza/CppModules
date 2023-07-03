#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie* zombix = new Zombie(name);

	zombix->announce();
	return (zombix);
}
