#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class Animal
{
	protected:
		std::string type;
	private:

	public:
		Animal();
		~Animal();

		std::string getType(void);
};

#endif
