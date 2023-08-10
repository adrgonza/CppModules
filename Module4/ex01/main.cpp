#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	const int arraySize = 10;

	Animal *animalArray[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		if (i < arraySize / 2)
			animalArray[i] = new Dog();
		else
			animalArray[i] = new Cat();
	}

	for (int i = 0; i < arraySize; i++)
		delete animalArray[i];

	std::cout << std::endl;

	Dog *dog = new Dog();
	std::cout << std::endl << dog->getbrain()->getIdeas(0) << std::endl << std::endl;
	delete dog;
}
