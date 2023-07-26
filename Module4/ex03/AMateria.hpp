#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include "string"

class AMateria
{
	protected:
	public:
		AMateria();
		AMateria(std::string const & type);

		~AMateria();

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		std::string const & getType() const;
};

#endif
