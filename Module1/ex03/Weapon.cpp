#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::~Weapon() {}

Weapon::Weapon(std::string str)
{
	this->type = str;
}

const std::string& Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(std::string str)
{
	this->type = str;
}
