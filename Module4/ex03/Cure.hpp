#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure &);

		~Cure();

		Cure & operator=(const Cure &);

		AMateria* clone() const;

		void use(ICharacter& target);
};
