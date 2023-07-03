#include "Zombie.hpp"

int	main(void)
{
	Zombie* zombix1 = newZombie("Jaime");

	randomChump("Jairo");

	Zombie* zombix2 = newZombie("Jose");
	Zombie* zombix3 = newZombie("Juan");

	randomChump("Jesus");

	delete zombix1;
	delete zombix2;
	delete zombix3;

	std::cout << std::endl;
	Zombie* Pedro = newZombie("Pedro");
	Zombie* Pablo = newZombie("Pablo");
	Zombie* Paco = newZombie("Paco");
	randomChump("Pepe");
	randomChump("Paul");
	Zombie* Patricio = newZombie("Patricio");
	Zombie* Pascual = newZombie("Pascual");
	randomChump("Pelayo");
	Zombie* Pau = newZombie("Pau");

	delete Pedro;
	delete Pablo;
	delete Paco;
	delete Patricio;
	delete Pascual;
	delete Pau;
}
