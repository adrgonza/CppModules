#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->setType("Dog");
	this->DogBrain = new Brain();
}

Dog::Dog( const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->DogBrain;
}

Dog& Dog::operator=( const Dog &other )
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		this->DogBrain = other.DogBrain;
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "guauuu" <<  std::endl;
}

Brain* Dog::getbrain()
{
	return (this->DogBrain);
}