#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	private:

	public:
		Ice();
		Ice(const Ice & other);

		~Ice();

		Ice& operator=( const Ice &other );

		virtual AMateria* clone() const override;
		virtual void use(ICharacter& target) override;
};

#endif
