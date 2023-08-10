#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* DogBrain;
	public:
		Dog();
		Dog( const Dog &other );

		~Dog();

		Dog& operator=(const Dog & other);

		void makeSound() const;
		Brain* getbrain();
};

#endif
