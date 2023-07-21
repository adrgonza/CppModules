#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animal.hpp"

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal( const WrongAnimal &other );

		~WrongAnimal();

		WrongAnimal& operator=( const WrongAnimal &other );

		std::string getType(void) const;
		void setType(std::string type);
		void makeSound() const;
};


#endif
