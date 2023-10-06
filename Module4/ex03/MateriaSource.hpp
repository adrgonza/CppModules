#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &);

		~MateriaSource();

		MateriaSource & operator=(const MateriaSource &);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};
