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
	public:
		Animal();
		Animal( const Animal &other );

		~Animal();

		Animal& operator=( const Animal &other );

		std::string getType(void);
		void setType(std::string type);
		void makeSound();
};

#endif
