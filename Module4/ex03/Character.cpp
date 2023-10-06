#include "Character.hpp"

Character::Character()
{
	_name = "default";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const std::string &name)
{
	_name = name;
}

Character::Character(const Character &other)
{
	_name = other._name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = other._inventory[i];

}

Character::~Character()
{

}

Character & Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
			_inventory[i] = other._inventory[i];
	}
}

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
	}
	std::cout << "Inventory full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "idx not btweeem 0-3" << std::endl;
		return ;
	}
	if (!_inventory[idx])
		return ;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "idx not btweeem 0-3" << std::endl;
		return ;
	}
	
}
