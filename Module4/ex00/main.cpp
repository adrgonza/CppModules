#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();


	const WrongAnimal* b = new WrongAnimal();
	const WrongAnimal* a = new WrongCat();

	std::cout << a->getType() << " " << std::endl;
	a->makeSound();
	b->makeSound();

	delete meta;
	delete i;
	delete j;
	delete b;
	delete a;

	return 0;
}
