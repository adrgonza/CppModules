#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &);

		~Ice();

		Ice & operator=(const Ice &);

		AMateria* clone() const;

		void use(ICharacter& target);
};
