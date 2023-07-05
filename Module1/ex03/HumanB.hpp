#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class Weapon;

class HumanB
{
	private:
		Weapon weapon;
		std::string name;

	public:
		HumanB();
		HumanB(std::string name);
		~HumanB();

		void attack();
		void setWeapon(Weapon weapon);
};

#endif
