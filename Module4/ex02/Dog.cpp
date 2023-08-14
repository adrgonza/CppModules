#include "Dog.hpp"

Dog::Dog() :Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->setType("Dog");
	this->DogBrain = new Brain();
}

Dog::Dog( const Dog &other) : Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = other.type;
	this->DogBrain = new Brain(*(other.DogBrain));
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
		delete this->DogBrain;
		this->DogBrain = new Brain(*(other.DogBrain));
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