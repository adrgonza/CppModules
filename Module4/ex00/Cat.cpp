#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->setType("Cat");
}

Cat::Cat( const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = other.type;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=( const Cat &other )
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "miauuuuuuuuuuu" <<  std::endl;
}
