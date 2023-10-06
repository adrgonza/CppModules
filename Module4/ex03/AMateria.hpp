#pragma once

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria();
		AMateria(const AMateria &);
		AMateria(std::string const & type);

		virtual ~AMateria();

		AMateria & operator=(const AMateria &);

		std::string const & getType() const;

		virtual AMateria* clone() const = 0;

		virtual void use(ICharacter& target);
};
