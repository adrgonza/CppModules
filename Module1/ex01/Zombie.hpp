#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie();
		~Zombie();

		void setName(std::string name);
		void announce( void );
};

Zombie* zombieHorde( int N, std::string name );
