#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		AMateria *_inventory[4];
		std::string _name;
		
	public:
		Character();
		Character(const std::string &);
		Character(const Character &);

		~Character();

		Character & operator=(const Character &);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
