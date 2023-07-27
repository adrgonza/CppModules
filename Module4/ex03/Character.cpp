#include "Character.hpp"

Character::Character()
{
	this->name = "default";
}

Character::Character(std::string name)
{
	this->name = name;
}

Character::~Character()
{
}

std::string const &Character::getName() const
{
	return this->name;
}
