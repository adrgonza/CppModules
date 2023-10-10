#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _materias[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &);

		~MateriaSource();

		MateriaSource & operator=(const MateriaSource &);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};
