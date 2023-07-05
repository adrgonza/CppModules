#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "HumanA.hpp"
#include "HumanB.hpp"

class Weapon
{
	private:
		std::string type;

	public:
		Weapon();
		Weapon(std::string str);
		~Weapon();

		const std::string& getType();
		void	setType(std::string str);
};

#endif
