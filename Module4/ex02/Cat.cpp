#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->setType("Cat");
	this->CatBrain = new Brain();
}

Cat::Cat( const Cat &other) : Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = other.type;
	this->CatBrain = new Brain(*(this->CatBrain));
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->CatBrain;
}

Cat& Cat::operator=( const Cat &other )
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		delete this->CatBrain;
		this->CatBrain = new Brain(*(other.CatBrain));
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "miauuuuuuuuuuu" <<  std::endl;
}

Brain* Cat::getbrain()
{
	return (this->CatBrain);
}
