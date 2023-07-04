#include "Zombie.hpp"

int main()
{
	int N = 8;

	Zombie* horde = zombieHorde(N, "Jesus");

	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde;


	N = 3;
	Zombie* horde1 = zombieHorde(N, "Pablo");

	for (int i = 0; i < N; i++)
		horde1[i].announce();

	delete[] horde1;


	N = 6;
	Zombie* horde2 = zombieHorde(N, "Juan");

	for (int i = 0; i < N; i++)
		horde2[i].announce();

	delete[] horde2;
}
