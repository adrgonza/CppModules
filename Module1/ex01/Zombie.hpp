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

		void announce( void );
};
